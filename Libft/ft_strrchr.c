//文字列の後方から、特定の文字を探す
//戻り値：発見された場合はsの中でcと一致した文字を指すポインタを返す
//       発見できなかった場合は、ヌルポインタを返す。

#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}


char *ft_strrchr(const char *s, int c)
{
    size_t i;
    
    i = ft_strlen(s);
    while(i >= 0)
    {
        if (s[i] == (char)c)
            return ((char*)&s[i]);
        if (i == 0)
            break ;
        i --;
    }
    return (NULL);
}

int main(void)
{
    //const char s[] = "abcdefg";
    //int c = '\0';

    printf("expect=%s\n", strrchr("abcdefg", 'c'));
    printf("actual=%s\n", ft_strrchr("abcdefg", 'c'));
    printf("expect=%s\n", strrchr("abcdefg", '\0'));
    printf("actual=%s\n", ft_strrchr("abcdefg", '\0'));
    printf("expect=%s\n", strrchr("", '\0'));
    printf("actual=%s\n", ft_strrchr("", '\0'));
    printf("expect=%s\n", strrchr("", 'a'));
    printf("actual=%s\n", ft_strrchr("", 'a'));
    return (0);
}