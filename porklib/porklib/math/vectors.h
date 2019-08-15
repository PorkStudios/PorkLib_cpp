#ifndef PORKLIB_CPP_VECTORS_H
#define PORKLIB_CPP_VECTORS_H

#include "porklib/common/types.h"

namespace porklib::math::vector {
    template<typename T>
    struct Vector2 {
        T x, y;

        Vector2();
        Vector2(T val);
        Vector2(T x, T y);
        Vector2(const Vector2<T>& other);
        Vector2(const Vector2<T>* other);

        Vector2<T> operator+(T val);
        Vector2<T> operator+(const Vector2<T>& other);
        Vector2<T> operator+(const Vector2<T>* other);
        Vector2<T> operator-(T val);
        Vector2<T> operator-(const Vector2<T>& other);
        Vector2<T> operator-(const Vector2<T>* other);
        Vector2<T> operator*(T val);
        Vector2<T> operator*(const Vector2<T>& other);
        Vector2<T> operator*(const Vector2<T>* other);
        Vector2<T> operator/(T val);
        Vector2<T> operator/(const Vector2<T>& other);
        Vector2<T> operator/(const Vector2<T>* other);
        Vector2<T> operator-();
    };

    template<typename T>
    struct Vector3 {
        T x, y, z;

        Vector3();
        Vector3(T val);
        Vector3(T x, T y, T z);
        Vector3(const Vector3<T>& other);
        Vector3(const Vector3<T>* other);

        Vector3<T> operator+(T val);
        Vector3<T> operator+(const Vector3<T>& other);
        Vector3<T> operator+(const Vector3<T>* other);
        Vector3<T> operator-(T val);
        Vector3<T> operator-(const Vector3<T>& other);
        Vector3<T> operator-(const Vector3<T>* other);
        Vector3<T> operator*(T val);
        Vector3<T> operator*(const Vector3<T>& other);
        Vector3<T> operator*(const Vector3<T>* other);
        Vector3<T> operator/(T val);
        Vector3<T> operator/(const Vector3<T>& other);
        Vector3<T> operator/(const Vector3<T>* other);
        Vector3<T> operator-();
    };
}

typedef porklib::math::vector::Vector2<i8> vec2i8;
typedef porklib::math::vector::Vector2<i16> vec2i16;
typedef porklib::math::vector::Vector2<i32> vec2i32;
typedef porklib::math::vector::Vector2<i32> vec2i;
typedef porklib::math::vector::Vector2<i64> vec2i64;
typedef porklib::math::vector::Vector2<f32> vec2f32;
typedef porklib::math::vector::Vector2<f32> vec2f;
typedef porklib::math::vector::Vector2<f64> vec2f64;
typedef porklib::math::vector::Vector2<f64> vec2d;

typedef porklib::math::vector::Vector3<i8> vec3i8;
typedef porklib::math::vector::Vector3<i16> vec3i16;
typedef porklib::math::vector::Vector3<i32> vec3i32;
typedef porklib::math::vector::Vector3<i32> vec3i;
typedef porklib::math::vector::Vector3<i64> vec3i64;
typedef porklib::math::vector::Vector3<f32> vec3f32;
typedef porklib::math::vector::Vector3<f32> vec3f;
typedef porklib::math::vector::Vector3<f64> vec3f64;
typedef porklib::math::vector::Vector3<f64> vec3d;

#endif //PORKLIB_CPP_VECTORS_H
