#include <stdio.h>
#include "../ft_printf.h"

#ifdef FT
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
#else
    #define P(...) \
        ret = printf(__VA_ARGS__); \
        printf(",return=%d\n", ret)
    #define CASE(s) \
        printf("%s_%d:", s, test_case); \
        test_case++
#endif

#define INIT() int ret=0; int test_case=0;

void test_normal() {
    INIT();
    CASE("normal"); P("aaaaaa");
}

void test_c() {
    INIT();
    for (int i = 0; i <= 127; i++) {CASE("c"); P("%c", i);}
    CASE("c"); P("%c", '\0');
}

void test_s() {
    INIT();
    CASE("s"); P("%s", "ai\0ueo");
    CASE("s"); P("%s", NULL);
}

void test_p() {
    INIT();
    CASE("p"); P("%p", (void *)5);
    CASE("p"); P("%p", (void *)12);
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
}

void test_minus() {
    INIT();
    CASE("minus"); P("[%-10c]", 'a');
    CASE("minus"); P("[%-10s]", "aiueo");
    CASE("minus"); P("[%--10s]", "aiueo");
    CASE("minus"); P("[%-1s]", "aiueo");
}

void test_zero() {
    INIT();
    CASE("zero"); P("[%010c]", 'a');
    CASE("zero"); P("[%010s]", "aiueo");
    CASE("zero"); P("[%010s]", "aiueo");
    CASE("zero"); P("[%01s]", "aiueo");
    CASE("zero"); P("[%01d]", 100);
    CASE("zero"); P("[%010d]", 100);
    CASE("zero_minus"); P("[%-010c]", 'a');
    CASE("zero_minus"); P("[%-010s]", "aiueo");
    CASE("zero_minus"); P("[%--010s]", "aiueo");
    CASE("zero_minus"); P("[%-01s]", "aiueo");
    CASE("zero_minus"); P("[%-01d]", 100);
    CASE("zero_minus"); P("[%-010d]", 100);
    CASE("zero_minus"); P("[%0-1d]", 100);
    CASE("zero_minus"); P("[%0-10d]", 100);
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
}
