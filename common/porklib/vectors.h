#ifndef PORKLIB_CPP_VECTORS_H
#define PORKLIB_CPP_VECTORS_H

#include "types.h"


namespace porklib {
    namespace common {
        namespace vector {
#define SELFAWARE_IDENTIFIER(NAME) template<typename T> using NAME = struct { T NAME; }
            SELFAWARE_IDENTIFIER(w);
            SELFAWARE_IDENTIFIER(x);
            SELFAWARE_IDENTIFIER(y);
            SELFAWARE_IDENTIFIER(z);
#undef SELFAWARE_IDENTIFIER

            template<word AXES, typename... FIELDS>
            struct BaseVector: FIELDS ... {
                BaseVector() = default;

                BaseVector(BaseVector<AXES, FIELDS> const&) = default;

                template<typename... T>
                constexpr BaseVector(T&& ...x) : FIELDS{static_cast<T&&>(x)}... {}
            };
        }
    }
}

#define Vector porklib::common::vector::BaseVector
#define w porklib::common::vector::w
#define x porklib::common::vector::x
#define y porklib::common::vector::y
#define z porklib::common::vector::z

typedef Vector<2, x<u8>, y<u8>, z<u8>> Vec2u8;
typedef Vector<2, x<u16>, y<u16>, z<u16>> Vec2u16;
typedef Vector<2, x<u32>, y<u32>, z<u32>> Vec2u32;
typedef Vector<2, x<u64>, y<u64>, z<u64>> Vec2u64;
typedef Vector<2, x<i8>, y<i8>, z<i8>> Vec2i8;
typedef Vector<2, x<i16>, y<i16>, z<i16>> Vec2i16;
typedef Vector<2, x<i32>, y<i32>, z<i32>> Vec2i32;
typedef Vector<2, x<i64>, y<i64>, z<i64>> Vec2i64;
typedef Vector<2, x<f32>, y<f32>, z<f32>> Vec2f32;
typedef Vector<2, x<f64>, y<f64>, z<f64>> Vec2f64;

typedef Vector<3, x<u8>, y<u8>, z<u8>> Vec3u8;
typedef Vector<3, x<u16>, y<u16>, z<u16>> Vec3u16;
typedef Vector<3, x<u32>, y<u32>, z<u32>> Vec3u32;
typedef Vector<3, x<u64>, y<u64>, z<u64>> Vec3u64;
typedef Vector<3, x<i8>, y<i8>, z<i8>> Vec3i8;
typedef Vector<3, x<i16>, y<i16>, z<i16>> Vec3i16;
typedef Vector<3, x<i32>, y<i32>, z<i32>> Vec3i32;
typedef Vector<3, x<i64>, y<i64>, z<i64>> Vec3i64;
typedef Vector<3, x<f32>, y<f32>, z<f32>> Vec3f32;
typedef Vector<3, x<f64>, y<f64>, z<f64>> Vec3f64;

#undef Vector
#undef w
#undef x
#undef y
#undef z

#endif //PORKLIB_CPP_VECTORS_H
