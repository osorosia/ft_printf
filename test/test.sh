

# ft_printf
gcc -D FT=1 test.c ../libftprintf.a
./a.out > actual.txt

# printf
gcc test.c ../libftprintf.a
./a.out > expect.txt

echo ------start------
diff --text actual.txt expect.txt
echo -------end-------
