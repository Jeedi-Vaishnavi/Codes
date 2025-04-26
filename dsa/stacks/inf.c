#include<stdio.h>
#include<ctype.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(char element)
{
if(top>MAX-1)
{
printf("stackk overflow");
return;
}
else
stack[++top]=element;
}
char pop()
{
if(top<0)
{
printf("stack underflow");
return ' ';
}
return stack[top--];
}
int priority(char x)
{
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
}
void infix_postfix(char in_exp[])
{
char c;
int i;
for(i=0;in_exp[i]!='\0';i++)
{
if(isalnum(in_exp[i]))
printf("%c",in_exp[i]);
else if(in_exp[i]=='(')
push(in_exp[i]);
else if(in_exp[i]==')')
{
while((c=pop())!='(')
printf("%c",c);
}
else
{
while(priority(stack[top])>=priority(in_exp[i]))
printf("%c",pop());
push(in_exp[i]);
}
}
while(top>=0)
printf("%c",pop());
}int main()
{
char in_exp[20];
printf("enter infix expression");
scanf("%s",in_exp);
infix_postfix(in_exp);
}
