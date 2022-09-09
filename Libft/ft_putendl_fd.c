//指定されたファイルディスクリプタで文字列sを出力して改行します。

#include <unistd.h>
#include <stdio.h>

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
    return;
}

void ft_putendl_fd(char *s,int fd)
{
    if (!s)
        return ;
    ft_putstr_fd(s, fd);
    //printf("here");
    ft_putchar_fd('\n', fd);
    return;
}

int main(void)
{
    //char s[] = "";//"TCY0 rsCQ0MUKbBG2 VLZ CdjfUEFP3lv XK32gNu7";
    //ft_putendl_fd(s, 1);
    ft_putendl_fd(NULL, 1);
}