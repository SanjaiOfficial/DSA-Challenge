#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * head)
{   
    struct Node * ptr = head;
    int i=0;
    while(ptr!=NULL)
    {
        printf("\nElement[%d] :%d",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}

// Case 1: Function to insert the node at the beginning
struct Node * insertAtTheBegin(struct Node * head, int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode-> next = head;
    newNode-> data = data;
    head = newNode;
    return head;
}

// Case 2: Function to insert the node in between
struct Node * insertAtIndex(struct Node * head, int data , int index)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    int i=0;

    while(i!=index-1)
    {
        ptr=ptr->next;
        ++i;
    }

    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

// Case 3: Insert the node at the end
struct Node * insertAtEnd(struct Node * head, int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;
    int i=0;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    newNode-> next = NULL;
    ptr->next=newNode;
    newNode-> data = data ;
    return head;
}

// Case 4: Insert after a particular node
struct Node * insertAfterNode(struct Node * head, int data, struct Node * pos)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = pos->next;
    pos->next = newNode;
    newNode->data = data;
    return head;
}


int main()
{
    
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));

    
    //Linking head and first Node
    head->data=55;
    head->next=first;

    //Linking first and second Node
    first->data=43;
    first->next=second;

    //Linking second and third Node
    second->data=34;
    second->next=third;
    
    //Ending the linked list
    third->data=10;
    third->next=NULL;
    
    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);

    // -------Uncomment the function that you want to use------------

    // head=insertAtTheBegin(head, 56);
    // head=insertAtIndex(head,56,3);
    // head = insertAtEnd(head,76);
    // head = insertAfterNode(head,87,second);
    
    printf("\nLinked list after insertion");
    linkedListTraversal(head);
    
    return 0;
}