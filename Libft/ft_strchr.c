//文字列から特定の文字を探す
//戻り値：発見された場合はsの中でcと一致した文字を指すポインタを返す
//       発見できなかった場合は、ヌルポインタを返す。

#include <string.h>
#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    size_t i;

    i = 0;
    while(s[i])
    {
        if (s[i] == (char)c)
            return ((char*)&s[i]);
        i ++;
    }
    if (c == '\0')
        return ((char*)&s[i]);
    return (NULL);
}

int main(void)
{
    //const char s[] = "abcdefg";
    //int c = '\0';

    printf("expect=%s\n", strchr("abcdefg", 'c'));
    printf("actual=%s\n", ft_strchr("abcdefg", 'c'));
    printf("expect=%s\n", strchr("abcdefg", '\0'));
    printf("actual=%s\n", ft_strchr("abcdefg", '\0'));
    printf("expect=%s\n", strchr("", '\0'));
    printf("actual=%s\n", ft_strchr("", '\0'));
    printf("expect=%s\n", strchr("", 'a'));
    printf("actual=%s\n", ft_strchr("", 'a'));
    return (0);
}