//あるメモリアドレスを起点に、一定の範囲内へ特定の文字を書き込む
//void* memset(void* s,int c, size_t size)
//s:書き込み先の先頭のメモリアドレス
//c:書き込む文字
//size:書き込む文字数
//戻り値はsへのポインタが返される

#include <stdio.h>
#include <string.h>

void *ft_memset(void *buf, int ch, size_t n)
{
    //unsigned char *change;
    size_t i;

    //change = (unsigned char*)buf;
    i = 0;
    while (i < n)
    {
        ((unsigned char*)buf)[i] = (unsigned char)ch;
        //change[i] = (unsigned char)ch;
        i ++;
    }
    return (buf);
}

/*int main(void)
{
    char str[50];
    strcpy(str, "The Forgers are a fake family.");
    ft_memset(str+18, '*', 4);//(str+18, '*', (0));
    printf("%s\n", str);
    strcpy(str, "The Forgers are a fake family.");
    memset(str+18, '*', 4);//(str+18, '*', (0));
    printf("%s\n", str);
    //puts(str);
    //strcpy(str, "The Forgers are a fake family.");
    //memset(str+18, '*', 4);
    //puts(str);
    return(0);
}*/

int main(void)
{
    //memset(NULL, 0, 3);//本家がセグフォ
    //memset(NULL, 1, 3);//本家がセグフォ
    memset("ABC", 0, 3);//本家がバスエラー
    printf("expect\n");
    //ft_memset(NULL, 0, 3);
    //ft_memset(NULL, 1, 3);
    ft_memset("ABC", 0, 3);
    printf("actual\n");
}

