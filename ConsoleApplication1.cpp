// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <class T>
struct Node
{
	T data;
	Node<T>*left;
	Node<T>*right;
	Node(const T &_data, Node<T>*_left, Node<T>*_right);

};
template <class T>
Node<T>::Node(const T &_data, Node<T>*_left, Node<T>*_right):data(_data),left(_left),right(_right){}

template <class T>
class BTree
{
	BTree();
	BTree(const BTree<T>&);
	BTree<T>& operator=(const BTree<T> &);
	~BTree();
	void insert(const T &, const char*);
	Node<T>* copy(Node<T>*);
	size_t count(const BTree<T>&);
	size_t countEvens(const BTree<T>&);
	size_T searchCount(bool(*pred)(const T &));

private:
	Node<T>* root;
	void insertHelp(const T &, const char*,Node<T>*&);
};
template <class T>
BTree<T>::BTree():root(nullptr){}
template <class T>
Node<T>* BTree<T>::copy(Node<T>*other)
{
	if (other == nullptr)
	{
		return nullptr;
	}
	return new Node<T>(other->data, copy(other->left), copy(other->right));
}
template <class T>
void BTree<T>::deleteSubtree(Node<T> *other)
{
	if (other == nullptr)
	{
		return;
	}

	deleteSubtree(other->left);
	deleteSubtree(other->right);
	delete other;

}
template <class T>
BTree<T>::BTree(const BTree<T>&other)
{
	toot = copy(other);
}
template <class T>
BTree<T>& BTree<T>::operator=(const BTree<T> &other)
{
	if (this != &other)
	{
		deleteSubtree(other);
		root=copy(other);
	}
	return *this;
}
template <class T>
BTree<T>::~BTree()
{
	deleteSubtree(root);
}
template <class T>
void BTree<T>::insert(const T &x, const char*trace)
{
	insertHelp(x, trace, root);
}
template <class T>
void BTree<T>::insertHelp(const T &x, const char*trace, Node<T>*&curr)
{
	if (curr = nullptr)
	{
		assert(trace[0]== 0);
		current = new Node<T>(x, nullptr, nullptr);
		return;
	}
	assert(trace[0] =='L'|| trace[0] == 'R');
	if (trace[0] == 'L')
	{
		insertHelp(x, trace + 1, curr->left);
	}
	else
	{
		insertHelp(x, trace + 1, curr->right);
	}
}
template<class T>
size_t  BTree<T>::count(const BTree<T>&root)
{
	if (root = nullptr)
	{
		return 0;
	}
	else 
	{
		return 1 + count(root->left)+count(root->right);		
	}
}
template<class T>
size_t  BTree<T>::countEvens(const BTree<T>&root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return ((root->data) % 2 == 0 ? 1 : 0) + countEvens(root->left)+countEvens(root->right);

}
template<class T>
size_t BTree<T>::searchCount(bool(*pred)(const T & data))
{

}



int main()
{
	
    
}

