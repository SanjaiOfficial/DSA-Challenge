#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node * prev;
    struct Node * next;
};

// Function to create a circular doubly linked list for 'N' nodes 
struct Node * linkedListCreation(int n, struct Node * head)
{
    if(head == NULL)
    {
        printf("Unable to allocate the memory!!!");
        exit(0);
    }
    struct Node * ptr = head;
    printf("Enter the data for node 1: ");
    scanf("%d",&(head->data));

    for(int i=2;i<=n;i++)
    {
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node)); 
        printf("Enter the data for node %d: ",i);
        scanf("%d",&(newNode->data));
        newNode->next = NULL;
        ptr->next=newNode;
        newNode->prev=ptr;
        ptr=ptr->next;
    }
     
    head->prev = ptr;
    ptr->next = head;
    return head;
}

// Function to traverse and display the linked list
struct Node * linkedListTraversal(struct Node* head)
{
    struct Node * ptr = head;
    do
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    int n;
    head->prev = NULL;
    head->next = NULL;

    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    // Function call
    head = linkedListCreation(n,head);
    // Printing the linked list
    printf("Doubly Linked List: \n");
    linkedListTraversal(head);
    return 0;
}