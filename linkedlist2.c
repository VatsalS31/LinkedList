#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
   
}
*list=NULL;
 
void Bin();    // Beginning insertion
void Ein();   //  End insertion
void Pin();   // Position insertion
void Bde();   // Beginning deletion
void Ede();   // End deletion
void Pde();   // Position deletion
void display();
void search();
int main()
{

    int ch;
    printf("BY VATSAL SHAH ");
    printf("-------------------------------------------------------------\n");
    do
    {
         printf("\nChoose what to do\n");
            printf("\n\nPress 1 for  Beginning Insertion");
            printf("\nPress 2 for End Insertion");
            printf("\nPress 3 for Position Insertion");
            printf("\nPress 4 for Beginning Deletion");
            printf("\nPress 5 for End Deletion");
            printf("\nPress 6 for Position Deletion");
            printf("\nPress 7 for Search the element");
            printf("\nPress 8 for Displaying the List");
            printf("\nPress 9 for Exit");
            printf("\nEnter the Choice : ");
            
        
        scanf("%d",&ch);
        switch(ch)
        {
           
           
                case 1:
                Bin();
                break;
                case 2:
                Ein();
                break;
                case 3:
                Pin();
                break;
                case 4:
                Bde();
                break;
                case 5:
                Ede();
                break;
                case 6:
                Pde();
                break;
                case 7:
                search();
                break;
                case 8:
                display();
                break;
                case 9:
                return 0;
                

        }
    
    }while(ch!=9);
} 
void Bin()
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
void Ein()
{
    struct node *nnode, *t;
        int b;
         printf("\nEnter the Element which to be Inserted from End: ");
        scanf("%d",&b);
        
        nnode = (struct node*) malloc(sizeof(struct node));
        nnode -> data = b;
        nnode -> next = 0;
        if (list == 0)
        list = nnode;
        else
        {
            t = list;
            while (t -> next != 0)
            t = t->next; 
            t -> next = nnode;
        }
}
void Pin()
{
    struct node *nnode, *t;
    int c,pos;
    printf("\nEnter the element and position where the element to be inseretd : ");
    scanf("%d",&c);
    scanf("%d",&pos);
    t=list;
    int k=1;
    while((k<pos-1) && (t->next!=0))
    {
        t=t->next;
        k++;
    }
    nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=c;
    nnode->next=t->next;
    t->next=nnode;
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
void Bde()
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
void Ede()
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
void Pde()
{
    struct node *p,*pos;
    int c=1,po;
    if(list==NULL)
    {
        printf("List is empty\n");

    }
    else
    {
        printf("\nEnter the Index from which you want to delete the element:");
        scanf("%d",&po);
        if(po==1)
        {
            Bde();
        }
        else
        {
            pos=(struct node*)malloc(sizeof( struct node));
            p=list;
            while(c<po-1)
            {
                p=p->next;
                c++;

            }
            pos=p->next;
            p->next = pos->next;
            free(pos);

        }

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