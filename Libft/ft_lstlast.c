//リストの最後のノードのポインタを返します。

t_list  *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
        return (NULL);
    while (lst->next)
        lst = lst->next;//lst->nextは次のリストのポインタ（＝最後のlst）
    return(lst);
}