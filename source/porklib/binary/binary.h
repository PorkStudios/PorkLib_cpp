#ifndef PORKLIB_CPP_BINARY_H
#define PORKLIB_CPP_BINARY_H

#include "porklib/common/common.h"

namespace porklib::binary {
    /**
     * A type that one may write arbitrary binary data to.
     * <p>
     * Similar to a Java OutputStream.
     *
     * @author DaPorkchop_
     */
    struct Sink {
        template<typename T> void put(const T* const data) { this->put(data, sizeof(T)); }
        virtual void put(const void* const data, size_t bytes) = 0;

        virtual ~Sink() = 0;
    };

    /**
     * A type that one may read arbitrary binary data from.
     * <p>
     * Similar to a Java InputStream.
     *
     * @author DaPorkchop_
     */
    struct Source   {
        template<typename T> void get(const T* data) { this->get(data, sizeof(T)); }
        virtual void get(const void* data, size_t bytes) = 0;

        virtual ~Source() = 0;
    };

    /**
     * A combination of a {@link Sink} and a {@link Source} with independent reader and writer indices over a block
     * of data (generally contiguous, generally in memory).
     *
     * @author DaPorkchop_
     */
    struct Buffer : Sink, Source {
        constexpr size_t readerIndex() { return this->m_readerIndex; }
        constexpr size_t writerIndex() { return this->m_writerIndex; }
        constexpr size_t readable() { return this->m_writerIndex - this->m_readerIndex; }
        constexpr boolean isReadable() { return this->m_readerIndex < this->m_writerIndex; }

        virtual ~Buffer() = 0;
    protected:
        size_t m_readerIndex = 0;
        size_t m_writerIndex = 0;
    };
}

#endif //PORKLIB_CPP_BINARY_H
