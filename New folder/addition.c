#include "apc.h"
void addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail)

{
    int carry = 0;

    while (tail1 || tail2 || carry)
    {
        int sum = carry;

        if(tail1)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if(tail2)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        carry = sum / 10;

        insert_first(res_head, res_tail, sum % 10);
    }
    
}