//動的にメモリ領域を確保し、0で初期化する。
//nは確保する区画の個数。0を指定した場合の動作については、取り決めがない。
//sizeは確保する領域の大きさを、バイト単位で指定する。0を指定した場合の動作は処理系定義。
//戻り値
//メモリの割り当てに成功した場合→確保されたブロックを0クリアしたメモリブロックを指すポインタ
//メモリの割り当てに失敗した場合→NULL

#include <stdlib.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char *change;
    size_t i;

    change = (unsigned char*)s;
    i = 0;
    while (i < n)
    {
        change[i] = '\0';
        i ++;
    }
}
//challenge
void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
   
    if (count && size > SIZE_MAX / count)
        return (NULL);
    if (size == 0 || count == 0)
    {
        size = 1;
        count = 1;
    }
    ptr = (void*)malloc(size * count);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, size * count);
    return (ptr);
}
/*
void *ft_calloc(size_t count, size_t size)
{
    void *ptr;
    void *ptr2;

    if (count && size > SIZE_MAX / count)
        return (NULL);
    if (size == 0 || count == 0)
    {
        ptr2 = malloc(1);
        if(!ptr2)
            return(NULL);
        ft_bzero(ptr2, 1);
        return (ptr2);　　　　　　
    }
    ptr = (void*)malloc(size * count);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, size * count);
    return (ptr);
}*/