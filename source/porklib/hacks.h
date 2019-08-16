#ifndef PORKLIB_CPP_HACKS_H
#define PORKLIB_CPP_HACKS_H

#include "types.h"

#define FOR_EACH_PRIMITIVE_1D(FUNC) \
    FUNC(u8); \
    FUNC(u16); \
    FUNC(u32); \
    FUNC(u64); \
    FUNC(i8); \
    FUNC(i16); \
    FUNC(i32); \
    FUNC(i64); \
    FUNC(f32); \
    FUNC(f64);

#define FOR_EACH_PRIMITIVE_2D(FUNC) \
    FUNC(u8, u8); \
    FUNC(u8, u16); \
    FUNC(u8, u32); \
    FUNC(u8, u64); \
    FUNC(u8, i8); \
    FUNC(u8, i16); \
    FUNC(u8, i32); \
    FUNC(u8, i64); \
    FUNC(u8, f32); \
    FUNC(u8, f64); \
    FUNC(u16, u8); \
    FUNC(u16, u16); \
    FUNC(u16, u32); \
    FUNC(u16, u64); \
    FUNC(u16, i8); \
    FUNC(u16, i16); \
    FUNC(u16, i32); \
    FUNC(u16, i64); \
    FUNC(u16, f32); \
    FUNC(u16, f64); \
    FUNC(u32, u8); \
    FUNC(u32, u16); \
    FUNC(u32, u32); \
    FUNC(u32, u64); \
    FUNC(u32, i8); \
    FUNC(u32, i16); \
    FUNC(u32, i32); \
    FUNC(u32, i64); \
    FUNC(u32, f32); \
    FUNC(u32, f64); \
    FUNC(u64, u8); \
    FUNC(u64, u16); \
    FUNC(u64, u32); \
    FUNC(u64, u64); \
    FUNC(u64, i8); \
    FUNC(u64, i16); \
    FUNC(u64, i32); \
    FUNC(u64, i64); \
    FUNC(u64, f32); \
    FUNC(u64, f64); \
    FUNC(i8, u8); \
    FUNC(i8, u16); \
    FUNC(i8, u32); \
    FUNC(i8, u64); \
    FUNC(i8, i8); \
    FUNC(i8, i16); \
    FUNC(i8, i32); \
    FUNC(i8, i64); \
    FUNC(i8, f32); \
    FUNC(i8, f64); \
    FUNC(i16, u8); \
    FUNC(i16, u16); \
    FUNC(i16, u32); \
    FUNC(i16, u64); \
    FUNC(i16, i8); \
    FUNC(i16, i16); \
    FUNC(i16, i32); \
    FUNC(i16, i64); \
    FUNC(i16, f32); \
    FUNC(i16, f64); \
    FUNC(i32, u8); \
    FUNC(i32, u16); \
    FUNC(i32, u32); \
    FUNC(i32, u64); \
    FUNC(i32, i8); \
    FUNC(i32, i16); \
    FUNC(i32, i32); \
    FUNC(i32, i64); \
    FUNC(i32, f32); \
    FUNC(i32, f64); \
    FUNC(i64, u8); \
    FUNC(i64, u16); \
    FUNC(i64, u32); \
    FUNC(i64, u64); \
    FUNC(i64, i8); \
    FUNC(i64, i16); \
    FUNC(i64, i32); \
    FUNC(i64, i64); \
    FUNC(i64, f32); \
    FUNC(i64, f64); \
    FUNC(f32, u8); \
    FUNC(f32, u16); \
    FUNC(f32, u32); \
    FUNC(f32, u64); \
    FUNC(f32, i8); \
    FUNC(f32, i16); \
    FUNC(f32, i32); \
    FUNC(f32, i64); \
    FUNC(f32, f32); \
    FUNC(f32, f64); \
    FUNC(f64, u8); \
    FUNC(f64, u16); \
    FUNC(f64, u32); \
    FUNC(f64, u64); \
    FUNC(f64, i8); \
    FUNC(f64, i16); \
    FUNC(f64, i32); \
    FUNC(f64, i64); \
    FUNC(f64, f32); \
    FUNC(f64, f64);

#endif //PORKLIB_CPP_HACKS_H
