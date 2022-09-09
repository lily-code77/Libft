//c: 出力する文字
//fd: 書き込むファイルディスクリプタ
//指定されたファイルデスクリプタで、文字cを出力します。
//write関数の第3引数は出力したいデータ量（バイト単位）。
//char: 1,short: 2,int: 4;long: 4 ///////サイズ32ビットの場合
//chsr: 1,short: 2,int: 4;long: 8 ///////サイズ64ビットの場合

#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return ;
}

int main(void)
{
    //ft_putnbr_fd(-2147483648,1);
    ft_putchar_fd(1,1);
}