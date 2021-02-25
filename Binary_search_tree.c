/*Code by Nikhil Ambigar*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root,int x);
struct node *create(int x);
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node* delete(struct node *root, int x);
struct node* find_minimum(struct node *root);


struct node *root=NULL;

int main()
{
    int ch,x,a;
    while(1)
    {
        printf("Binary Search Tree operations\n");
        printf("1.Create 2.Insert 3.Preorder 4.Inorder 5.Postorder 6.Delete 7.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d",&a);
            root=create(a);
            break;
        case 2:
            printf("Enter the data:");
            scanf("%d",&x);
            root=insert(root,x);
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            inorder(root);
            printf("\n");
            break;
        case 5:
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter the data:");
            scanf("%d",&x);
            delete(root,x);
            break;
        case 7:
            exit(1);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
struct node *create(int a)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int x)
{
    if(root==NULL)
        return create(x);
    else if(x>root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left,x);
    return root;
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
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left = delete(root->left, x);
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum(root->left); // left most element will be minimum
    return root;
}
