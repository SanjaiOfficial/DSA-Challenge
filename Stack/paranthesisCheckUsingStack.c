#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node * next;
};

int bracketChecker(char ptr, struct Node *top)
{
    // if()
}

void stackPush(struct Node ** top, int data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}


int isEmpty(struct Node * top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

int stackPop(struct Node ** top)
{
    struct Node * ptr = *top;
    if(*top==NULL)
    {
        return 1;
    }
    int data = ptr->data;
    *top = (*top)->next;
    free(ptr);
    return 0;
}

int main()
{
    int i,t;
    char exp[200];
    printf("Enter the expression: ");
    scanf("%s",exp);
    struct Node * top = (struct Node *)malloc(sizeof(struct Node));
    top = NULL;
    i=0;
    while (exp[i]!='\0')
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
        {
            stackPush(&top,exp[i]);
        }
        else if(exp[i]=='}'||exp[i]==')'||exp[i]==']')
        {
            if(exp[i] == top->data)
            {
                t = stackPop(&top);
            }
            else
            {
                break;
            }
        }
        i++;
    }
    if((t && isEmpty(top)))
    {
        printf("\nThe equation is in balanced way!!!");
    }
    else
    {
        printf("\nThe equation is not balanced!!!");
    }

}
