#include<iostream>
using namespace std;

class CircularQueue
{
	int front;	//dequeue
	int rear;	//enqueue
	int size;
	int *arr;
	
	public:
		CircularQueue(int size=10)
		{
			front=rear=-1;
			this->size=size;
			arr = new int[size];
		}
		~CircularQueue()
		{
			delete[]arr;
		}
	bool isEmpty();
	bool enqueue(int data);
	int dequeue();
	void display();
	bool isFull();
};

bool CircularQueue::isEmpty()
{
	if(front==-1)
		return true;
	else
		return false;
}
bool CircularQueue::isFull()
{
	if((front==0 && rear==size-1)||(rear==front-1))
		return true;
	else
		return false;
}

bool CircularQueue::enqueue(int data)
{
	//check list is full or not
	if(isFull())
	{
		std::cout<<"Oops,Queue is Full!"<<endl;
		return false;
	}
	else 
	{
		rear=(int)(rear+1)%size;	//(-1+1)%5 ==0 typecast needed otherwise floatingpoint exception
		if(front==-1)
			front=rear;
		arr[rear]=data;
	}
	//cout<<"element added successfully :"<<arr[rear]<<"\t:"<<rear<<endl;
	return true;
}
int CircularQueue::dequeue()
{
	int ret=-1;
	if(isEmpty())
	{
		std::cout<<"Oops,Queue is Empty"<<endl;
		return ret=-1;
	}
	else
	{
		ret=arr[front];
		if(front==rear)	//if only node
		{
			front=rear=-1;
		}
		else
		{
			front=(int)(front+1)%size;
		}	
	}
	return ret;
}
void CircularQueue::display()
{	
	cout<<"Queue:"<<endl;
	if(isEmpty()==false)  //if queue is not empty
	{	int i=0;
		for(i=front;i!=rear;i=(int)(i+1)%size)
		{
			std::cout<<arr[i]<<endl;
		}
		std::cout<<arr[i]<<endl;
	}
	else
	{
		std::cout<<"Queue is empty"<<endl;
	}
}
int main()
{
	CircularQueue q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.display();
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;	
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	return 0;
}


	
