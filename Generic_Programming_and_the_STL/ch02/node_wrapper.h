#include <iostream>
template<class Node>
struct node_wrap {
	Node* ptr;
	node_wrap(Node* p) : ptr = p{}
	Node& operator*() const { return *ptr; }
	Node* operator->() const { return ptr; }
	node_wrap& operator++() { ptr = prt->next; return *this; }
	node_wrap& operator++(int n)
	{
		node_wrap* tmp = *this;
		for (int i = 0; i < n; i++)
			tmp++;
		return tmp;
	}
	bool operator==(const node_wrap& i) const { return ptr == i.ptr; }
	bool operator!=(const node_wrap& i) const { return ptr != i.ptr; }
};

