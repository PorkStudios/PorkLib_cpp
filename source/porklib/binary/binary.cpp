#include "binary.h"

namespace porklib::binary {
    Sink* Buffer::sink() {
        struct Impl: Sink {
            Buffer* const delegate;

            Impl(Buffer* const delegate) : delegate(delegate) {}
            void put(const void* data, u_size bytes) override { this->delegate->write(data, bytes); }
            ~Impl() override {}
        };

        return new Impl(this);
    }

    Source* Buffer::source() {
        struct Impl: Source {
            Buffer* const delegate;

            Impl(Buffer* const delegate): delegate(delegate) {}
            void get(const void* data, u_size bytes) override { this->delegate->read(data, bytes); }
            ~Impl() override {}
        };

        return new Impl(this);
    }
}
