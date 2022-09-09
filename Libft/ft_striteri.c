//引数として渡された文字列*sの各文字に関数fを適用し、そのインデックスを第1引数として渡します。
//各文字はアドレスでfに渡され、必要に応じて修正されます。

#include <stdio.h>

void ft_striteri(char *s,void (*f)(unsigned int, char *))
{
    size_t i;

    if (s == NULL || f == NULL)
        return ;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i ++;
    }
    return;
}

void f(unsigned int i, char *c)
{
    str[0] = 'z';
    return;
//    unsigned int j;

//    j = 0;
//    while (j < i)
//    {
//        str[j] = str[i];
//        j ++;
    //    i --;
//    }
//    return;
//  c[i] = *(c + 1);
//  return;
}

int main(void)
{
    char str1[] = "abcdefg";
    
    ft_striteri(str1,&f);
    printf("%s\n", str1);
    return (0);
}