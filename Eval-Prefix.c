/*CODE BY NIKHIL AMBIGAR*/ 

#include<stdio.h>
#include<math.h>
int stack[20];
int top=-1;
void push(int x)
{
    top++;
    stack[top]=x;
}
int pop()
{
    int x;
    x=stack[top];
    top--;
    return x;
}
int main()
{
    char exp[20];
    int i;
    int n1,n2,num,n3;
    printf("Enter the prefix expression: ");
    scanf("%s",exp);
    for(i=strlen(exp)-1;i>=0;i--)
    {
        if(isdigit(exp[i]))
        {
            num=exp[i]-48;     /*48==0 in ascii. that is subtracting by 48 translates the char values to int.*/
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch(exp[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n1 - n2;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n1 / n2;
                break;
            }
            case '^':
            {
                n3 = pow(n1,n2);
                break;
            }
            }
            push(n3);

        }
    }
    printf("Result= %d",pop());
}
