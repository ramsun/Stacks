/*
Ramamurthy Sundar
class.h

A definition of the stack data structure.  The stack uses a deque in the backend.  
*/

#pragma once
#include <deque>
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class StudentStack
{
private:
	std::deque<T> sDeque;

public:
	StudentStack() {};
	void push(const T& val);
	void pop();
	T front();
	T back();
	int size();
	bool isEmpty();
};

