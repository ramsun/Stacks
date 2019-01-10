/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 272 - Machine Problem 4
Fall 2018

class.cpp

Implementation for class.h.  See comments on function definitions.
*/

#include "class.h"

//top of stack
template <typename T>
T StudentStack<T>::front() {
	return sDeque.front();
}

//bottom of stack
template <typename T>
T StudentStack<T>::back() {
	return sDeque.back();
}

//tell number of elements in stack
template <typename T>
int StudentStack<T>::size() {
	return sDeque.size();
}

//tell whether stack is empty or not
template <typename T>
bool StudentStack<T>::isEmpty() {
	return sDeque.empty();
}

//push to the front of the deque (top of stack)
template <typename T>
void StudentStack<T>::push(const T& val) {
	sDeque.push_front(val);
}

//remove from the front of the deque (top of the stack)
template <typename T>
void StudentStack<T>::pop() {
	if (!sDeque.empty()) sDeque.pop_front();
}

//potential types passed into the class
template class StudentStack<int>;
template class StudentStack<std::string>;
template class StudentStack<char>;
