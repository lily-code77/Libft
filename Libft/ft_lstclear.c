//#1:要素へのポインタへのアドレス
//#2:要素の内容を削除する関数delのアドレス

//指定された要素全てを削除する関数delを使用し、freeします。
//最後にnextが指すポインタをNULLに設定する必要があります。
#include <stdlib.h>

/*void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *prev;
    
    prev = *lst;
    if (!lst)
        return ;
    if (del != NULL)
        while (*lst)
        {
            prev->next = *lst->next;
            del((*lst)->content);
            *lst = prev->next;
            free (prev);
        }
        *lst->next = NULL;
}*/

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *tmp;

    if (!lst || !del)
        return ;
    while (*lst)//*lstのポインタ以降NULLまで
    {
        del((*lst)->content);
        tmp=*lst;//これをせずに、35行目を実行してしまうと、*lstが更新されてしまうので、freeするために退避させている。
        *lst = tmp->next;//配列でいう、i++
        free (tmp);
    }
    *lst = NULL;
}