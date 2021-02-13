/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
#include<stdlib.h>

struct node *create();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
void main()
{
    int ch;
    while(1)
    {
        printf("!!!Binary tree operations!!!\n");
        printf("1.Create\n 2.Preorder\n 3.Inorder\n 4.Postorder\n 5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            root=create();
            break;
        case 2:
            printf("Preorder is:\n");
            preorder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder is:\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder is:\n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }

}

struct node *create()
{

    int x;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data(enter -1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    temp->data=x;
    printf("Enter the left child of %d element:",x);
    temp->left=create();
    printf("Enter the right child of %d element:",x);
    temp->right=create();

    return temp;
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);

}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);

}

