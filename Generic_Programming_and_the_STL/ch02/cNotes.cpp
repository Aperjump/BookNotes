#include <iostream>
#include "node_wrapper.h"
/**
链表的简单实现方式
author : aperion_wang
**/
// 设置链表长度
#define NUM 10

struct int_node{
	int val = 0;
	int_node* next;
};

// template<class Node>
// bool find(node_wrap<Node>(head), node_wrap<Node>(), node_wrap val)
int main()
{
	using namespace std;
	int_node* initialnode = new int_node;
	int_node* iter = initialnode;
	for (int i = 0; i < NUM; i++)
	{
		iter->val = i * 12;
		iter->next = new int_node;
		iter = iter->next;
	}
	
	int_node* iterprint = initialnode;
	for (int i = 0; i < NUM; i++)
	{
		cout << iterprint->val << "\t";
		iterprint = iterprint->next;
	}
	cout << "\nNormal implementation" << endl;
	for (int_node* p = initialnode; p != NULL; p = p->next)
	{
		cout << p->val << "\t";
	}
	cout << endl;
}


