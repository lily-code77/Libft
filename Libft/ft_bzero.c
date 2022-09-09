//バイト列*sから始まる領域の先頭nバイトを数値ゼロ（値が'\0'のバイト）で埋める。
//戻り値
//メモリの割り当てに成功した場合→確保されたブロックを0クリアしたメモリブロックを指すポインタ
//メモリの割り当てに失敗した場合→NULL

#include <stdio.h>
#include <string.h>

void *ft_memset(void *buf, int ch, size_t n)
{
    unsigned char *change;
    size_t i;

    change = (unsigned char*)buf;
    i = 0;
    while (i < n)
    {
        change[i] = (unsigned char)ch;
        i ++;
    }
    return (buf);
}

void ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

int main(void)
{
    char str[50];
    strcpy(str, "The Forgers are a fake family.");
    ft_bzero(str + 2, 4);
    printf("%s\n", str);
    strcpy(str, "The Forgers are a fake family.");
    bzero(str + 2, 4);
    printf("%s\n", str);
}