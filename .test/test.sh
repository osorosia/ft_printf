os=$(uname)

# printf
gcc test.c ../libftprintf.a
./a.out > expect.txt

# ft_printf
gcc -D FT=1 test.c ../libftprintf.a
./a.out > actual.txt

if [ $os == 'Linux' ]; then
    valgrind --log-file="./leaks.log" --leak-check=full ./a.out &> /dev/null
fi

echo ------start------
diff --text -U 0 actual.txt expect.txt

if [ $os == 'Linux' ]; then
    cat ./leaks.log | grep 'ERROR SUMMARY'
fi

if [ $os == 'Darwin' ]; then
    cat ./leaks.log | grep Process | grep leak
fi

echo -------end-------
