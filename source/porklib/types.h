#ifndef PORKLIB_CPP_TYPES_H
#define PORKLIB_CPP_TYPES_H

#include <cstdint>
#include <sys/param.h>
#include <byteswap.h>

#ifndef BYTE_ORDER
#error "BYTE_ORDER not defined"
#endif

#if BYTE_ORDER != BIG_ENDIAN
#define IS_LITTLE_ENDIAN
#else
#define IS_BIG_ENDIAN
#endif

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
    template<typename A, typename B = A> using BiConsumer = void (*)(A, B);
    template<typename R> using Supplier = R (*)();
    template<typename R, typename A> using Function = R (*)(A);
    template<typename R, typename A, typename B = A> using BiFunction = R (*)(A, B);

    //specifications
    template<typename A> using Predicate = Function<bool, A>;
    template<typename A, typename B = A> using BiPredicate = BiFunction<bool, A, B>;
    template<typename A> using HashCode = Function<word, A>;
    template<typename A> using Equals = BiPredicate<A>;

    namespace lambda {
        template<typename A> void noop(A a) {}
        template<typename A, typename B> void noop(A a, B b) {}

        template<typename A, A AMOUNT> A add(A value) { return value + AMOUNT; }
        template<typename A, A FACTOR> A multiply(A value) { return value * FACTOR; }
        template<typename A> A lsh1(A value) { return value << 1; }

        template<typename A> A identity(A value) { return value; }

        template<typename A> void free(A value) { delete value; }
    }

    struct u16_le   {
        u16 v;
        #ifdef IS_LITTLE_ENDIAN
        operator u16 () { return this->v; }
        u16& operator = (u16 v) { return this->v = v; }
        #else
        operator u16 () { return __bswap_16(this->v); }
        u16& operator = (u16 v) { return this->v = __bswap_16(v); }
        #endif

        u16_le() {}
        u16_le(u16 v) { *this = v; }
    };

    struct u32_le   {
        u32 v;
        #ifdef IS_LITTLE_ENDIAN
        operator u32 () { return this->v; }
        u32& operator = (u32 v) { return this->v = v; }
        #else
        operator u32 () { return __bswap_32(this->v); }
        u32& operator = (u32 v) { return this->v = __bswap_32(v); }
        #endif

        u32_le() {}
        u32_le(u32 v) { *this = v; }
    };

    struct u64_le   {
        u64 v;
        #ifdef IS_LITTLE_ENDIAN
        operator u64 () { return this->v; }
        u64& operator = (u64 v) { return this->v = v; }
        #else
        operator u64 () { return __bswap_64(this->v); }
        u64& operator = (u64 v) { return this->v = __bswap_64(v); }
        #endif

        u64_le() {}
        u64_le(u64 v) { *this = v; }
    };

    struct i16_le   {
        i16 v;
        #ifdef IS_LITTLE_ENDIAN
        operator i16 () { return this->v; }
        i16& operator = (i16 v) { return this->v = v; }
        #else
        operator i16 () { return __bswap_16(this->v); }
        i16& operator = (i16 v) { return this->v = __bswap_16(v); }
        #endif

        i16_le() {}
        i16_le(i16 v) { *this = v; }
    };

    struct i32_le   {
        i32 v;
        #ifdef IS_LITTLE_ENDIAN
        operator i32 () { return this->v; }
        i32& operator = (i32 v) { return this->v = v; }
        #else
        operator i32 () { return __bswap_32(this->v); }
        i32& operator = (i32 v) { return this->v = __bswap_32(v); }
        #endif

        i32_le() {}
        i32_le(i32 v) { *this = v; }
    };

    struct i64_le   {
        i64 v;
        #ifdef IS_LITTLE_ENDIAN
        operator i64 () { return this->v; }
        i64& operator = (i64 v) { return this->v = v; }
        #else
        operator i64 () { return __bswap_64(this->v); }
        i64& operator = (i64 v) { return this->v = __bswap_64(v); }
        #endif

        i64_le() {}
        i64_le(i64 v) { *this = v; }
    };

    struct u16_be   {
        u16 v;
        #ifdef IS_BIG_ENDIAN
        operator u16 () { return this->v; }
        u16& operator = (u16 v) { return this->v = v; }
        #else
        operator u16 () { return __bswap_16(this->v); }
        u16& operator = (u16 v) { return this->v = __bswap_16(v); }
        #endif

        u16_be() {}
        u16_be(u16 v) { *this = v; }
    };

    struct u32_be   {
        u32 v;
        #ifdef IS_BIG_ENDIAN
        operator u32 () { return this->v; }
        u32& operator = (u32 v) { return this->v = v; }
        #else
        operator u32 () { return __bswap_32(this->v); }
        u32& operator = (u32 v) { return this->v = __bswap_32(v); }
        #endif

        u32_be() {}
        u32_be(u32 v) { *this = v; }
    };

    struct u64_be   {
        u64 v;
        #ifdef IS_BIG_ENDIAN
        operator u64 () { return this->v; }
        u64& operator = (u64 v) { return this->v = v; }
        #else
        operator u64 () { return __bswap_64(this->v); }
        u64& operator = (u64 v) { return this->v = __bswap_64(v); }
        #endif

        u64_be() {}
        u64_be(u64 v) { *this = v; }
    };

    struct i16_be   {
        i16 v;
        #ifdef IS_BIG_ENDIAN
        operator i16 () { return this->v; }
        i16& operator = (i16 v) { return this->v = v; }
        #else
        operator i16 () { return __bswap_16(this->v); }
        i16& operator = (i16 v) { return this->v = __bswap_16(v); }
        #endif

        i16_be() {}
        i16_be(i16 v) { *this = v; }
    };

    struct i32_be   {
        i32 v;
        #ifdef IS_BIG_ENDIAN
        operator i32 () { return this->v; }
        i32& operator = (i32 v) { return this->v = v; }
        #else
        operator i32 () { return __bswap_32(this->v); }
        i32& operator = (i32 v) { return this->v = __bswap_32(v); }
        #endif

        i32_be() {}
        i32_be(i32 v) { *this = v; }
    };

    struct i64_be   {
        i64 v;
        #ifdef IS_BIG_ENDIAN
        operator i64 () { return this->v; }
        i64& operator = (i64 v) { return this->v = v; }
        #else
        operator i64 () { return __bswap_64(this->v); }
        i64& operator = (i64 v) { return this->v = __bswap_64(v); }
        #endif

        i64_be() {}
        i64_be(i64 v) { *this = v; }
    };
}

#endif //PORKLIB_CPP_TYPES_H
