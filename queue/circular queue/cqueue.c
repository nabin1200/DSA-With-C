#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct cqueue
{
    int front;
    int rear;
    int item[max];
}qu;

void insert(qu *q )
{
    int n;
    if((q->rear+1)%max==q->front)
    {
        printf("queue is full");

    }
    else
    {
    q->rear=(q->rear+1)%max;
    printf("\nenter the value you want to store:");
    scanf("%d",&n);
    q->item[q->rear]=n;
    }
    printf("inserted sucessfully");


}

void delet(qu *q)
{
    if(q->front==q->rear)
    printf("empty");
    else
    q->front=(q->front+1)%max;

}
void display(qu *q)
{
    int i;
    if(q->front==q->rear)
    {
        printf("empty");
    }
    else{
        for(i=(q->front+1)%max;i!=q->rear;i=(i+1)%max)
        {
            printf("%d \t",q->item[i]);
        }
        printf("%d",q->item[q->rear]);
    }

}
int main()
{
    int choice;
    qu q;
    q.front=-1;
    q.rear=-1;
    while(1){
        printf("\n-----------------------menu------------------\n");
        printf("\nhere is your choice\n");
        printf("1.insert\n2.remove\n3.display\n4.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert(&q);break;
            case 2:
            delet(&q);break;
            case 3:
            display(&q);break;
            case 4:
            exit(0);
            break;
            default:
            printf("wrong choice");
            break;

        }

    }
    return 0;
}