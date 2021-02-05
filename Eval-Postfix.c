#include<stdio.h>
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
    char *e;
    int n1,n2,num,n3;
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            num=*e-48;     /*48==0 in ascii. that is subtracting by 48 translates the char values to int.*/
            push(num);
        }
        else
        {
            n2 = pop();
            n1 = pop();
            switch(*e)
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
                n3 = n1 ^ n2;
                break;
            }
            }
            push(n3);

        }
        e++;
    }
    printf("Result= %d",pop());
}
