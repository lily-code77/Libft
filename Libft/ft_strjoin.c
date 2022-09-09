//*s1と*s2を連結した新しい文字列を返します。
//但し、割り当てに失敗した場合はNULLを返します。
//s1の末尾にs2を連結する。
//戻り値はs1(連結後の値)

#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

/*char    *ft_strcat(const char *dest, const char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (dest[i] != '\0')
    {
        i ++;
    }
    while (src[j] != '\0')
    {
        dest[i + j] = src[j];
        j ++;
    }
    dest[i + j] = '\0';
    return (dest);
}*/

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    size_t i;
    size_t j;
    size_t total_len;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    total_len = ft_strlen(s1) + ft_strlen(s2);
    result = (char *)malloc(sizeof (char) * (total_len + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while(s1[i])//ft_strlcpyが使える→ft_strlen(s)を取り直す必要があり、total_lenで一回出しているので、少し冗長的になる気がしたので対応やめた。
    {
        result[i] = s1[i];
        i ++;
    }
    while(s2[j])//ft_strlcatが使える→上で、strlcpyを使用するのをやめたので、ここでもやめた。
    {
        result[i + j] = s2[j];
        j ++;
    }
    result[i + j] = '\0';
    return (result);
}

int main(void)
{
    char const *dest = "Anya";
    char const *src = "Forger";
    printf("%s", ft_strjoin(dest, src));
    return (0);
}