//s1とs2をn文字比べて
//s1が小さい場合　→ 負の値 を返す
//s1とs2が同じ場合　→ 0 を返す
//s1が大きい場合　→ 正の値 を返す

#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    
    i = 0;
    if (n == 0)
        return (0);
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            break ;
        i ++;
    }
    if (n == i)
        return (0);
    else
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
    char s1[] = "Spyfamily";
    char s2[] = "Spy";
    
    //変数に代入して、普通にgcc
    printf("1)expect=%d\n", strncmp(s1, s2, 3));
    printf("1)actual=%d\n", ft_strncmp(s1, s2, 3));
    printf("2)expect=%d\n", strncmp(s1, s2, 5));//
    printf("2)actual=%d\n", ft_strncmp(s1, s2, 5));
    printf("3)expect=%d\n", strncmp("", s2, 4));//
    printf("3)actual=%d\n", ft_strncmp("", s2, 4));//
    printf("4)expect=%d\n", strncmp(s1, "", 4));//
    printf("4)actual=%d\n", ft_strncmp(s1, "", 4));//
    printf("5)expect=%d\n", strncmp(s1, s2, 0));
    printf("5)actual=%d\n", ft_strncmp(s1, s2, 0));
    printf("6)expect=%d\n", strncmp("", "", 4));
    printf("6)actual=%d\n", ft_strncmp("", "", 4));
    printf("7)expect=%d\n", strncmp("", "", 0));
    printf("7)actual=%d\n", ft_strncmp("", "", 0));
    printf("8)expect=%d\n", strncmp("", s2, 0));
    printf("8)actual=%d\n", ft_strncmp("", s2, 0));
    printf("9)expect=%d\n", strncmp(s1, "", 0));
    printf("9)actual=%d\n", ft_strncmp(s1, "", 0));
}
