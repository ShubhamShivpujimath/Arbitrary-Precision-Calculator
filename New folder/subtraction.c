#include "apc.h"

void subtraction(Dlist  *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,
                 Dlist **res_tail, int *is_negative)
{
    int borrow = 0;
    int cmp = compare_lists(head1, head2);

    *is_negative = 0;
    if(cmp < 0)
    {
        Dlist *temp;
        temp = tail1;
        tail1 = tail2;
        tail2 = temp;
        *is_negative = 1;
    }
    else if(cmp == 0)
    {
        insert_first(res_head, res_tail, 0);
        return;
    }

    while (tail1)
    {
        int diff = tail1->data - borrow - (tail2?tail2->data : 0);
        if(diff < 0)
        {
            diff += 10;
            borrow = 0;
        }
        else
        {
            borrow = 0;
        }

        insert_first(res_head, res_tail, diff);
        tail1 = tail1->prev;

        if(tail2)
        {
            tail2 = tail2->prev;
        }
    }

    while (*res_head&&(*res_head)->next&&(*res_head)->data == 0)
    {
        Dlist *old = *res_head;
        *res_head = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(old);
    }
}
