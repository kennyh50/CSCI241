/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 6
   PROGRAMMER: Kenneth Harris
   LOGON ID:   z1733721
   DUE DATE:   11/12/2018

   FUNCTION:   This program tests the functionality of the Queue
               template class.
*********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
using namespace std;
using std::ostream;
using std::istream;

template <class T>
class Queue;

template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);


private:
	T* queueArray;
	size_t queueCapacity,queueSize;
	int queueFront;
	int queueBack;

public:
	Queue();
	~Queue();
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void push(const T&);
	void pop();
	void reserve(size_t n);

};
/***************************************************************
Function: Queue
Use: Constructor. Sets the queue size and capacity to 0 and the 
queue array pointer to nullptr.  It initializes the front subscript
 to 0 and the back subscript is set to the queue capacity -1.
Parameters: No parameters
Returns: nothing
Notes: 
***************************************************************/ 
template <class T>
Queue<T>::Queue()
{
queueCapacity = 0;
queueSize = 0;
queueArray= nullptr;
queueFront = 0;
queueBack = queueCapacity - 1;
}

/***************************************************************
Method: ~Queue
Use: Destructor.  Deletes the the dynamic memeory for the queue 
array
Parameters: none
Returns: nothing
Notes:
***************************************************************/ 
template <class T>
Queue<T>::~Queue()
{
delete[] queueArray;
}

/***************************************************************
Mehtod: Copy Constructor
Use: copies the contents of the entire queue array
Parameters:
Returns:
Notes:
***************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& other)
{
queueArray = new T[other.queueCapacity];

for (size_t i = 0; i < other.queueCapacity; ++i)
	{
	queueArray[i] = other.queueArray[i];
	}
queueCapacity = other.queueCapacity;
queueSize = other.queueSize;
queueFront = other.queueFront;
queueBack = other.queueBack;
}


/***************************************************************
Mehtod: Copy Assignment Operator
Use:
Parameters:
Returns: object pointed to by this
Notes:
***************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
if(this != &other)
	{

	delete[] queueArray;

	queueSize = other.queueSize;
	queueCapacity = other.queueCapacity;
	queueFront = other.queueFront;
	queueBack = other.queueFront;

	queueArray = (queueCapacity == 0)? nullptr: new T[queueCapacity];
	copy(other.queueArray, other.queueArray + other.queueSize, queueArray);

	}

return *this;
}

/***************************************************************
Mehtod: clear
Use: sets the queue back to the empty state
Parameters: none
Returns: nothing
Notes:
***************************************************************/
template <class T>
void Queue<T>::clear()
{
queueSize = 0;
queueFront = 0;
queueBack = queueCapacity - 1;
}

/***************************************************************
Mehtod: size
Use:returns the queue Size
Parameters: none
Returns: queueSize
Notes:
***************************************************************/
template <class T>
size_t Queue<T>::size() const
{
return queueSize;
}

/***************************************************************
Mehtod: capacity
Use: Returns the queue capacity
Parameters:None
Returns: queueCapacity
Notes:
***************************************************************/
template <class T>
size_t Queue<T>::capacity() const
{
return queueCapacity;
}

/***************************************************************
Mehtod: empty
Use:Returns true if queue size is 0; otherwise it returns false.
Parameters: None
Returns: boolean value
Notes:
***************************************************************/
template <class T>
bool Queue<T>::empty() const
{
	return(queueSize == 0);
}

/***************************************************************
Mehtod: front
Use:
Parameters:
Returns:
Notes:
***************************************************************/
template <class T>
const T& Queue<T>::front() const
{
if(empty())
	{
	throw std::underflow_error("queue underflow on front()");
	}

return queueArray[queueFront];
}

/***************************************************************
Mehtod: back
Use: If the queue is empthy the method throws an underflow_error 
exception.  Otherwise it returns the back element of the queue array.
Parameters: none
Returns: reference to a constant item of the template parameter
Notes:
***************************************************************/
template <class T>
const T& Queue<T>::back() const
{
if(empty())
	{
	throw std::underflow_error("queue underflow on back()");
	}
return queueArray[queueBack];
}


/***************************************************************
Mehtod: push
Use: IF the queue is full reserve method is called to increase 
capacity of the queue array.  
Parameters: reference to a constant item of the template parameter type.
Returns: nothing
Notes:
***************************************************************/
template <class T>
void Queue<T>::push(const T& val)
{
if(queueSize == queueCapacity)
{
	if(queueCapacity == 0)
	{
		reserve(1);
	}

	else
	{
		reserve(queueCapacity * 2);
	}
}
	queueBack = (queueBack + 1) % queueCapacity;
	queueArray[queueBack] = val;
	++queueSize;
}

/***************************************************************
Mehtod: pop
Use: If the queue is empty, an underflow_error exception is thrown.  
Otherwise, the queue is incremented to effectively remove the front 
item in the queue array.  
Parameters: none
Returns:nothing
Notes:
***************************************************************/
template <class T>
void Queue<T>::pop()
{
if(empty())
	{
	throw std::underflow_error("queue underflow on pop()");
	}

queueFront = (queueFront + 1) % queueCapacity;
--queueSize;
}


/***************************************************************
Mehtod: reserve
Use: Reserves additional capacity for the queue array if it is at capacity.
Parameters: size_t n
Returns: Nothing
Notes:
***************************************************************/
template <class T>
void Queue<T>::reserve(size_t n)
{
if(n < queueSize || n == queueCapacity)
	{
	return;
	}

T* tempArray = new T[n];

int current = queueFront;
for(size_t i = 0; i < queueSize; ++i)
	{
	tempArray[i] = queueArray[current];
	current = (current + 1) % queueCapacity;
	}

queueCapacity = n;
queueFront = 0;
queueBack = queueSize - 1;
delete[] queueArray;
queueArray = tempArray;
}


/***************************************************************
Function: operator<< 
Use:
Parameters:
Returns: lhs
Notes:
***************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs)
{
for(size_t i = 0; i < rhs.queueSize; ++i)
{
	lhs << rhs.queueArray[i] << ' ';
}
	return lhs;
}

#endif
