//小文字から大文字へ変換する
//戻り値は
//c=小文字の場合は、大文字が返される。
//c=小文字以外の場合は、cが返される。

#include <ctype.h>
#include <stdio.h>

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
    
}

int main(void)
{
    int c = 'b';
    int b = '6';

    printf("%c\n", ft_toupper(c));
    printf("%c\n", toupper(c));
    printf("%c\n", ft_toupper(b));
    printf("%c\n", toupper(b));
    return (0);
}
