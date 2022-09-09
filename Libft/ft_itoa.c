//mallocを使用して割り当て、引数として受け取った数値を文字列で返します。
//負の数を処理する必要があります。

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static size_t count_num(int nb)
{
    size_t counter;

    counter = 0;
    if (nb == INT_MIN)
    {
        counter ++;//「-」分
        nb = (-1) * (INT_MIN / 10);
        counter ++;//「末尾の8」分
    }
    if (nb < 0)
    {
        counter ++;
        nb = (-1) * nb;
    }
    else if (nb == 0)
        counter ++;
    while (nb > 0)
    {   
        nb = nb / 10;
        counter ++;
    }
    return (counter);
}

static char *ft_strcpy(char *dest, char *src)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
    return (dest);
}

/*size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
}*/

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

char *ft_itoa(int n)
{
    size_t amount;
    char *result;

    amount = count_num(n);
    result = (char *)malloc(sizeof(char) * (amount + 1));
    if (!result)
        return (NULL);
    if (n == 0)
		return(ft_strcpy(result, "0"));//result[0] = '0';
    if (n == INT_MIN)
        return (ft_strcpy(result, "-2147483648"));
    /*{ 
        strlcpy(result, "-2147483648", amount + 1);
        return (result);
    }normの行数オーバー*/
    if (n < 0)
	{
        result[0] = '-';
		n = n * (-1);
	} 
    result[amount --] = '\0';
	while (n > 0)
	{
		result[amount] = '0' + (n % 10);
		n = n / 10;
		amount--;
	} 
    return (result);
}

int main(void)
{
    printf("0=%s\n", ft_itoa(0));
    printf("INT_MIN=%s\n", ft_itoa(INT_MIN));
    printf("-3=%s\n", ft_itoa(-3));
    printf("-103=%s\n", ft_itoa(-103));
    printf("INT_MAX=%s\n", ft_itoa(INT_MAX));
    return (0);
}