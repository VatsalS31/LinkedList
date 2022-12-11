#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
   
}
*list=NULL;
 
void push();    


void pop();   
void peek();

void display();
void search();
int main()
{

    int ch;
    printf("BY VATSAL SHAH 21BKT0131");
    printf("-------------------------------------------------------------\n");
    do
    {
         printf("\nChoose what to do\n");
            printf("\n\nPress 1 for  Push");
            
            printf("\nPress 2 for Pop");
          
            printf("\nPress 3 for Search the element");
            printf("\nPress 4 for Displaying the List");
            printf("\nPress 5 for peek 1st element");
            printf("\nPress 6 for Exit");
            printf("\nEnter the Choice : ");
            
        
        scanf("%d",&ch);
        switch(ch)
        {
           
           
                case 1:
                push();
                break;
               
                case 2:
                pop();
                break;
               
                case 3:
                search();
                break;
                case 4:
                display();
                break;
                case 5:
                peek();
                break;
                case 6:
                return 0;
                

        }
    
    }while(ch!=6);
} 
void push()
{
    struct node*nnode;
        int a;
        printf("\nEnter the Element which to be Inserted from Begining: ");
        scanf("%d",&a);
        nnode=(struct node*)malloc(sizeof(struct node));
        nnode->data=a;
        nnode->next=0;
        if(list==0)
        {
            list=nnode;

        }
        else
        {
            nnode->next=list;
            list=nnode;
        }
}


void display()
{
    struct node *t;
    if(list==0)
    {
        printf("\nList is empty");

    }
    else
    {
        t=list;
        while(t!=0)
        {
            printf("%d",t->data);
            printf(" ");
            t=t->next;
        }
        


    }
}
void pop()
{
     struct node *p;
    if(list == NULL)
    {
        printf("Empty List!");

    }
    else
    {
        p=list;
        list=list->next;

    }
    free(p);

}

    

void search()
{
    struct node *m;
    m=list;
    int x;
    printf("Enter the value that you want to Search");
    scanf("%d",&x);
    int f=0;
    while(m!=NULL && f!=1)
    {
        if(m->data==x)
        {
            f=1;
        }
        m=m->next;
    }
    if(f==0)
    {
        printf("\nValue not found!\n");
    }
    else
    {
         printf("\nValue found!");

    }
   

}
void peek()
{
    struct node*t;
    t=list;
    printf("%d",t->data);
}