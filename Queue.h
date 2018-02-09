
#ifndef QUEUE_H
#define QUEUE_H


#include "LinkedList.h"
#include "Node.h"


#add UML notation here

template <class T>
class Queue : protected LinkedList <T>
{


public:
	// default constructor
	Queue()
	{
		LinkedList::LinkedList();
	}

	
	Queue(const Queue<T>& q)
	{
		LinkedList::LinkedList(q);
	}



	//functions
  //return value at front of queue
	T checkFront()
	{
		return LinkedList::getValue(1);
	}

	//return value at rear of queue
	T checkRear()
	{
		return LinkedList::getValue(getLength());
	}
  
  //remove a value from the queue
  	bool dequeue(){
    
		return remove();
	}

  
  
	//check if queue is empty or not
	bool isEmpty()
	{
  return LinkedList::isEmpty();
	}

	//gives queue length
	int getLength() const
	{
		return LinkedList::getLength();
	}

	//Add an entry to queue
	bool enqueue();
	



	

	
};

