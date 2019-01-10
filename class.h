/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 272 - Machine Problem 4
Fall 2018

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

