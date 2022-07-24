#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *stack)
{
    if(stack->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *stack)
{
    if(stack->top==stack->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int stackPush(int data, struct Stack * stack)
{
    
    
    if(isFull(stack))
    {
        printf("STACK OVERFLOW!!!");
    }
    else
    {
        stack->arr[stack->top] = data;
        stack->top++;
    }
}

int stackPop(struct Stack *stack)
{
    int data = stack->arr[stack->top];
    if(isEmpty(stack))
    {
        printf("\nSTACK UNDERFLOW!!!");
    }
    else
    {
        stack->top--;
        return data;
    }
}

void stackPrint(struct Stack * stack)
{
    int i = stack->top;
    // for(i;a
}

int main()
{
    int n,i,choice;
    enum stackChoice{Create=1,Push=2,Pop=3,Peek=4,IsFull=5,IsEmpty=6,Exit=7};
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top=-1;
    do
    {
    
        printf("\t\tSTACK OPERATIONS \n\n1.Create\n2.Push\n3.Pop\n4.Peek\n5.IsFull\n6.IsEmpty\n7.Exit\n\nEnter your choice(1-7): ");
        scanf("%d",&choice);

        switch(choice)
        {
            case Create:
            {
                printf("\nEnter the size of the stack: ");
                scanf("%d",&(stack->size));
                stack->arr = (int*)malloc(stack->size*sizeof(int));
                printf("\nStack created successfully!!!");
                break;
            }

            case Pop:
            {
                printf("Popped Element: %d",stackPop(stack));
                break;
            }

            case Push: 
            {   
                int data;
                printf("Enter the element to be pushed: ");
                scanf("%d",data);
                stackPush(data,stack);
            }

            case Peek:
            {
                break;
            }

            case IsEmpty:
         {
            if(isEmpty(stack))
            {
                printf("\nStack is empty");
            }
            else
            {
                printf("\nStack is not empty!!!");
            }
            break;
         }

        case IsFull:
        {
            if(isFull(stack))
            {
                printf("\nStack is FULL");
            }
            else
            {
                printf("\nStack is not FULL!!!");
            }
            break;
        }

        default:
        {
            printf("\nWrong Choice!!!");
        }
     }
    }while(choice!=Exit);
}