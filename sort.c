#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"

int length(struct list *l)
{
	int len=0;
    while(l->next)
    {
    	len++;
    	l=l->next;
    }
    return len;
}

char insert(struct list *l,int n,int len)
{
	struct list *parent=l;
	l=l->next;
	while(len)
	{
		if(l->k>=n)
		{
			struct list *l1 = malloc(sizeof(struct list));
    		l1->k = n;
   			l1->next = l;
   			parent->next=l1;
   			return 1;
		}
		len--;
		parent=l;
		l=l->next;
	}
	return 0;
}

void sort(struct list *l)
{
	struct list *root=l;
	struct list *parent=l;
	l=l->next;
	int idx=0;
	while(l)
	{
		char ins=insert(root,l->k,idx);
		if(ins)
		{
			struct list *next=parent->next->next;
			free(parent->next);
			parent->next=next;
			l=parent->next;
		}
		else
		{
			parent=l;
			l=l->next;
		}
		idx++;
	}
}

