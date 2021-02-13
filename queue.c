/** front is updated while poping* */
/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
int queue[100],n,ch,front,rear,x;
void main()
{
    front=0;
    rear=0;
    printf("Enter the size of queue(Maximum=100):\n");
    scanf("%d",&n);
    printf("Queue operations\n");
    printf("1.Push  2.Pop  3.display  4.exit\n");
    do
    {
        printf("Enter your choice:\n");
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
                return 0;
            }
        default:
            {
                printf("Enter the valid choice\n");
            }
        }
    }
    while(ch!=4);
        return 0;
}
void push()
{
    if(rear==n)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("enter the value to be pushed:\n");
        scanf("%d",&x);
        queue[rear]=x;
        rear++;
    }
}
void pop()
{
    if(front==rear)
    {
        printf("queue is empty");
    }
    else
    {
        printf("the popped element is %d\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front==rear)
    {
        printf("queue is empty");
    }
    else
    {
        printf("The elements in the queue are:\n");
        for(int i=0;i<rear;i++)\
        {
            printf("%d ",queue[i]);
        }
    }
}
