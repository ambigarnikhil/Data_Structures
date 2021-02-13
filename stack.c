/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
#include<stdlib.h>
int stack[100],n,top,ch,x,i;
void main()
{
    printf("Enter the size of stack (maximum=100)\n");
    scanf("%d",&n);
    top=-1;
    printf("Stack Operations\n");
    printf("1.Push  2.Pop  3.Display  4.Exit\n");
    do
    {
        printf("Enter the choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    push();
                    break;
                }
            case 2:
                {
                    pop();
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    printf("Exit\n");
                    break;
                }
            default:
                {
                    printf("Enter the valid choice\n");
                }
        }

    }
    while(ch!=4);
    {
       return 0;
    }
}

void push()
{
    if(top>=n-1)
        printf("Stack is full\n");
    else
    {
        printf("Enter the element to be pushed:\n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
        printf("Stack is already empty\n");
    else
    {
        printf("Popped element is %d\n",stack[top]);
        top--;
    }
}
void display()
{
    if(top<=-1)
        printf("Stack is already empty\n");
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
