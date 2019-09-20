#ifndef PORKLIB_CPP_TYPES_H
#define PORKLIB_CPP_TYPES_H

#include <cstdint>

typedef std::size_t u_size;
constexpr u_size SIZE_NULL = (1 << sizeof(u_size) << 3) - 1;

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

typedef float f32;
typedef double f64;

#if __WORDSIZE == 64
typedef u64 unum;
typedef i64 inum;
typedef f64 flt;
#else
typedef u32 unum;
typedef i32 inum;
typedef f32 flt;
#endif

typedef bool boolean;

namespace porklib {
    template<typename A> using Consumer = void (*)(A);
    template<typename A, typename B> using BiConsumer = void (*)(A, B);
    template<typename R> using Supplier = R (*)();
    template<typename A, typename R> using Function = R (*)(A);
    template<typename A, typename B, typename R> using BiFunction = R (*)(A, B);

    namespace lambda {
        template<typename A> void noop_Consumer(A a) {}
        template<typename A, typename B> void noop_BiConsumer(A a, B b) {}
    }
}

#endif //PORKLIB_CPP_TYPES_H
