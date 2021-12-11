# ft_printf

## format
対応したもの。
```
%[flag][width][.pricision]specifier
```
- flag
    - '#'
        - x, X
        - num=0のとき、無効 
    - '0'
        - c, s, p, d, i, u, x, X, % 
        - precisionが有効(>0?)(TODO)、かつd,i,u,x,Xのとき、無効
    - '-'
        - c, s, p, d, i, u, x, X, %
        - overrides '0'
    - ' '(space)
        - d, i
    - '+'
        - d, i
        - overrides ' '(space)
- width
- precision
    - s, d, i, u, x, X
    - '.'以降が非数字 -> precision = 0
- specifier
    - c, s, p, d, i, u, x, X, %

基本的に、下記バージョンのmanに準拠。  
https://www.freebsd.org/cgi/man.cgi?query=sprintf&apropos=0&sektion=3&manpath=FreeBSD+10.3-RELEASE&format=html
