#include "porklib/math/vectors.h"

using namespace porklib::math::vector;

//
//
// Vector2
//
//

template<typename T, typename F>
inline Vector2<T, F>::Vector2(): x(0), y(0) {}

template<typename T, typename F>
inline Vector2<T, F>::Vector2(T val): x(val), y(val) {}

template<typename T, typename F>
inline Vector2<T, F>::Vector2(T x, T y): x(x), y(y) {}

template<typename T, typename F>
inline Vector2<T, F>::Vector2(const Vector2<T, F>& other): x(other.x), y(other.y) {}

template<typename T, typename F>
inline void porklib::math::vector::Vector2<T, F>::set(T xIn, T yIn) {
    this->x = xIn;
    this->y = yIn;
}

template<typename T, typename F>
inline void porklib::math::vector::Vector2<T, F>::normalize() {
    auto len = this->len();

    this->x = static_cast<T>(this->x * len);
    this->y = static_cast<T>(this->y * len);
}

template<typename T, typename F>
inline Vector2<T, F> porklib::math::vector::Vector2<T, F>::cpyNormalize() {
    auto len = this->len();

    return Vector2<T, F>(
            static_cast<T>(this->x * len),
            static_cast<T>(this->y * len)
    );
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::empty() {
    return this->x == 0 || this->y == 0;
}

template<typename T, typename F>
template<typename R>
inline R porklib::math::vector::Vector2<T, F>::len() {
    return sqrt<T, R>(this->sqlen());
}

template<typename T, typename F>
template<typename R>
inline R porklib::math::vector::Vector2<T, F>::sqlen() {
    return static_cast<R>(this->x) * static_cast<R>(this->x) + static_cast<R>(this->y) * static_cast<R>(this->y);
}

template<typename T, typename F>
template<typename A, typename R>
R porklib::math::vector::Vector2<T, F>::dot(A val) {
    return static_cast<R>(this->x) * static_cast<R>(val) + static_cast<R>(this->y) * static_cast<R>(val);
}

template<typename T, typename F>
template<typename A, typename R>
R porklib::math::vector::Vector2<T, F>::dot(const Vector2<A, F>& other) {
    return static_cast<R>(this->x) * static_cast<R>(other.x) + static_cast<R>(this->y) * static_cast<R>(other.y);
}

template<typename T, typename F>
inline void porklib::math::vector::Vector2<T, F>::abs() {
}

template<typename T, typename F>
inline Vector2<T, F> porklib::math::vector::Vector2<T, F>::cpyAbs() {
    return Vector2<T, F>();
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::equals(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline void porklib::math::vector::Vector2<T, F>::floor() {
}

template<typename T, typename F>
template<typename R>
inline Vector2<R> porklib::math::vector::Vector2<T, F>::floorI() {
    return Vector2<R>();
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator==(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator!=(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator>(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator<(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator+=(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator-=(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator*=(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline bool porklib::math::vector::Vector2<T, F>::operator/=(const Vector2<T, F>& other) {
    return false;
}

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator+(T val) { return Vector2<T, F>(this->x + val, this->y + val); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator+(const Vector2<T, F>& other) { return Vector2<T, F>(this->x + other.x, this->y + other.y); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator-(T val) { return Vector2<T, F>(this->x - val, this->y - val); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator-(const Vector2<T, F>& other) { return Vector2<T, F>(this->x - other.x, this->y - other.y); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator*(T val) { return Vector2<T, F>(this->x * val, this->y * val); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator*(const Vector2<T, F>& other) { return Vector2<T, F>(this->x * other.x, this->y * other.y); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator/(T val) { return Vector2<T, F>(this->x / val, this->y / val); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator/(const Vector2<T, F>& other) { return Vector2<T, F>(this->x / other.x, this->y / other.y); }

template<typename T, typename F>
inline Vector2<T, F> Vector2<T, F>::operator-() { return Vector2<T, F>(-this->x, -this->y); }

//
//
// Vector3
//
//

template<typename T, typename F>
inline Vector3<T, F>::Vector3(): x(0), y(0), z(0) {}

template<typename T, typename F>
inline Vector3<T, F>::Vector3(T val): x(val), y(val), z(val) {}

template<typename T, typename F>
inline Vector3<T, F>::Vector3(T x, T y, T z): x(x), y(y), z(z) {}

template<typename T, typename F>
inline Vector3<T, F>::Vector3(const Vector3<T, F>& other): x(other.x), y(other.y), z(other.z) {}

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator+(T val) { return Vector3<T, F>(this->x + val, this->y + val, this->z + val); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator+(const Vector3<T, F>& other) { return Vector3<T, F>(this->x + other.x, this->y + other.y, this->z + other.z); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator-(T val) { return Vector3<T, F>(this->x - val, this->y - val, this->z - val); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator-(const Vector3<T, F>& other) { return Vector3<T, F>(this->x - other.x, this->y - other.y, this->z - other.z); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator*(T val) { return Vector3<T, F>(this->x * val, this->y * val, this->z * val); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator*(const Vector3<T, F>& other) { return Vector3<T, F>(this->x * other.x, this->y * other.y, this->z * other.z); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator/(T val) { return Vector3<T, F>(this->x / val, this->y / val, this->z / val); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator/(const Vector3<T, F>& other) { return Vector3<T, F>(this->x / other.x, this->y / other.y, this->z / other.z); }

template<typename T, typename F>
inline Vector3<T, F> Vector3<T, F>::operator-() { return Vector3<T, F>(-this->x, -this->y, -this->z); }

template struct Vector2<i8>;
template struct Vector2<i16>;
template struct Vector2<i32>;
template struct Vector2<i64>;
template struct Vector2<f32, i32>;
template struct Vector2<f64, i64>;

template struct Vector3<i8>;
template struct Vector3<i16>;
template struct Vector3<i32>;
template struct Vector3<i64>;
template struct Vector3<f32, i32>;
template struct Vector3<f64, i64>;
