// adtmulti.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"
#include "adtlist.h"


int _tmain(int argc, _TCHAR* argv[])
{
	list l,m,result;
	l = create_list();
	result =create_list();
	add_to_list(l, 3, 5);
	add_to_list(l, 3, 1);
	//add_to_list(l, 5, 4);
	//add_to_list(l, 5, 7);
	m = create_list();
	add_to_list(m, -1, 5);
	add_to_list(m, -1, 3);
	//add_to_list(m, -1, 1);
	//add_list(l, m);
	multi_list(l, m, result);
	//delete_list(l);
	//print_list(l);
	print_list(result);
	return 0;
}

