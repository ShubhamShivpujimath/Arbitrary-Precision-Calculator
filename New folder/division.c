#include "apc.h"

static int is_zero_list(Dlist *head)
{
    while (head)
    {
        if (head->data != 0)
            return 0;
        head = head->next;
    }
    return 1;
}

void division(Dlist *head1, Dlist *tail1,
              Dlist *head2, Dlist *tail2,
              Dlist **quot_head, Dlist **quot_tail,
              Dlist **rem_head,  Dlist **rem_tail,
              int *is_div_by_zero)
{
    Dlist *cur_head = NULL;
    Dlist *cur_tail = NULL;
    Dlist *p;
    int    dummy_neg;

    *is_div_by_zero = 0;

    /* Check divide by zero */
    if (is_zero_list(head2))
    {
        *is_div_by_zero = 1;
        return;
    }
    p = head1;

    while (p)
    {

        insert_last(&cur_head, &cur_tail, p->data);

        while (cur_head && cur_head->next && cur_head->data == 0)
        {
            Dlist *old     = cur_head;
            cur_head       = cur_head->next;
            cur_head->prev = NULL;
            free(old);
        }

        int count = 0;

        while (compare_lists(cur_head, head2) >= 0)
        {
            Dlist *sub_head = NULL, *sub_tail = NULL;

            subtraction(cur_head, cur_tail,
                        head2,    tail2,
                        &sub_head, &sub_tail,
                        &dummy_neg);

            free_list(&cur_head, &cur_tail);

            cur_head = sub_head;
            cur_tail = sub_tail;

            count++;
        }

        insert_last(quot_head, quot_tail, count);

        p = p->next;
    }

    while (*quot_head && (*quot_head)->next && (*quot_head)->data == 0)
    {
        Dlist *old      = *quot_head;
        *quot_head      = (*quot_head)->next;
        (*quot_head)->prev = NULL;
        free(old);
    }


    if (!(*quot_head))
        insert_last(quot_head, quot_tail, 0);

    if (!cur_head)
        insert_last(&cur_head, &cur_tail, 0);

    *rem_head = cur_head;
    *rem_tail = cur_tail;
}