// QueueADT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream> 
#include <string>
#include "Currency.h"
#include "Dollar.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Node.h"

using namespace std;


void intEnqueue(Queue<int> *intQptr);
void intDequeue(Queue<int> *intQptr);
void intQueueClear(Queue<int> *intQptr);
void stringEnqueue(Queue<string> *stringQptr);
void stringDequeue(Queue<string> *stringQptr);
void stringQueueClear(Queue<string> *stringQptr);
void currencyEnqueue(Queue<Currency> *currencyQptr);
void currencyDequeue(Queue<Currency> *currencyQptr);
void currencyClear(Queue<Currency> *currencyQptr);


Queue<int>intQueue;
Queue<string>stringQueue;
Queue<Currency>CurrencyQueue;


int main() {
	





	int choice = 0;
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
			<< "10. Exit Program" << endl
		    << "Selection number: ";

		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			choice = 0;
		}
		cout << endl;

		if (choice == 1) intEnqueue(&intQueue);
		else if (choice == 2) intDequeue(&intQueue);
		else if (choice == 3) intQueueClear(&intQueue);
		else if (choice == 4) stringEnqueue(&stringQueue);
		else if (choice == 5) stringDequeue(&stringQueue);
		else if (choice == 6) stringQueueClear(&stringQueue);
		else if (choice == 7) currencyEnqueue(&CurrencyQueue);
		else if (choice == 8) currencyDequeue(&CurrencyQueue);
		else if (choice == 9) currencyClear(&CurrencyQueue);
		else loopMenu = false;
	}


	return 0;
}





//intEnqueue
//enters an integer into the queue
void intEnqueue(Queue<int> *intQptr)
{
	int x;
	cout << "Enter a number to add to the queue: ";
	cin >> x;
	intQptr->enqueue(x);
	cout << "Queue items:" << endl << intQptr << endl;
}


//intDequeue         
//remove an entry from the queue
void intDequeue(Queue<int> *intQptr)
{
	if (intQptr->empty())
	{

		cout << "Queue is empty!" << endl;
	}
	else
	{
		intQptr->dequeue();
		cout << "Integer Queue:" << endl << intQptr << endl << endl;
	}
}


//ClearQueue           
//clears int queue
void intQueueClear(Queue<int> *intQptr)
{
	intQptr->clear();
	cout << "Queue contains:" << endl << intQptr << endl << endl;
}


//stringEnqueue
//enters a string to the queue;
//
void stringEnqueue(Queue<string>* stringQptr)
{
	string input;

	cout << "Enter a string to enqueue to the Queue ADT " << endl;
	cin >> input;
	while(! (cin)) {
		cin.clear();
		cout << "Invalid data type! Please enter string again." << endl;
	}
	
		stringQptr->enqueue(input);
	cout << "Queue string items:" << endl << stringQptr << endl << endl;
}


//stringDequeue              
//removes a string from the queue

void stringDequeue(Queue<string> *stringQptr)
{
	if (stringQptr->empty()) {
		cout << "Queue is empty!" << endl;
	}
	else
	{
		stringQptr->dequeue();
		cout << "Queue contains:" << endl << stringQptr << endl << endl;
	}
}

//stringQueueclear              
//Clears the string queue
void stringQueueClear(Queue<string> *stringQptr)
{
	stringQptr->clear();
	cout << "String Queue items:" << endl << stringQptr << endl << endl;
}


//currencyEnqueue      
//enters a currency to the queue
void currencyEnqueue(Queue<Currency> *currencyQptr)
{
	int dollars;
	int cents;

	cout << "Enter the amount of Dollars and cents " << endl;
	cin >> dollars >> cents;


	currencyQptr->enqueue(Dollar(dollars, cents));

	cout << "Queue currency contains:" << endl << currencyQptr << endl << endl;
}


//currencyDequeue      
//removes a currency object from the queue
void currencyDequeue(Queue<Currency> *currencyQptr)
{
	if (currencyQptr->empty())
	{
		cout << "Queue is empty!" << endl << endl;
	}
	else
	{
		currencyQptr->dequeue();
		cout << "Currency items:" << endl << currencyQptr << endl << endl;
	}
}




//currencyClear             
//clears the currency queue
void currencyClear(Queue<Currency> *currencyQptr)
{
	if (currencyQptr->isEmpty())
	{

		cout << "Queue is empty!" << endl;
	}
		
	currencyQptr->clear();
	cout << "Currency Queue items:" << endl << currencyQptr << endl << endl;
}



ostream& operator<< (ostream&out, Currency d) {
	out << "Dollar, " << d.whole << ", " << d.fraction << ", cents" << endl;
	return out;
}

template<class T>
ostream& operator<<(ostream&outputline, const Currency stackcurrency) {
	int position = 1;
	Node<T>* curr = currencyQptr->head;
	while (curr != nullptr) {
		outputline << position << ". " << curr->getData() << endl;
		curr = curr->getPtr();
		position++;
	}
	return outputline;
}






// operator<<        
template <class T>
ostream& operator<< (ostream &output, const LinkedList<T> *Qptr)
{
	int position = 1;
	Node<T>* curr = Qptr->head;
	while (curr != nullptr) {
		output << position << ". " << curr->getData() << endl;
		curr = curr->getPtr();
		position++;
	}
	return output;
}
	





template <class T>
ostream& operator<< (ostream &output, Queue<T> *Qptr)
{
	int position = 1;
	Node<T>* curr = Qptr->head;
	while (curr != nullptr) {
		output << position << ". " << curr->getData() << endl;
		curr = curr->getPtr();
		position++;
	}
	return output;
}


