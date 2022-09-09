/*戻り値
複写先の文字列destと複写元の文字列srcの長さ（バイト数）の和がsize_t型で返る。
この長さには、末端のNULL文字は含まない。戻り値は、初期値のstrlen(*dest)+strlen(*src)となる。
戻り値>=dstsizeの時、切り捨てが発生した事を意味する。
*/

//戻り値は、destの長さとsizeの小さい方の値にsrcの長さを足した値とすること
//strlcatはstrcatの改良版なので、文字列の連結も行います
//そこではdestの文字列の後ろにsrcの文字列を追加しています

#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> 
#include <stdlib.h>

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len ++;
    return (len);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  dst_len;
    size_t  src_len;
	size_t	res;
    size_t  i;

    src_len = ft_strlen(src);
    /*if (!dst )//srcがNULLの時は本家もセグフォを起こすstrlen(src)でsrcのlenをとっている。//dstsize == 0
        return (src_len);*/
    if (dstsize == 0)
        return (src_len);
	dst_len = ft_strlen(dst);
    if (dstsize < dst_len)
        return (src_len + dstsize);
    else
    {
        res = src_len + dst_len;//kokoで必要。ここに変数に代入しておかないと、下記のwhileの中でdst_lenが増えてしまう。
		i = 0;
        while (src[i] && (dst_len + 1) < dstsize)
        {
            dst[dst_len] = src[i];
            dst_len ++;
            i ++;
        }
        dst[dst_len] = '\0';
    }
    return (res);
}
/*
int main()
{
    char first[] = "This is ";
    char last[] = "a potentially long string";
    int r;
    int size = 19;
    char buffer[size];

    strcpy(buffer,first);
    r = ft_strlcat(buffer,last,size);

    puts(buffer);
    printf("Value returned(strlcat): %d\n",r);
    if( r > size )
        puts("String truncated");
    else
        puts("String was fully copied");

    return(0);
}*/
/*
int main(void)
{
    //size_t expect = strlcat(NULL, "ABC", 3);//本家がセグフォ
	size_t expect = strlcat(NULL, "ABC", 0);//dstsizeが0だとsrc_lenを返してくる。
    //size_t expect = strlcat(NULL, NULL, 0); //srcがNULLだと本家もセグフォ
    printf("expect\n");
    printf("%zu\n", expect);
    fflush(stdout);
	//size_t actual = ft_strlcat(NULL, "ABC", 3);
    size_t actual = ft_strlcat(NULL, "ABC", 0);
    //size_t actual = ft_strlcat(NULL, NULL, 0);
    printf("actual\n");
    printf("%zu\n", actual);
    fflush(stdout);
}*/

void	my_test(char *dest1, char *dest2,const char *src, size_t size)
{
	
	pid_t pid;
	pid_t wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;
	size_t	expect;
	size_t	actual;
	printf("====test(%s,%s,%s,%zu)\n",dest1, dest2, src, size);
	pid = fork();
	if (pid == 0)
	{
		expect = strlcat(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}
	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcat(dest2, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_actual);
	}
	assert(WIFEXITED(status_expect) == WIFEXITED(status_actual));
	assert(WIFSIGNALED(status_expect) == WIFSIGNALED(status_actual));
	if (WIFEXITED(status_expect))
	{
		expect = strlcat(dest1, src, size);
		actual = ft_strlcat(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
}

int	main(void)
{
	char *dest1;
	char *dest2;
	const char *src = strdup(" World");
	size_t	size = 6;
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, size);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, 5);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, size);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, 1);// セグフォが起きるが正しい
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, 0);// セグフォが起きるが正しい
	my_test(NULL, NULL, src, size);// セグフォが起きるが正しい
	my_test(NULL, NULL, src, 1);// セグフォが起きるが正しい
	my_test(NULL, NULL, src, 0);// セグフォが「起きない」が正しい
	my_test(NULL, NULL, NULL, size);
	my_test(NULL, NULL, NULL, 1);// セグフォが起きるが正しい
	my_test(NULL, NULL, NULL, 0);// セグフォが起きるが正しい
}