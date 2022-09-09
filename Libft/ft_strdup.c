//新しい文字列に*s1を複製します。
//新しい文字列のためのメモリはmallocで確保します。
//メモリの割り当てに成功した場合→*s1を複製した新しい文字列へのポインター
//メモリの割り当てに失敗した場合→NULL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strcpy(char *dest, const char *src)
{
    size_t i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
    return (dest);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
    {
        while (src[i])
            i ++;
        return (i);
    }
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i ++;
    }
        dst[i] = '\0';
    while (src[i])
        i ++;
    return (i);
}

size_t ft_strlen(const char *a)
{
    size_t i;

    i = 0;
    while(a[i])
    {
        i ++;
    }
    return (i);
}

char    *ft_strdup(const char *s1)
{
    char *ptr;
    size_t len;

    len = ft_strlen(s1);
    ptr = (char *) malloc (sizeof (*s1) * (len + 1));
    if (!ptr)
        return (NULL);
    else 
        ft_strlcpy(ptr, s1, len + 1);
    return (ptr);
}

int main(void)
{
    char *p;
    char str[] = "abcde";
    char str2[] = "";
    //本家と自作を打ち直して検証比較する必要があるmain関数になっています。
    
    p = ft_strdup(str);
    printf("変更前のstr：%s\n", str);
    printf("変更前のp：%s\n", p);
    ft_strcpy(str, "abeee");
    printf("変更後のstr：%s\n", str);
    printf("変更後のp：%s\n", p);
    p = ft_strdup(str2);
    printf("変更前のstr2：%s\n", str2);
    printf("変更前のp：%s\n", p);
    ft_strcpy(str2, "abeee");
    printf("変更後のstr2：%s\n", str2);
    printf("変更後のp：%s\n", p);
    free (p); 
    return (0);
}