#include "porklib/math/vectors.h"

using namespace porklib::math::vector;

//
//
// Vector2
//
//

template<typename T>
inline Vector2<T>::Vector2(): x(0), y(0) {}

template<typename T>
inline Vector2<T>::Vector2(T val): x(val), y(val) {}

template<typename T>
inline Vector2<T>::Vector2(T x, T y): x(x), y(y) {}

template<typename T>
inline Vector2<T>::Vector2(const Vector2<T>& other): x(other.x), y(other.y) {}

template<typename T>
inline Vector2<T>::Vector2(const Vector2<T>* other): x(other->x), y(other->y) {}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(T val) {
    return Vector2<T>(
            x + val,
            y + val
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) {
    return Vector2<T>(
            x + other.x,
            y + other.y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T>* other) {
    return Vector2<T>(
            x + other->x,
            y + other->y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(T val) {
    return Vector2<T>(
            x - val,
            y - val
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) {
    return Vector2<T>(
            x - other.x,
            y - other.y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T>* other) {
    return Vector2<T>(
            x - other->x,
            y - other->y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(T val) {
    return Vector2<T>(
            x * val,
            y * val
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) {
    return Vector2<T>(
            x * other.x,
            y * other.y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(const Vector2<T>* other) {
    return Vector2<T>(
            x * other->x,
            y * other->y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator/(T val) {
    return Vector2<T>(
            x / val,
            y / val
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator/(const Vector2<T>& other) {
    return Vector2<T>(
            x / other.x,
            y / other.y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator/(const Vector2<T>* other) {
    return Vector2<T>(
            x / other->x,
            y / other->y
    );
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-() {
    return Vector2<T>(
            -x,
            -y
    );
}

//
//
// Vector3
//
//

template<typename T>
inline Vector3<T>::Vector3(): x(0), y(0), z(0) {}

template<typename T>
inline Vector3<T>::Vector3(T val): x(val), y(val), z(val) {}

template<typename T>
inline Vector3<T>::Vector3(T x, T y, T z): x(x), y(y), z(z) {}

template<typename T>
inline Vector3<T>::Vector3(const Vector3<T>& other): x(other.x), y(other.y), z(other.z) {}

template<typename T>
inline Vector3<T>::Vector3(const Vector3<T>* other): x(other->x), y(other->y), z(other->z) {}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(T val) {
    return Vector3<T>(
            x + val,
            y + val,
            z + val
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) {
    return Vector3<T>(
            x + other.x,
            y + other.y,
            z + other.z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>* other) {
    return Vector3<T>(
            x + other->x,
            y + other->y,
            z + other->z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(T val) {
    return Vector3<T>(
            x - val,
            y - val,
            z - val
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) {
    return Vector3<T>(
            x - other.x,
            y - other.y,
            z - other.z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>* other) {
    return Vector3<T>(
            x - other->x,
            y - other->y,
            z - other->z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(T val) {
    return Vector3<T>(
            x * val,
            y * val,
            z * val
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T>& other) {
    return Vector3<T>(
            x * other.x,
            y * other.y,
            z * other.z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T>* other) {
    return Vector3<T>(
            x * other->x,
            y * other->y,
            z * other->z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(T val) {
    return Vector3<T>(
            x / val,
            y / val,
            z / val
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(const Vector3<T>& other) {
    return Vector3<T>(
            x / other.x,
            y / other.y,
            z / other.z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(const Vector3<T>* other) {
    return Vector3<T>(
            x / other->x,
            y / other->y,
            z / other->z
    );
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-() {
    return Vector3<T>(
            -x,
            -y,
            -z
    );
}

template struct Vector2<i8>;
template struct Vector2<i16>;
template struct Vector2<i32>;
template struct Vector2<i64>;
template struct Vector2<f32>;
template struct Vector2<f64>;

template struct Vector3<i8>;
template struct Vector3<i16>;
template struct Vector3<i32>;
template struct Vector3<i64>;
template struct Vector3<f32>;
template struct Vector3<f64>;
