#include<stdio.h>
#include<stdlib.h>
void space(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" ");
	}
}
int power(int a,int b)
{
	int i,ans=1;
	for(i=0;i<b;i++)
	{
		ans=ans*a;
	}
	return ans;
}
struct node
{
	int data;
	struct node *child,*sibling;
};
struct node* create_node_at()
{
	struct node* ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->child=NULL;
	ptr->sibling=NULL;
	return ptr;
}
void input(struct node* root,int n,int arr[],int *m)
{
	*m=1;
	int index=0;
	struct node *ptr2=root;
	int i,j;
	for(i=0;n>0;i++)
	{
		for(j=0;j<power(2,i);j++)
		{
			if(n>0)
			{
				int temp;
				root=create_node_at();
				scanf("%d",&temp);
				arr[index]=temp;
				index++;
				root->data=temp;
				n--;
				root=root->sibling;
			}
		}
		if(n>0)
		{
			int m=2;
			ptr2->child=create_node_at();
			ptr2=ptr2->child;
			root=ptr2->sibling;
			
		}
	}
}
void print(int arr[],int n,int m)
{
	int i,j,index=0;
	for(i=1;n>0;i++)
	{
		for(j=0;j<power(2,i-1);j++)
		{
			if(n>0)
			{
				space(m/i);
				if(n>0)printf("%d",arr[index]);
				index++;
				n--;
			}
		}
		printf("\n\n");
	}
}
int main()
{
	int n,maxim;
	printf("how many elements in the binary tree?\n");
	scanf("%d",&n);
	int *arr=(int *)malloc(n*sizeof(int));
	struct node* root;
	input(root,n,arr,&maxim);
	print(arr,n,maxim);
}