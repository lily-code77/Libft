//*srcの先頭からn文字分を、*dstへコピーする。
//途中にNULL文字を含んでいてもコピーを続ける。
//*dstと*srcが重なっているときの動作は未定義

//第2引数にはconstがついているので入力となる汎用ポインタ

#include <stdio.h>
#include <string.h>

/*void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    unsigned const char *s;
    size_t i;

    d = (unsigned char*)dst;
    s = (unsigned const char*)src;
    i = 0;
    //if (d == NULL && s == NULL)
    //    return (NULL);
    if (d == s || n == 0)
        return (d);
    while (i < n)
    {
        d[i] = s[i];
        i ++;
    }
    return (d);
}*/

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    i = 0;
    if (dst == src || n == 0)
        return (dst);
    while (i < n)
    {
        ((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
        i ++;
    }
    return (dst);
}
/*
int main(void)
{
    char str[50];
    const char src_str[] = "**********";
    size_t i;

    i = 3;//0;
    strcpy(str, "abcdddd");
    printf("%s\n", str);
    ft_memcpy(str,src_str,i);
    printf("ft_memcpy = %s\n", str);
    strcpy(str, "abcdddd");
    memcpy(str,src_str,i);
    printf("memcpy = %s\n", str);
    return (0);
}*/

int main(void)
{
    //memcpy(NULL, NULL, 3);
    //memcpy(NULL, "ABC", 3);//本家がセグフォ
    memcpy("ABC", NULL, 3);//本家がセグフォ
    printf("expect\n");
    //ft_memcpy(NULL, NULL, 3);
    //ft_memcpy(NULL, "ABC", 3);
    ft_memcpy("ABC", NULL, 3);
    printf("actual\n");
}