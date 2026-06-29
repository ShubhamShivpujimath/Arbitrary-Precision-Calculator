/**********************************************************
 * NAME: SHUBHAM SHIVPUJIMATH
 * DATE: 20-06-2026
 * DESCRIPTION: Arbitrary Precision Calculator
 **********************************************************/
#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *res_head = NULL, *res_tail = NULL;

    /* CLA check */
    if (argc != 4)
    {
        printf("Usage : ./apc <number1> <operator> <number2>\n");
        printf("Example: ./apc 12345678901234567890 + 98765432109876543210\n");
        printf("Operators: + - * /\n");
        return 1;
    }

    char *num1 = argv[1];
    char  op   = argv[2][0];
    char *num2 = argv[3];

    create_list(&head1, &tail1, num1);
    create_list(&head2, &tail2, num2);

    if (op == '+')
    {
        printf("Result : ");
        addition(tail1, tail2, &res_head, &res_tail);
        print_list(res_head);
    }
    else if (op == '-')
    {
        int is_negative = 0;
        printf("Result : ");
        subtraction(head1, tail1, head2, tail2,
                    &res_head, &res_tail, &is_negative);
        if (is_negative)
            printf("-");
        print_list(res_head);
    }
    else if (op == '*')
    {
        printf("Result : ");
        multiplication(head1, tail1, head2, tail2,
                       &res_head, &res_tail);
        print_list(res_head);
    }
    else if (op == '/')
    {
        int is_div_by_zero = 0;
        Dlist *rem_head = NULL, *rem_tail = NULL;

        division(head1, tail1, head2, tail2,
                 &res_head, &res_tail,
                 &rem_head, &rem_tail,
                 &is_div_by_zero);

        if (is_div_by_zero)
        {
            printf("Error : Division by zero\n");
        }
        else
        {
            printf("Quotient  : ");
            print_list(res_head);
            printf("Remainder : ");
            print_list(rem_head);
            free_list(&rem_head, &rem_tail);
        }
    }
    else
    {
        printf("Error : Unknown operator '%c'\n", op);
        printf("Use : + - * /\n");
        return 1;
    }

    free_list(&head1, &tail1);
    free_list(&head2, &tail2);
    free_list(&res_head, &res_tail);

    return 0;
}