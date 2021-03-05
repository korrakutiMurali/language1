#include<stdio.h>
struct node
{
    int data;
    struct node*link;
};
typedef struct node ll;
int size=0;
ll *first,*temp,*temp2;
int ch;
int main()
{
    do 
    {
     menu();
     printf("enter your choice \n");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1: insertAtEnd(); break;
     case 2: insertAtpos(); break;
     case 3: insertAtbeg(); break;
     case 4: print(); break;
     case 5: printsize(); break;
     case 6: exit(1);
     default: printf("wrong choice choose from 1 to 6");
     }
    }while(ch!=6);
return 0;
}
void insertAtEnd()
{
    if(first==NULL)
    {
        first=(ll*)malloc(sizeof(ll));
        printf("enter data:");
        scanf("%d",&first->data);
        first->link=NULL;
        ++size;
        printf("Insert At End\n");
        return;
    }
    temp = first;
    while(temp->link !=NULL) //from here execution is done only after if first is not null
    {
        temp=temp->link;
    }
    
    temp2 =(ll*)malloc(sizeof(ll));   //new last node
    printf("enter data");
    scanf("%d",&temp2->data);
    temp2->link=NULL;                           //  NULL because it is going to be last node
    temp->link=temp2;
    ++size;
}    
void insertAtpos()
{
    int i;int position=0;ll*newnode;
    if(first==NULL)
    {
        insertAtEnd();
    }
    printf("enter at which position:");
    scanf("%d",&position);
    //check for position valid or not
    if(position == 0 || position >size+2)
    {
        printf("invalid position");
        return;
    }
    temp = first;
    for(i=0;i<position-2;i++)   //for 3rd position
    {                               //at the end of the loop temp is at position-1
        temp=temp->link;
    }
        //create a new node
        newnode=(ll*)malloc(sizeof(ll));
        printf("Enter the data to new node:");
        scanf("%d",&newnode->data);
        newnode->link=temp->link;
        temp->link=newnode;
        printf("inserted node at %d",position);
}
void insertAtbeg()
{   
    ll *newnode;
    if(first==NULL)   //the below code will execute only if linked list is not there
    {
        first==(ll*)malloc(sizeof(ll));
        printf("enter the first data:");
        scanf("%d",&first->data);
        first->link=NULL;
        printf("first node created\n");
    }
    else //if linked list is present
    {
        newnode=(ll*)malloc(sizeof(ll));
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->link=first;
        first=newnode;
        printf("node inserted at begining\n");
    }
}
void print()
{
    temp = first;
    while(temp!=NULL)
    {
        printf("[%d %u]",temp->data,temp->link);
        temp=temp->link;
    }
}
void printsize()
{
    printf("size is %d\n",size);
}
void menu()
{
    printf("1 insertAtEnd \n2 insertAtpos \n3 insertAtbeg \n4 print \n5 printsize \n6 exit\n");
}
