#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
struct node
{
	int k;
	struct node*next;
};
int deg[MAX];
int st[MAX];
int lev[MAX];
struct node* head[MAX];
int queue[MAX];
int front=-1,rear=-1,v;

void enqueue(int k)
{
	if(front==-1) 
        front = 0;
    rear=(rear+1)%MAX;
    queue[rear]=k;
}
void dequeue()
{
	front=(front+1)%MAX;
}
int isempty()
{
	if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}
void* insert_end(struct node* p,int X)
{
	struct node* q=(struct node*)malloc(sizeof(struct node*));
	q->next=NULL;
	while(p->next!=NULL)
		p=p->next;
	p->next=q;
	q->k=X;
}


void BFS(int i)
{   
    enqueue(i);
    lev[i]=0;
    st[i-1]++;
    struct node* temp=head[i-1];
    int p=1;
    while(!isempty())
    {
        int v=queue[front];
		int k=deg[v-1];
		struct node* temp=head[v-1];			
        for(i=0; i<k; i++)
        {
           	
			temp=temp->next;
           	int m=temp->k;		m--;
		    if(st[m]==-1) 
            {
                enqueue(m+1);
                lev[m]=p;
                st[m]++;
            }
			else if(st[m]==1);
			else
            {
            
            }
        }
        dequeue();
        st[v-1]++;
        p++;
    }
}
void create()
{
	int u,i;
	scanf("%d",&::v);
	for(i=0;i<v;i++)
	{
		head[i]=(struct node*)malloc(sizeof(struct node));
		head[i]->k=i+1;
		head[i]->next=NULL;
		st[i]=-1;
	}	 
	int e,s,d;	scanf("%d",&e);	
	while(e--)
	{
		scanf("%d %d",&s,&d);
		deg[s-1]++;
		insert_end(head[s-1],d);
		deg[d-1]++;
		insert_end(head[d-1],s);
	}
}
int main()
{
	create();
	BFS(1);
	int i;
	for(i=0;i<v;i++)
		if(lev[i]%2==0)
			printf("1 ");
		else
			printf("0 ");
	return 0;
}
