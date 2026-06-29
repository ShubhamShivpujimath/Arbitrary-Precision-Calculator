#include "apc.h"

static void multiply_by_digit(Dlist *tail, int d,
                               int shift,
                               Dlist **res_head, Dlist **res_tail)
{
    int i;
    int carry = 0;

    for (i = 0; i < shift; i++)
        insert_first(res_head, res_tail, 0);

    while (tail || carry)
    {
        int prod = carry;

        if (tail)
        {
            prod += tail->data * d;
            tail  = tail->prev;
        }

        carry = prod / 10;
        insert_first(res_head, res_tail, prod % 10);
    }

    if (!(*res_head))
        insert_first(res_head, res_tail, 0);
}

void multiplication(Dlist *head1, Dlist *tail1,
                    Dlist *head2, Dlist *tail2,
                    Dlist **res_head, Dlist **res_tail)
{
    int shift = 0;

    insert_first(res_head, res_tail, 0);

    while (tail2)
    {
        Dlist *row_head = NULL;
        Dlist *row_tail = NULL;
        Dlist *sum_head = NULL;
        Dlist *sum_tail = NULL;

        multiply_by_digit(tail1, tail2->data, shift, &row_head, &row_tail);

        addition(*res_tail, row_tail, &sum_head, &sum_tail);

        free_list(res_head, res_tail);
        free_list(&row_head, &row_tail);

        *res_head = sum_head;
        *res_tail = sum_tail;

        tail2 = tail2->prev;
        shift++;
    }

    while (*res_head && (*res_head)->next && (*res_head)->data == 0)
    {
        Dlist *old     = *res_head;
        *res_head      = (*res_head)->next;
        (*res_head)->prev = NULL;
        free(old);
    }
}