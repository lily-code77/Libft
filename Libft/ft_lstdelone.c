//#1:削除するノードのアドレス
//#2:ノードのcontentのデータ削除に使用する関数delのアドレス
//データを削除する関数delを使い、lstのcontentのデータを削除します。
//content削除後、ノードをfreeします。
//ノードのnextはfreeしてはいけません。
#include <stdlib.h>

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
        return ;
    del(lst->content);
    free(lst); 
    return ;
}