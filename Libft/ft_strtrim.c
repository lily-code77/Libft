//mallocで確保したメモリに文字列*s1の先頭から末尾までの間で、*setで指定された文字が削除されたコピーを返す。
//例：
//s1 = "1234AAA22331122"
//set = "1234"
//戻り値　= "AAA"
//割り当てが失敗した場合はNULLを返す。
//s1の前からと後ろから見ていき、setの中にある文字をs1から削除する。
//戻り値は切り抜いた後の文字列の先頭アドレス
//Allocates and returns a copy of 's1' with the characters specified in 'set' removed from "the beginning and the end of the string.""

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int ft_search_set(char c, char const *set)
{
    size_t i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (1);
        i ++;
    }
    return (0);
}

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
	size_t src_len;

    i = 0;
	src_len = ft_strlen(src);
    if (dstsize == 0)
        return (src_len);
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i ++;
    }
    dst[i] = '\0';
    return (src_len);//return(ft_strlen(src));と同じこと
}
//challenge→不要
/*char *ft_strtrim(char const *s1, char const *set)
{
    char *result;
    size_t start;
    size_t end;
    size_t i;

    if (s1 == NULL || set == NULL)
        return (NULL);
    start = 0;
    while (s1[start] && ft_search_set(s1[start], set))
        start ++;
    end = ft_strlen(s1);
    while (end > start && ft_search_set(s1[end - 1], set))
        end --;
    result = (char*)malloc(sizeof(*s1) * (end - start + 1));
    if (!result)
        return (NULL);
    printf("end-start+1=%lu\n", end - start + 1);
    printf("ft_strlcpy=%zu\n", ft_strlcpy(result, &s1[start], end - start + 1));
    //ft_strlcpy(result, &s1[start], end - start + 1);//resultにnullが入らないからft_strlcpy(result, &s1[start], end - start + 1)は使えない。
    printf("%s\n", result);
    i = 0;
    while (start < end)//ft_strlcpyが使用できる。→nullが入らないからNG
    {
        result[i] = s1[start];
        i ++;
        start ++;
    }
    result[i] = '\0';
    return (result);
}*/

char *ft_strtrim(char const *s1, char const *set)
{
    char *result;
    size_t i;
    size_t start;
    size_t end;

    if (s1 == NULL || set == NULL)
        return (NULL);
    start = 0;
    while (s1[start] && ft_search_set(s1[start], set))
        start ++;
    end = ft_strlen(s1);
    while (end > start && ft_search_set(s1[end - 1], set))
        end --;
    result = (char*)malloc(sizeof(*s1) * (end - start + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (start < end)//ft_strlcpyが使用できる。→nullが入らないからNG
    {
        result[i] = s1[start];
        i ++;
        start ++;
    }
    result[i] = '\0';
    return (result);
}

int main(void)
{
    char const a[] = "1234AAAA2331122";
    char const b[] = "1234";

    //ft_strtrim(a, b);
    printf("%s", ft_strtrim(a, b));
    return (0);
}