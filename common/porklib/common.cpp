#include "common.h"

word Object::hashCode() {
    return (word) this;
}

bool Object::equals(Object *other) {
    return this == other;
}
