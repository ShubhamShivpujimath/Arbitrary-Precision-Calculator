#ifndef APC_H
#define APC_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

/* dll.c */
void insert_first(Dlist **head, Dlist **tail, int data);
void insert_last(Dlist **head, Dlist **tail, int data);
void create_list(Dlist **head, Dlist **tail, char *num);
void print_list(Dlist *head);
void free_list(Dlist **head, Dlist **tail);
int compare_lists(Dlist *head1, Dlist *tail1);

/* Addition.c */
void addition(Dlist *tail1, Dlist *tail2, Dlist **res_head, Dlist **res_tail);

/* Subtraction.c */
void subtraction(Dlist  *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,
                 Dlist **res_tail, int *is_negative);

/* Multiplication.c*/
void multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **res_head,
                    Dlist **res_tail);

/* Division.c */
void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **quot_head,
              Dlist **quot_tail, Dlist **res_head, Dlist **res_tail, int *is_div_by_zero);




#endif
