#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

static int  space(const char str)
{
    if (str == ' ' || str == '\f' || str == '\n'
        || str == '\r' || str == '\t' || str == '\v')
        return (1);
    return (0);
}

static int  is_over(long n, int m)
{
    return (n > (LONG_MAX - m) / 10);
}

static int  which_sign(int sign)
{
    if (sign == -1)
        return((int)LONG_MIN);
    if (sign == 1)
        return((int)LONG_MAX);
    return (0);
}

int ft_atoi(const char *str)
{
    long result;
    int sign;
    size_t  i;

    sign = 1;
    result = 0;
    i = 0;
    while (space(str[i]))
        i ++;
    if (str[i] == '-' || str[i] == '+')
        sign = (str[i ++] - 44) * -1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        if (is_over(result, (str[i] - '0')))
            return (which_sign(sign));
        result = result * 10 + (str[i] - '0');
        i ++;
    }
    return ((int)result * sign);
}

int main(void)
{
    printf("%d\n", ft_atoi(" \n-34627"));
    printf("%d\n", atoi(" \n-34627"));
    
    printf("%d\n", ft_atoi("42!!!!@@@@!!!!@@@@!!!!@@@@!!!!"));//
    printf("%d\n", atoi("42!!!!@@@@!!!!@@@@!!!!@@@@!!!!"));//
   
    printf("%d\n", ft_atoi("9223372036854775812"));//
    printf("%d\n", atoi("9223372036854775812"));//
    
    printf("%d\n", ft_atoi("922337203685477570"));
    printf("%d\n", atoi("922337203685477570"));

    printf("%d\n", ft_atoi("922337203685477577"));
    printf("%d\n", atoi("922337203685477577"));

    printf("%d\n", ft_atoi("-9223372036854775807"));
    printf("%d\n", atoi("-9223372036854775807"));

    printf("%d\n", ft_atoi("-9223372036854775800"));
    printf("%d\n", atoi("-9223372036854775800"));

    printf("   atoi(\"LONG_MAX\")=[%d]\n", atoi("9223372036854775807"));
	printf("ft_atoi(\"LONG_MAX\")=[%d]\n", ft_atoi("9223372036854775807"));
    printf("   atoi(\"LONG_MIN\")=[%d]\n", atoi("-9223372036854775808"));
	printf("ft_atoi(\"LONG_MIN\")=[%d]\n", ft_atoi("-9223372036854775808"));

    printf("-----iroiro-----\n");
	printf("   atoi(\"LONG_MIN＋1\")=[%d]\n", atoi("-9223372036854775807"));
	printf("ft_atoi(\"LONG_MIN+1\")=[%d]\n", ft_atoi("-9223372036854775807"));
    printf("   atoi(\"LONG_MAX-1\")=[%d]\n", atoi("9223372036854775806"));
	printf("ft_atoi(\"LONG_MAX-1\")=[%d]\n", ft_atoi("9223372036854775806"));

    printf("   atoi(\"INT_MIN-1\")=[%d]\n", atoi("-2147483649"));
	printf("ft_atoi(\"INT_MIN-1\")=[%d]\n", ft_atoi("-2147483649"));
    printf("   atoi(\"INT_MAX+1\")=[%d]\n", atoi("2147483648"));
	printf("ft_atoi(\"INT_MAX+1\")=[%d]\n", ft_atoi("2147483648"));

    printf("   atoi(\"INT_MIN-10\")=[%d]\n", atoi("-2147483658"));
	printf("ft_atoi(\"INT_MIN-10\")=[%d]\n", ft_atoi("-2147483658"));
    printf("   atoi(\"INT_MAX+10\")=[%d]\n", atoi("2147483657"));
	printf("ft_atoi(\"INT_MAX+10\")=[%d]\n", ft_atoi("2147483657"));

    printf("-----overflow-----\n");
	printf("   atoi(\"+1\")=[%d]\n", atoi("9223372036854775808"));
	printf("ft_atoi(\"+1\")=[%d]\n", ft_atoi("9223372036854775808"));
	printf("   atoi(\"一桁多い\")=[%d]\n", atoi("92233720368547758000"));
	printf("ft_atoi(\"一桁多い\")=[%d]\n", ft_atoi("92233720368547758000"));

	printf("-----underflow-----\n");
	printf("   atoi(\"-1\")=[%d]\n", atoi("-9223372036854775809"));
	printf("ft_atoi(\"-1\")=[%d]\n", ft_atoi("-9223372036854775809"));
	printf("   atoi(\"一桁多い\")=[%d]\n", atoi("-92233720368547758000"));
	printf("ft_atoi(\"一桁多い\")=[%d]\n", ft_atoi("-92233720368547758000"));
}

/*int main(void)
{
    printf("%d\n", ft_atoi(" \n-12345"));
    printf("%d\n", atoi(" \n-12345"));
    
    //printf("INT_MAX=[%ld]\n", INT_MAX);
	//printf("INT_MIN=[%ld]\n", INT_MIN);
	
	printf("   atoi(\"INT_MAX\")=[%d]\n", atoi("2147483647"));
	printf("ft_atoi(\"INT_MAX\")=[%d]\n", ft_atoi("2147483647"));
    printf("   atoi(\"INT_MIN\")=[%d]\n", atoi("-2147483648"));
	printf("ft_atoi(\"INT_MIN\")=[%d]\n", ft_atoi("-2147483648"));

	//printf("-----LONG_MIN-----\n");
	printf("   atoi(\"LONG_MAX\")=[%d]\n", atoi("9223372036854775807"));
	printf("ft_atoi(\"LONG_MAX\")=[%d]\n", ft_atoi("9223372036854775807"));
    printf("   atoi(\"LONG_MIN\")=[%d]\n", atoi("-9223372036854775808"));
	printf("ft_atoi(\"LONG_MIN\")=[%d]\n", ft_atoi("-9223372036854775808"));

	printf("-----overflow-----\n");
	printf("   atoi(\"+1\")=[%d]\n", atoi("9223372036854775808"));
	printf("ft_atoi(\"+1\")=[%d]\n", ft_atoi("9223372036854775808"));
	printf("   atoi(\"一桁多い\")=[%d]\n", atoi("92233720368547758000"));
	printf("ft_atoi(\"一桁多い\")=[%d]\n", ft_atoi("92233720368547758000"));

	printf("-----underflow-----\n");
	printf("   atoi(\"-1\")=[%d]\n", atoi("-9223372036854775809"));
	printf("ft_atoi(\"-1\")=[%d]\n", ft_atoi("-9223372036854775809"));
	printf("   atoi(\"一桁多い\")=[%d]\n", atoi("-92233720368547758000"));
	printf("ft_atoi(\"一桁多い\")=[%d]\n", ft_atoi("-92233720368547758000"));
    
    printf("-----iroiro-----\n");//NG出た。
	printf("   atoi(\"LONG_MIN＋1\")=[%d]\n", atoi("-9223372036854775807"));
	printf("ft_atoi(\"LONG_MIN+1\")=[%d]\n", ft_atoi("-9223372036854775807"));
    printf("   atoi(\"LONG_MAX-1\")=[%d]\n", atoi("9223372036854775806"));
	printf("ft_atoi(\"LONG_MAX-1\")=[%d]\n", ft_atoi("9223372036854775806"));

    printf("   atoi(\"INT_MIN-1\")=[%d]\n", atoi("-2147483649"));
	printf("ft_atoi(\"INT_MIN-1\")=[%d]\n", ft_atoi("-2147483649"));
    printf("   atoi(\"INT_MAX+1\")=[%d]\n", atoi("2147483648"));
	printf("ft_atoi(\"INT_MAX+1\")=[%d]\n", ft_atoi("2147483648"));

    printf("   atoi(\"INT_MIN-10\")=[%d]\n", atoi("-2147483658"));
	printf("ft_atoi(\"INT_MIN-10\")=[%d]\n", ft_atoi("-2147483658"));
    printf("   atoi(\"INT_MAX+10\")=[%d]\n", atoi("2147483657"));
	printf("ft_atoi(\"INT_MAX+10\")=[%d]\n", ft_atoi("2147483657"));

   return(0);
}*/
