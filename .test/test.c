#include <stdio.h>
#include "../ft_printf.h"

#ifdef FT
    #define P_FT(...) P(__VA_ARGS__)
    #define P_LINUX(...)
    #define P(...) \
        ret = ft_printf(__VA_ARGS__); \
        ft_putstr_fd(",return=", 1); \
        ft_putnbr_fd(ret, 1); \
        ft_putchar_fd('\n', 1)
    #define CASE(s) \
        ft_putstr_fd(s, 1); \
        ft_putchar_fd('_', 1); \
        ft_putnbr_fd(test_case, 1); \
        ft_putchar_fd(':', 1); \
        test_case++
    #define SUB() test_case=0; \
        ft_putstr_fd("\n------\n\n", 1)
#else
    #ifdef __linux__
        #define P_FT(...)
        #define P_LINUX(...) \
            ret = printf_linux(__VA_ARGS__); \
            printf(",return=%d\n", ret)
    #else
        #define P_FT(...) P(__VA_ARGS__)
        #define P_LINUX(...)
    #endif
    #define P(...) \
        ret = printf(__VA_ARGS__); \
        printf(",return=%d\n", ret)
    #define CASE(s) \
        printf("%s_%d:", s, test_case); \
        test_case++
    #define SUB() test_case=0; \
        printf("\n------\n\n") 
#endif

#ifdef FT
    #define PP_FT(...) P(__VA_ARGS__)
    #define PP(...)
#else
    #define PP_FT(...)
    #define PP(...) P(__VA_ARGS__)
#endif

#ifdef __APPLE__
bool mac = true;
#else
bool mac = false;
#endif

#define INIT() int ret=0; int test_case=0; SUB()

int printf_linux(const char *format, ...)
{
    return printf(format);
}

void test_normal() {
    INIT();
    CASE("normal"); P("aaaaaa");
    CASE("normal"); P("aa\0aaa");
}

void test_c() {
    INIT();
    for (int i = 0; i <= 127; i++) {CASE("c"); P("%c", i);}
    CASE("c"); P("%c", '\0');
}

void test_s() {
    INIT();
    CASE("s"); P("%s", "aiueo");
    CASE("s"); P("%s", "ai\0ueo");
    CASE("s"); P("%s", NULL);
}

void test_p() {
    INIT();
    CASE("p"); P_FT("%p", NULL); P_LINUX("0x0");
    CASE("p"); P_FT("%p", (void *)0); P_LINUX("0x0");
    CASE("p"); P("%p", (void *)1);
    CASE("p"); P("%p", (void *)-1);
    CASE("p"); P("%p", (void *)5);
    CASE("p"); P("%p", (void *)12);
    CASE("p"); P("%p", (void *)0xabcdef0123456789);
    CASE("p"); P("%p", (void *)0x0123456789abedef);
}

void test_d() {
    INIT();
    CASE("d"); P("%d", 0);
    CASE("d"); P("%d", 14);
    CASE("d"); P("%d", -14);
    CASE("d"); P("%d", INT_MAX);
    CASE("d"); P("%d", INT_MIN);
}

void test_i() {
    INIT();
    CASE("i"); P("%i", 0);
    CASE("i"); P("%i", 14);
    CASE("i"); P("%i", -14);
    CASE("i"); P("%i", INT_MAX);
    CASE("i"); P("%i", INT_MIN);
}

void test_u() {
    INIT();
    CASE("u"); P("%u", 0);
    CASE("u"); P("%u", 14);
    CASE("u"); P("%u", -14);
    CASE("u"); P("%u", INT_MAX);
    CASE("u"); P("%u", INT_MIN);
}

void test_x() {
    INIT();
    CASE("x"); P("%x", 0);
    CASE("x"); P("%x", 14);
    CASE("x"); P("%x", -14);
    CASE("x"); P("%x", INT_MAX);
    CASE("x"); P("%x", INT_MIN);
}

void test_xx() {
    INIT();
    CASE("X"); P("%X", 0);
    CASE("X"); P("%X", 14);
    CASE("X"); P("%X", -14);
    CASE("X"); P("%X", INT_MAX);
    CASE("X"); P("%X", INT_MIN);
}

void test_per() {
    INIT();
    CASE("per"); P("%%");
    CASE("per"); P("%%%%");
    CASE("per"); P("%%%%%%");
}

void test_width() {
    INIT();
    CASE("width"); P("[%10c]", 'a');
    CASE("width"); P("[%10s]", "aiueo");
    CASE("width"); P("[%1s]", "aiueo");
    SUB();
    CASE("width_1"); P("[%1c]", 'a');
    CASE("width_1"); P("[%1s]", "aiueo");
    CASE("width_1"); P("[%1p]", (void *)1);
    CASE("width_1"); P("[%1d]", -14);
    CASE("width_1"); P("[%1i]", -14);
    CASE("width_1"); P("[%1u]", 14);
    CASE("width_1"); P("[%1x]", 14);
    CASE("width_1"); P("[%1X]", 14);
    CASE("width_1"); P("[%1%]");
    SUB();
    CASE("width_10"); P("[%10c]", 'a');
    CASE("width_10"); P("[%10s]", "aiueo");
    CASE("width_10"); P("[%10p]", (void *)1);
    CASE("width_10"); P("[%10d]", -14);
    CASE("width_10"); P("[%10i]", -14);
    CASE("width_10"); P("[%10u]", 14);
    CASE("width_10"); P("[%10x]", 14);
    CASE("width_10"); P("[%10X]", 14);
    CASE("width_10"); P_FT("[%10%]"); P_LINUX("[         %%]");
}

void test_minus() {
    INIT();
    CASE("minus"); P("[%-10c]", 'a');
    CASE("minus"); P("[%-10s]", "aiueo");
    CASE("minus"); P("[%--10s]", "aiueo");
    CASE("minus"); P("[%-1s]", "aiueo");
    CASE("minus"); P("[%-2p]", 1);
    CASE("minus"); P("[%-d]", 0);
    CASE("minus"); P("[%-d]", INT_MAX);
    CASE("minus"); P("[%-d]", INT_MIN);
    CASE("minus"); P("[%-i]", 0);
    CASE("minus"); P("[%-i]", INT_MAX);
    CASE("minus"); P("[%-i]", INT_MIN);
    SUB();
    CASE("minus_all"); P("[%-c]", 'a');
    CASE("minus_all"); P("[%-s]", "aiueo");
    CASE("minus_all"); P("[%-p]", (void *)1);
    CASE("minus_all"); P("[%-d]", -14);
    CASE("minus_all"); P("[%-i]", -14);
    CASE("minus_all"); P("[%-u]", 14);
    CASE("minus_all"); P("[%-x]", 14);
    CASE("minus_all"); P("[%-X]", 14);
    CASE("minus_all"); P("[%-%]");
    SUB();
    CASE("minus_1"); P("[%-1c]", 'a');
    CASE("minus_1"); P("[%-1s]", "aiueo");
    CASE("minus_1"); P("[%-1p]", (void *)1);
    CASE("minus_1"); P("[%-1d]", -14);
    CASE("minus_1"); P("[%-1i]", -14);
    CASE("minus_1"); P("[%-1u]", 14);
    CASE("minus_1"); P("[%-1x]", 14);
    CASE("minus_1"); P("[%-1X]", 14);
    CASE("minus_1"); P("[%-1%]");
    SUB();
    CASE("minus_10"); P("[%-10c]", 'a');
    CASE("minus_10"); P("[%-10s]", "aiueo");
    CASE("minus_10"); P("[%-10p]", (void *)1);
    CASE("minus_10"); P("[%-10d]", -14);
    CASE("minus_10"); P("[%-10i]", -14);
    CASE("minus_10"); P("[%-10u]", 14);
    CASE("minus_10"); P("[%-10x]", 14);
    CASE("minus_10"); P("[%-10X]", 14);
    CASE("minus_10"); P_FT("[%-10%]"); P_LINUX("[%%         ]");
}

void test_zero() {
    INIT();
    CASE("zero"); P("[%01s]", "aiueo");
    CASE("zero"); P("[%01d]", 100);
    CASE("zero"); P("[%010d]", 100);
    CASE("zero"); P("[%04d]", -14);
    CASE("zero"); P("[%04d]", 0);
    CASE("zero"); P("[%04d]", INT_MAX);
    CASE("zero"); P("[%04d]", INT_MIN);
    CASE("zero"); P("[%04d]", (long)INT_MAX + 1);
    CASE("zero"); P("[%04p]", 14);
    CASE("zero"); P("[%010p]", 14);
    SUB();
    CASE("zero_all"); P_FT("[%010c]", 'a'); P_LINUX("[000000000a]");
    CASE("zero_all"); P_FT("[%010s]", "aiueo"); P_LINUX("[00000aiueo]");
    CASE("zero_all"); P("[%010p]", (void *)1);
    CASE("zero_all"); P("[%010d]", -14);
    CASE("zero_all"); P("[%010i]", -14);
    CASE("zero_all"); P("[%010u]", 14);
    CASE("zero_all"); P("[%010x]", 14);
    CASE("zero_all"); P("[%010X]", 14);
    CASE("zero_all"); P_FT("[%010%]"); P_LINUX("[000000000%%]");
    SUB();
    CASE("zero_minus"); P("[%--010s]", "aiueo");
    CASE("zero_minus"); P("[%-01s]", "aiueo");
    CASE("zero_minus"); P("[%-01d]", 100);
    CASE("zero_minus"); P("[%-010d]", 100);
    CASE("zero_minus"); P("[%0-1d]", 100);
    CASE("zero_minus"); P("[%0-10d]", 100);
    CASE("zero_minus"); P("[%0--10d]", 100);
    SUB();
    CASE("zero_-01"); P("[%-01c]", 'a');
    CASE("zero_-01"); P("[%-01s]", "aiueo");
    CASE("zero_-01"); P("[%-01p]", (void *)1);
    CASE("zero_-01"); P("[%-01d]", -14);
    CASE("zero_-01"); P("[%-01i]", -14);
    CASE("zero_-01"); P("[%-01u]", 14);
    CASE("zero_-01"); P("[%-01x]", 14);
    CASE("zero_-01"); P("[%-01X]", 14);
    CASE("zero_-01"); P("[%-01%]");
    SUB();
    CASE("zero_-010"); P("[%-010c]", 'a');
    CASE("zero_-010"); P("[%-010s]", "aiueo");
    CASE("zero_-010"); P("[%-010p]", (void *)1);
    CASE("zero_-010"); P("[%-010d]", -14);
    CASE("zero_-010"); P("[%-010i]", -14);
    CASE("zero_-010"); P("[%-010u]", 14);
    CASE("zero_-010"); P("[%-010x]", 14);
    CASE("zero_-010"); P("[%-010X]", 14);
    CASE("zero_-010"); P_FT("[%-010%]"); P_LINUX("[%%         ]");
    SUB();
    CASE("zero_0-10"); P("[%0-10c]", 'a');
    CASE("zero_0-10"); P("[%0-10s]", "aiueo");
    CASE("zero_0-10"); P("[%0-10p]", (void *)1);
    CASE("zero_0-10"); P("[%0-10d]", -14);
    CASE("zero_0-10"); P("[%0-10i]", -14);
    CASE("zero_0-10"); P("[%0-10u]", 14);
    CASE("zero_0-10"); P("[%0-10x]", 14);
    CASE("zero_0-10"); P("[%0-10X]", 14);
    CASE("zero_0-10"); P_FT("[%0-10%]"); P_LINUX("[%%         ]");
    SUB();
    CASE("zero_010"); P_FT("[%010c]", 'a'); P_LINUX("[000000000a]");
    CASE("zero_010"); P_FT("[%010s]", "aiueo"); P_LINUX("[00000aiueo]");
    CASE("zero_010"); P("[%010p]", (void *)1);
    CASE("zero_010"); P("[%010d]", -14);
    CASE("zero_010"); P("[%010i]", -14);
    CASE("zero_010"); P("[%010u]", 14);
    CASE("zero_010"); P("[%010x]", 14);
    CASE("zero_010"); P("[%010X]", 14);
    CASE("zero_010"); P_FT("[%010%]"); P_LINUX("[000000000%%]");
}

void test_dot() {
    INIT();
    // d
    CASE("dot_d"); P("[%10.6d]", 100);
    CASE("dot_d"); P("[%10.6d]", -100);
    CASE("dot_d"); P("[%10.1d]", 100);
    CASE("dot_d"); P("[%10.1d]", -100);
    CASE("dot_d"); P("[%10.d]", 100);

    CASE("dot_d"); P("[%10.d]", -100);
    CASE("dot_d"); P("[%1.d]", 100);
    CASE("dot_d"); P("[%1.d]", -100);
    CASE("dot_d"); P("[%.6d]", 100);
    CASE("dot_d"); P("[%.6d]", -100);

    CASE("dot_d"); P("[%.1d]", 100);
    CASE("dot_d"); P("[%.1d]", -100);
    // p
    SUB();
    CASE("dot_p"); P("[%10.1p]", 100);
    CASE("dot_p"); P("[%10.6p]", 100);
    // s
    SUB();
    CASE("dot_s"); P("[%10.6s]", "aiueo");
    CASE("dot_s"); P("[%10.1s]", "aiueo");
    CASE("dot_s"); P("[%.1s]", "aiueo");
    CASE("dot_s"); P("[%.6s]", "aiueo");
    CASE("dot_s"); P("[%.s]", "aiueo");
    CASE("dot_s"); P("[%10.s]", "aiueo");
    // u
    SUB();
    CASE("dot_u"); P("[%.6u]", 100);
    // x
    SUB();
    CASE("dot_x"); P("[%.6x]", 100);
    // X
    SUB();
    CASE("dot_X"); P("[%.6X]", 100);
}

void test_sharp() {
    INIT();
    SUB();
    CASE("sharp_c"); P("[%#c]", 'a');
    SUB();
    CASE("sharp_s"); P("[%#s]", NULL);
    CASE("sharp_s"); P("[%#s]", "");
    CASE("sharp_s"); P("[%#s]", "aiueo");
    SUB();
    CASE("sharp_p"); P_FT("[%#p]", 0); P_LINUX("[0x0]");
    CASE("sharp_p"); P("[%#p]", 100);
    SUB();
    CASE("sharp_d"); P("[%#d]", 0);
    CASE("sharp_d"); P("[%#d]", 100);
    SUB();
    CASE("sharp_i"); P("[%#i]", 0);
    CASE("sharp_i"); P("[%#i]", 100);
    SUB();
    CASE("sharp_u"); P("[%#u]", 0);
    CASE("sharp_u"); P("[%#u]", 100);
    SUB();
    CASE("sharp_x"); P("[%#x]", 0);
    CASE("sharp_x"); P("[%#x]", 100);
    SUB();
    CASE("sharp_X"); P("[%#X]", 0);
    CASE("sharp_X"); P("[%#X]", 100);
    SUB();
    CASE("sharp_per"); P("[%#%]");
}

void test_space() {
    INIT();
    SUB();
    CASE("space_c"); P("[% c]", 'a');
    SUB();
    CASE("space_s"); P("[% s]", "aiueo");
    SUB();
    CASE("space_p"); P_FT("[% p]", 0); P_LINUX("[0x0]");
    CASE("space_p"); P_FT("[% p]", 100); P_LINUX("[0x64]");
    SUB();
    CASE("space_d"); P("[% d]", 0);
    CASE("space_d"); P("[% d]", 100);
    CASE("space_d"); P("[% d]", -100);
    SUB();
    CASE("space_i"); P("[% i]", 0);
    CASE("space_i"); P("[% i]", 100);
    CASE("space_i"); P("[% i]", -100);
    SUB();
    CASE("space_u"); P("[% u]", 0);
    CASE("space_u"); P("[% u]", 100);
    SUB();
    CASE("space_x"); P("[% x]", 0);
    CASE("space_x"); P("[% x]", 100);
    SUB();
    CASE("space_X"); P("[% X]", 0);
    CASE("space_X"); P("[% X]", 100);
    SUB();
    CASE("space_per"); P("[% %]");
}

void test_plus() {
    INIT();
    SUB();
    CASE("plus_c"); P("[%+c]", 'a');
    SUB();
    CASE("plus_s"); P("[%+s]", "aiueo");
    SUB();
    CASE("plus_p"); P_FT("[%+p]", 0); P_LINUX("[0x0]");
    CASE("plus_p"); P_FT("[%+p]", 100); P_LINUX("[0x64]");
    SUB();
    CASE("plus_d"); P("[%+d]", 0);
    CASE("plus_d"); P("[%+d]", 100);
    CASE("plus_d"); P("[%+d]", -100);
    SUB();
    CASE("plus_i"); P("[%+i]", 0);
    CASE("plus_i"); P("[%+i]", 100);
    CASE("plus_i"); P("[%+i]", -100);
    SUB();
    CASE("plus_u"); P("[%+u]", 0);
    CASE("plus_u"); P("[%+u]", 100);
    SUB();
    CASE("plus_x"); P("[%+x]", 0);
    CASE("plus_x"); P("[%+x]", 100);
    SUB();
    CASE("plus_X"); P("[%+X]", 0);
    CASE("plus_X"); P("[%+X]", 100);
    SUB();
    CASE("plus_per"); P("[%+%]");
}

void test_plus_space() {
    INIT();
    SUB();
    CASE("+space_c"); P("[%+ c]", 'a');
    SUB();
    CASE("+space_s"); P("[%+ s]", "aiueo");
    SUB();
    CASE("+space_p"); P_FT("[%+ p]", 0); P_LINUX("[0x0]");
    CASE("+space_p"); P_FT("[%+ p]", 100); P_LINUX("[0x64]");
    SUB();
    CASE("+space_d"); P("[%+ d]", 0);
    CASE("+space_d"); P("[%+ d]", 100);
    CASE("+space_d"); P("[%+ d]", -100);
    SUB();
    CASE("+space_i"); P("[%+ i]", 0);
    CASE("+space_i"); P("[%+ i]", 100);
    CASE("+space_i"); P("[%+ i]", -100);
    SUB();
    CASE("+space_u"); P("[%+ u]", 0);
    CASE("+space_u"); P("[%+ u]", 100);
    SUB();
    CASE("+space_x"); P("[%+ x]", 0);
    CASE("+space_x"); P("[%+ x]", 100);
    SUB();
    CASE("+space_X"); P("[%+ X]", 0);
    CASE("+space_X"); P("[%+ X]", 100);
    SUB();
    CASE("+space_per"); P("[%+ %]");
    
    SUB();
    CASE("space+_c"); P("[% +c]", 'a');
    SUB();
    CASE("space+_s"); P("[% +s]", "aiueo");
    SUB();
    CASE("space+_p"); P_FT("[% +p]", 0); P_LINUX("[0x0]");
    CASE("space+_p"); P_FT("[% +p]", 100); P_LINUX("[0x64]");
    SUB();
    CASE("space+_d"); P("[% +d]", 0);
    CASE("space+_d"); P("[% +d]", 100);
    CASE("space+_d"); P("[% +d]", -100);
    SUB();
    CASE("space+_i"); P("[% +i]", 0);
    CASE("space+_i"); P("[% +i]", 100);
    CASE("space+_i"); P("[% +i]", -100);
    SUB();
    CASE("space+_u"); P("[% +u]", 0);
    CASE("space+_u"); P("[% +u]", 100);
    SUB();
    CASE("space+_x"); P("[% +x]", 0);
    CASE("space+_x"); P("[% +x]", 100);
    SUB();
    CASE("space+_X"); P("[% +X]", 0);
    CASE("space+_X"); P("[% +X]", 100);
    SUB();
    CASE("space+_per"); P("[% +%]");
}

void test_special() {
    INIT();

    SUB();
    CASE("sp_[#]"); P("[%#x]", 0);
    CASE("sp_[#]"); P("[%#X]", 0);
    SUB();
    CASE("sp_[10.c]");      P("[%10.c]", 'a'); SUB();
    CASE("sp_[10.s]");   P_FT("[%10.s]", NULL); P_LINUX("[          ]");
    CASE("sp_[10.s]");   P_FT("[%10.s]", "aiueo"); P_LINUX("[          ]"); SUB();
    CASE("sp_[10.p]");   P_FT("[%10.p]", 0); P_LINUX("[        0x]");
    CASE("sp_[10.p]");      P("[%10.p]", -1);
    CASE("sp_[10.p]");      P("[%10.p]", 1);
    CASE("sp_[10.p]");      P("[%10.p]", INT_MAX);
    CASE("sp_[10.p]");      P("[%10.p]", INT_MIN);
    CASE("sp_[10.p]");      P("[%10.p]", INT_MAX + 1LL);
    CASE("sp_[10.p]");      P("[%10.p]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.d]");      P("[%10.d]", 0);
    CASE("sp_[10.d]");      P("[%10.d]", -1);
    CASE("sp_[10.d]");      P("[%10.d]", 1);
    CASE("sp_[10.d]");      P("[%10.d]", INT_MAX + 1LL);
    CASE("sp_[10.d]");      P("[%10.d]", INT_MIN - 1LL);
    CASE("sp_[10.d]");      P("[%10.d]", INT_MAX + 1LL);
    CASE("sp_[10.d]");      P("[%10.d]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.i]");      P("[%10.i]", 0);
    CASE("sp_[10.i]");      P("[%10.i]", -1);
    CASE("sp_[10.i]");      P("[%10.i]", 1);
    CASE("sp_[10.i]");      P("[%10.i]", INT_MAX + 1LL);
    CASE("sp_[10.i]");      P("[%10.i]", INT_MIN - 1LL);
    CASE("sp_[10.i]");      P("[%10.i]", INT_MAX + 1LL);
    CASE("sp_[10.i]");      P("[%10.i]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.u]");      P("[%10.u]", 0);
    CASE("sp_[10.u]");      P("[%10.u]", -1);
    CASE("sp_[10.u]");      P("[%10.u]", 1);
    CASE("sp_[10.u]");      P("[%10.u]", INT_MAX + 1LL);
    CASE("sp_[10.u]");      P("[%10.u]", INT_MIN - 1LL);
    CASE("sp_[10.u]");      P("[%10.u]", INT_MAX + 1LL);
    CASE("sp_[10.u]");      P("[%10.u]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.x]");      P("[%10.x]", 0);
    CASE("sp_[10.x]");      P("[%10.x]", -1);
    CASE("sp_[10.x]");      P("[%10.x]", 1);
    CASE("sp_[10.x]");      P("[%10.x]", INT_MAX + 1LL);
    CASE("sp_[10.x]");      P("[%10.x]", INT_MIN - 1LL);
    CASE("sp_[10.x]");      P("[%10.x]", INT_MAX + 1LL);
    CASE("sp_[10.x]");      P("[%10.x]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.X]");      P("[%10.X]", 0);
    CASE("sp_[10.X]");      P("[%10.X]", -1);
    CASE("sp_[10.X]");      P("[%10.X]", 1);
    CASE("sp_[10.X]");      P("[%10.X]", INT_MAX + 1LL);
    CASE("sp_[10.X]");      P("[%10.X]", INT_MIN - 1LL);
    CASE("sp_[10.X]");      P("[%10.X]", INT_MAX + 1LL);
    CASE("sp_[10.X]");      P("[%10.X]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.per]"); P_FT("[%10.%]"); P_LINUX("[         %%]");
    SUB();
    CASE("sp_[10.0c]");      P("[%10.0c]", 'a'); SUB();
    CASE("sp_[10.0s]");   P_FT("[%10.0s]", NULL); P_LINUX("[          ]");
    CASE("sp_[10.0s]");   P_FT("[%10.0s]", "aiueo"); P_LINUX("[          ]"); SUB();
    CASE("sp_[10.0p]");   P_FT("[%10.0p]", 0); P_LINUX("[        0x]");
    CASE("sp_[10.0p]");      P("[%10.0p]", -1);
    CASE("sp_[10.0p]");      P("[%10.0p]", 1);
    CASE("sp_[10.0p]");      P("[%10.0p]", INT_MAX);
    CASE("sp_[10.0p]");      P("[%10.0p]", INT_MIN);
    CASE("sp_[10.0p]");      P("[%10.0p]", INT_MAX + 1LL);
    CASE("sp_[10.0p]");      P("[%10.0p]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0d]");      P("[%10.0d]", 0);
    CASE("sp_[10.0d]");      P("[%10.0d]", -1);
    CASE("sp_[10.0d]");      P("[%10.0d]", 1);
    CASE("sp_[10.0d]");      P("[%10.0d]", INT_MAX + 1LL);
    CASE("sp_[10.0d]");      P("[%10.0d]", INT_MIN - 1LL);
    CASE("sp_[10.0d]");      P("[%10.0d]", INT_MAX + 1LL);
    CASE("sp_[10.0d]");      P("[%10.0d]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0i]");      P("[%10.0i]", 0);
    CASE("sp_[10.0i]");      P("[%10.0i]", -1);
    CASE("sp_[10.0i]");      P("[%10.0i]", 1);
    CASE("sp_[10.0i]");      P("[%10.0i]", INT_MAX + 1LL);
    CASE("sp_[10.0i]");      P("[%10.0i]", INT_MIN - 1LL);
    CASE("sp_[10.0i]");      P("[%10.0i]", INT_MAX + 1LL);
    CASE("sp_[10.0i]");      P("[%10.0i]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0u]");      P("[%10.0u]", 0);
    CASE("sp_[10.0u]");      P("[%10.0u]", -1);
    CASE("sp_[10.0u]");      P("[%10.0u]", 1);
    CASE("sp_[10.0u]");      P("[%10.0u]", INT_MAX + 1LL);
    CASE("sp_[10.0u]");      P("[%10.0u]", INT_MIN - 1LL);
    CASE("sp_[10.0u]");      P("[%10.0u]", INT_MAX + 1LL);
    CASE("sp_[10.0u]");      P("[%10.0u]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0x]");      P("[%10.0x]", 0);
    CASE("sp_[10.0x]");      P("[%10.0x]", -1);
    CASE("sp_[10.0x]");      P("[%10.0x]", 1);
    CASE("sp_[10.0x]");      P("[%10.0x]", INT_MAX + 1LL);
    CASE("sp_[10.0x]");      P("[%10.0x]", INT_MIN - 1LL);
    CASE("sp_[10.0x]");      P("[%10.0x]", INT_MAX + 1LL);
    CASE("sp_[10.0x]");      P("[%10.0x]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0X]");      P("[%10.0X]", 0);
    CASE("sp_[10.0X]");      P("[%10.0X]", -1);
    CASE("sp_[10.0X]");      P("[%10.0X]", 1);
    CASE("sp_[10.0X]");      P("[%10.0X]", INT_MAX + 1LL);
    CASE("sp_[10.0X]");      P("[%10.0X]", INT_MIN - 1LL);
    CASE("sp_[10.0X]");      P("[%10.0X]", INT_MAX + 1LL);
    CASE("sp_[10.0X]");      P("[%10.0X]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.0per]"); P_FT("[%10.0%]"); P_LINUX("[         %%]");
    SUB();
    CASE("sp_[10.6c]");      P("[%10.6c]", 'a'); SUB();
    CASE("sp_[10.6s]");      P("[%10.6s]", NULL);
    CASE("sp_[10.6s]");      P("[%10.6s]", "aiueo"); SUB();
    CASE("sp_[10.6p]");   P_FT("[%10.6p]", 0); P_LINUX("[  0x000000]");
    CASE("sp_[10.6p]");      P("[%10.6p]", -1);
    CASE("sp_[10.6p]");      P("[%10.6p]", 1);
    CASE("sp_[10.6p]");      P("[%10.6p]", INT_MAX);
    CASE("sp_[10.6p]");      P("[%10.6p]", INT_MIN);
    CASE("sp_[10.6p]");      P("[%10.6p]", INT_MAX + 1LL);
    CASE("sp_[10.6p]");      P("[%10.6p]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6d]");      P("[%10.6d]", 0);
    CASE("sp_[10.6d]");      P("[%10.6d]", -1);
    CASE("sp_[10.6d]");      P("[%10.6d]", 1);
    CASE("sp_[10.6d]");      P("[%10.6d]", INT_MAX + 1LL);
    CASE("sp_[10.6d]");      P("[%10.6d]", INT_MIN - 1LL);
    CASE("sp_[10.6d]");      P("[%10.6d]", INT_MAX + 1LL);
    CASE("sp_[10.6d]");      P("[%10.6d]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6i]");      P("[%10.6i]", 0);
    CASE("sp_[10.6i]");      P("[%10.6i]", -1);
    CASE("sp_[10.6i]");      P("[%10.6i]", 1);
    CASE("sp_[10.6i]");      P("[%10.6i]", INT_MAX + 1LL);
    CASE("sp_[10.6i]");      P("[%10.6i]", INT_MIN - 1LL);
    CASE("sp_[10.6i]");      P("[%10.6i]", INT_MAX + 1LL);
    CASE("sp_[10.6i]");      P("[%10.6i]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6u]");      P("[%10.6u]", 0);
    CASE("sp_[10.6u]");      P("[%10.6u]", -1);
    CASE("sp_[10.6u]");      P("[%10.6u]", 1);
    CASE("sp_[10.6u]");      P("[%10.6u]", INT_MAX + 1LL);
    CASE("sp_[10.6u]");      P("[%10.6u]", INT_MIN - 1LL);
    CASE("sp_[10.6u]");      P("[%10.6u]", INT_MAX + 1LL);
    CASE("sp_[10.6u]");      P("[%10.6u]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6x]");      P("[%10.6x]", 0);
    CASE("sp_[10.6x]");      P("[%10.6x]", -1);
    CASE("sp_[10.6x]");      P("[%10.6x]", 1);
    CASE("sp_[10.6x]");      P("[%10.6x]", INT_MAX + 1LL);
    CASE("sp_[10.6x]");      P("[%10.6x]", INT_MIN - 1LL);
    CASE("sp_[10.6x]");      P("[%10.6x]", INT_MAX + 1LL);
    CASE("sp_[10.6x]");      P("[%10.6x]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6X]");      P("[%10.6X]", 0);
    CASE("sp_[10.6X]");      P("[%10.6X]", -1);
    CASE("sp_[10.6X]");      P("[%10.6X]", 1);
    CASE("sp_[10.6X]");      P("[%10.6X]", INT_MAX + 1LL);
    CASE("sp_[10.6X]");      P("[%10.6X]", INT_MIN - 1LL);
    CASE("sp_[10.6X]");      P("[%10.6X]", INT_MAX + 1LL);
    CASE("sp_[10.6X]");      P("[%10.6X]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.6per]"); P_FT("[%10.6%]"); P_LINUX("[         %%]");
    SUB();
    CASE("sp_[10.4c]");      P("[%10.4c]", 'a'); SUB();
    CASE("sp_[10.4s]");   P_FT("[%10.4s]", NULL); P_LINUX("[      (nul]");
    CASE("sp_[10.4s]");      P("[%10.4s]", "aiueo"); SUB();
    CASE("sp_[10.4p]");   P_FT("[%10.4p]", 0); P_LINUX("[    0x0000]");
    CASE("sp_[10.4p]");      P("[%10.4p]", -1);
    CASE("sp_[10.4p]");      P("[%10.4p]", 1);
    CASE("sp_[10.4p]");      P("[%10.4p]", INT_MAX);
    CASE("sp_[10.4p]");      P("[%10.4p]", INT_MIN);
    CASE("sp_[10.4p]");      P("[%10.4p]", INT_MAX + 1LL);
    CASE("sp_[10.4p]");      P("[%10.4p]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4d]");      P("[%10.4d]", 0);
    CASE("sp_[10.4d]");      P("[%10.4d]", -1);
    CASE("sp_[10.4d]");      P("[%10.4d]", 1);
    CASE("sp_[10.4d]");      P("[%10.4d]", INT_MAX + 1LL);
    CASE("sp_[10.4d]");      P("[%10.4d]", INT_MIN - 1LL);
    CASE("sp_[10.4d]");      P("[%10.4d]", INT_MAX + 1LL);
    CASE("sp_[10.4d]");      P("[%10.4d]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4i]");      P("[%10.4i]", 0);
    CASE("sp_[10.4i]");      P("[%10.4i]", -1);
    CASE("sp_[10.4i]");      P("[%10.4i]", 1);
    CASE("sp_[10.4i]");      P("[%10.4i]", INT_MAX + 1LL);
    CASE("sp_[10.4i]");      P("[%10.4i]", INT_MIN - 1LL);
    CASE("sp_[10.4i]");      P("[%10.4i]", INT_MAX + 1LL);
    CASE("sp_[10.4i]");      P("[%10.4i]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4u]");      P("[%10.4u]", 0);
    CASE("sp_[10.4u]");      P("[%10.4u]", -1);
    CASE("sp_[10.4u]");      P("[%10.4u]", 1);
    CASE("sp_[10.4u]");      P("[%10.4u]", INT_MAX + 1LL);
    CASE("sp_[10.4u]");      P("[%10.4u]", INT_MIN - 1LL);
    CASE("sp_[10.4u]");      P("[%10.4u]", INT_MAX + 1LL);
    CASE("sp_[10.4u]");      P("[%10.4u]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4x]");      P("[%10.4x]", 0);
    CASE("sp_[10.4x]");      P("[%10.4x]", -1);
    CASE("sp_[10.4x]");      P("[%10.4x]", 1);
    CASE("sp_[10.4x]");      P("[%10.4x]", INT_MAX + 1LL);
    CASE("sp_[10.4x]");      P("[%10.4x]", INT_MIN - 1LL);
    CASE("sp_[10.4x]");      P("[%10.4x]", INT_MAX + 1LL);
    CASE("sp_[10.4x]");      P("[%10.4x]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4X]");      P("[%10.4X]", 0);
    CASE("sp_[10.4X]");      P("[%10.4X]", -1);
    CASE("sp_[10.4X]");      P("[%10.4X]", 1);
    CASE("sp_[10.4X]");      P("[%10.4X]", INT_MAX + 1LL);
    CASE("sp_[10.4X]");      P("[%10.4X]", INT_MIN - 1LL);
    CASE("sp_[10.4X]");      P("[%10.4X]", INT_MAX + 1LL);
    CASE("sp_[10.4X]");      P("[%10.4X]", INT_MIN - 1LL); SUB();
    CASE("sp_[10.4per]"); P_FT("[%10.4%]"); P_LINUX("[         %%]");
}

void test_leaks() {
    INIT();
    CASE("leaks_no_spec"); PP_FT("[%5a]", 0); PP("[%%5a]");
    CASE("leaks_no_spec"); PP_FT("[% -+]", 0); PP("[%% -+]");
    SUB();
    CASE("leaks_[per]"); PP_FT("%"); PP("%%");
    CASE("leaks_[per]"); PP_FT("%%%%%%%"); PP("%%%%%%%%");
}

int main() {
    test_normal();
    test_c();
    test_s();
    test_p();
    test_d();
    test_i();
    test_u();
    test_x();
    test_xx();
    test_per();
    // bonus
    test_width();
    test_minus();
    test_zero();
    test_dot();
    test_sharp();
    test_space();
    test_plus();
    test_plus_space();
    // other
    test_special();
    // leaks
    test_leaks();
}

#ifdef FT
#ifdef __APPLE__
void end(void)__attribute__((destructor));
void end(void)
{
    system("leaks a.out &> leaks.log");
}
#endif
#endif
