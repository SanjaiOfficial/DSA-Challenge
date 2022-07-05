#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

int main()
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    
}