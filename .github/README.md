# ft_printf

## format
対応したもの。
```
%[flag][width][.pricision]specifier
```
- flag
    - '#': '0x'または'0X'を付与
        - x, X
        - num=0のとき、無効 
    - '0': 0埋め
        - c, s, p, d, i, u, x, X, % 
        - precisionが有効(precision=0も含む)、かつd,i,u,x,Xのとき、無効
    - '-': 左寄せ
        - c, s, p, d, i, u, x, X, %
        - overrides '0'
    - ' '(space): 数字(>=0)の前に' '(space)を出力
        - d, i
    - '+': 数字(>=0)の前に'+'を出力
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
