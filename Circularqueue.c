/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
int cqueue[100];
void insert();
void delete();
void display();
int front=-1,rear=-1;
int n;
void main()
{
    int ch;
    printf("Enter the size of circular queue(Maximum=100):\n");
    scanf("%d",&n);
    while(1)
    {
        printf("Circular queue Operations\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default :
            printf("Invalid choice\n");
        }
    }
}
void insert()
{
    int ele;
    if((front==0 && rear==n- 1) || front==rear+1)
    {
        printf("Circular Queue is full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        printf("Enter the number:\n");
        scanf("%d",&ele);
        cqueue[rear]=ele;
    }
    else if(rear==n-1)
    {
        rear=0;
        printf("Enter the number:\n");
        scanf("%d",&ele);
        cqueue[rear]=ele;
    }
    else
    {
        rear++;
        printf("Enter the number:\n");
        scanf("%d",&ele);
        cqueue[rear]=ele;
    }
}
void delete()
{
    if(front==-1 && rear==-1)
    {
        printf("Circular queue is empty\n");
    }
    else if(front==rear)
    {
        printf("Deleted element is %d\n",cqueue[front]);
        front=-1;
        rear=-1;
    }
    else if(front==n-1)
    {
        printf("The deleted element is %d\n",cqueue[front]);
        front=0;
    }
    else
    {
        printf("Deleted element is %d\n",cqueue[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if(front>rear)
    {
        for(i=front;i<n;i++)
        {
           printf("%d ",cqueue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d ",cqueue[i]);
        }
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",cqueue[i]);
        }
    }


}
