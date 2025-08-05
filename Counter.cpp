#include <iostream>
using namespace std;

class Counter 
{
public:
	static int totalCreated;
	static int currentlyAlive;
	Counter()
	{
		++totalCreated;
		++currentlyAlive;
	}
	
	~Counter()
	{
		--currentlyAlive;
	}

	static int getTotalCreated()
	{
		return totalCreated;
	}

	static int getCurrentlyAlive()
	{
		return currentlyAlive;
	}
};

int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main()
{
	cout<<"Start:\n";
	cout<<"Total created: "<<Counter::getTotalCreated()<<endl;
	cout<<"Currently alive: "<<Counter::getCurrentlyAlive()<<endl;
	{
		Counter a, b;
		cout<<"\nAfter creating 2 objects:\n";
		cout<<"Total created: "<<Counter::getTotalCreated()<<endl;
		cout<<"Currently alive: "<<Counter::getCurrentlyAlive()<<endl;
		{
			Counter c;
			cout<<"\nAfter creating an object inside inner block:\n";
			cout<<"Total created: "<<Counter::getTotalCreated()<<endl;
			cout<<"Currently alive: "<<Counter::getCurrentlyAlive()<<endl;
		}
		cout<<"\nAfter c is destroyed:\n";
		cout<<"Total created: "<<Counter::getTotalCreated()<<endl;
		cout<<"Currently alive: "<<Counter::getCurrentlyAlive()<<endl;
	}
	cout<<"\nAfter all objects are destroyed:\n";
	cout<<"Total created: "<<Counter::getTotalCreated()<<endl;
	cout<<"Currently alive: "<<Counter::getCurrentlyAlive()<<endl;
	return 0;
}
