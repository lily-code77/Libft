//sを区切り文字で分けた各文字列を返します。割り当てが失敗した場合はNULL。
//split("AAbbBBbbCC", "b")の場合{AA,BB,CC,NULL}
//mallocで割り当て、sとcで区切った文字列を返します。配列はNULLポインタで終了します。
//分割後の文字列領域をmallocしている時にNULLが返った時は、それまで確保していた領域を全てfreeする。（機械採点は通るが人によっては減点対象）

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void free_unmalloc(size_t nbr, char **res)//(char *res)←自分のレベル以上なので対応しない
{
    size_t i;

    i = 0;
    while (i < nbr) //(res[i] != NULL)←自分のレベル以上なので対応しない
    {
        free(res[i]);
        i ++;
    }
    free (res);
}

static size_t  counting_notc(char const *s, char c)
{
    size_t count;
    size_t i;
    size_t len;

    i = 0;
    count = 0;
    len = strlen(s);
    if (len == 0)
        return (0);
    if (s[0] == c)
        i ++;
    if (s[i] != c)
    {
        count ++;
        i ++;
    }
    while (i < len)
    {
        if (s[i - 1] == c && s[i] != c)
            count ++;
        i ++;
    }
    return (count);
}

static int  ft_allocate_wrdbl(char **res, char const *s, char c)
{
    size_t i;
    size_t nbl;
    size_t size;

    i = 0;
    nbl = 0;
    while (s[i])
    {
        if (s[i] == c)
            i ++;
        else
        {
            size = 0;
            while (s[i] && s[i++] != c)
                size ++;
            res[nbl] = (char *)malloc(sizeof(*s) * (size + 1));
            if (!res[nbl])
            {
                free_unmalloc(nbl, res);
                return (0);
            }
            nbl ++;
        }
    }   
    return (1);
}

static void ft_fillin_s(char **res, char const *s, char c)
{
    size_t i;
    size_t nbl;
    size_t size;

    i = 0;
    nbl = 0;
    while (s[i])
    {
        if (s[i] == c)
            i ++;
        else
        {
            size = 0;
            while (s[i] && s[i] != c)
            {
                res[nbl][size] = s[i];
                size ++;
                i ++;
            }
            res[nbl][size] = '\0';
            nbl ++;
        }
    }
}

char**ft_split(char const *s, char c)
{
    size_t num_of_notc;
    char**  result;

    if (s == NULL)
        return (NULL);
    num_of_notc = counting_notc(s, c);
    result = (char **)malloc(sizeof(char *) * (num_of_notc + 1));//ここで確保すべきは、num_of_notcではなくnum_of_c
    if (!result)
        return (NULL);
    if (ft_allocate_wrdbl(result, s, c) == 0)
        return (NULL);
    ft_fillin_s(result, s, c);
    result[num_of_notc] = NULL;
    return (result);
}

int main(void)
{
    //char *str = "";//"caca\0cbbb";
    char *str ="AAbbBBbbCC";
    char **s;
    //char c = ' ';
    char c = 'b';
    int i;
        
    s = ft_split(str, c);
    i = 0;
    while (s[i])
    {
        printf("%s\n", s[i]);
        i ++;
    }
    return (0);
}


