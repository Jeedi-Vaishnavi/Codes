#include<stdio.h>
#define MAX 100
char stack[MAX];
int top=-1;
int isEmpty()
{
if(top==-1)
return 1;
else
return 0;
}
void push(char element)
{
if(top==MAX-1)     
printf("stack overflow\n");
stack[++top]=element;
}
char pop()
{
if(top==-1)
{
printf("stack underflow\n");
exit(1);
}
return stack[top--];
}
int precedence(char symbol)
{
switch(symbol)
{
case '^' :
           return 3;
 case '*' :
 case '/' :   
            return 2;     
 case '+' :
 case '-' :
           return 1;
 default :
           return 0;
 }
 }
void inftopof(char in_exp[ ])
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
while(precedence(stack[top])>=precedence(in_exp[i]))
printf("%c",pop());
push(in_exp[i]);
}
}
while(top >=0)
printf("%c",pop());
}
int post_eval()
{
int i,a,b,result;
for(i=0;i<strlen(postfix);i++)
{
if(postfix[i]>='0'&&postfix[i]<='9')
{
push(postfix[i]-'0');
}
else
{
a=pop();
b=pop();
switch(postfix[i])
{
case '+' :result=push(b+a);
          break;
case '-' :result=push(b-a);
          break;
case '*' :result=push(b*a);
          break;
case '/' :result=push(b/a);
          break;    
}
}
push(result);
}
return pop;
}             
int main()
{
int result;
char in_exp[50];
printf("enter the infix expression\n");
scanf("%s",in_exp);
inftopof(in_exp);
result=post_eval
printf("the result of post fix epression is %d ",result);
return 0;
}
     
