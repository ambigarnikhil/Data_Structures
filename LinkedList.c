/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;
void main()
{
    int ch,len;
    while(1)
    {
        printf("Linked list operations\n");
        printf("1.Append\n");
        printf("2.Display\n");
        printf("3.Addatbegin\n");
        printf("4.Addatafter\n");
        printf("5.Length\n");
        printf("6.Delete\n");
        printf("7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            append();
            break;

        case 2:
            display();
            break;
        case 3:
            addatbegin();
            break;
        case 4:
            addatafter();
            break;
        case 5:
            len=length();
            printf("Length is %d\n",len);
            printf("\n\n");
            break;
        case 6:
            delete();
            break;
        case 7:
            exit(1);
        default:
            printf("Invalid input\n");
        }
    }

}
void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}
void addatbegin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}
void addatafter()
{
    int loc;
    int i=1;
    printf("Enter the location:\n");
    scanf("%d",&loc);
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(loc>length())
    {
        printf("Invalid Location\n");
    }
    else
    {
        struct node* p;
        p=root;
        while(i<=loc-1)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
}
void display()
{
    struct node* p;
    p=root;
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d->",p->data);
            p=p->link;
        }
        printf("\n\n");
    }
}
int length()
{
    int count=0;
    struct node* p;
    p=root;
    while(p!=NULL)
    {
        count++;
        p=p->link;
    }
    return count;
}
void delete()
{
    int loc;
    struct node* temp;
    printf("Enter the location:\n");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("Invalid location\n");
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        int i=1;
        struct node* p;
        struct node* q;
        p=root;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);

    }
}
