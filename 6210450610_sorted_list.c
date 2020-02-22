//6210450610 Prapawarin Kramkeaw
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void sorted_list(struct node **x, struct node *y);
struct node 
{
    int i;
    struct node *n;
};
int main() 
{
    struct node *a = NULL;
    struct node *next = NULL;
    int x;

    for (;;)
    {
        scanf("%d", &x);
        if (x==-1)
        {
          break;
        }
        else
        {
          struct node *next = (struct node *)malloc(sizeof(struct node));

          next->i = x;
          next->n = NULL;

          sorted_list(&a, next);
        }
    }
    for(;a; a = a->n)
    {
        printf("%d\n", a->i);
    }
}
void sorted_list(struct node **x, struct node *y) 
{
    struct node *a;
    if (*x == NULL || (*x)->i >= y->i) 
    {
        y->n = *x;
        *x = y;
    } else 
    {
        a = *x;
        while (a->n != NULL && a->n->i < y->i) 
        {
            a = a->n;
        }
        y->n = a->n;
        a->n = y;
    }
}