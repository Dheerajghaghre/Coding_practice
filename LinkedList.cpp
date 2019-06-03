#include<iostream.h>
#include<malloc.h>

struct node
{
	int data;
	struct node* next;
};
void insertNode(struct node** head);
struct node* createLinkedList()
{       struct node* head=NULL;
	int size=0;
	cout<<"Size of linked list:- ";
	cin>>size;
	for(int i=0;i<size;i++)
	{
	   insertNode(&head);
	}
	return head;
}
void insertNode(struct node** head)
{
	cout<<"Enter node data:- ";
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	cin>>new_node->data;
	new_node->next=*head;
	*head = new_node;
}
void traverse(struct node* head)
{
	cout<<"traverse linked list:- "<<endl;
	struct node* temp=head;
	while(temp)
	{
		cout<<"node:- "<<temp->data<<endl;
		temp=temp->next;
	}
}
void insertAtPos(struct node** head, int pos, int value)
	{
	     struct node* temp = *head;
	     int c=1;
	     struct node* new_node = (struct node*)malloc(sizeof(struct node));
	     new_node->data = value;
	     new_node->next = NULL;
	     if(pos==1)
	     {
		new_node->next= *head;
		*head = new_node;
		return;
	     }
	     while(c<pos-1 && temp)
	     {
		temp=temp->next;
		c++;
	     }
	     if(temp==NULL){
		cout<<"position dosenot exist"<<endl;

	     }
	     else{
	     new_node->next=temp->next;
	     temp->next=new_node;
	     }
	}

void deleteNodeFirst(struct node** head)
{
	struct node* temp= *head;
	if(temp==NULL)
	{
	   cout<<"linked list is empty;- "<<endl;
	}
	*head = temp->next;
	int deleteData = temp-> data;
	cout<<"data deleted from linked list;- "<<deleteData<<endl;
	free(temp);
}
void deleteList(struct node** head)
{
	struct node* temp;
	struct node* curr= *head;
	while(*head)
	{
		temp=curr;
		*head= (*head)->next;
		curr=*head;
		free(temp);
	}
}




int main()
{

	int choice, value, position, a=1;
	struct node* head= NULL;
	while(a)
	{
		cout<<"Menu of Linked List:-"<<endl;
		cout<<"Press 1 to create the List"<<endl;
		cout<<"Press 2 to traverse the List"<<endl;
		cout<<"Press 3 to insert the node at the position"<<endl;
		cout<<"Press 4 to delete front node"<<endl;
		cout<<"Press 5  to delete whole linked list"<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"Enter your choice -";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(head)
				cout<<"linked list already created";
				else
				head = createLinkedList();
				break;
			case 2:
				traverse(head);
				break;
			case 3:
				cout<<"enter the value and position:- ";
				cin>>value>>position;
				insertAtPos(&head,position,value);
				break;
			case 4:
				deleteNodeFirst(&head);
				break;
			case 5:
				deleteList(&head);
				break;
			case 0:
				a=0;
				break;
			default:
				cout<<"enter the right value:- ";
				break;
		}

	}


 return 0;

}
