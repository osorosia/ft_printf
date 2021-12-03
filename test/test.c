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
    CASE("d"); P("%d", INT_MAX);
    CASE("d"); P("%d", INT_MIN);
}

int main() {
    test_normal();
    test_c();
    test_s();
    test_p();
    test_d();
}
