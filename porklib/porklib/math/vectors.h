#ifndef PORKLIB_CPP_VECTORS_H
#define PORKLIB_CPP_VECTORS_H

#include "funcs.h"

namespace porklib::math::vector {
    template<typename T, typename F = T>
    struct Vector2 {
        T x, y;

        Vector2();
        Vector2(T val);
        Vector2(T x, T y);
        Vector2(const Vector2<T, F>& other);

        void set(T xIn, T yIn);

        void normalize();
        Vector2<T, F> cpyNormalize();
        bool empty();
        template<typename R = flt> R len();
        template<typename R = flt> R sqlen();
        inline f32 lenF() { return len<f32>(); }
        inline f64 lenD() { return len<f64>(); }
        inline f32 sqlenF() { return sqlen<f32>(); }
        inline f64 sqlenD() { return sqlen<f64>(); }
        template<typename A = T, typename R = A> R dot(A val);
        template<typename A = T, typename R = A> R dot(const Vector2<A, F>& other);
        void abs();
        Vector2<T, F> cpyAbs();
        bool equals(const Vector2<T, F>& other);
        void floor();
        template<typename R = F> Vector2<R> floorI();

        bool operator == (const Vector2<T, F> & other);
        bool operator != (const Vector2<T, F> & other);
        bool operator > (const Vector2<T, F> & other);
        bool operator < (const Vector2<T, F> & other);
        bool operator += (const Vector2<T, F> & other);
        bool operator -= (const Vector2<T, F> & other);
        bool operator *= (const Vector2<T, F> & other);
        bool operator /= (const Vector2<T, F> & other);

        Vector2<T, F> operator+(T val);
        Vector2<T, F> operator+(const Vector2<T, F>& other);
        Vector2<T, F> operator-(T val);
        Vector2<T, F> operator-(const Vector2<T, F>& other);
        Vector2<T, F> operator*(T val);
        Vector2<T, F> operator*(const Vector2<T, F>& other);
        Vector2<T, F> operator/(T val);
        Vector2<T, F> operator/(const Vector2<T, F>& other);
        Vector2<T, F> operator-();
    };

    template<typename T, typename F = T>
    struct Vector3 {
        T x, y, z;

        Vector3();
        Vector3(T val);
        Vector3(T x, T y, T z);
        Vector3(const Vector3<T, F>& other);

        Vector3<T, F> operator+(T val);
        Vector3<T, F> operator+(const Vector3<T, F>& other);
        Vector3<T, F> operator-(T val);
        Vector3<T, F> operator-(const Vector3<T, F>& other);
        Vector3<T, F> operator*(T val);
        Vector3<T, F> operator*(const Vector3<T, F>& other);
        Vector3<T, F> operator/(T val);
        Vector3<T, F> operator/(const Vector3<T, F>& other);
        Vector3<T, F> operator-();
    };
}

typedef porklib::math::vector::Vector2<i8> vec2i8;
typedef porklib::math::vector::Vector2<i16> vec2i16;
typedef porklib::math::vector::Vector2<i32> vec2i32;
typedef porklib::math::vector::Vector2<i32> vec2i;
typedef porklib::math::vector::Vector2<i64> vec2i64;
typedef porklib::math::vector::Vector2<f32, i32> vec2f32;
typedef porklib::math::vector::Vector2<f32, i32> vec2f;
typedef porklib::math::vector::Vector2<f64, i64> vec2f64;
typedef porklib::math::vector::Vector2<f64, i64> vec2d;
typedef porklib::math::vector::Vector2<flt, inum> vec2;

typedef porklib::math::vector::Vector3<i8> vec3i8;
typedef porklib::math::vector::Vector3<i16> vec3i16;
typedef porklib::math::vector::Vector3<i32> vec3i32;
typedef porklib::math::vector::Vector3<i32> vec3i;
typedef porklib::math::vector::Vector3<i64> vec3i64;
typedef porklib::math::vector::Vector3<f32, i32> vec3f32;
typedef porklib::math::vector::Vector3<f32, i32> vec3f;
typedef porklib::math::vector::Vector3<f64, i64> vec3f64;
typedef porklib::math::vector::Vector3<f64, i64> vec3d;
typedef porklib::math::vector::Vector3<flt, inum> vec3;

#endif //PORKLIB_CPP_VECTORS_H
