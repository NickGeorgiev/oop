// new.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<class T>
class Vector
{
private:
	T * start;
	int currSize;
	int capacity;
	void resize();
	void copy();
	void erase();
public:
	Vector();
	Vector& operator=(const Vector<T> &);
	Vector(const Vector &);
	~Vector();
};
template<class T>
Vector<T>::Vector():currSize(1),capacity(2),start(nullptr){}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template<class T>
Vector<T>::Vector(const Vector<T> &other)
{
	copy(other);
}

template<class T>
Vector<T>::~Vector()
{
	delete[]start;
}
template<class T>
void Vector<T>::copy()
{
	currSize = other.currSize;
	capacity = other.capacity;
	start = new T[capacity];
	for (int i = 0; i < currSize; i++)
	{
		*(start + i) = *(other.start + i);  //прекопира всечки елементи от масива като цикли от 0 до currSize
	}

}
template<class T>
void Vector<T>::erase()
{
	delete[]erase;
	currSize = 0;
	capacity = 0;
}

template<class T>
void Vector<T>::resize()
{
	if (size > capacity)
	{
		capacity *= 5;
	}
}
int main()
{
    return 0;
}

