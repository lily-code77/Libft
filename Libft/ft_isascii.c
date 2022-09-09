//真：ASCII文字　→ 0以外を返す
//偽：ASCII文字以外　→ 0が返す
#include <stdio.h>
#include <ctype.h>

int ft_isascii(int c)
{
     return (c >= 0 && c <= 127);
}

int main (void)
{
    int a = 0;
    int b = 128;
    printf("%d\n", ft_isascii(a));
    printf("%d\n", isascii(a));
    printf("%d\n", ft_isascii(b));
    printf("%d\n", isascii(b));
    return(0);
}