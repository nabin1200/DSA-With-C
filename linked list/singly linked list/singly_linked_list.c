#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* next;
};struct node * start=NULL,*temp,*neww,*before,*after;


void create();
void display();
void insertAtFirst();
void insertAtMiddle();
void insertAtEnd();
void deletFromFirst();
void deletFromLast();
void deletMiddle();

int main()
{
    char ch;
    do{
    printf("\n---------------meanu---------------\n");
    printf("\n1.create\n2.display\n3.insert at first\n4.insert at end\n5.delet from first\n6.delet from last\n7.delet middle\n8.insert at middle\n9.exit");
    printf("\nenter your choice=");
    ch=getche();
    switch(ch){
        case '1':
        create();break;
        case '2':
        display();break;
        case '3':
        insertAtFirst();break;
        case '4':
        insertAtEnd();break;
        case '5':
        deletFromFirst();break;
        case '6':
        deletFromLast();break;
        case '7':
        deletMiddle();break;
        case '8':
        insertAtMiddle();break;
        case '9':
        exit(0);break;
        default :
        printf("\nwrong choice");
    }
    }while(ch!='9');
}

void create()
{
    int n;
    char ch;
    printf("\nenter a number");
    scanf("%d",&n);
    start=(struct node*)(malloc(sizeof(struct node)));
    start->data=n;
    start->next=NULL;
    temp=start; 

    printf("Do you want to continue?");
    ch=getche();
    while(ch=='y'||ch=='Y' )
    {
        printf("\nenter a number");
        scanf("%d",&n);
        neww=(struct node*)(malloc(sizeof(struct node)));
        neww->data=n;
        neww->next=NULL;
        temp->next=neww;
        temp=temp->next;
        printf("Do you want to continue?");
    ch=getche();
    }
   
    //return 0;

}
void display()
{
    if(start==NULL)
    {
        printf("\nlist no found\n");

    }

    else{
        temp=start;
        printf("\n here is your list\n");
        
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void insertAtFirst()
{
    int n;
    if(start==NULL)
    {
        printf("\nlist not found");
        
    }
    else
    {
        printf("\nenter the number you want to insert");
        scanf("%d",&n);
        neww=(struct node*)(malloc(sizeof(struct node)));
        neww->data=n;
        neww->next=start;
        start=neww;

    }
}
void insertAtMiddle()
{
    int n,poss,i=1;
    if(start==NULL)
    {
        printf("l\nist not found");
    }
    else
    {
        printf("\nenter the number you want to insert=");
        scanf("%d",&n);
        neww=(struct node*)(malloc(sizeof(struct node)));
        neww->data=n;
        neww->next=NULL;
        printf("enter the position you want to insert");
        scanf("%d",&poss);
        after=start;
        while(i<poss)
        {
            before=after;
            after=after->next;
            i++;
        }
        before->next=neww;
        neww->next=after;
        

    }
}
void insertAtEnd()
{
    int n;
    if(start==NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        printf("\nenter a number you want to insert at end=");
        scanf("%d",&n);
        neww=(struct node*)(malloc(sizeof(struct node)));
        neww->data=n;
        neww->next=NULL;
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=neww;

    }
}
void deletFromFirst()
{
    if(start==NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp=start;
        start=temp->next;
        free(temp);
    }

}
void deletFromLast()
{
    if(start==NULL)
    {
        printf("\nlist not found");
    }
    temp=start;
    while(temp->next!=NULL)
    {
        before=temp;
        temp=temp->next;
    }
    free(temp);
    before->next=NULL;

}
void deletMiddle()
{
    int poss,i=1;
    if(start==NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp=start;
        printf("\nenter the position to delet=");
        scanf("%d",&poss);
        while(i<poss)
        {
            before=temp;
            temp=temp->next;
            i++;

        }
        after=temp->next;
        before->next=after;
        free(temp);

    }
}