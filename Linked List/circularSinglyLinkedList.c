#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

//------------Function to traverse the linked list-----------------
void linkedListTraversal(struct Node* head)
{
    struct Node * ptr = head;
    
    do
    {
        printf("%d-> ",ptr->data);
        ptr=ptr->next;
        
    }while (ptr!=head);

}


struct Node * linkedListCreation(struct Node * head , int n)
{
    struct Node * ptr = head;
    head->next = NULL;
    if(head == NULL)
    {
        printf("Unable to locate the memory!!!");
        exit(0);
    }
    printf("Enter the data for node 1: ");
    scanf("%d",&(head->data));
    for(int i=2;i<=n;i++)
    {
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ",i);
        scanf("%d",&(newNode->data));
        newNode->next = NULL;
        ptr->next = newNode;
        ptr = ptr->next; 
    }
    ptr->next = head;
    return head;
}


int main()
{   
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    head = linkedListCreation(head,n);
    printf("The linked list is : \n");
    linkedListTraversal(head);
    return 0;
}
