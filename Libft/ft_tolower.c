#include <ctype.h>
#include <stdio.h>

int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
    
}

int main(void)
{
    int c = 'B';
    int b = '6';

    printf("%c\n", ft_tolower(c));
    printf("%c\n", tolower(c));
    printf("%c\n", ft_tolower(b));
    printf("%c\n", tolower(b));
    return (0);
}
