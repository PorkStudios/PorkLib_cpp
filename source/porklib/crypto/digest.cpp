#include "digest.h"

namespace porklib::crypto {
    //apparently the pure virtual destructor needs to be declared even though it's pure virtual
    //man c++ is weird
    Digest::~Digest() {}
}
