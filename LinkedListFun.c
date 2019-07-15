//Merge two sorted Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *temp;
    SinglyLinkedListNode *temp1;
    SinglyLinkedListNode *temp2;
    SinglyLinkedListNode *temp3;
    SinglyLinkedListNode *temp4;
    if(head1==NULL&&head2==NULL){
        return head1;
    }
    else if(head1==NULL&&head2!=NULL){
        return head2;
    }else if(head1!=NULL&&head2==NULL){
        return head1;
    }
    if(head1->data < head2->data){
            temp=head1;
            temp4=temp;
            temp1=head2;            
        }
    else{
        temp=head2;
        temp4=temp;
        temp1=head1;
        
    }
    while(temp1){
        if(temp->data<=temp1->data&&temp->next!=NULL&&temp->next->data<=temp1->data){
            temp=temp->next;
        }else if(temp->next==NULL){
            temp->next=temp1;
            return temp4;
        }else{
        temp3=temp1->next;
        temp2=temp->next;
        temp->next=temp1;
        temp1->next=temp2;
        temp1=temp3;
        temp=temp->next;
        }
        
    }
    return temp4;

}

//Print the element of Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {
    while(head){
        printf("%d",head->data);
        printf("\n");
        head=head->next;
    }


}

//Insert a node at the tail of Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

    struct SinglyLinkedListNode *temp;
    struct SinglyLinkedListNode *temp1=head;
    if(head==NULL){
        SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    newNode->data=data;
    newNode->next=NULL;
    head = newNode; 
    return head;
    }

    while(head){
        temp=head;
       head= head->next;
    }
    SinglyLinkedListNode *newNode =(struct SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    temp->next = newNode;
    newNode->data=data;
    newNode->next=NULL; 
    return temp1;
}
//Insert the node at the head of Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    if(llist==NULL){
        struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
        newNode->data=data;
        newNode->next=NULL;
        return newNode;
    }


     struct SinglyLinkedListNode *newNode = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
     newNode->data=data;
     newNode->next=llist;
     llist=newNode;
     return llist;
}
//Insert a node at a specific position in a linked list
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
SinglyLinkedListNode *temp=head;

for(int i=0;i<position-1;i++){
head=head->next;
}
SinglyLinkedListNode *newNode= (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
newNode->data=data;
newNode->next=head->next;
head->next=newNode;
return temp;
}
//Delete a node
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode *temp=head;
    SinglyLinkedListNode *temp1;
    if(position==0){
        head=head->next;
        return head;
    }

    for(int i=0;i<position;i++){
        temp1=head;
        head=head->next;
    }
    temp1->next=head->next;
    return temp;
}

//Print in reverse
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
        if(head==NULL){
            return;
        }
        int val=head->data;
        head=head->next;
        reversePrint(head);
        printf("%d",val);
         printf("\n");
    }
//Reverse a Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
SinglyLinkedListNode *temp=NULL, *nextNode=NULL;
while(head){
    nextNode=head->next;
    head->next=temp;
    temp=head;
    head=nextNode;

}
return temp;
}
//Compare two Linked List
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    int a=1,b=0;
    while(a){
        if(head1==NULL && head2==NULL){
            a=0;b=1;
            break;
        }
        else if(head1!=NULL && head2==NULL){
            a=0;
            break;
        }
        else if(head1==NULL&&head2!=NULL){
            a=0;
            break;
        }
        else if(head1->data==head2->data){
            head1=head1->next;
            head2=head2->next;
        }
        else{
            a=0;
            break;
        }

    }

    
return b;

}

//Merge two sorted linked list
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *temp;
    SinglyLinkedListNode *temp1;
    SinglyLinkedListNode *temp2;
    SinglyLinkedListNode *temp3;
    SinglyLinkedListNode *temp4;
    if(head1==NULL&&head2==NULL){
        return head1;
    }
    else if(head1==NULL&&head2!=NULL){
        return head2;
    }else if(head1!=NULL&&head2==NULL){
        return head1;
    }
    if(head1->data < head2->data){
            temp=head1;
            temp4=temp;
            temp1=head2;            
        }
    else{
        temp=head2;
        temp4=temp;
        temp1=head1;
        
    }
    while(temp1){
        if(temp->data<=temp1->data&&temp->next!=NULL&&temp->next->data<=temp1->data){
            temp=temp->next;
        }else if(temp->next==NULL){
            temp->next=temp1;
            return temp4;
        }else{
        temp3=temp1->next;
        temp2=temp->next;
        temp->next=temp1;
        temp1->next=temp2;
        temp1=temp3;
        temp=temp->next;
        }
        
    }
    return temp4;

}
//Get node value
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {

    SinglyLinkedListNode *temp=head;
    for(int i=0;i<positionFromTail;i++){
        head=head->next;
    }

    while(head->next!=NULL){
        head=head->next;
        temp=temp->next;
    }
    return temp->data;

}
//Delete duplicate value nodes from a linked list
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {

    SinglyLinkedListNode *temp=head;
    for(int i=0;i<positionFromTail;i++){
        head=head->next;
    }

    while(head->next!=NULL){
        head=head->next;
        temp=temp->next;
    }
    return temp->data;

}
//Cycle detection
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *temp=head;
    SinglyLinkedListNode *temp1=head;
    int a=1,b=0;

    while(a){
        if((temp1->next==NULL)||(temp1->next->next==NULL)){
            a=0;
        break;
        }
        temp=temp->next;
        temp1=temp1->next->next;
        if(temp==temp1){
            b=1;
            a=0;
            break;
        }       
        
        
    }
    if(b)
    return true;

    return false;

}
//Find Merge point of two list
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *temp1 = head1;
    SinglyLinkedListNode *temp2 = head2;

    int n1=0,n2=0,diff=0;
    static int value;

    while(temp1!=NULL){
        n1=n1+1;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        n2=n2+1;
        temp2=temp2->next;
    }

    if(n1<n2){
        diff=n2-n1;
        for(int i=0;i<diff;i++){
            head2=head2->next;            
        }
        

    }
    else if(n1>n2){
        diff=n1-n2;
        for(int i=0;i<diff;i++){
            head1=head1->next;
        }
        
    }

    while(!(head1==head2)){
        
        head1=head1->next;
        head2=head2->next;
    }
    value=head1->data;
    return value;
}
//Inserting a node into a sorted doubly linked list
/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *temp = head;
    DoublyLinkedListNode *temp1;
    DoublyLinkedListNode* newnode= (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));
    newnode->data=data;

    if(head->data>data){
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        temp=head;
    }
    else{

    while((head->data<data)&&(head->next!=NULL)){
        head=head->next;
    }
    if((head->next==NULL)&&(head->data<data)){
        head->next=newnode;
        newnode->prev=head;
        newnode->next=NULL;
    }
    else{
    head=head->prev;   
    newnode->next=head->next;
    newnode->prev=head;
    head->next=newnode;
    }
}

return temp;

}
//Reverse a doubly linked list
/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *temp;
    DoublyLinkedListNode *temp1;
    if(head->next==NULL)
    return head;
    
    while(head){
        temp=head->next;
        temp1=head->prev;
        head->prev=temp;
        head->next=temp1;
        head=temp;
    }
    head=temp1->prev;
    return head;


}



