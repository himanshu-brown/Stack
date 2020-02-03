#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 10
#define NIL  -1
typedef struct stacktype
 {
  int a[MAX_SIZE];
  int top;
 }stack;
void main()
{
 void push(stack *,int);
 int pop(stack *);
 int isoverflow(stack *);
 int isunderflow(stack *);
 int peep(stack *);
 stack s1;
 s1.top=NIL;
 while(1)
 {
  int choice,item,x;
  clrscr();
  printf("1. Push \n 2. Pop \n 3. Peep \n4. Exit\n");
  printf("Enter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
	printf("Enter which item you want to be push : ");
	scanf("%d",&item);
	x=isoverflow(&s1);
	if(x==1)
	 printf("Stack is overflow");
	else
	push(&s1,item);
	break;
   case 2:
	x=isunderflow(&s1);
	if(x==1)
	printf("Stack is underflow");
	else
	{
	x=pop(&s1);
	printf("%d",x);
	}
	break;
   case 3:
	x=peep(&s1);
	 printf("%d",x);
	 break;
   case 4:
	exit(0);
  }
  getch();
 }
}
int isoverflow(stack *p)
{
 if(p->top==MAX_SIZE)
 return 1;
 else
 return 0;
}
int isunderflow(stack *p)
{
 if(p->top==NIL)
 return 1;
 else
 return 0;
}
void push(stack *p,int item)
{
  p->top=p->top+1;
  p->a[p->top]=item;
}
int pop(stack *p)
{
 int item;
 item=p->a[p->top];
 p->top=p->top-1;
 return item;
}
int peep(stack *p)
{
 int item;
 item=p->a[p->top];
 return item;
}
