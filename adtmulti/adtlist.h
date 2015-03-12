#ifndef ADTLIST_H_INCLUDED
#define ADTLIST_H_INCLUDED

/************************************************************************!
* \file
* \brief ¸ÅÊö
*
*ÏêÏ¸¸ÅÊö
*
* \author  Vincent,vicentcj@163.com
* \version V
* \date
*************************************************************************/
typedef struct node{
	int coefficient;
	unsigned exponent;
	node * next_node;
}NODE, *ptr_node;
typedef ptr_node position;
typedef ptr_node list;

void push_front(list l, int c, unsigned  e);
void push_back(list l, position p, int c, unsigned e);
position create_list(void);
void insert_unit(position p, int c, unsigned e);
position find_position(list l, unsigned e);
position find_above(list l, unsigned e);
void delete_unit(position p);
inline void add_unit(position p, position q);
void add_to_list(list l, int coefficient, unsigned exponent);
void add_list(list l, list buf);
void multi_unit(list result, position p, position q);
void multi_list(list l, list m, list result);
void print_list(list l);
void delete_list(list l);

#endif // ADTLIST_H_INCLUDED
