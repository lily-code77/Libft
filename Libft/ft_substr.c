//文字列sのstart文字目からlen文字分をmallocで確保したcharに入れて、それを返す。
//start >= ft_strlen(s)の場合は空の文字列を返す。
//len == 0の時も空の文字列を返す
//lenが長すぎてsの終わりを超える場合は、sの最後まで抽出した文字列を返す。

#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

char    *ft_strdup(const char *s1)
{
    char *ptr;
    size_t len;//修正箇所

    len = ft_strlen(s1);
    ptr = (char *) malloc (sizeof (*s1) * (len + 1));
    if (!ptr)
        return (NULL);
    else 
        ft_strlcpy(ptr, s1, len + 1);
        //ft_strcpy(ptr, s1);
    return (ptr);
}
//challenge→不要
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t s_len;
    size_t new_len;
    size_t i;
    size_t j;

    if (s == NULL)
        return (NULL);
    s_len = ft_strlen(s);
    if (s_len <= start || len == 0)//
        return (ft_strdup(""));
    new_len = s_len - start;//
    if (new_len > len)//lenは引数
        new_len = len;
    res = (char *)malloc(sizeof(*s) * (new_len + 1));
    if (!res)
        return (NULL);
    //printf("new_len + 1=%zu\n",new_len + 1);
    //printf("%zu\n",ft_strlcpy(res, &s[start], new_len + 1));//resに終端が入らないからNG。
    i = start;
    j = 0;
    while (s[i] && j < len)//ft_strlcpyも使える。→NULLが入らなくなるからNG。
            res[j ++] = s[i ++];
    res[j] = '\0';
    return (res);
}

/*
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t j;
    char *res;
    size_t new_len;

    if (s == NULL)
        return (NULL);
    if (ft_strlen(s) <= start || len == 0)//ft_strlenは変数に入れられる。→norm的に5つ以上の変数禁止。
    {
        return (ft_strdup(""));
    }
    new_len = (ft_strlen(s) - start);//ft_strlenは変数に入れられる。
    if (new_len > len)//lenは引数
        new_len = len;
    res = (char *)malloc(sizeof(*s) * (new_len + 1));
    if (!res)
        return (NULL);
    i = start;
    j = 0;
    while (s[i] && j < len)//ft_strlcpyも使える。→NULLが入らなくなるからNG。
            res[j ++] = s[i ++];
        res[j] = '\0';
        return (res);
}*/

int main(void)
{
    char *str;

    str = ft_substr("ABCDEFGHIJKLM", 4, 2);
    printf("%s", str);
    return (0);
}