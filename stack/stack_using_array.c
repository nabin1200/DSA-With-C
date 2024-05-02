#include<stdio.h>
#include<conio.h>
#define max 10
int top=-1,stack[max];
void push();
void pop();
void display();

int main()
{
    int choice;
    do{
    printf("--------------------------stack menu-----------------------\n");
    printf("\n1.push \n2.pop \n3.display \n4.exit\n");
    printf("enter your choice =");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        push();
        break;

        case 2:
        pop();
        break;

        case 3:
        display();
        break;
    }

    }while(choice!=4);
    printf("you exit sucessfully");
    return 0;
}

void push()
{
    int n;
    if(top==max-1)
    {
        printf("stack full");
    }
    else
    {
        printf("enter the number you wat to push =");
        scanf("%d",&n);
        top++;
        stack[top]=n;

    }
}
void pop()
{
int n;
if(top==-1)
{
    printf("stack is empty");
}
else
{
    n=stack[top];
    top--;
    printf("stack is poped \n");


}

}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty \n");
    }
    else
    {
        printf("------------elements of stack are----------- \n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }

    }
    
}
