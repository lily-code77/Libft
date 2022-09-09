//mallocで確保し、文字列's'の各文字に関数'f'を適用した新しい文字列を返す。

#include <stdlib.h>
#include <stdio.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    size_t  i;
    size_t  len;

    if (s == NULL || f == NULL)
       return (NULL);
    len = ft_strlen(s);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while(s[i])
    {
        str[i] = f(i, s[i]);
        i ++;
    }
    str[i] = '\0';
    return (str);
}

char f(unsigned int i, char c)
{
    char s;
    s = c + 1;
    return (s);
}

int main(void)
{
    char str1[] = "abc";
    
    printf("%s\n", ft_strmapi(str1, *f));
    return (0);
}