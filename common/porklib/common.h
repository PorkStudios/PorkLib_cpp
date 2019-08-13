#ifndef PORKLIB_CPP_DEV_COMMON_H
#define PORKLIB_CPP_DEV_COMMON_H

#include <jmorecfg.h>
#include "types.h"

/**
 * Root class for all other classes, because I honestly prefer Java.
 *
 * @author DaPorkchop_
 */
class Object {
    public:
        /**
         * Computes this object's hash code value.
         *
         * @return this object's hash code
         */
        virtual word hashCode();

        /**
         * Checks whether or not this object is equal to another one.
         *
         * @param other the other object to check for equality with
         * @return whether or not the two object are equal
         */
        virtual bool equals(Object *other);

        virtual ~Object() = 0;
};

/**
 * A type that has a certain size.
 *
 * @author DaPorkchop_
 */
class Sized : public Object {
    public:
        /**
         * @return whether or not the instance is empty
         */
        virtual bool isEmpty() {
            return this->size() == 0;
        }

        /**
         * @return the size of this instance (the number of elements)
         */
        virtual word size() = 0;
};

/**
 * A sequence of characters.
 *
 * @author DaPorkchop_
 */
class String : public Sized {
    public:
        /**
         * Gets the character at a specific index.
         * @param index the index of the character to get
         * @return the character at the given index
         * @throws
         */
        virtual u16 charAt(word index) = 0;
};

#endif //PORKLIB_CPP_DEV_COMMON_H
