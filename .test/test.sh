
# printf
gcc test.c ../libftprintf.a
./a.out > expect.txt

# ft_printf
gcc -D FT=1 test.c ../libftprintf.a
./a.out > actual.txt

valgrind --log-file="./valgrind.log" --leak-check=full ./a.out > /dev/null

echo ------start------
diff --text -U 0 actual.txt expect.txt
echo -------end-------
