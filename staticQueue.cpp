#include<iostream>
using namespace std;

class Queue
{
	int front;
	int last;	//rear
	int size;
	int * arr;

	public:
		Queue(int size=10)
		{
			this->size=size;
			front=last=-1;
			arr=new int(size);
		}
	bool isEmpty();
	int peek();
	bool enqueue(int data);
	int dequeue();
};

bool Queue::isEmpty()
{
	return last==-1;
}

int Queue::peek()
{
	return arr[last];
}
bool Queue::enqueue(int data)
{
	if(last==size-1)
		return false;
	else
	{
		arr[++last]=data;
	}
	return true;
}
int Queue::dequeue()
{
	if(!isEmpty())
		return arr[++front];
	else
		return -1;
}
int main()
{
	Queue q(3);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);	
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
}
