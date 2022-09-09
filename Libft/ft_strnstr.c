//*haystack : 検索対象のメモリブロック
//*needle : 検索文字列
//len : 検索バイト数

//needleが空の文字列の時はhaystackを返し、haystackにneedleが無い場合はNULLを返します。
//それ以外の時は、最初に出現したneedleの最初の文字へのポインタを返します。

#include <stdio.h>
#include <string.h>
#include <xlocale.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (needle[0] == '\0')
        return ((char *)haystack);
    i = 0;
    while (i < len && haystack[i])
    //while (haystack[i] && i < len)//逆。(←こっちが間違え)NULLのi番目なんてないから、セグフォが起こる。
    {
        j = 0;
        if (haystack[i] == needle[j])
        {
            while (i + j < len && haystack[i + j] == needle[j])
            {
                j ++;
                if (needle[j] == '\0')
                    return ((char*)&haystack[i]);
            }
        }
        i ++;
    }
    return (NULL);
}

void	my_test(const char *haystack, const char *needle, size_t len)
{
	
	pid_t	pid;
	pid_t	wait_pid;
	int     status_expect = 0;
	int     status_actual = 0;
	char	*expect;
	char	*actual;
	printf("====test(%s,%s,%zu)\n",haystack, needle, len);
	pid = fork();
	if (pid == 0)
	{
		expect = strnstr(haystack, needle, len);
		exit(0);
	}
	else
	{
		wait_pid = wait(&status_expect);
	}
	pid = fork();
	if (pid == 0)
	{
		actual = ft_strnstr(haystack, needle, len);
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
		expect = strnstr(haystack, needle, len);
		actual = ft_strnstr(haystack, needle, len);
		printf("  %s：expect\n", expect);
		printf("  %s：actual\n", actual);
		if (expect == NULL &&  actual == NULL)
			return ;
		if (expect == NULL || actual == NULL)
			assert(0);
		assert(!strncmp(expect, actual,len));
	}
	else
	{
		printf(" Sig Abort \n");
		printf(" WTERMSIG:%d\n",WTERMSIG(status_actual));
	}
}
int	main(void)
{
	const char *s1 = strdup("2");
	const char *s2 = strdup("2");
	my_test(s1,s2,3);
	my_test(s1,s2,2);
	my_test(s1,s2,1);
	my_test(s1,s2,0);//
	my_test(s1,NULL,0);//
	my_test(NULL,s2,0);//
	my_test(NULL,NULL,0);//
	my_test(s1,NULL,1);//
	my_test(NULL,s2,1);//
	my_test(NULL,NULL,1);//
	my_test(s1,NULL,2);
	my_test(NULL,s2,2);
	my_test(NULL,NULL,2);
	my_test(s1,NULL,3);
	my_test(NULL,s2,3);
	my_test(NULL,NULL,3);
	my_test("abbbcdefg", "bbc", 1);
	my_test("abbbcdefg", "bbc", 5);
	my_test("abbbcdefg", "bbc", 100);
	my_test("ab", "abcdefgh", 1);
	my_test("ab", "abcdefgh", 5);
	my_test("ab", "abcdefgh", 100);
	system("leaks a.out");
}

/*
int main(void)
{
    char beach[] = "nviauhpfnvpau";
    char diamond[] = "iau";
    size_t n = 5;//0;

    //printf("%s\n", ft_strnstr(beach, diamond, n));
    //printf("%s\n", strnstr(beach, diamond, n));
    printf("%s\n", ft_strnstr(NULL, diamond, n));
    printf("%s\n", strnstr(NULL, diamond, n));
    return (0);
}*/
