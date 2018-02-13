
Ambrose Hundal
Stephen Lee
CIS 22C
Winter 18
Lab 2b- QueueADT
*/



#include <iostream>
#include <string>
#include "Currency.h"
#include "Dollar.h"
#include "List.h"
#include "Queue.h"


using namespace std;


void intEnqueue(Queue<int> *intQptr);
void intDequeue(Queue<int> *intQptr);
void intQueueClear(Queue<int> *intQptr);
void stringEnqueue(Queue<string> *stringQptr);
void stringDequeue(Queue<string> *stringQptr);
void stringClear(Queue<string> *stringQptr);
void currencyEnqueue(Queue<Currency> *currencyQptr);
void currencyDequeue(Queue<Currency> *currencyQptr);
void currencyClear(Queue<Currency> *currencyQptr);





int main() {
	Queue<int>intQueue;
	Queue<string>stringQueue;
	Queue<Currency>CurrencyQueue;

	



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
			<< "10. Exit Program" << endl;

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
		else if (choice == 6) stringClear(&stringQueue);
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
void ClearintQueue(Queue<int> *intQptr)
{
	intQptr->clear();
	cout << "Queue contains:" << endl << intQptr << endl << endl;
}


//stringEnqueue
//
void stringEnqueue()
{
	string buffer;
	ifstream read_input_file("demo.txt");

	cout << "Adding \"demo.txt\" contents to queue:" << endl;
	while (true)
	{
		read_input_file >> buffer;
		if (!read_input_file) break;
		stringQueue->enqueue(buffer);
	}
	read_input_file.close();
	cout << "Queue string items:" << endl << stringQptr << endl << endl;
}


//stringDequeue              
//removes a string from the queue

void stringDequeue((Queue<string> *stringQptr)
{
	if (*stringQptr->empty()) {
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
void stringQueueClear()
{
	stringQueue->clear();
	cout << "string stack items:" << endl << stringQptr << endl << endl;
}


//currencyEnqueue      
//enters a currency to the queue
void currencyEnqueue()
{

	currencyQueue->enqueue(Dollar(3, 35));

	cout << "Queue currency contains:" << endl << CurrencyQptr << endl << endl;
}


//currencyDequeue      
//removes a currency object from the queue
void currencyDequeue()
{
	if (currencyQueue->empty())
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
void currencyClear()
{
	currencyQueue->clear();
	cout << "Currency items:" << endl << currencyQueue << endl << endl;
}




// operator<<        
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{

	int itemCount = 0;
	if (ListPtr->empty()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail();
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
	
	int itemCount = 0;
	if (ListPtr->empty()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << currPtr->value << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}






