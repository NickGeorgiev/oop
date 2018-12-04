// BTree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include<cassert>

template <class T>
struct Node
{
	T data;
	Node<T>*left;
	Node<T>*right;
	Node(const T &_data, Node<T>*_left, Node<T>*_right);
};
template <class T>
Node<T>::Node(const T &_data, Node<T>*_left=nullptr, Node<T>*_right=nullptr) :data(_data), left(_left), right(_right) {}

template <class T>
class BTree
{
	BTree();
	BTree(const BTree<T>&);
	BTree<T>& operator=(const BTree<T> &);
	~BTree();
	void insert(const T &, const char*);
	void insertBOT(Node<T> *&, const T &);
	void insertBOT(const T &);

private:
	Node<T>* root;
	void insertHelp(const T &, const char*, Node<T>*&);
	Node<T>* copy(Node<T>*);
	size_t count(const BTree<T>&);
	size_t countEvens(const BTree<T>&);
	int searchCount(bool(*pred)(const T & data), const BTree<T>&root);
	void deleteSubtree(Node<T> *);
	int height(Node<T> *);
	int countLeaves(Node<T> *);
	bool isLeaf(Node<T> *);
	T findMinBinary(Node<T>*);
	T findMinTree(Node<T>*);
	T findMinNode(Node<T>*);
	int sumLeaves(Node<T>*);
};
template <class T>
BTree<T>::BTree() :root(nullptr) {}
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
		root = copy(other);
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
		assert(trace[0] == 0);
		current = new Node<T>(x, nullptr, nullptr);
		return;
	}
	assert(trace[0] == 'L' || trace[0] == 'R');
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
size_t BTree<T>::count(const BTree<T>&root)
{
	if (root = nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + count(root->left) + count(root->right);
	}
}
template<class T>
size_t BTree<T>::countEvens(const BTree<T>&root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return ((root->data) % 2 == 0 ? 1 : 0) + countEvens(root->left) + countEvens(root->right);

}
template<class T>
int BTree<T>::searchCount(bool(*pred)(const T & data), const BTree<T>&root)
{
	if (root = nullptr)
	{
		return 0;
	}
	return (pred(data)) + searchCount(pred, root->left) + searchCount(pred, root->right);

}
template<class T>
int BTree<T>::height(Node<T> *root)
{
	if (root == nulptr)
	{
		return -1;
	}
	return 1 + std::max(height(root->left), height(root->right));
}
template<class T>
int BTree<T>::countLeaves(Node<T> *root)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (root->left = nullptr && root->right = nullptr)
	{
		return 1;
	}
	return countLeaves(root->left) + countLeaves(root->right);
}
template<class T>
bool BTree<T>::isLeaf(Node<T> *root)
{
	return (root->left = nullptr && root->right = nullptr);
}
template<class T>
T BTree<T>::findMinBinary(Node<T>*root)
{
	T min = root->data;
	if (root->left) {
		min = findMin(root->left);
	}
	return min;

}
template<class T>
T BTree<T>::findMinTree(Node<T>*root)//If it is not Binary tree
{
	T min = root->data;
	if (root->left) {
		T leftMin = findMin(root->left);
		if (min > leftMin)
		{
			min = leftMin;
		}
	}
	if (root->right) {
		T RightMin = findMin(root->right);
		if (min > RightMin)
		{
			min = RightMin;
		}
	}
	return min;

}
template<class T>
T BTree<T>::findMinNode(Node<T>*root)
{
	T min = root->data;
	if (isLeaf(root))
	{
		if (min > root->data)
			min = root->data;
		if (root->left)
			T minL = findMinNode(root->left);
		if (root->right)
			T minR = findMinNode(root->right);
	}
	if (minL > minR)
	{
		min = minL;
	}
	else min = minR;
	return min;
}
template <class T>
int BTree<T>::sumLeaves(Node<T>* root)
{
	if (root = nullptr)
	{
		return 0;
	}
	return ((!root->left && !root->right) ? 1 : 0 )+ sumLeaves(root->left) + sumLeaves(root->right);
}

template <class T>
void BTree<T>::insertBOT(Node<T> *&root, const T &x)
{
	if (root == nullptr)
	{
		root = new Node<T>(x, nullptr, nullptr);
		return;
	}

	if (x < root->data)
	{
		insertBOT(root->left, x);
	}
	else {
		insertBOT(root->right, x);
	}
}

template <class T>
void BTree<T>::insertBOT(const T &x)
{
	insertBOT(root, x);
}
int main()
{


	return 0;

}

