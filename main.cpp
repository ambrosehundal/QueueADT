/*
Ambrose Hundal
Stephen Lee
CIS 22C
Winter 18

Lab 2b- QueueADT

*/



#include <iostream>
#include "Queue.h"
#include "List.h"
#include "Currency.h"
#include "Dollar.h"

using namespace std;


void intEnqueue(); 
void intDequeue();
void intQueueClear();
void stringEnqueue();
void stringDequeue();
void stringClear();
void currencyEnqueue();
void currencyDequeue();
void currencyClear();





int main(){
Queue<int>intQueue;
Queue<string>stringQueue;
Queue<Currency>CurrencyQueue;

	cout << "Welcome to Queue ADT implementation. ";
	bool loopMenu = true;
	while (loopMenu)
	{
		cout << "Please choose an operation from the options listed below:" << endl
			<< "1. Enqueue an integer to the queue" << endl
			<< "2. Dequeue an integer from the queue" << endl
			<< "3. Clear integer queue" << endl
			<< "4. Enqueue a string to the string queue." << endl
			<< "5. Dequeue an entry from string queue" << endl
			<< "6. Clear the string queue" << endl
			<< "7. Enqueue a currenry to queue" << endl
			<< "8. Dequeue an entry from currency queue" << endl
			<< "9. Clear the Currency queue" << endl
			<< "10. Exit Program" << endl;
		
		cin >> choice;
		if (cin.fail ())
		{
			cin.clear (); 
			choice = 0;
		}
		cout << endl;
			
			if (choice == 1) intEnqueue();
			else if (choice == 2) intDequeue();
			else if (choice == 3) intQueueClear();
			else if (choice == 4) stringEnqueue();
			else if (choice == 5) stringDequeue();
			else if (choice == 6) stringClear();
			else if (choice == 7) currencyEnqueue();
			else if (choice == 8) currencyDequeue();
			else if (choice == 9) currencyClear();
			else if (choice == 10) loopActive = false;
		}
	}
}

  
      

//intEnqueue
//enters an integer into the queue
void intEnqueue ()
{
 int x;
  cout << "Enter a number to add to the queue: ";
  cin >> x;
	intQueue->enqueue(x);
	cout << "Queue items:" << endl << intQueue << endl;
}


//intDequeue         
//remove an entry from the queue
void intDequeue ()
{
	if (intQueue->empty ())
	{
		
		cout << "Queue is empty!" << endl;
	}
	else
	{
		intQueue->dequeue();
		cout << "Integer Queue:" << endl << intQueue << endl << endl;
	}
}


//ClearQueue           
//clears int queue
void ClearintQueue ()
{
	intQueue->clear ();
	cout << "Queue contains:" << endl << intQueue << endl << endl;
}


//stringEnqueue
//
void stringEnqueue()
{
	string buffer;
	ifstream read_input_file ("demo.txt");

	cout << "Adding \"demo.txt\" contents to queue:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		stringQueue->enqueue(buffer);
	}
	read_input_file.close ();
	cout << "Queue string items:" << endl << stringQueue << endl << endl;
}


//stringDequeue              
//removes a string from the queue

void stringDequeue()
{
	if (stringDequeue->empty ())	{
  cout << "Queue is empty!" << endl;
	}
	else
	{
		stringQueue->dequeue ();
		cout << "Queue contains:" << endl << stringQueue << endl << endl;
	}
}

//stringQueueclear              
// Clears the string queue
void stringQueueClear ()
{
	stringQueue->clear ();
	cout << "string stack items:" << endl << stackString << endl << endl;
}


//currencyEnqueue      
//enters a currency to the queue
void currencyEnqueue()
{
	
 currencyQueue->enqueue(Dollar(3, 35));
	
	cout << "Queue currency contains:" << endl << CurrencyQueue << endl << endl;
}


//currencyDequeue      
//removes a currency object from the queue
void currencyDequeue ()
{
	if (currencyQueue->empty ())
	{
		cout << "Queue is empty!" << endl << endl;
	}
	else
	{
		currencyQueue->dequeue();
		cout << "Currency items:" << endl << currencyQueue << endl << endl;
	}
}




//currencyClear             
//clears the currency queue
currencyClear()
{
	currencyQueue->clear ();
	cout << "Currency iters:" << endl << currencyQueue << endl << endl;
}




// operator<<        
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	
	int itemCount = 0;
	if (ListPtr->empty ()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail ();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << currPtr->value << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}
template <class T>
std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr)
{
	// Since operator<< is a friend of the List class, we can access
	// it's members directly.
	int itemCount = 0;
	if (ListPtr->empty ()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail ();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << currPtr->value << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}










}
