//C言語では、長さ、大きさ、サイズを表現する型として、 size_t の名前の型が使われます。
//sizeof演算子や、strlen関数など、byte数や長さを表現するところで使われる型です。
//この型は、<stddef.h>で定義される型ですが、通常は<stdio.h>や<stdlib.h>をインクルードすれば使えるようになる型です。

//const char*の変数は、定数データへのポインタです。中身の変更不可、アドレスの変更可です。

#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

int main(void)
{
    const char str[] = "SPYFAMILY";

    printf("%zu\n", ft_strlen(""));
    printf("%zu\n", strlen(""));
    return (0);
}