#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * linkedListCreation(int n,struct Node * head)
{
    int i;
    if(head==NULL)
    {
        printf("Unable to allocate memory for head node!!!");
        exit(0);
    }

    printf("Enter the data for node 1: ");
    scanf("%d",&(head->data));

    struct Node * ptr = head;

    for(i=2;i<=n;i++)
    {
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data for node %d: ",i);
        scanf("%d",&(newNode->data));
        newNode->next = NULL;
        ptr->next = newNode;
        ptr = ptr->next;

    }
    return head;
}

struct Node * middleElement(struct Node * head)
{
    struct Node * slowPtr = head;
    struct Node * fastPtr = head;
    while(fastPtr!=NULL || fastPtr->next!=NULL)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

//------------Function to traverse the linked list-----------------
void traverse(struct Node* head)
{
    struct Node * ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }

}

int main()
{
    int n;
    struct Node * mid;
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    printf("Enter the no . of nodes: ");
    scanf("%d",&n);
    //Linked List creation for n nodes
    head = linkedListCreation(n,head);
    //Linked List traversal and display
    printf("The linked list is: \n");
    traverse(head);
    mid = middleElement(head);
    printf("\nMiddle element: %d",mid->data);
    return 0;
}
