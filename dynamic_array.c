/*Create a array dynamically and store all the elements based on user input and display the array*/
/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n;
    int *arr;
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    adding_elements(n,arr);
    display(n,arr);
}
void adding_elements(int n,int *arr)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d element:",i+1);
        scanf("%d",arr+i);
    }
}
void display(int n,int *arr)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }

}
