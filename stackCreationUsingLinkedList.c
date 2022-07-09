#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void createStack(struct Node *top,int size)
{
    for(int i=0;i<size;i++)
    {
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        top->next = newNode;
        newNode->next = NULL;
    }

}

int isFull(struct Node * top)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr == NULL)
    {
        return 1; 
    }
    else
    {
        return 0;
    }
}

void stackPush(struct Node * top, int data) 
{
    if(isFull(top))
    {
        printf("\nSTACK OVERFLOW!!!");
    }
    else
    {
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        top->next = ptr;
        ptr = top;
    }
}   

int stackPop(struct Node * top )
{
    
}
void stackDisplay(struct Node * top)
{

}


int main()
{
    int choice;
    enum stackChoice{Display=1,Push=2,Pop=3,Peek=4,IsFull=5,IsEmpty=6,Exit=7}; 
    struct Node * top = (struct Node *)malloc(sizeof(struct Node));
    printf("\t\tSTACK OPERATIONS \n\n1.Display\n2.Push\n3.Pop\n4.Peek\n5.IsFull\n6.IsEmpty\n7.Exit\n\nEnter your choice(1-7): ");
    scanf("%d",&choice);
    switch(choice)
    {
        case Display:
        {
            stackDisplay(top);
        }

        case Push:
        {   
            int data;
            printf("\nEnter the data to be pushed: ");
            scanf("%d",data);
            stackPush(top,data);
            break;
        }

        case Pop:
        {
            stackPop(top);
        }
    }
}