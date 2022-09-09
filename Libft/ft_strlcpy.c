//プロトタイプ： size_t strlcpy(char *dst, const char *src, size_t dstsize)
//複写元の文字列*srcの長さ（バイト数）がsize_t型で返る。
//この長さには、末端のNULL文字は含まない。
//戻り値はstrlen(*src)と同じものである。
//戻り値 >= dstsizeの時、切り捨てが発生したことを意味する。

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

//challenge
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
	size_t src_len;

    i = 0;
	src_len = ft_strlen(src);
    if (dstsize == 0)
        return (src_len);
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i ++;
    }
    dst[i] = '\0';
    return (src_len);//return(ft_strlen(src));と同じこと
}

/*
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if (dstsize == 0)
    {
        return (ft_strlen(src));
        //while (src[i])
        //    i ++;
        //return (i);
    }
    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i ++;
    }
    dst[i] = '\0';
    while (src[i])//複写元の文字列srcの長さ（バイト数）がsize_t型で返る関数なので、srcの長さがdstsizeより大きい時にこの処理が必要。
        i ++;
    return (i);//return(ft_strlen(src));と同じこと
}*/

void	my_test(char *dest1, char *dest2,char *src, size_t size)
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
		expect = strlcpy(dest1, src, size);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}
	pid = fork();
	if (pid == 0)
	{
		actual = ft_strlcpy(dest2, src, size);
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
		expect = strlcpy(dest1, src, size);
		actual = ft_strlcpy(dest2, src, size);
		printf("  %zu：expect\n", expect);
		printf("  %zu：actual\n", actual);
		assert(expect == actual);
	}
	else if(WIFSIGNALED(status_expect))
	{
		printf(" Sig Abort \n");
		assert(WTERMSIG(status_actual) == WTERMSIG(status_expect));
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual) );
	}
}
int	main(void)
{
	char *dest1;
	char *dest2;
	char *src = strdup(" World");
	size_t	size = 6;
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, size+100);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, size);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, 1);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, src, 0);
	dest1 = strdup("");
	dest2 = strdup("");
	my_test(dest1, dest2, src, size+100);
	dest1 = strdup("");
	dest2 = strdup("");
	my_test(dest1, dest2, src, size);
	dest1 = strdup("");
	dest2 = strdup("");
	my_test(dest1, dest2, src, 1);
	dest1 = strdup("");
	dest2 = strdup("");
	my_test(dest1, dest2, src, 0);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, size+100);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, size);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, 1);
	dest1 = strdup("Hello");
	dest2 = strdup("Hello");
	my_test(dest1, dest2, NULL, 0);
	my_test(NULL, NULL, src, size);
	my_test(NULL, NULL, src, 1);
	my_test(NULL, NULL, src, 0);
	my_test(NULL, NULL, NULL, size);
	my_test(NULL, NULL, NULL, 1);
	my_test(NULL, NULL, NULL, 0);
}

/*int main(void)
{
    char dest[5];
    const char *src;
    int size;

    src = "Spy Family fake daughter Anya Forger";
    size = 0;
    printf("%zu\n", ft_strlcpy(dest, src, size));
    printf("%s\n", dest);
    printf("%zu\n", strlcpy(dest, src, size));
    printf("%s\n", dest);
    return (0);
}*/
/*int main(void)
{
    size_t expect = strlcpy(NULL, "ABC", 0);
    //size_t expect = strlcpy("ABC", NULL, 0); 本家はsrcがNULLの時、セグフォを起こす。
    printf("expect\n");
    printf("%zu\n", expect);
    fflush(stdout);
    size_t actual = ft_strlcpy(NULL, "ABC", 0);
    //size_t actual = ft_strlcat("ABC", NULL, 0);
    printf("actual\n");
    printf("%zu\n", actual);
    fflush(stdout);
}*/