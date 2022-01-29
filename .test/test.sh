os=$(uname)

# printf
gcc test.c ../libftprintf.a
./a.out > expect.txt

# ft_printf
gcc -D FT=1 test.c ../libftprintf.a
./a.out > actual.txt

if [ $os == 'Linux' ]; then
    valgrind --log-file="./valgrind.log" --leak-check=full ./a.out > /dev/null
fi

echo ------start------
diff --text -U 0 actual.txt expect.txt

if [ $os == 'Linux' ]; then
    check=`cat ./valgrind.log | grep 'LEAK SUMMARY' | wc -l`
    if [ $check -eq 0 ]; then
        echo LEAKS: OK
    else
        echo LEAKS: KO!!!!
    fi
fi

echo -------end-------
