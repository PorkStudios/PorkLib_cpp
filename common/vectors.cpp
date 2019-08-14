#include "vectors.h"

using namespace pork::common::vector;

//
//
// Vector2
//
//

template<typename T>
Vector2<T>::Vector2(const Vector2<T>& other): x(other.x), y(other.y) {
}

template<typename T>
Vector2<T>::Vector2(const Vector2<T>* other): x(other->x), y(other->y) {
}

template<typename T>
Vector2<T>::Vector2(T x, T y): x(x), y(y) {
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) {
    return Vector2<T>(
            x + other.x,
            y + other.y
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator+(T val) {
    return Vector2<T>(
            x + val,
            y + val
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) {
    return Vector2<T>(
            x - other.x,
            y - other.y
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator-(T val) {
    return Vector2<T>(
            x - val,
            y - val
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) {
    return Vector2<T>(
            x * other.x,
            y * other.y
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator*(T val) {
    return Vector2<T>(
            x * val,
            y * val
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& other) {
    return Vector2<T>(
            x / other.x,
            y / other.y
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator/(T val) {
    return Vector2<T>(
            x / val,
            y / val
    );
}

template<typename T>
Vector2<T> Vector2<T>::operator-(void) {
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
Vector3<T>::Vector3(const Vector3<T>& other): x(other.x), y(other.y), z(other.z) {
}

template<typename T>
Vector3<T>::Vector3(const Vector3<T>* other): x(other->x), y(other->y), z(other->z) {
}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z): x(x), y(y), z(z) {
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& other) {
    return Vector3<T>(
            x + other.x,
            y + other.y,
            z + other.z
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator+(T val) {
    return Vector3<T>(
            x + val,
            y + val,
            z + val
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& other) {
    return Vector3<T>(
            x - other.x,
            y - other.y,
            z - other.z
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator-(T val) {
    return Vector3<T>(
            x - val,
            y - val,
            z - val
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& other) {
    return Vector3<T>(
            x * other.x,
            y * other.y,
            z * other.z
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator*(T val) {
    return Vector3<T>(
            x * val,
            y * val,
            z * val
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& other) {
    return Vector3<T>(
            x / other.x,
            y / other.y,
            z / other.z
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator/(T val) {
    return Vector3<T>(
            x / val,
            y / val,
            z / val
    );
}

template<typename T>
Vector3<T> Vector3<T>::operator-() {
    return Vector3<T>(
            -x,
            -y,
            -z
    );
}
