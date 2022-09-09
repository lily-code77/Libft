//lstの各contentへ関数fを適用します。

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!lst || !f)
        return ;
    while (lst)
    {
        f(lst->content);
        lst = lst->next; //i++みたいな意味。lstの最後に向かって、次へ次への進めている。
    }
    return ;
}