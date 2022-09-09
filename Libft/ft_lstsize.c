//Counts the number of elements in a list.
#include <stdio.h>
#include <limits.h>

int ft_lstsize(t_list *lst)
{
	int size;
	
	if (!lst)
		//return (1);←１回目のレビューで提出したもの
		return (0);//今回の修正
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size ++;
	}
	//if (size > INT_MAX)
	//	return (-1);
	return (size);
}

/*int main(void)
{
	int tmp = ft_lstsize(NULL);
	size_t stmp = ft_lstsize(NULL);
	printf("%d %d", tmp, stmp);
}*/

int func(size_t n) {
	return n;
}

int main() {
	size_t n = (size_t)INT_MAX + 1;
	printf("size_t: %zu\n", func(n));
	printf("int: %d\n", func(n));
}