#include<stdio.h>
#include<conio.h>
#define max 10
int rear=-1,queue[max],front=0;
void insert();
int remove_elements();
void display();

int main()
{
    int choice;
    do{
    printf("--------------------------stack menu-----------------------\n");
     printf("\n1.insert \n2.remove \n3.display \n4.exit\n");
    printf("enter your choice =");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        insert();
        break;

        case 2:
        remove_elements();
        break;

        case 3:
        display();
        break;
    }

    }while(choice!=4);
    return 0;
}

void insert()
{
    int n;
    if(rear==max-1)
    {
        printf("queue is full\n");
    }
    else
    {
        printf("enter the number you wat to push =");
        scanf("%d",&n);
        rear++;
        queue[rear]=n;

    }
}


int remove_elements()
{
int n;
if(front>rear)
{
    printf("queue is empty");
}
else
{
    n=queue[front];
    front++;
    printf("queue is removed \n");
   


}

}
void display()
{
    int i;
    if(front>rear)
    {
        printf("queue is empty \n");
    }
    else
    {
        printf("elements of queue are \n");
        for(i=rear;i>=front;i--)
        {
            printf("%d\n",queue[i]);
        }

    }
    
}
