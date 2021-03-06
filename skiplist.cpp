// skiplist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <iostream>

template <class T>
struct slnode
{
	T data;
	slnode *next[2];
	slnode(const T&, slnode*, slnode*);
};

template <class T>
class SListIterator;

template <class T>
class SList
{
public:
	SList();
	SList(const SList<T> &other);
	SList& operator= (const SList<T> &other);

	void push(const T&);

	size_t size();

	SListIterator<T> begin();
	SListIterator<T> find(const T&);
	SListIterator<T> end();

	friend class SListIterator<T>;

	void printDotty(std::ostream&);

	~SList();
	void print() const {
		slnode<T>* crr = first;
		while (crr) {
			std::cout << crr->data << " ";
			crr = crr->next[0];
		}
	}
private:
	slnode<T> *first, *last;
	size_t crrsize;
	size_t skipLength;

	void copy(const SList<T> &other);
	void erase();

	void optimize();
};


template <class T>
class SListIterator
{
public:
	SListIterator(SList<T>&, bool = false);
	T& operator * ();
	SListIterator<T>& operator ++ ();

	bool operator != (const SListIterator<T>&);
	bool operator == (const SListIterator<T>&);

private:
	SList<T> &list;
	slnode<T> *currentElement;
};

template <class T>
slnode<T>::slnode(const T &_data, slnode *_next, slnode *_skip)
	:data(_data)
{
	next[0] = _next;
	next[1] = _skip;
}

template <class T>
SList<T>::SList()
{
	first = last = nullptr;
	crrsize = 0;
	skipLength = 0;
}

template <class T>
SList<T>::SList(const SList<T> &other)
{
	copy(other);
}

template <class T>
SList<T>& SList<T>::operator= (const SList<T> &other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template <class T>
void SList<T>::push(const T&x)
{
	first = new slnode<T>(x, first, nullptr);
	if (last == nullptr)
	{
		last = first;
	}

	crrsize++;
	if (((int)sqrt(crrsize)) > skipLength)
	{
		optimize();
	}


}
template <class T>
size_t SList<T>::size()
{
	return crrsize;
}

template <class T>
SListIterator<T> SList<T>::begin()
{
	return SListIterator<T>(*this);
}
template <class T>
SListIterator<T> SList<T>::find(const T&)
{
	return end();
}
template <class T>
SListIterator<T> SList<T>::end()
{
	return SListIterator<T>(*this, true);

}
template <class T>
SList<T>::~SList()
{
	erase();
}

template <class T>
void SList<T>::copy(const SList<T> &other)
{
	first = last = nullptr;
	if (other.first) {
		slnode<T>* crr = other.first;
		while (crr) {
			slnode<T>* newElement = new slnode<T>(crr->data, nullptr, nullptr);
			if (!first) {
				first = newElement;
					last = first;
			}
			else {
				last->next[0] = newElement;
				last = last->next[0];
			}
			crrsize++;
			crr = crr->next[0];
		}
	}
	if (first) {
		optimize();
	}
}

template <class T>
void SList<T>::erase()
{
	while (first)
	{
		node<T>*curr = first;
		first = last = nullptr;
		delete curr;
	}
	first = last;
}

template <class T>
void SList<T>::optimize()
{
	skipLength = sqrt(crrsize);

	slnode<T> *crr = first,
		*lastFoundSkipElement = first;
	size_t index = 0;

	while (crr != nullptr)
	{
		crr->next[1] = nullptr;
		if ((index > 0 && index % skipLength == 0) ||
			crr->next[0] == nullptr
			)
		{
			lastFoundSkipElement->next[1] = crr;
			lastFoundSkipElement = crr;
		}
		crr = crr->next[0];
		index++;
	}
}


template <class T>
SListIterator<T>::SListIterator(SList<T> &_list, bool end)
	:list(_list)
{
	if (end)
	{
		currentElement = nullptr;
	}
	else {
		currentElement = list.first;
	}
}

template <class T>
void SList<T>::printDotty(std::ostream &out)
{
	slnode<T> *crr = first;
	out << "digraph G{\n";

	while (crr != nullptr)
	{
		out << (long)crr << "[label=\"" << crr->data << "\"];\n";

		if (crr->next[0] != nullptr)
		{
			out << (long)crr
				<< "->"
				<< (long)(crr->next[0])
				<< ";\n";
		}

		if (crr->next[1] != nullptr)
		{
			out << (long)crr
				<< "->"
				<< (long)(crr->next[1])
				<< ";\n";
		}

		crr = crr->next[0];
	}

	out << "}";

}


template <class T>
T& SListIterator<T>::operator * ()
{
	assert(currentElement != nullptr);
	return currentElement->data;
}

template <class T>
SListIterator<T>& SListIterator<T>::operator ++ ()
{
	assert(currentElement != nullptr);
	currentElement = currentElement->next[0];
	return *this;
}

template <class T>
bool SListIterator<T>::operator != (const SListIterator<T> &other)
{
	return currentElement != other.currentElement;
}

template <class T>
bool SListIterator<T>::operator == (const SListIterator<T> &other)
{
	return currentElement == other.currentElement;
}


int main()
{
	return 0;
}

