/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 7
   PROGRAMMER: Kenneth Harris
   LOGON ID:   z1733721
   DUE DATE:   11/20/2018

   FUNCTION:   
*********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
using std::ostream;

template<class T>
struct Node
{

	T data;
	Node<T>* next;

	Node(const T& = T(), Node<T>* next = nullptr);
};

template<class T>
Node<T>::Node(const T& data, Node* next)
{
	this->data = data;
	this->next = next;
}

template<class T>
class Stack;

template<class T>
std::ostream& operator<<(std::ostream&, const Stack<T>& other);

template<class T>
class Stack
{
friend std::ostream& operator<< <>(std::ostream& lhs, const Stack<T>& rhs);

private:
        size_t stkSize;
        Node<T>* stkTop;

public:
	Stack();
	~Stack();
	Stack(const Stack<T>& other);
	Stack<T>& operator=(const Stack<T>& other);
	void clear();
	size_t size() const;
	bool empty() const;
	const T& top() const;
	void push(const T& val);
	void pop();
	void copyList(const Stack<T>& other);


};

/***************************************************************
Method: Stack()
Use: Constructor - Sets the stack to the initial empty state.
Parameters: None
Returns: Nothing
Notes:
***************************************************************/ 
template<class T>
Stack<T>::Stack()
{
	stkTop = nullptr;
	stkSize = 0;

}


/***************************************************************
Method:~Stack()
Use: Destructor - Sets the stack back to its empty state.
Parameters:None
Returns: Nothing
Notes:
***************************************************************/
template<class T>
Stack<T>::~Stack()
{
	clear();
}


/***************************************************************
Method: Stack(const Stack&)
Use: Copy constructor - Copies the contents of the stack array.
Parameters: constant reference to the stack class.
Returns: Nothing
Notes: incomplete
***************************************************************/
template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
	stkTop = nullptr;

	copyList(other);

	stkSize = other.stkSize;
}


/***************************************************************
Method:Stack<T>& operator=(const Stack<T>&)
Use:
Parameters: constant reference to the stack template class
Returns: object pointed to by this
Notes:
***************************************************************/
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
if(this != &other)
	{
	clear();

	copyList(other);

	stkSize = other.stkSize;
	}

return *this;
}

/***************************************************************
Method: clear()
Use: sets the stack back to the empty state
Parameters: none
Returns: nothing
Notes:
***************************************************************/
template<class T>
void Stack<T>::clear()
{
while(stkSize != 0)
	{
	pop();
	}
}


/***************************************************************
Method: size()
Use: Returns the stack size
Parameters: none
Returns: stkSize
Notes:
***************************************************************/
template<class T>
size_t Stack<T>::size() const
{
	return stkSize;
}

/***************************************************************
Method: empty()
Use: returns true if the stack size is 0; otherwise it returns false.
Parameters: None
Returns: boolean value
Notes:
***************************************************************/
template<class T>
bool Stack<T>::empty() const
{
	return(stkSize == 0);
}

/***************************************************************
Method: top()
Use: Returns the top item of the stack
Parameters: none
Returns: Top item of the stack
Notes:
***************************************************************/
template<class T>
const T& Stack<T>::top() const
{
if(empty())
        {
        throw std::underflow_error("stack underflow on top()");
        }


return stkTop->data;
}

/***************************************************************
Method: push
Use: Inserts the item at the top of the stack.
Parameters: Reference to a constant item of the template parameter
Returns: Nothing
Notes:
***************************************************************/
template<class T>
void Stack<T>::push(const T& val)
{
	Node<T>* newNode = new Node<T>(val, stkTop);

	stkTop = newNode;
	++stkSize;
}

/***************************************************************
Method: pop()
Use: Removes the node at the top of the stack. Called when the
stack is empty.
Parameters: None
Returns: Nothing
Notes:
***************************************************************/
template<class T>
void Stack<T>::pop()
{
if(empty())
        {
        throw std::underflow_error("stack underflow on pop()");
        }

Node<T>* delNode = stkTop;
stkTop = stkTop->next;

delete delNode;
--stkSize;
}

/***************************************************************
Method: copyList
Use: Copies the linked list from other
Parameters: constant reference to an object of the Stack template 
class
Returns: Nothing
Notes:
***************************************************************/
template<class T>
void Stack<T>::copyList(const Stack<T>& other)
   {
   Node<T>* ptr, * newNode, * last = nullptr;
 
   for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
      {
      newNode = new Node<T>(ptr->data);

      if (last == nullptr)
         stkTop = newNode;
      else
         last->next = newNode;

      last = newNode;
      }
   }


/***************************************************************
Function: operator<< <>
Use:
Parameters: lhs and rhs
Returns: lhs
Notes:
***************************************************************/
template<class T>
std::ostream& operator<< (std::ostream& lhs, const Stack<T>& rhs)
{
Node<T>* ptr;

for(ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
	lhs << ptr->data << ' ';

return lhs;
}


#endif
