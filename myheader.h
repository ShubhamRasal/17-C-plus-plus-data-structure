#include<iostream>
using namespace std;

class Node
{
	public:
		Node *prev;
		Node *next;
		int data;
		Node(int val=0)
		{
			data=val;
			next=prev=NULL;
		}
};
		
