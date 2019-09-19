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
     * @param format the base format
     * @param ... arguments to the formatter
     * @return the formatted, NUL-terminated message. This must be freed once no longer needed!
     */
    const char* fmt(const char* format, ...);

    /**
     * A function that can accept a single value of type T.
     *
     * @tparam T the parameter type
     */
    template<typename T> using Consumer = void (*)(T);

    /**
     * A type that contains a number of values.
     *
     * @tparam T the type of value stored in this collection
     */
    template<typename T> struct Collection   {
        Collection() = default;
        virtual ~Collection() = 0;

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
         * @param value the value to check for the presence of
         * @return whether or not the value is contained in this collection
         */
        virtual bool contains(T value) = 0;

        /**
         * Iterates over every value in this collection and runs the given function on it.
         * <p>
         * The order of iteration is not defined.
         *
         * @param function the function to run
         */
        virtual void forEach(Consumer<T> function) = 0;

        /**
         * @return the number of elements in this collection
         */
        virtual size_t size() = 0;

        /**
         * Removes all values from this collection.
         * <p>
         * After invoking this method, the instance will no longer contain any values. However, it is not required
         * to be in its original state (i.e. it may still use the same amount of resources as it did before it was
         * cleared).
         */
        virtual void clear() = 0;
    };
}

#endif //PORKLIB_CPP_DEV_COMMON_H
