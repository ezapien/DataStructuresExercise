// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T> class simpleList
{
	template <class T> class node {
	public:
		T _value;
		node<T>* _next;

		node(T value, node<T>* next)
		{
			_value = value;
			_next = next;
		}
	};

	node<T>*_head = NULL;
	unsigned _size = 0;

public:

	simpleList()
	{
	}

	simpleList(T a)
	{
		_head = new node<T>(a, NULL);
		_size = 1;
	}

	bool append(T a)
	{
		node<T> *e = new node<T>(a, NULL);

		if (!_head)
			_head = e;
		else {
			node<T>* ptr = _head;
			while (ptr->_next)
				ptr = ptr->_next;
			ptr->_next = e;
		}
		_size++;
		return true;
	}

	bool insert(T a)
	{
		node<T> *e = new node<T>(a, _head);
		_head = e;
		_size++;
		return true;
	}

	void remove(unsigned i)
	{
		if (i >= size())
			throw std::out_of_range("Index out of range");

		node<T>* ptr = _head, *oldptr;

		if (i == 0) {
			_head = _head->_next;
			delete ptr;
		}
		else {
			while (--i)
			{
				ptr = ptr->_next;
			}
			oldptr = ptr->_next;
			ptr->_next = ptr->_next->_next;
			delete oldptr;
		}
		_size--;
	}

	unsigned size() const
	{
		return _size;
		/*unsigned result = 0;
		node<T>* ptr = _head;
		while (ptr) {
		result++;
		ptr = ptr->_next;
		}
		return result;*/
	}

	T & get(unsigned i) const
	{
		if (i >= size())
			throw std::out_of_range("Index out of range");
		node<T>* ptr = _head;
		while (i)
		{
			ptr = ptr->_next;
			i--;
		}
		return ptr->_value;
	}

	T & operator [](unsigned i) const
	{
		return get(i);
	}

	void removeAll()
	{
		node<T> *ptr = _head;
		while (ptr) {
			node<T> *oldptr = ptr;
			ptr = ptr->_next;
			delete oldptr;
		}
		_head = NULL;
		_size = 0;
	}

	~simpleList()
	{
		removeAll();
	}

	node<T> *tail()
	{
		node<T> *ptr = _head;
		while (ptr->_next) {
			ptr = ptr->_next;
		}
		return ptr;
	}

	void mergesort(node<T> *start, node<T> *finish)
	{

	}

	void sort()
	{
		mergesort(_head, tail());
	}
};

int main()
{
	printf("%s", "hello again\n");
	simpleList<int> l;


	for (unsigned i = 0; i < 1000000; i++) {
		l.insert(rand());
	}

	for (unsigned i = 0; i < 1000000; i++) {
		l.remove(rand() % l.size());
	}

	unsigned max = l.size();

	for (unsigned i = 0; i < max; i++) {
		printf("%u\n", l[0]);
		l.remove(0);
	}
	return 0;
}

