#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*struct list
{
    int k;
    struct list *next;
}; */

struct list *create()
{
	struct list *l = malloc(sizeof(struct list));
	l->next=NULL;
	return l;
}

void add(struct list *l, int n)
{
	while(l->next)
	l=l->next;
    struct list *l1 = malloc(sizeof(struct list));
    l1->k = n;
    l1->next = NULL;
    l->next=l1;
}

int find(struct list *l, int n)
{
	l=l->next;
	int count=0;
	while(l)
	{
		if(l->k==n)
			count++;
		l=l->next;
	}
	return count;
}

void delete(struct list *l, int n)
{
    while(l->next!=NULL && l->next->k!=n)
    	l=l->next;
    if(l->next==NULL)
    	return;
    struct list *nn=l->next->next;
    free(l->next);
    l->next=nn;
}

short int empty(struct list *l)
{
    if (l->next == NULL)
        return 0;
    else
        return 1;
}

void output(struct list *l)
{
	l=l->next;
	while(l)
	{
		printf("%d ",l->k);
		l=l->next;
	}
	printf("\n");
}

struct list *rem(struct list *l)
{
	if(l==NULL)
		return NULL;
	rem(l->next);
	free(l);
	return NULL;
}
