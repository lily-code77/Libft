//数字かどうか判定する
//引数：判定する文字
//戻り値：引数が数字であれば0以外を返し、そうでなければ0を返す。
#include <stdio.h>
#include <ctype.h>
//#include <limits.h>

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9'); 
}

int main (void)
{
    int a = 'a';
    int b = '4';
    printf("%d\n", ft_isdigit(a));
    printf("%d\n", isdigit(a));
    printf("%d\n", ft_isdigit(b));
    printf("%d\n", isdigit(b));
    return(0);
}

/*int main(void)
{
    for (int i = 0; i < UCHAR_MAX; ++i){
        if (ft_isdigit(i)){
            printf("%c(%x)\n", i, i);
        }
    }
    return (0);
}*/