#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data,min,max;
    struct node *next;
}*top;
void push();
void pop();
void display();
void min();
void max();
int main()
{
    
    int ch;
    
    
  
    for(;;)
    {
        printf("enter your choice:1.push,2.pop,3.display,4.min,5.max");
        scanf("%d",&ch);
        if(ch==1)
        {
            push();
        }
        else if(ch==2)
        {
            pop();
        }
        else if(ch==3)
        {
            display();
        }
        else if(ch==4)
        {
            min();
        }
        else if(ch==5)
        {
            max();
        }
        else{
            exit(0);
        }
        
        //exit(0);
    }
    return 0;
}
void push()
{
    int ele;
    printf("enter an element to push");
    scanf("%d",&ele);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("unable to continue");
        exit (0);
    }
    newnode->data=ele;
    newnode->next=NULL;
    
    if(top==NULL)
    {
        newnode->min=ele;
        newnode->max=ele;
        top=newnode;
        
        
        //newnode->next=NULL;
        
    }
    
    else
    {
        newnode->min=ele<top->min?ele:top->min;
        newnode->max=ele>top->max?ele:top->max;
         newnode->next=top;
         top=newnode;
    } 
    
    
}
void pop()
{
    if(top==NULL)
    {
        printf("stack empty cant pop");
        exit(0);
    }
    else
    {
        struct node *temp;
        temp=top;
        printf("elemet %d \t",top->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("stack empty cant display");
        exit(0);
    }
    struct node *temp;
    temp=top;
    do
    {
        printf("%d \t",temp->data);
        printf("%d \t",temp->min);
        printf("%d \n",temp->max);
    }while((temp=temp->next)!=NULL);
}
void min()
{
    
    if(top==NULL)
    {
        printf("stack empty cant display");
        exit(0);
    }
   
    printf("min element in stack %d",top->min);
    
}
void max()
{
    
    if(top==NULL)
    {
        printf("stack empty cant display");
        exit(0);
    }
    else
   
    printf("max element in stack %d",top->max);
    
    
}
