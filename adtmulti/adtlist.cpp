/************************************************************************!
* \file
* \brief
*
*
*
* \author Vincent, vicentcj@163.com
* \version
* \date //201
*
*
*************************************************************************/
#include "stdafx.h"
#include "malloc.h"
#include "adtlist.h"

void push_front(list l, int c, unsigned  e)
{
	position new_unit;
	new_unit = (position)malloc(sizeof(NODE));
	if (NULL == new_unit)
	{
		new_unit->coefficient = c;
		new_unit->exponent = e;
		new_unit->next_node = l->next_node;
		l->next_node = new_unit;
	}
	else
		printf("fail to add \n");
}
void push_back(list l, position p, int c, unsigned e)
{
	position new_unit;
	new_unit = (position)malloc(sizeof(NODE));
	if (NULL == new_unit)
	{
		new_unit->coefficient = c;
		new_unit->exponent = e;
		new_unit->next_node = NULL;
		p->next_node = new_unit;
	}
	else
		printf("fail to add \n");
}
void delete_unit(position p)
{
	position temp;
	temp = p->next_node;
	p->next_node = temp->next_node;
	free(temp);
}
void delete_list(list l)
{
	position temp,p;
	p = l;
	while (NULL != p->next_node)
	{
		delete_unit(p);
	}
}
position create_list(void)
{
	position new_unit;
	new_unit = (position)malloc(sizeof(NODE));
	if (NULL != new_unit)
	{
		new_unit->coefficient = 0;
		new_unit->exponent = 0;
		new_unit->next_node = NULL;
	}
	else
		printf("fail to create list!! \n");
		return new_unit;
}
void insert_unit(position p, int c, unsigned e)
{
	position new_unit;
	new_unit = (position)malloc(sizeof(NODE));
	if (NULL != new_unit)
	{
		new_unit->coefficient = c;
		new_unit->exponent = e;
		new_unit->next_node = p->next_node;
		p->next_node = new_unit;
	}
	else
		printf("fail to insert \n");
}
position find_position(list l, unsigned e)
{
	position p=l->next_node;
	while (NULL != p)
	{
		if (e == p->exponent)
			return p;
		p = p->next_node;
	}
	return NULL;
}
position find_above(list l, unsigned e)
{
	position p = l;
	if (NULL == p->next_node)
		return p;
	while (NULL != p->next_node)
	{
		if (e < p->next_node->exponent)
			p = p->next_node;
		else
			break;
	}
	return p;
}
//void delete_unit(position p)
//{
//	position temp;
//	temp = p->next_node;
//	p->next_node = temp->next_node;
//	free(temp);
//}
inline void add_unit(position p, position q)
{
	p->coefficient += q->coefficient;
}
bool is_equal(position p, position q)
{
	return p->exponent == q->exponent;
}
void add_to_list(list l, int coefficient, unsigned exponent)
{
	position temp;
	temp = find_above(l, exponent);
    if(NULL !=temp)
	insert_unit(temp, coefficient, exponent);
	else
        insert_unit(l,coefficient,exponent);
}
void add_list(list l, list buf)
{
	position p,temp;
	for (p = buf->next_node; NULL != p; p = p->next_node)
	{
		temp = find_position(l, p->exponent);
		if (NULL != temp)
		{
			add_unit(temp, p);
			if (0 == temp->coefficient)
				delete_unit(find_above(l, temp->exponent));
		}
		else
		{
			temp = find_above(l, p->exponent);
			add_to_list(l, p->coefficient, p->exponent);
		}
	}
}
void multi_unit(list result, position p,position q)
{
	int coefficient;
	unsigned exponent;
	coefficient  = p->coefficient * q->coefficient;
	exponent = p->exponent + q->exponent;
	add_to_list(result,coefficient,exponent);
}
void multi_list(list l, list m, list result)
{
	position p,q;
	list temp_list;
	temp_list = create_list();
	if (NULL != temp_list)
	{
		for (p = l->next_node; NULL != p; p=p->next_node)
		{
			for (q = m->next_node; NULL != q; q=q->next_node)
			{
				multi_unit(temp_list, p, q);
				
			}
			add_list(result, temp_list);
			delete_list(temp_list);

		}

		//for (p = m->next_node; NULL != p; p=p->next_node)
		//{
		//	for (q = l->next_node; NULL != q; q=q->next_node)
		//	{
		//		multi_unit(temp_list, q, p);
		//		
		//	}
		//	add_list(result, temp_list);
		//	delete_list(temp_list);
		//}
	}
	else
		printf("fail to create temp list");
}
void print_list(list l)
{
	position temp;
	for (temp = l->next_node; NULL != temp; temp = temp->next_node)
		printf("%d   %d  \n", temp->coefficient, temp->exponent);
}
