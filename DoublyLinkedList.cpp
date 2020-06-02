#include "myheader.h"

class Doubly_Linked_List
{
	public:
		Node *head;
		Node *end;	//tail
		int totalNode;
	Doubly_Linked_List()
	{
		head=end=NULL;
		totalNode=0;
	}
	~Doubly_Linked_List();
	bool insertFirst(int);
	bool insertLast(int);
	bool insertAtPos(int data,int pos);
	bool insertBeforeNode(Node * ,int data);
	bool insertAfterNode(Node* ,int data);
	int deleteFirst();
	int deleteLast();
	int deleteAtPos(int);
	bool deleteNode(Node *);
	void forwardTraversal();
	void backwardTraversal();
};
Doubly_Linked_List::~Doubly_Linked_List()
{
	if(head!=NULL && end!=NULL){	
		while(head!=end)
		{
			head=head->next;
			delete head->prev;
		}
		delete head;
	}
}
void Doubly_Linked_List::forwardTraversal()
{
	Node *temp=head;
	if(temp==NULL)
		std::cout<<"List is empty"<<endl;
	else
	{
		while(temp!=NULL)
		{
			std::cout<<"| "<<temp->data<<" |<=>";
			temp=temp->next;
		}
		std::cout<<"end"<<endl;
	}
}
void Doubly_Linked_List::backwardTraversal()
{
	if(end==NULL)
		std::cout<<"List is empty"<<endl;	
	else
	{
		Node * temp=end;
		while(temp!=NULL)
		{
			std::cout<<"| "<<temp->data<<" |<=>";
                        temp=temp->prev;
                }
                std::cout<<"front"<<endl;
	}
}
bool Doubly_Linked_List::insertFirst(int data)
{
	Node *newNode=new Node(data);
	if(newNode == NULL)	//if memory error
		return false;
	if(head==NULL || end==NULL)	
	{
		head=end=newNode;
	}
	else
	{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
	totalNode++;
	return true;
}
bool Doubly_Linked_List::insertLast(int data)
{	
	Node *newNode=new Node(data);
	if(newNode==NULL)
		return false;
	if(end==NULL || head==NULL)
	{
		head=end=newNode;
	}
	else
	{
		newNode->prev=end;
		end->next=newNode;
		end=newNode;
	}
	totalNode++;
	return true;
}
bool Doubly_Linked_List::insertAtPos(int data,int pos)
{	
	
	if(pos<1 || pos>totalNode+1)
		return false;
	if(pos==1)
		return this->insertFirst(data);
	else if(pos==totalNode+1)
		return this->insertLast(data);
	else
	{
		Node *navigate=head;
		Node * newNode=new Node(data);

		while(pos>1)
		{
			navigate=navigate->next;
			pos--;
		}
		(navigate->prev)->next=newNode;
		newNode->prev=navigate->prev;
		newNode->next=navigate;
		navigate->prev=newNode;
	}
	totalNode++;
	return true;
}
int Doubly_Linked_List::deleteFirst()
{	
	int ret=-1;
	
	if(head==NULL)
		ret=-1;
	else if(head==end)	//only one node
	{
		ret=head->data;
		delete head;
		head=end=NULL;
	}	
	else
	{
		//cout<<"inside else"<<end;
		ret=head->data;
		head=head->next;
		delete head->prev;
		head->prev=NULL;	
	}
	totalNode--;
	return ret;	
}
int Doubly_Linked_List::deleteLast()
{
	int ret=-1;
	if(end==NULL)
		ret=-1;
	else if(head==end)
	{
		ret=end->data;
		delete end;
		head=end=NULL;
	}
	else
	{
		ret=end->data;
		end = end->prev;
		delete end->next;
		end->next=NULL;
	}
	totalNode--;
	return ret;
}
int Doubly_Linked_List::deleteAtPos(int pos)
{
	int ret=-1;
	if(pos<1 && pos>totalNode)
		ret=-1;
	else if(pos==1)
		return deleteFirst();
	else if(pos==totalNode)
		return deleteLast();
	else
	{
		Node *navigate=head;
		while(pos>1)
		{	
			navigate=navigate->next;
			pos--;
		}
		(navigate->prev)->next=navigate->next;
		(navigate->next)->prev=navigate->prev;
		ret=navigate->data;
		delete navigate;
	} 
	
	totalNode--;
	return ret;
}

int main()
{
	Doubly_Linked_List dll;
	dll.insertFirst(10);
	dll.insertFirst(20);
	dll.insertLast(30);
	cout<<"head:"<<dll.head<<endl;
	dll.deleteFirst();	
	cout<<"head:"<<dll.head<<endl;
	dll.forwardTraversal();	
	dll.insertAtPos(40,3);
	dll.insertAtPos(50,4);
	dll.forwardTraversal();
	dll.deleteLast();
	dll.insertFirst(100);
	dll.forwardTraversal();
	dll.deleteAtPos(dll.totalNode);
	dll.forwardTraversal();
		
	dll.backwardTraversal();
	return 0;
}
