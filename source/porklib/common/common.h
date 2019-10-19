#ifndef PORKLIB_CPP_DEV_COMMON_H
#define PORKLIB_CPP_DEV_COMMON_H

#include "porklib/types.h"

namespace porklib {
    /**
     * Checks whether a type inherits from another type.
     *
     * @tparam B the requested type
     * @tparam T the type to check
     * @param ptr a pointer to an instance of the type to check
     * @return whether or not the type inherits from the other type
     */
    template<typename B, typename T>
    inline bool instanceof(const T* ptr) { return dynamic_cast<const B*>(ptr) != nullptr; };

    /**
     * Computes the length (in chars) of the given text.
     *
     * @param text the text
     * @return the length of the text
     */
    word lengthOf(const char* text);

    /**
     * Formats the given string with the given arguments into a single NUL-terminated output string.
     *
     * @param format the base format
     * @param ... arguments to the formatter
     * @return the formatted, NUL-terminated message. This must be freed once no longer needed!
     */
    const char* fmt(const char* format, ...);

    /**
     * Fills the given memory block with zeroes, starting at the given address.
     *
     * @param ptr the address to start writing zeroes at
     * @param bytes the number of bytes to zero out
     */
    void zero(void* const ptr, u_size bytes);

    /**
     * Copies the given memory block to the given destination memory block.
     *
     * @param src the first address to start copying from
     * @param dst the first address to start copying to
     * @param bytes the number of bytes to copy
     */
    void copy(const void* const src, void* const dst, u_size bytes);

    /**
     * A type that contains a number of values.
     *
     * @tparam T the type of value stored in this collection
     */
    template<typename T> struct Collection {
        Collection() = default;
        virtual ~Collection() = default;

        /**
         * Adds the given value to this collection.
         * <p>
         * The implementation may refuse to add the value (e.g. due to capacity constraints).
         *
         * @param value the value to add
         * @return whether or not the value was added
         */
        virtual bool add(T value) = 0;

        /**
         * Checks whether or not the given value is contained in this collection.
         *
         * @param value the value to check for the presence of
         * @return whether or not the value is contained in this collection
         */
        virtual bool contains(T value) = 0;

        /**
         * Removes the given value from this collection.
         * <p>
         * Note that if the value is present in this collection multiple times, this will only remove one of them.
         *
         * @param value the value to remove
         * @return whether or not the value was removed
         */
        virtual bool remove(T value) = 0;

        /**
         * Removes every occurrence of the given value from this collection.
         * <p>
         * Similar to {@link #remove(T)}, but removes all occurrences instead of just one.
         *
         * @param value the value to remove
         * @return whether or not at least one occurrence of the value was removed
         */
        virtual bool removeAll(T value) {
            bool changed = false;
            while (this->remove(value)) {
                changed = true;
            }
            return changed;
        }

        /**
         * Iterates over every value in this collection and runs the given function on it.
         * <p>
         * The order of iteration is not defined.
         *
         * @param function the function to run
         */
        virtual void forEach(Consumer <T> function) = 0;

        /**
         * @return the number of elements in this collection
         */
        virtual u_size size() = 0;

        /**
         * Removes all values from this collection.
         * <p>
         * After invoking this method, the instance will no longer contain any values. However, it is not required
         * to be in its original state (i.e. it may still use the same amount of resources as it did before it was
         * cleared).
         */
        virtual void clear() = 0;
    };

    /**
     * A {@link Collection} with a fixed order. All items are given a specific index.
     * <p>
     * Adding or removing elements at indices not at the end of the list will result in all following values
     * being displaced in the list (i.e. they will be moved forwards or back to make place for/fill the gap from
     * the added/removed value).
     *
     * @tparam T the type of value stored in this list
     */
    template<typename T> struct List: Collection<T> {
        virtual ~List() = default;

        bool add(T value) override = 0;
        bool contains(T value) override = 0;
        bool remove(T value) override = 0;

        /**
         * Gets the value stored in this list at the given index.
         *
         * @param index the index of the element to get
         * @return the value at the given index
         * //TODO: @throws IndexOutOfBoundsException if the given index is out of bounds
         */
        virtual T get(u_size index) = 0;

        /**
         * Gets the index of the given value in this list.
         * <p>
         * Generally implemented as a brute-force search, iterating over every element in the list until a matching one is found.
         *
         * @param value the value to search for
         * @return the index of the given value in this list, or {@link SIZE_NULL} if none is found
         */
        virtual u_size indexOf(T value) = 0;

        void forEach(Consumer <T> function) override = 0;
        u_size size() override = 0;
        void clear() override = 0;
    };

    template<typename T, Consumer <T> DESTROY = lambda::noop_Consumer> struct ArrayList: List<T> {
    private:
        T* data;
        u_size capacity;
        u_size m_size;
    public:
        ArrayList(): data(new T[16]), capacity(16), m_size(0) {}
        ArrayList(u_size initialCapacity): data(initialCapacity <= 0 ? nullptr : new T[initialCapacity]), capacity(initialCapacity), m_size(0) {}
        ~ArrayList() {
            this->clear();
            delete this->data;
        };

        bool add(T value) override {
            if (this->m_size == this->capacity) {
                T* old_data = this->data;
                copy(old_data, this->data = new T[this->capacity <<= 1], this->m_size * sizeof(T));
                delete old_data;
            }
            this->data[this->m_size++] = value;
            return true;
        }

        bool contains(T value) override {
            for (u_size i = 0; i < this->m_size; i++) {
                if (this->data[i] == value) {
                    return true;
                }
            }
            return false;
        }

        bool remove(T value) override {
            throw "unimplemented";
        }

        void forEach(Consumer <T> function) override {
            for (u_size i = 0; i < this->m_size; i++) {
                function(this->data[i]);
            }
        }

        u_size size() override { return this->m_size; }

        void clear() override {
            for (u_size i = 0; i < this->m_size; i++) {
                DESTROY(this->data[i]);
            }
            this->m_size = 0;
        }

        T get(u_size index) override {
            throw "unimplemented";
        }

        u_size indexOf(T value) override {
            for (u_size i = 0; i < this->m_size; i++) {
                if (this->data[i] == value) {
                    return i;
                }
            }
            return SIZE_NULL;
        }

        /**
         * Trims the size of the backing array to be exactly the same as the number of elements in the list.
         */
        void trim() {
            if (this->capacity > this->m_size)  {
                T* old_data = this->data;
                copy(old_data, this->data = new T[this->capacity = this->m_size], this->m_size * sizeof(T));
                delete old_data;
            }
        }
    };
}

#endif //PORKLIB_CPP_DEV_COMMON_H
