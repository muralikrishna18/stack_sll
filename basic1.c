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
    
    if(top==NULL)
    {
         top->min=ele;
          top->max=ele;
        top=newnode;
        
        
        //newnode->next=NULL;
        
    }
    else
    {
        if(ele>top->data)
        newnode->max=ele;
        if(ele<top->data)
        newnode->min=ele;
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
    }while((temp=temp->next)!=NULL);
}
void min()
{
    int min;
    if(top==NULL)
    {
        printf("stack empty cant display");
        exit(0);
    }
    /*else
    min=top->data;
    struct node *temp;
    temp=top;
    do
    {
        min=(min>temp->data?temp->data:min);
    
    }while((temp=temp->next)!=NULL);*/
    printf("min element in stack %d",top->min);
    
}
void max()
{
    int max;
    if(top==NULL)
    {
        printf("stack empty cant display");
        exit(0);
    }
    else
    /*max=top->data;
    struct node *temp;
    do
    {
        max=max<temp->data?temp->data:max;
    
    }while((temp=temp->next)!=NULL);*/
    printf("max element in stack %d",top->max);
    
    
}
