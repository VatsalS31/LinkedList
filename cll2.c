#include<stdio.h>
#include<stdlib.h>

void beg_ins(int);
void last_ins(int);
void pos_insert(int,int);
void beg_delete();
void last_delete();
void pos_delete();
void display();
void search(int);
struct node
{
    int data;
    struct node*next;
};
struct node*head;
int main()
{
    int item,n,pos,key;
    do
    {
        printf("press 1 for beginsert\n");
        printf("press 2 for last insert\n");
         printf("press 3 for position insert\n");
        printf("press 4 for beg delete\n");
        printf("press 5 for last delete\n");
         printf("press 6 for position delete\n");
         printf("press 7 for search\n");
        printf("enetr choice\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
            beg_ins(item);
            break;
            case 2:
            last_ins(item);
            break;
            case 3:
            pos_insert(item,pos);
            break;
            case 4:
            beg_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            pos_delete(item,pos);
            break;
            // case 7:
            // search(key);
            // break;
            case 7:
            display();
            break;

        }
       
     }while(n!=7);
}
int count(struct node*list)
{
    int l=0;
    while(list->next!=NULL)
    {
        l++;
        list=list->next;
    }
    return l;
    
}
void display(){
    if(head==NULL){
        printf("\n The list is empty");
    }
    struct node*temp=head;
    while(temp!=head){
        printf("\n %d",temp->data);
        temp=temp->next;
    }
}


void beg_ins(int item)
{
    
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*temp;
     printf("Enter the value u want to insert");
        scanf("%d",&item);
    if(ptr==NULL)
    {
        printf("\noverflow\n");
    }
    else
    {
        ptr->data=item;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;

        }
         else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            ptr->next=head;
            temp->next=ptr;
             head=ptr;
        }

    }
    }
   
}
void last_ins(int item)
{
    
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*temp;
     printf("Enter the value u want to insert");
        scanf("%d",&item);
    if(ptr==NULL)
    {
        printf("\noverflow\n");
    }
    else
    {
        ptr->data=item;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;

        }
         else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            ptr->next=head;
            temp->next=ptr;
            
        }

    }
    }
   
}
void beg_delete()
{
    struct node*ptr;
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
            ptr->next=head->next;
            free(head);
            head=ptr->next;
        }

    }

}
void last_delete()
{
    struct node*ptr,*preptr;
    if(head==NULL)
    {
        printf("underflow\n");
    }
    else if(head->next==head)
    {
        head=NULL;
        free(head);
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
             preptr=ptr;
            ptr=ptr->next;
           

        }
        preptr->next=head;
        free(ptr);
    }
}
void pos_insert(int item,int pos)
{
     int t = count(head);
    int i=0;
    struct node*temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    if(pos<t+1 && pos!=0 && pos!=t+1){
        struct node* p = head;
        int i=0;
        while (i<pos-1)
        {
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;

    }
    else if(pos==t+1){
        last_ins(item);
    }
    else if(pos==0)
    {
        beg_ins(item);
    }  
    else
    {
        printf("please enter vaild index\n");
    }

}
void pos_delete(int item,int pos)
{
     int m = count(head); 
    int i=0;
    if(pos<m && pos!=0 ){
        struct node* p = head;
        struct node* q = NULL;
        while(i<pos){
            i++;
            q=p;
            p=p->next;
        }
        q->next = p->next;
    }
    else if(pos==0){
        beg_delete();
    }
    else if(pos==m){
        last_delete();
    }
    else{
        printf("enter valid index\n");
    }
}




