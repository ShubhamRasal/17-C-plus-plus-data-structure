#include<iostream>
using namespace std;

class BSTNODE
{
	public:
	int data;
	BSTNODE *left;
	BSTNODE *right;
	
	BSTNODE(int data)
	{
		this->data=data;
		left=right=NULL;		
	}
};
/*
	Function name	:Find(BSTNODE *rootadd,cont int data)
	Description	:Find operation is straightforward operation in BST. Start with the root and keep
			 moving left or  right using BST property.
			If the data we are searching is same as nodes data then we return current node,
	Complexity	:Time complexity :O(n) for worst case.(When BST is skew tree)
			 Space complexity:O(n) for recursive stack. 
	Developer	:Shubham D. Rasal 28 May 2020
*/
BSTNODE * Find(BSTNODE *root,const int data)
{
	if(root==NULL)	//not found
		return NULL;	
	else if(data==root->data)	return root;
	else if(data < root->data)	return Find(root->left,data);
	else	return Find(root->right,data);

}
/*
        Function name   :FindWithoutRecursion(BSTNODE *rootadd,cont int data)
        Description     :Find operation is straightforward operation in BST. Start with the root and keep
                         moving left or  right using BST property.
                        If the data we are searching is same as nodes data then we return current node,
        Complexity      :Time complexity :O(n) for worst case.(When BST is skew tree)
                         Space complexity:O(1)
        Developer       :Shubham D. Rasal 28 May 2020
*/

BSTNODE * FindWithoutRecursion(BSTNODE* root,const int data)
{
	while(root)  //if root is not NULL
	{
		if(root->data == data)		//if root data is equal to to key
			break;
			
		if(data<root->data)           // if key is less than root data then search in left subtree of root
			root=root->left;
		else if(data > root->data)    //if key is greater than root data then search in right subtree of root
			root=root->right;
	}
	return root;                          // return root  if input parameter is NULL then return as it is.

}
/*
	Function Name	:Inorder(BSTNODE * rootNode)
	Description	:In inorder traversal the root node visited between the subtrees.
			Inorder traversal is defined as follows,
			 1.Traverse the left subtree in Inorder.
			 2.Visit the root.
			 3.Traverse the right subtree in Inorder.
	Complexity	:Time complexity: O(n)i Space complexity:O(n)
	Developer	:Shubham D. Rasal 28 May 2020
*/
void Inorder(BSTNODE *temp)
{
	if(temp!=NULL)
	{
		Inorder(temp->left);
		std::cout<<temp->data<<" ";
		Inorder(temp->right);
	}
}
/*
        Function Name   :Preorder(BSTNODE * rootNode)
        Description     :In preorder traversal the root node visited before the subtrees.
                        Preorder traversal is defined as follows, 
                	 1.Visit the node.        
			 2.Traverse the left subtree in preorder
                         3.Traverse the right subtree in preorder.
	 Complexity      :Time complexity: O(n) Space complexity:O(n)
        Developer       :Shubham D. Rasal 28 May 2020
*/
void Preorder(BSTNODE *root)	//DLR
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		Preorder(root->left);
		Preorder(root->right);
	}
}
/*
        Function Name   :postorder(BSTNODE * rootNode)
        Description     :In postorder traversal the root node visited after the subtrees.
                        Postorder traversal is defined as follows, 
                         1.Traverse the left subtree in Postorder.
                         2.Traverse the right subtree in Postorder.
			 3.Visit the root.
	 Complexity      :Time complexity: O(n) Space complexity:O(n)
        Developer       :Shubham D. Rasal 28 May 2020
*/
void Postorder(BSTNODE *root)
{
	if(root)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout<<root->data<<" ";
	}
}
/*
	Function Name	:insert(BSTNODE **PointertoRootNode,int data)
	Description	:Insert new node into BST.
			For inserting data we must follow Binary search tree property.(all the left
			subtree element should be less than the root data and all the right subtree element should be
			greater than the root data.)
			Duplicate elements are not inserted.
			first element is the parent root.
			This is iterative version of inserting data into tree.
	Complexity	:Time complexity:O(n)	Space Complexity:O(1)
	Developer	:Shubham D. Rasal	28 May 2020
*/	
void insert(BSTNODE **root,int data)
{
	BSTNODE *newNode=new BSTNODE(data);
	
	if(newNode==NULL)//memory error
	{
		std::cout<<"ERROR:Memory Error!"<<endl;
		return ;
	}
	if(*root==NULL)  //if tree is empty then root is new node.
	{
		*root=newNode;
		return;	
	}
	else
	{
		BSTNODE *temp = *root;
		while(1)
		{
			if(temp->data==data)	//No duplicate data is allowed in BST
			{		
				delete newNode;	//delete the allocated node to avoid memory leak.
				break;		//break the loop.
			}
			else if(data < temp->data)  //if data is less then current node then insert data into left subtree of root
			{	
				if(temp->left==NULL)	// finally, if we found correct spot for data
				{
					temp->left=newNode;	//assign new node to leftchild of root 
					break;	
				}
				else	//we know that element is smaller than root so search for correct spot in leftsubtree of root.
					temp=temp->left;	
			}
			else if(temp->data < data)	//if data is greter than root data then insert data into rightsubtree of root.
			{
				if(temp->right == NULL)	//finally, if we found correct spot for data
				{	
					temp->right = newNode;	//assign new node to rightchild of root
					break;
				}
				else
					temp=temp->right; // data is greater than root data so insert data into rightsubtree of root
			}
		}	//while end
	}	//else end
}//insert end

/*
	Function Name	:FindMin(BSTNODE *root)
	Description	:This function returns the address of minimum node in Binary search tree.
			 As it is BST and we follow the BST property, hence the minimum element is the left-most node ,
			 which does not have left child.
	Complexity	:Time complexity :O(n) in worst case (when BST is left skew tree)	
			 Space complexity:O(n), for recursive stack
	
	@shubham D. Rasal 28May 2020
*/
BSTNODE *FindMin(BSTNODE *root)
{
	if(root==NULL)	//if root is NULL then return NULL 	//Filter
		return NULL;
	if(root->left==NULL)
		return root;
	else 				//i:f(root->left!=NULL)	//if root has left child then go deep to the left-most
		return FindMin(root->left);		

}
/*
        Function Name   :FindMin(BSTNODE *root)
        Description     :This function returns the address of minimum node in Binary search tree.
                         As it is BST and we follow the BST property, hence the minimum element is the left-most node ,
                         which does not have left child.
	Complexity	:Time Complexity:O(n) Space complexity:O(1)
	@shubham Dharma Rasal 28 May 2020
*/
BSTNODE *FindMinWithoutRecursion(BSTNODE *root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)	
		root=root->left;
	
	return root;
	
}
/*
        Function Name   :FindMaxx(BSTNODE *root)
        Description     :This function returns the address of maximum node in Binary search tree.
                         As it is BST and we follow the BST property, hence the maximum element is the right-most node ,
                         which does not have left child.
        Complexity      :Time Complexity:O(n) Space complexity:O(1)
        @shubham Dharma Rasal 28 May 2020
*/

BSTNODE *FindMax(BSTNODE *root)
{
	if(root==NULL)
		return NULL;
	if(root->right!=NULL)
		return FindMax(root->right);
	return root;
}

/*
	Function Name:	delete(BSTNODE **root,int data)
	Description	:This function is deleting the node of given data if is present in the tree.
			 It returns boolean value,true if it successfully deleted the node otherwise false.
			 There are 3 cases while deleting node in tree as follows,	
			 1.If element to be deleted is a leaf node.
			 2.If element to be deleted has one child.
			 3.If element to be deleted has two child.
	Complexity	:Time Complexity:O(n) Space complexity:O(n)
	@Shubham Dharma Rasal 28May 2020

*/
BSTNODE* deleteNode(BSTNODE * root,int data)
{
	cout<<"deleteNode"<<root->data<<endl;
	if(root==NULL)
		cout<<"element is not there"<<endl;
	 
	else if(data < root->data)	//if data is in left-subtree of BST
	{
		root->left=deleteNode(root->left,data);
		cout<<"root data 2"<<root->data<<endl;
	}
	else if(data > root->data)//data is in right-subtree of BST
	{
		root->right= deleteNode(root->right,data);
		cout<<"root data 3"<<root->data<<endl;
	}
	else
	{	//found element
		if(root->left !=NULL && root->right != NULL)  //if node has two children
		{	
			/* replace with largest in left subtree or we can also replace with lowest in right subtree */
			BSTNODE* temp=FindMax(root->left);
			root->data=temp->data;
			root->left= deleteNode(root->left,root->data);		
		}
		else
		{
			cout<<"else-else"<<endl;
			/* one child */
			BSTNODE *temp=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right == NULL)
				root=root->left;
			delete temp;
		}
	}
	return root;
}

int main()
{
	BSTNODE *root=NULL;
	int inp;
	cout<<"enter"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>>inp;
		insert(&root,inp);
		cout<<"hello"<<endl;
	}
	cout<<"Inorder:";
	Inorder(root);
	cout<<endl;
	
	cout<<"preorder:";
	Preorder(root);
	cout<<endl;
	
	cout<<"postorder:";
	Postorder(root);
	cout<<endl;
		
	cout<<"Enter Number to search"<<endl;
	cin>>inp;
	BSTNODE *temp=Find(root,inp);
	if(temp)
	{
		cout<<"Element is found:"<<temp->data<<endl;
	}
	else
	{
		cout<<"element is not found"<<endl;
	}
	temp=FindWithoutRecursion(root,inp);
	if(temp)
	{
		cout<<"element is found without recursion"<<temp->data<<endl;
	}
	else
		cout<<"element is not found without recursion"<<endl;
	cout<<"Minimum:"<<FindMin(root)->data<<endl;
	cout<<"Minimum without recursion"<<FindMinWithoutRecursion(root)->data<<endl;
	cout<<"Maximum "<<FindMax(root)->data<<endl;
	
	cout<<"enter number to delete"<<endl;
	cin>>inp;
	deleteNode(root,inp);
	//cout<<root->data<<endl;
	Inorder(root);
	return 0;
}
