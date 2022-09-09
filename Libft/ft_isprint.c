//印刷可能文字　→0以外を返す
//印刷可能文字以外　→0を返す

#include <stdio.h>
#include <ctype.h>

int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

int main (void)
{
    int a = 32;
    int b = 33;
    int c = 126;
    int d = 127;
    printf("%d\n", ft_isprint(a));
    printf("%d\n", isprint(a));
    printf("%d\n", ft_isprint(b));
    printf("%d\n", isprint(b));
    printf("%d\n", ft_isprint(c));
    printf("%d\n", isprint(c));
    printf("%d\n", ft_isprint(d));
    printf("%d\n", isprint(d));
    return(0);
}