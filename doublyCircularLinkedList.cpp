#include<iostream>
using namespace std;

class Node
{
	public :
		int data;
		Node *prev;
		Node *next; 
	Node(int val=0)
	{
		data=val;
		next=NULL;
	}
	
};

class Doubly
{
	public:
		Node *head;
		Node *tail;
		int totalNode;
	Doubly();
	~Doubly();
	bool insertFirst(int );
	bool insertLast(int);
	bool insertAt(int,int);
	int deleteFirst();
	int deleteLast();
	int deleteAt(int);
	void display();
};
Doubly::Doubly()
{
	head=tail=NULL;
	totalNode=0;
}

Doubly::~Doubly()
{
	cout<<"destructor"<<endl;
}
bool Doubly::insertFirst(int data)
{
	Node * newNode=new Node(data);
	if(newNode==NULL)
	{
		return false;
	}
	if(head!=NULL) //if list is empty
	{	
		newNode->next=head;
		head->prev=newNode;	//(newNode->next)->prev=newNode
		newNode->prev=tail;
		tail->next=newNode;
		head=newNode;
	}
	else
	{
		head=tail=newNode;
		head->prev=tail;
		tail->next=head;
	}
	totalNode++;
	return true;
}
bool Doubly::insertLast(int data)
{
	Node * newNode=new Node(data);
	if(newNode==NULL)
	{
		return false;	
	}
	if(tail==NULL && head==NULL)
	{
		head=tail=newNode;
	//	tail->next=head;
	//	head->prev=tail;
	}
	else
	{	
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	//	tail->next=head;
	//	head->prev=tail;
	}
	tail->next=head;
	head->prev=tail;
	totalNode++;
	return true;
}
bool Doubly::insertAt(int data,int pos)
{
	//filter
	if(pos<1 && pos>totalNode+1)
		return false;
	Node * newNode = new Node(data);
	if(pos==1)
		return insertFirst(data);
	else if(pos==totalNode+1)
		return insertLast(data);
	else
	{
		Node * navigate=head;
		while(pos>1)
		{
			pos--;
			navigate=navigate->next;
		}
		newNode->prev = navigate->prev;
		(newNode->prev)->next=newNode; //(navigate->prev)->next=newNode;
		newNode->next=navigate;
		navigate->prev=newNode;
	}
	totalNode++;
	return true;	
}
int Doubly::deleteFirst()
{
	int ret=-1;
	if(head==NULL || tail==NULL)
		ret = -1;	//error
	else if(head==tail)	//if it has only one node
	{
		ret=head->data;
		delete head;	//delete tail
		head=tail=NULL;
	}
	else
	{	Node * temp=head;
		head=head->next;
		tail->next=head;
		head->prev=tail;
		ret=temp->data;
		delete temp;
	}
	totalNode--;
	return ret;			
}
int Doubly::deleteLast()
{
	int ret=-1;
        if(head==NULL || tail==NULL)
                ret = -1;       //error 
        else if(head==tail)     //if it has only one node
        {       
                ret=head->data; 
                delete head;    //delete tail
                head=tail=NULL;
        }
        else    
	{
		Node* temp=tail;
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
	        ret=temp->data;
		delete temp;
	}
	totalNode--;
	return ret;
}
int Doubly::deleteAt(int pos)
{
	int ret=-1;
	//filter for pos
	if(pos<1 || pos > totalNode)
		return -1;
	else if(pos==1)
		ret=deleteFirst();
	else if(pos==totalNode)
		ret=deleteLast();
	else
	{
		cout<<"inside else"<<endl;
		Node * navigate=head;
		int i=1;
		while(i<pos)
		{
			navigate=navigate->next;
			i++;
		}
		cout<<i<<endl;
		(navigate->prev)->next=navigate->next;
		(navigate->next)->prev=navigate->prev;
		ret=navigate->data;
		delete navigate;
	}
	totalNode--;
	return ret;
}
void Doubly::display()
{
	if(head==NULL)
	{
		cout<<"List is empty"<<endl;
		return ;
	}
	do
	{
		cout<<"| "<<head->data<<" |<=>";
		head=head->next;
	}while(head!=tail->next);
	cout<<endl;
}
int main()
{
	Doubly dcl;
	dcl.insertFirst(10);
	dcl.insertFirst(20);
	dcl.display();
	dcl.insertLast(30);
	dcl.insertLast(40);
	dcl.display();
	dcl.insertAt(100,3);
	dcl.deleteFirst();
	dcl.display();
	cout<<dcl.deleteLast()<<endl;
	//cout<<dcl.deleteLast()<<endl;
	dcl.display();
	cout<<dcl.deleteAt(dcl.totalNode-1)<<endl;
	dcl.display();
	return 0;
} 
