#ifndef PORKLIB_CPP_NETWORK_H
#define PORKLIB_CPP_NETWORK_H

#include <porklib/binary/binary.h>

#include <netinet/in.h>

namespace porklib::network {
    /**
     * Represents a UDP datagram.
     *
     * @author DaPorkchop_
     */
    struct Datagram {
        const char* data;
        u_size size;
    };
}

#endif //PORKLIB_CPP_NETWORK_H
