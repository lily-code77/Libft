//lstの各contentに関数fを適用し、新しいリストを作成します。
//del関数は必要に応じて、コンテンツを削除します。

#include <stdlib.h>

/*t_list  *ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
    t_list  *newnode_end;
    t_list  *newlst;
    
    while (lst)
    {
        newnode_end = ft_lstnew(f(lst->content));//contentにf関数を適応させたelementをft_lstnewで新しいノードにしている。
        newlst = ft_lstadd_back(&lst, newnode_end);//新しくできたノードをリストの後ろから足している。
        if (!newlst)
        {
            ft_lstclear(&lst, del);
            return (NULL);
        }
        lst = lst->next; //i++のようなもの。次へ次へとelementを進めている。
    }
    return (newlst);
}*/
/*t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *newnode_end;
    t_list *new_lst;

    if (!lst || !f || !del)
        return (NULL);
    new_lst = NULL;
    while (lst)
    {
        newnode_end = ft_lstnew((*f)(lst->content));
        if (!newnode_end)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, newnode_end);
        lst = lst->next;
    }
    return (new_lst);
}*/

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *newnode_end;

    if (!lst || !f)
        return (NULL);
    new_list = ft_lstnew(f(lst->content));
    if (!new_list)
        return (NULL);
    lst = lst->next;
    while (lst)
    {
        newnode_end = ft_lstnew(f(lst->content));
        if (!newnode_end)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, newnode_end);
        lst = lst->next;
    }
    return (new_list);
}


