//Add the element 'new' at the end of the list.

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list  *tmp;

    if (!lst || !new)
        return ;
    //new->next = NULL; ←libftTesterのSEGV対策で消した。
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    tmp = ft_lstlast(*lst);
    tmp->next = new;
    return ;
}

int main(void)
{
    t_list  *list = ft_lstnew("list");
    t_list  *list2 = ft_lstnew("list2");

    ft_lstadd_back(&list, list2);
    for(; list;)
    {
        printf("%s\n", list->content);
    }  list = list->next;
    return (0);
}