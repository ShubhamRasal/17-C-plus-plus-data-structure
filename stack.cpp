#include<iostream>
using namespace std;
	
class Stack
{
	private:
		int top;
		int size;
	public:
		int *arr;
	Stack(int size=10)
	{
		arr=new int[size];
		top=-1;
		this->size=size;
	}
	~Stack()
	{
		delete[]arr;
	}
	bool push(int data);
	int pop();
	bool isEmpty();
};

bool Stack::push(int data)
{
	if(top==size-1)
	{
		std::cout<<"Overflow"<<endl;
		return false;
	}
	else
	{	
		arr[++top]=data;
		std::cout<<"element Inserted successfully"<<endl;
	}
	return true;
}
int Stack::pop()
{
	int ret=0;
	if(top<0)
	{	ret=-1;
		std::cout<<"Underflow"<<endl;
	}
	else
		ret=arr[top--];
	return ret;
}
bool Stack::isEmpty()
{
	return top < 0 ? true:false;
}	

int main()
{
	Stack s1(5);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);
	s1.push(70);
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	
return 0;
}
	






