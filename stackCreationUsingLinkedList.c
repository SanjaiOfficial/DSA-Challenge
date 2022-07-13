#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};


void stackPush(struct Node ** top, int data) 
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}


int stackPop(struct Node ** top)
{
    struct Node * ptr = *top;
    int data = ptr->data;
    *top = (*top)->next;
    free(ptr);
    return data;
}

void stackDisplay(struct Node * head)
{
    struct Node * top = head;
    while(top!=NULL)
    {
        printf("%d\n",top->data);
        top = top->next;
    }
}

int stackPeek(struct Node * head)
{
    return head->data;
}

int main()
{
    int choice;
    enum stackChoice{Display=1,Push=2,Pop=3,Peek=4,IsFull=5,IsEmpty=6,Exit=7}; 
    struct Node * top = (struct Node *)malloc(sizeof(struct Node));
    top = NULL;
    do
    {

        printf("\t\tSTACK OPERATIONS \n\n1.Display\n2.Push\n3.Pop\n4.Peek\n5.IsFull\n6.IsEmpty\n7.Exit\n\nEnter your choice(1-7): ");
        scanf("%d",&choice);
        switch(choice)
        {
            case Display:
            {
                stackDisplay(top);
                break;
            }

            case Push:
            {   
                int data;
                printf("\nEnter the data to be pushed: ");
                scanf("%d",&data);
                stackPush(&top,data);
                break;
            }

            case Pop:
            {
                int data = stackPop(&top);
                printf("\nThe popped element is: %d", data);
                break;
            }

            case Peek:
            {
                int peekData = stackPeek(top);
                printf("The element at the top is :%d", peekData); 
            }
        }
    }while(choice!=Exit);   
}