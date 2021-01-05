#include <iostream>
#include "MyStack.h"
using namespace std;
template <class Stack_entry>
MyStack<Stack_entry>::MyStack()
/*Pre: None.
Post: The stack is initialized to be empty.*/
{
	count = 0;
}
template <class Stack_entry>
bool MyStack<Stack_entry>::empty() const
/*Pre: None.
Post: if the stack is empty, true is returned. Ohterwise
false is returned.*/
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::push(const Stack_entry &item)
/*Pre: None.
Post: if the stack is not full, item is added to the top
of the stack. Ohterwise an error code of overflow is returned
and the stack is left unchanged.*/
{
	Error_code outcome = success;
	if (count >= maxstack) outcome = overflow;
	else entry[count++] = item;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::pop()
/*Pre: None.
Post: If the stack is not empty, the top of the stack is
removed. If the stack is empty, an Error code of underflow
is returned.*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else --count;
	return outcome;
}
template <class Stack_entry>
Error_code MyStack<Stack_entry>::top(Stack_entry &item) const
/*Pre: None.
Post: if the stack is not empty, the top of the stack
is returned in item. if the stack is empty, an error code
of underflow is returned.*/
{
	Error_code outcome = success;
	if (count == 0) outcome = underflow;
	else item = entry[count - 1];
	return outcome;
}
template <class Stack_entry>
Stack_entry MyStack<Stack_entry>::top()const//重载top函数以适应不同的需要
{
	if (count == 0) underflow;
	return entry[count - 1];
}
template <class Stack_entry>
void MyStack<Stack_entry>::setnull()
{
	count = 0;//与构造实现是一致的
}