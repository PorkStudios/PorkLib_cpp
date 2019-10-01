#ifndef PORKLIB_CPP_VECTORS_H
#define PORKLIB_CPP_VECTORS_H

#include <porklib/types.h>

namespace porklib::math::vector {
    template<typename V, typename _FLOOR = V> struct Vector2 {
        V x, y;

        //constructors

        inline Vector2():
                x(0), y(0) {};

        inline Vector2(V v):
                x(v), y(v) {};

        inline Vector2(V x, V y):
                x(x), y(y) {};

        template<typename S, typename S_FLOOR> inline Vector2(const Vector2<S, S_FLOOR>& other):
                x(static_cast<V>(other.x)), y(static_cast<V>(other.y)) {};

        //setters

        template<typename S> inline void set(S value) {
            this->x = this->y = static_cast<V>(value);
        }

        template<typename S> inline void set(S xIn, S yIn) {
            this->x = static_cast<V>(xIn);
            this->y = static_cast<V>(yIn);
        }

        //operators

        template<typename S, typename S_FLOOR> inline bool operator==(const Vector2<S, S_FLOOR>& other) {
            return this->x == static_cast<V>(other.x) && this->y == static_cast<V>(other.y);
        }

        template<typename S, typename S_FLOOR> inline bool operator!=(const Vector2<S, S_FLOOR>& other) {
            return this->x != static_cast<V>(other.x) && this->y != static_cast<V>(other.y);
        }

        //bool operator > (const Vector2<V> & other);
        //bool operator < (const Vector2<V> & other);

        template<typename S, typename S_FLOOR> inline void operator+=(const Vector2<S, S_FLOOR>& other) {
            this->x += static_cast<V>(other.x);
            this->y += static_cast<V>(other.y);
        }

        template<typename S> inline void operator+=(S value) {
            this->x += static_cast<V>(value);
            this->y += static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator-=(const Vector2<S, S_FLOOR>& other) {
            this->x -= static_cast<V>(other.x);
            this->y -= static_cast<V>(other.y);
        }

        template<typename S> inline void operator-=(S value) {
            this->x -= static_cast<V>(value);
            this->y -= static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator*=(const Vector2<S, S_FLOOR>& other) {
            this->x *= static_cast<V>(other.x);
            this->y *= static_cast<V>(other.y);
        }

        template<typename S> inline void operator*=(S value) {
            this->x *= static_cast<V>(value);
            this->y *= static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator/=(const Vector2<S, S_FLOOR>& other) {
            this->x /= static_cast<V>(other.x);
            this->y /= static_cast<V>(other.y);
        }

        template<typename S> inline void operator/=(S value) {
            this->x /= static_cast<V>(value);
            this->y /= static_cast<V>(value);
        }

        template<typename S> inline Vector2<V, _FLOOR> operator+(S value) {
            return Vector2(this->x + static_cast<V>(value), this->y + static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector2<V, _FLOOR> operator+(const Vector2<S, S_FLOOR>& other) {
            return Vector2(this->x + static_cast<V>(other.x), this->y + static_cast<V>(other.y));
        }

        template<typename S> inline Vector2<V, _FLOOR> operator-(S value) {
            return Vector2(this->x - static_cast<V>(value), this->y - static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector2<V, _FLOOR> operator-(const Vector2<S, S_FLOOR>& other) {
            return Vector2(this->x - static_cast<V>(other.x), this->y - static_cast<V>(other.y));
        }

        template<typename S> inline Vector2<V, _FLOOR> operator*(S value) {
            return Vector2(this->x * static_cast<V>(value), this->y * static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector2<V, _FLOOR> operator*(const Vector2<S, S_FLOOR>& other) {
            return Vector2(this->x * static_cast<V>(other.x), this->y * static_cast<V>(other.y));
        }

        template<typename S> inline Vector2<V, _FLOOR> operator/(S value) {
            return Vector2(this->x / static_cast<V>(value), this->y / static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector2<V, _FLOOR> operator/(const Vector2<S, S_FLOOR>& other) {
            return Vector2(this->x / static_cast<V>(other.x), this->y / static_cast<V>(other.y));
        }

        inline Vector2<V, _FLOOR> operator-() {
            return Vector2(-this->x, -this->y);
        };
    };

    template<typename V, typename _FLOOR = V> struct Vector3 {
        V x, y, z;

        //constructors

        inline Vector3():
                x(0), y(0), z(0) {};

        inline Vector3(V v):
        x(v), y(v), z(v) {};

        inline Vector3(V x, V y, V z):
        x(x), y(y), z(z) {};

        template<typename S, typename S_FLOOR> inline Vector3(const Vector3<S, S_FLOOR>& other):
                x(static_cast<V>(other.x)), y(static_cast<V>(other.y)), z(static_cast<V>(other.z)) {};

        //setters

        template<typename S> inline void set(S value) {
            this->x = this->y = this->z = static_cast<V>(value);
        }

        template<typename S> inline void set(S xIn, S yIn, S zIn) {
            this->x = static_cast<V>(xIn);
            this->y = static_cast<V>(yIn);
            this->z = static_cast<V>(zIn);
        }

        //operators

        template<typename S, typename S_FLOOR> inline bool operator==(const Vector3<S, S_FLOOR>& other) {
            return this->x == static_cast<V>(other.x) && this->y == static_cast<V>(other.y) && this->z == static_cast<V>(other.z);
        }

        template<typename S, typename S_FLOOR> inline bool operator!=(const Vector3<S, S_FLOOR>& other) {
            return this->x != static_cast<V>(other.x) && this->y != static_cast<V>(other.y) && this->z != static_cast<V>(other.z);
        }

        //bool operator > (const Vector3<V> & other);
        //bool operator < (const Vector3<V> & other);

        template<typename S, typename S_FLOOR> inline void operator+=(const Vector3<S, S_FLOOR>& other) {
            this->x += static_cast<V>(other.x);
            this->y += static_cast<V>(other.y);
            this->z += static_cast<V>(other.z);
        }

        template<typename S> inline void operator+=(S value) {
            this->x += static_cast<V>(value);
            this->y += static_cast<V>(value);
            this->z += static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator-=(const Vector3<S, S_FLOOR>& other) {
            this->x -= static_cast<V>(other.x);
            this->y -= static_cast<V>(other.y);
            this->z -= static_cast<V>(other.z);
        }

        template<typename S> inline void operator-=(S value) {
            this->x -= static_cast<V>(value);
            this->y -= static_cast<V>(value);
            this->z -= static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator*=(const Vector3<S, S_FLOOR>& other) {
            this->x *= static_cast<V>(other.x);
            this->y *= static_cast<V>(other.y);
            this->z *= static_cast<V>(other.z);
        }

        template<typename S> inline void operator*=(S value) {
            this->x *= static_cast<V>(value);
            this->y *= static_cast<V>(value);
            this->z *= static_cast<V>(value);
        }

        template<typename S, typename S_FLOOR> inline void operator/=(const Vector3<S, S_FLOOR>& other) {
            this->x /= static_cast<V>(other.x);
            this->y /= static_cast<V>(other.y);
            this->z /= static_cast<V>(other.z);
        }

        template<typename S> inline void operator/=(S value) {
            this->x /= static_cast<V>(value);
            this->y /= static_cast<V>(value);
            this->z /= static_cast<V>(value);
        }

        template<typename S> inline Vector3<V, _FLOOR> operator+(S value) {
            return Vector2(this->x + static_cast<V>(value), this->y + static_cast<V>(value), this->z + static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector3<V, _FLOOR> operator+(const Vector3<S, S_FLOOR>& other) {
            return Vector2(this->x + static_cast<V>(other.x), this->y + static_cast<V>(other.y), this->z + static_cast<V>(other.z));
        }

        template<typename S> inline Vector3<V, _FLOOR> operator-(S value) {
            return Vector2(this->x - static_cast<V>(value), this->y - static_cast<V>(value), this->z - static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector3<V, _FLOOR> operator-(const Vector3<S, S_FLOOR>& other) {
            return Vector2(this->x - static_cast<V>(other.x), this->y - static_cast<V>(other.y), this->z - static_cast<V>(other.z));
        }

        template<typename S> inline Vector3<V, _FLOOR> operator*(S value) {
            return Vector2(this->x * static_cast<V>(value), this->y * static_cast<V>(value), this->z * static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector3<V, _FLOOR> operator*(const Vector3<S, S_FLOOR>& other) {
            return Vector2(this->x * static_cast<V>(other.x), this->y * static_cast<V>(other.y), this->z * static_cast<V>(other.z));
        }

        template<typename S> inline Vector3<V, _FLOOR> operator/(S value) {
            return Vector2(this->x / static_cast<V>(value), this->y / static_cast<V>(value), this->z / static_cast<V>(value));
        }

        template<typename S, typename S_FLOOR> inline Vector3<V, _FLOOR> operator/(const Vector3<S, S_FLOOR>& other) {
            return Vector2(this->x / static_cast<V>(other.x), this->y / static_cast<V>(other.y), this->z / static_cast<V>(other.z));
        }

        inline Vector3<V, _FLOOR> operator-() {
            return Vector2(-this->x, -this->y, -this->z);
        };
    };
}

typedef porklib::math::vector::Vector2<i8> vec2i8;
typedef porklib::math::vector::Vector2<i16> vec2i16;
typedef porklib::math::vector::Vector2<i32> vec2i32;
typedef porklib::math::vector::Vector2<i64> vec2i64;
typedef porklib::math::vector::Vector2<inum> vec2i;
typedef porklib::math::vector::Vector2<f32, i32> vec2f32;
typedef porklib::math::vector::Vector2<f64, i64> vec2f64;
typedef porklib::math::vector::Vector2<flt, inum> vec2f;

typedef porklib::math::vector::Vector3<i8> vec3i8;
typedef porklib::math::vector::Vector3<i16> vec3i16;
typedef porklib::math::vector::Vector3<i32> vec3i32;
typedef porklib::math::vector::Vector3<i64> vec3i64;
typedef porklib::math::vector::Vector3<inum> vec3i;
typedef porklib::math::vector::Vector3<f32, i32> vec3f32;
typedef porklib::math::vector::Vector3<f64, i64> vec3f64;
typedef porklib::math::vector::Vector3<flt, inum> vec3f;

#endif //PORKLIB_CPP_VECTORS_H
