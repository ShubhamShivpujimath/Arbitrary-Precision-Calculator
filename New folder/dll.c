#include "apc.h"

void insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;
}

void insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
}

void create_list(Dlist **head, Dlist **tail, char *num)
{
    int i;

    for (i = 0; num[i] != '\0'; i++)
        insert_last(head, tail, num[i] - '0');
}

void print_list(Dlist *head)
{
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(Dlist **head, Dlist **tail)
{
    Dlist *cur = *head;
    Dlist *nxt;

    while (cur)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    *head = NULL;
    *tail = NULL;
}

int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *p;

    for (p = head1; p; p = p->next) len1++;
    for (p = head2; p; p = p->next) len2++;

    if (len1 != len2)
        return len1 > len2 ? 1 : -1;

    while (head1)
    {
        if (head1->data != head2->data)
            return head1->data > head2->data ? 1 : -1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}