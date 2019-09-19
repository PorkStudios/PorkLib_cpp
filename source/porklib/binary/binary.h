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
        virtual ~Sink() = 0;

        template<typename T> void put(const T* data) { this->put(data, sizeof(T)); }
        virtual void put(const void* data, size_t bytes) = 0;
    };

    /**
     * A type that one may read arbitrary binary data from.
     * <p>
     * Similar to a Java InputStream.
     *
     * @author DaPorkchop_
     */
    struct Source {
        virtual ~Source() = 0;

        template<typename T> void get(const T* data) { this->get(data, sizeof(T)); }
        virtual void get(const void* data, size_t bytes) = 0;
    };

    /**
     * A buffer with independent reader and writer indices.
     * <p>
     * Similar to Netty's ByteBuf.
     *
     * @author DaPorkchop_
     */
    struct Buffer {
        virtual ~Buffer() = 0;

        constexpr size_t readerIndex() { return this->m_readerIndex; }
        constexpr size_t writerIndex() { return this->m_writerIndex; }
        constexpr size_t readable() { return this->m_writerIndex - this->m_readerIndex; }
        constexpr boolean isReadable() { return this->m_readerIndex < this->m_writerIndex; }

        virtual void write(const void* data, size_t bytes) = 0;
        virtual void read(const void* data, size_t bytes) = 0;

        virtual Sink* sink();
        virtual Source* source();

    protected:
        size_t m_readerIndex = 0;
        size_t m_writerIndex = 0;
    };
}

#endif //PORKLIB_CPP_BINARY_H
