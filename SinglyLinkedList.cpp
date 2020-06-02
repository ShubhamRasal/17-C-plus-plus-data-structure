#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node * next;
	Node(int val=0)
	{
		data=val;
		next=NULL;
	}

};
class SinglyLinkedList
{	
	public:
		Node * head;
		int totalNode;
	public:
		SinglyLinkedList()
		{
			totalNode=0;
			head=NULL;
		}
		SinglyLinkedList(SinglyLinkedList & ref)
		{
	
			if(ref.head!=NULL)
			{
				Node *navigate_ref=ref.head;
				Node * navigate_this=NULL;
				while(navigate_ref!=NULL)
				{
					Node *newNode = new Node(navigate_ref->data);
					if(this->head==NULL)
					{
						head=newNode;
						navigate_this=head;
					}
					else
					{
						navigate_this->next=newNode;
						navigate_this=navigate_this->next;
					}
				navigate_ref=navigate_ref->next;
				}
							
			}
		
		}
		~SinglyLinkedList()
		{
			cout<<"destructor"<<endl;
			Node *navigate=head,*temp;
			while(navigate!=NULL)  // if head is not null and while till we dont reach the end of list
			{
				temp=navigate->next;
				delete navigate;
				navigate=temp;
			}
		}
		
		bool insertFirst(int data);
		bool insertLast(int data);
		bool insertAtPosition(int data,int pos);
		void display();
		int searchFirstOccurance(int);
		int deleteFirst();
		int deleteLast();
		int deleteAtPosition(int pos);
};

bool SinglyLinkedList::insertFirst(int data)
{
	Node *newNode = new Node(data);
	if(newNode==NULL)	//if we dont get memory
		return false;

	if(head!=NULL)	//if list is not empty
	{
		newNode->next=head;	//// if list is not empty then put node first and head to that node
	}
	
	//now put head to the next node
	head=newNode;
	
	totalNode++;
	return true;
}
bool SinglyLinkedList::insertLast(int data)
{
	Node *newNode = new Node(data);
	if(newNode==NULL)	// if dont get memory
		return false;

	// check if list is empty 
	if(head==NULL){
		head=newNode;
	}
	else
	{
		Node * navigate=head;
		
		//traverse till we reach the last node of list
		while(navigate->next!=NULL)
			navigate=navigate->next;
	
		//navigate is at last node so insert node next to it
		navigate->next=newNode;
	}
	totalNode++;
	return true;	
}
bool SinglyLinkedList::insertAtPosition(int data,int pos)
{
	//filter	
	if(head==NULL || pos>totalNode+1 || pos<=0)
                return false;

	Node * newNode = new Node(data);
	if(newNode==NULL)	//if dont get memory
	{
		return false;
	}
	if(pos == 1)
	{
		newNode->next=head;
		head=newNode;
	}
	else
	{
		int temp_cnt=1;
		Node *navigate=head,*temp=NULL;
	
		while(navigate->next!=NULL && temp_cnt<pos-1)
		{
			navigate=navigate->next;
			temp_cnt++;
		}
		newNode->next = navigate->next;
		navigate->next=newNode;
	}
	totalNode++;
	return true;
}
int SinglyLinkedList::searchFirstOccurance(int data)
{	
	//filter
	if(head==NULL)
	{
		return 0;
	}
	Node * navigate=head;
	int iret=1;
	while(navigate!=NULL)
	{
		if(data == navigate->data)
			break;
		iret++;
		navigate=navigate->next;
	}
/*	if(iret>totalNode)
		return 0;
	else
		return iret;
*/
	if(navigate!=NULL)
		return iret;
	else
		return 0;
}
int SinglyLinkedList::deleteFirst()
{
	if(head==NULL)
		return -1;
	Node * temp=head;
	int ret=temp->data;
	
	head=head->next;

	delete temp;
	return ret;
}

int SinglyLinkedList::deleteLast()
{
	if(head==NULL)
		return -1;
	Node *navigate=head;
	Node *slowtemp=navigate;
	
	while(navigate->next!=NULL)
	{
		slowtemp=navigate;
		navigate=navigate->next;
	}
	int ret=navigate->data;
	slowtemp->next=NULL;
	delete navigate;
	return ret;
}
int SinglyLinkedList::deleteAtPosition(int pos)
{
	if(head==NULL || pos > totalNode || pos<=0)
		return -1;
	if(pos==1)
		return deleteFirst();

	Node * navigate=head,*slowtemp=head;
	while(pos>1 && navigate->next!=NULL)
	{
		pos--;
		slowtemp=navigate;
		navigate=navigate->next;
	}
	int ret=navigate->data;
	slowtemp->next=navigate->next;
	delete navigate;
	return ret;
}

void SinglyLinkedList::display()
{
	Node * navigate=head;
	while(navigate!=NULL)
	{
		std::cout<<"| "<<navigate->data<<" |=>";
		navigate=navigate->next;
	}
	std::cout<<"NULL"<<endl;
}


/*
int main()
{
	SinglyLinkedList sll;
	sll.insertFirst(30);
	sll.insertFirst(20);
	sll.insertFirst(10);
	sll.insertAtPosition(40,1);
	sll.display();
	cout<<"first occurance of 10:"<<sll.searchFirstOccurance(430)<<endl;
	cout<<"total count"<<sll.totalNode<<endl;
	sll.deleteAtPosition(4);
	sll.display();

	sll.deleteFirst();
	sll.display();
	sll.deleteLast();
	sll.display();	

	cout<<"list using copy constructor"<<endl;
	SinglyLinkedList sll2(sll);
	sll2.display();
	return 0;
}*/
