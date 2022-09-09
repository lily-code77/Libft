// typedef struct   s_list
//{
// void             *content;
// struct s_list    *next;
//} t_list;
//content : Tne data contained in the element. The void * allows to store any kind of data.
//next : The next element's address or NULL if it's the last element. 

//mallocでメモリを割り当て、新しいノードを返します。
//変数contentはパラメータcontentを使って初期化されます。
//変数nextはNULLを使って初期化されます。

#include <stdio.h>
#include <stdlib.h>

t_list  *ft_lstnew(void *content)
{
    t_list* new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

