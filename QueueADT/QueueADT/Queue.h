#pragma once
#ifndef QUEUE_H
#define QUEUE_H 

#include "LinkedList.h"



/*
  UML Notation
  +enqueue(entry : T) : bool
  +dequeue() : bool
  +empty() : bool
  +clear() : void
  +size() : int
  +front() : T
  +rear() : T
*/


template <class T>
class Queue : public LinkedList<T>
{
public:
	Queue();
	~Queue();
	bool enqueue(T entry);
	bool dequeue();
	bool empty();
	void clear();
	int size();  
	T front();
	T rear();


	//operator<<        
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr);
};


/*******************************
  Default Queue<T> constructor
********************************/        
template <class T>
Queue<T>::Queue()
{
	LinkedList<T>();

}


/*******************************
 Queue<T> destructor
********************************/

template <class T>
Queue<T>::~Queue()
{
	LinkedList<T>::clear();
}




/*******************************
  bool enqueue(T entry)
  inserts an entry onto the queue
********************************/
template <class T>
bool Queue<T>::enqueue(T entry)
{
	LinkedList<T>::addNode(entry);
	return true;
}

//dequeue
//remove an entry from the queue
template <class T>
bool Queue<T>::dequeue()
{
	LinkedList<T>::deleteNode(1);
	return true;
}

// empty        
// checks whether the queue is empty or not     
template <class T>
bool Queue<T>::empty()
{
	return LinkedList<T>::isEmpty();
}



// size         
template <class T>
int Queue<T>::size()
{
	return LinkedList<T>::getsize();
}


// clear          
template <class T>
void Queue<T>::clear()
{
	LinkedList<T>::clear();
}


//front
// returns the first element
template <class T>
T Queue<T>::front()
{
	return getData();
}

//rear
//returns the last value in the queue
template <class T>
T Queue<T>::rear()
{
	return getValue(getSize() - 1);
}

#endif
