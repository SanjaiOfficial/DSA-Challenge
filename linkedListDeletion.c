#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

//------------Function to traverse the linked list-----------------
void linkedListTraversal(struct Node* q)
{
    while (q!=NULL)
    {
        printf("%d\n",q->data);
        q=q->next;
    }

}

// Case 1: Delete a node in the beginning

struct Node * deleteAtStart(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Delete a node in between at a given index
struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node * ptr = head;
    int i=0;
    while(i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

// Case 3: Delete a node at the end
struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * ptr = head;
    struct Node * q = head->next;
    while (q->next!=NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
    return head; 
}

// Case 4: Delete a node for the given value 
struct Node * deleteAtValue(struct Node * head, int data2)
{
    struct Node * ptr = head;
    while(ptr->data!=data2)
    {
        ptr = ptr->next;
    }
    struct Node * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

int main()
{
    
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * first = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    
    //Linking head and first node
    head->data=55;
    head->next=first;

    //Linking first and second node
    first->data=43;
    first->next=second;

    //Linking second and third node
    second->data=34;
    second->next=third;
    
    //Ending the linked list
    third->data=10;
    third->next=NULL;

    printf("\nLinked list before deletion:\n");
    linkedListTraversal(head);
    
    // head = deleteAtStart(head);
    // head = deleteAtIndex(head,2);
    head = deleteAtEnd(head);
    // head = deleteAtValue(head,34);
    
    printf("\nLinked list after deletion:\n");
    linkedListTraversal(head);


    return 0;
}
