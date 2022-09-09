//指定されたファイルディスクリプタで文字列sを出力します。

#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return;
}

void ft_putstr_fd(char *s, int fd)
{
    size_t i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i ++;
    }
    return ;
}

int main(void)
{
    ft_putstr_fd("",1 );
}