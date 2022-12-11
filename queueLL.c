#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
   
}
*list=NULL;
 
void enq();    // Beginning insertion

void deq(); 
void front();  // End deletion
void rear();
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
            printf("\n\nPress 1 for  Enqueue");
            
            printf("\nPress 2 for Dequeue");
            
            printf("\nPress 3 for Search the element");
            printf("\nPress 4 for Displaying the List");
            printf("\nPress 5 for front element");
            printf("\nPress 6 for rear element");
            printf("\nPress 7 for exit");
            printf("\nEnter the Choice : ");
            
        
        scanf("%d",&ch);
        switch(ch)
        {
           
           
                case 1:
                enq();
                break;
                
                case 2:
                deq();
                break;
                
                case 3:
                search();
                break;
                case 4:
                display();
                break;
                case 5:
                front();
                break;
                case 6:
                rear();
                break;
                case 7:
                return 0;
                

        }
    
    }while(ch!=7);
} 
void enq()
{
    struct node*nnode;
        int a;
        printf("\nEnter the Element which to be Inserted : ");
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

void deq()
{ 
    struct node*p,*q;
    if(list==NULL)
    {
        printf("\nEmpty List");

    }
    else
    {
        p=list;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        free(p);
        q->next=NULL;
    }
    

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
void front()
{ struct node*t;
    t=list;
    printf("front element is: ");
    printf("%d",t->data);
}
void rear()
{
    struct node*t;
   t=list;
   while(t->next!=NULL)
   {
    t=t->next;
    printf("rear element is: ");
    printf("%d",t->data);
    
     
   }
   
   
}