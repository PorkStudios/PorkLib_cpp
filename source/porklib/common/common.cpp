#include "common.h"

#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

namespace porklib {
    word lengthOf(const char* text) {
        word i = 0;
        while (text[i] != 0) {
            i++;
        }
        return i;
    }

    const char* fmt(const char* format, ...) {
        va_list args;
        va_start(args, format);
        char* result = new char[snprintf(nullptr, 0, format, args) + 1];
        sprintf(result, format, args);
        return result;
    }

    void zero(const void* ptr, u_size bytes) {
        while (bytes--) {
            ((u8*) ptr)[bytes] = 0;
        }
    }

    //must define pure virtual destructor because c++ is stupid
    template<typename T> Collection<T>::~Collection() {}
    template<typename T> List<T>::~List() {}

    //ArrayList implementations
    template<typename T> ArrayList<T>::ArrayList(): data(new T[16]), capacity(16), m_size(0) {}

    template<typename T> ArrayList<T>::ArrayList(u_size initialCapacity): data(new T[initialCapacity]), capacity(initialCapacity), m_size(0) {}

    template<typename T> ArrayList<T>::~ArrayList() {
        delete this->data;
    }

    template<typename T> bool ArrayList<T>::add(T value) {
        if (this->m_size == this->capacity)   {
            this->capacity <<= 1;
            this->data = realloc(this->data, this->capacity);
        }
        this->data[this->m_size++] = value;
        return true;
    }

    template<typename T> bool ArrayList<T>::contains(T value) {
        for (u_size i = 0; i < this->m_size; i++)   {
            if (this->data[i] == value) {
                return true;
            }
        }
        return false;
    }

    template<typename T> bool ArrayList<T>::remove(T value) {
        throw "unimplemented";
    }

    template<typename T> void ArrayList<T>::forEach(Consumer<T> function) {
        for (u_size i = 0; i < this->m_size; i++)   {
            function(this->data[i]);
        }
    }

    template<typename T> u_size ArrayList<T>::size() {
        return this->m_size;
    }

    template<typename T> void ArrayList<T>::clear() {
        zero(this->data, this->m_size * sizeof(T));
    }

    template<typename T> T ArrayList<T>::get(u_size index) {
        throw "unimplemented";
    }

    template<typename T> u_size ArrayList<T>::indexOf(T value) {
        for (u_size i = 0; i < this->m_size; i++)   {
            if (this->data[i] == value) {
                return i;
            }
        }
        return SIZE_NULL;
    }
}
