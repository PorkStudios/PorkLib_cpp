#ifndef PORKLIB_CPP_TYPES_H
#define PORKLIB_CPP_TYPES_H

#include <cstdint>

typedef std::size_t size_t;

//(u)int_fast32_t is 32-bit on 32-bit machines and 64-bit on 64-bit machines, i'm not expecting to deal with anything lower than that in the near/far future
typedef std::uint_fast32_t word;
typedef std::uint_fast32_t uword;
typedef std::int_fast32_t sword; //   --|=====>

typedef std::uint8_t u8;
typedef std::uint16_t u16;
typedef std::uint32_t u32;
typedef std::uint64_t u64;
typedef std::int8_t i8;
typedef std::int16_t i16;
typedef std::int32_t i32;
typedef std::int64_t i64;

/*
#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ i8;
#endif
#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ i16;
#endif
#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ i32;
#endif
#ifdef __INT64_TYPE__
typedef __INT64_TYPE__ i64;
#endif
#ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ u8;
#endif
#ifdef __UINT16_TYPE__
typedef __UINT16_TYPE__ u16;
#endif
#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ u32;
#endif
#ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ u64;
#endif

//typedef __SIZE_TYPE__ size;
typedef size_t word;
*/

typedef float f32;
typedef double f64;

#endif //PORKLIB_CPP_TYPES_H
