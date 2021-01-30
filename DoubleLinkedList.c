#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void main()
{
    int ch,len;
    while(1)
    {
        printf("Double Linked list operations\n");
        printf("1.Append\n");
        printf("2.Addatbegin\n");
        printf("3.Addatafter\n");
        printf("4.Length\n");
        printf("5.Display\n");
        printf("6.Delete\n");
        printf("7.Addatlast\n");
        printf("8.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            append();
            break;
        case 2:
            addatbegin();
            break;
        case 3:
            addatafter();
            break;
        case 4:
            len=length();
            printf("Length is %d\n",len);
            break;
        case 5:
            display();
            break;
        case 6:
            delete();
            break;
        case 7:
            addatlast();
            break;
        case 8:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
}
void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data:\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->right!=NULL)
        {
            p=p->right;
        }
        p->right=temp;
        temp->left=p;
    }
}
void display()
{
    struct node *p;
    p=root;
    if(root==NULL)
    {
        printf("Double Linked List is empty\n");
    }
    else
    {
        while(p!=NULL)
        {
            printf("%d<->",p->data);
            p=p->right;
        }
        printf("\n");
    }
}
int length()
{
    int count=0;
    struct node *p=root;
    while(p!=NULL)
    {
        count++;
        p=p->right;
    }
    return count;
}
void addatbegin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data to add at first position:\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
    }
}
void addatafter()
{
    int loc,len,i=1;
    struct node *temp,*p;
    printf("Enter the location:\n");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location\n");
        printf("Only %d number of nodes are present in double linked list\n",len);
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d",&temp->data);
        temp->left=NULL;
        temp->right=NULL;
        p=root;
        while(i<loc)
        {
            p=p->right;
            i++;
        }
        temp->right=p->right;
        p->right->left=temp;
        p->right=temp;
        temp->left=p;
    }
}
void delete()
{
    struct node *temp;
    int loc,len,i=1;
    printf("Enter the node location to be deleted:\n");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location\n");
        printf("There are only %d number of nodes.\n",len);
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->right;
        temp->right=NULL;
        root->left=NULL;
        free(temp);
    }
    else
    {
        struct node *p,*q;
        while(i<loc-1)
        {
            p=p->right;
            i++;
        }
        q=p->right;
        q->right->left=p;
        p->right=q->right;
        q->left=NULL;
        q->right=NULL;
        free(q);
    }
}
void addatlast()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data to add at last position:\n");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    struct node *p;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    p->right=temp;
    temp->left=p;
}

