//英数字かどうか判定する
//引数；判定する文字
//引数が英数字であれば0以外を返し、そうでなければ0を返す。
#include <stdio.h>
#include <ctype.h>
//#include <limits.h>

int ft_isalnum(int c)
{
    return(ft_isalpha(c) || ft_isdigit(c));
}

int main (void)
{
    int a = 'a';
    int b = '4';
    printf("%d\n", ft_isalnum(a));
    printf("%d\n", isalnum(a));
    printf("%d\n", ft_isalnum(b));
    printf("%d\n", isalnum(b));
    return(0);
}

/*
int ft_isalpha(int c)
int ft_isdigit(int c)

int ft_isalnum(int c)
{
    if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
        return (1);
    return (0);
}