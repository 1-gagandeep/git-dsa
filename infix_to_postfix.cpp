#include<iostream>
#include<cstring>
#include<cmath>
#define max 100

using namespace std;

int post_eval();
char stack[max]; int top=-1;
char infix[max],postfix[max];
int space(char);
int precedence(char);
void push(int);
int pop();
int isempty();
void intopost();
void print();

void intopost()
{
    int i,j=0;
    char next;
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next=pop())!='(')
                        postfix[j++]=next;
                    break;
                case'+':
                case'-':
                case '*':
                case '/':
                case '^':
                    while(!isempty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++]=pop();
                    push(symbol);
                    break;
                default:
                    postfix[j++]=symbol;
            }
        }
    }
    while(!isempty())
        postfix[j++]=pop();
    postfix[j]='\0';
    print();
}
int precedence(char symbol)
{
    switch(symbol)
    {
        case'^':
            return 3;
        case'/':
        case'*':
            return 2;
        case'+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
int space(char c)
{
    if(c==' ' || c=='\t')
        return 1;
    else
        return 0;
}
void push(int val)
{
    if(top==max-1)
    {
        cout << "Stack overflow";
        return;
    }
    top++;
    stack[top]=val;
}
int pop()
{
    int c;
    if(top==-1)
    {
        cout << "Stack underflow";
        exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void print()
{
    int i=0;
    cout << "The equivalent postfix expression is: ";
    while(postfix[i])
    {
        cout << postfix[i++];
    }
    cout << endl;
}
int post_eval()
{
    int i,a,b;
    for(i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0' && postfix[i]<='9')
        {
            push(postfix[i]-'0');
        }
        else
        {
            a=pop();
            b=pop();
            switch(postfix[i])
            {
                case '+':
                    push(b+a);break;
                case '-':
                    push(b-a);break;
                case '*':
                    push(b*a);break;
                case '/':
                    push(b/a);break;
                case '^':
                    push(pow(b,a)); break;
            }
        }
    }
    return pop();
}
int main()
{
    int result;
    cout << "Enter the infix expression: ";
    cin.getline(infix, max);
    cout <<"Expression is: "<< infix << endl;
    intopost();
    result=post_eval();
    cout << "The result obtained after postfix evaluation is:" << result << endl;
    
}
