//英字かどうか判定する。
//引数：判定する文字
//戻り値：引数が英字であれば0以外を返し、そうでなければ0を返す。
#include <stdio.h>
#include <ctype.h>
//#include <limits.h>

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main (void)
{
    int a = 'a';
    int b = '4';
    printf("%d\n", ft_isalpha(a));
    printf("%d\n", isalpha(a));
    printf("%d\n", ft_isalpha(b));
    printf("%d\n", isalpha(b));
    return(0);
}

/*int main(void)
{
    for (int i = 0; i < UCHAR_MAX; ++i){
        if (ft_isalpha(i)){
            printf("%c(%x)\n", i, i);
        }
    }
    return(0);
}*/