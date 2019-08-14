#ifndef PORKLIB_CPP_VECTORS_H
#define PORKLIB_CPP_VECTORS_H

#include "types.h"

namespace pork {
    namespace common {
        namespace vector {
            template<typename T>
            struct Vector2 {
                T x;
                T y;

                Vector2() = default;
                Vector2(const Vector2<T>& other);
                Vector2(const Vector2<T>* other);
                Vector2(T x, T y);

                inline Vector2<T> operator+(const Vector2<T>& other);
                inline Vector2<T> operator+(T val);
                inline Vector2<T> operator-(const Vector2<T>& other);
                inline Vector2<T> operator-(T val);
                inline Vector2<T> operator*(const Vector2<T>& other);
                inline Vector2<T> operator*(T val);
                inline Vector2<T> operator/(const Vector2<T>& other);
                inline Vector2<T> operator/(T val);
                inline Vector2<T> operator-();
            };

            template<typename T>
            struct Vector3 {
                T x;
                T y;
                T z;

                Vector3() = default;
                Vector3(const Vector3<T>& other);
                Vector3(const Vector3<T>* other);
                Vector3(T x, T y, T z);

                inline Vector3<T> operator+(const Vector3<T>& other);
                inline Vector3<T> operator+(T val);
                inline Vector3<T> operator-(const Vector3<T>& other);
                inline Vector3<T> operator-(T val);
                inline Vector3<T> operator*(const Vector3<T>& other);
                inline Vector3<T> operator*(T val);
                inline Vector3<T> operator/(const Vector3<T>& other);
                inline Vector3<T> operator/(T val);
                inline Vector3<T> operator-();
            };
        }
    }
}

typedef pork::common::vector::Vector2<u8> vec2u8;
typedef pork::common::vector::Vector2<u16> vec2u16;
typedef pork::common::vector::Vector2<u32> vec2u32;
typedef pork::common::vector::Vector2<u64> vec2u64;
typedef pork::common::vector::Vector2<i8> vec2i8;
typedef pork::common::vector::Vector2<i16> vec2i16;
typedef pork::common::vector::Vector2<i32> vec2i32;
typedef pork::common::vector::Vector2<i32> vec2i;
typedef pork::common::vector::Vector2<i64> vec2i64;
typedef pork::common::vector::Vector2<f32> vec2f32;
typedef pork::common::vector::Vector2<f32> vec2f;
typedef pork::common::vector::Vector2<f64> vec2f64;
typedef pork::common::vector::Vector2<f64> vec2d;

typedef pork::common::vector::Vector3<u8> vec3u8;
typedef pork::common::vector::Vector3<u16> vec3u16;
typedef pork::common::vector::Vector3<u32> vec3u32;
typedef pork::common::vector::Vector3<u64> vec3u64;
typedef pork::common::vector::Vector3<i8> vec3i8;
typedef pork::common::vector::Vector3<i16> vec3i16;
typedef pork::common::vector::Vector3<i32> vec3i32;
typedef pork::common::vector::Vector3<i32> vec3i;
typedef pork::common::vector::Vector3<i64> vec3i64;
typedef pork::common::vector::Vector3<f32> vec3f32;
typedef pork::common::vector::Vector3<f32> vec3f;
typedef pork::common::vector::Vector3<f64> vec3f64;
typedef pork::common::vector::Vector3<f64> vec3d;

#endif //PORKLIB_CPP_VECTORS_H
