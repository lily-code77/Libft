

//メモリー領域srcの先頭nバイトをメモリー領域destにコピーする。
//途中にNULL文字を含んでいてもコピーを続ける
//destとsrcが重なっている時の動作はmemcpy()では未定義ですが、
//このmemmove()では正しくコピー（つまり移動）が行われます。

#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    unsigned const char *s;
    size_t i;

    d = (unsigned char*)dst;
    s = (unsigned const char*)src;
    i = 0;
    //if (d == NULL && s == NULL)
    //    return (NULL);
    if (d == s || n == 0)
        return (d);
    while (i < n)
    {
        d[i] = s[i];
        i ++;
    }
    return (d);
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    unsigned const char *s;
    size_t i;

    d = (unsigned char*)dest;
    s = (unsigned const char*)src;
    i = 0;
    if (dest == src || n == 0)//
        return (dest);        //
    if (dest < src)
        ft_memcpy(dest, src, n);
    else
    {
        while (n > 0)
        {
            d[n - 1] = s[n - 1];
            n --;
        }
    }
    return(d);
}

/*void    *ft_memmove(void *dest, const void *src, size_t n)
{
    if (dest == src || n == 0)//
        return (dest);        //
    if (dest < src)
        ft_memcpy(dest, src, n);
    else
    {
        while (n > 0)
        {
            ((unsigned char *)dest)[n - 1] = ((unsigned const char *)src)[n - 1];//norm的に字数オーバー
            n --;
        }
    }
    return(dest);
}*/

/*void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		memcpy(dest, src, n);
	else
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return (dest);
}*/

/*int main(void)
{
    char    ft_dest[100];
    char    ori_dest[100];

    ft_memmove(ft_dest, "KbaHNrSQfl7e28Cz", 0);
    memmove(ori_dest, "KbaHNrSQfl7e28Cz", 0);
    printf("ft_memmove=%s\n", ft_dest);
    printf("___memmove=%s\n", ori_dest);
    return (0);
}*/

int main(void)
{
    //memmove(NULL, NULL, 3);
    //memmove(NULL, "ABC", 3);//本家がセグフォ
    memmove("ABC", NULL, 3);//本家がセグフォ
    printf("expect\n");
    //ft_memmove(NULL, NULL, 3);
    //ft_memmove(NULL, "ABC", 3);
    ft_memmove("ABC", NULL, 3);
    printf("actual\n");
}