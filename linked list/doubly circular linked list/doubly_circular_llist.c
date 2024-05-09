#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL, *temp, *before, *after, *neww;

void create();
void removeFromEnd();
void display();
void removeFromFront();
void insertAny();
void removeAny();
void insertAtFront();
void insertAtEnd();

int main()
{
    char choice;
    do
    {
        printf("\nSelect an option:\n");
        printf("1. create\n");
        printf("2. insert at front\n");
        printf("3. insert at any place\n");
        printf("4. insert at end\n");
        printf("5. remove from front\n");
        printf("6. Remove any\n");
        printf("7. remove from end\n");
        printf("8. display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        choice = getche();
        switch (choice)
        {
        case '1':
            create();
            break;
        case '2':
            insertAtFront();
            break;
        case '3':
            insertAny();
            break;
        case '4':
            insertAtEnd();

            break;
        case '5':
            removeFromFront();
            break;
        case '6':
            removeAny();
            break;
        case '7':
            removeFromEnd();
            break;
        case '8':
            display();
            break;
        case '9':
            exit(0);

        default:
            printf("\nInvalid choice! Please enter again.\n");
            break;
        }
    } while (choice != '9');
}

void create()
{
    int n;
    char ch;
    printf("\nenter the number you want to insert:");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->prev = NULL;
    start->next = NULL;
    temp = start;
    printf("\ndo you want to continue?");
    ch = getche();
    while (ch == 'y' || ch == 'Y')
    {
        printf("\nenter the number you want to insert:");
        scanf("%d", &n);
        neww = (struct node *)(malloc(sizeof(struct node)));
        neww->data = n;
        temp->next = neww;
        neww->prev = temp;
        neww->next = start;
        temp = temp->next;
        printf("do you want to continue?");
        ch = getche();
    }
    start->prev = neww;
}

void display()
{
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp = start;
        printf("\nhere is your list\n");
        while (temp->next != start)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
void insertAny()
{
    int n, i = 1;
    int pos;
    if (start == NULL)
    {
        printf("\nlist not found\n");
    }
    else
    {
        temp = start;
        printf("\nenter the position you want to insert:");
        scanf("%d", &pos);
        neww = (struct node *)(malloc(sizeof(struct node)));
        printf("\n enter the number you want to insert:");
        scanf("%d", &n);
        neww->data = n;
        neww->next = NULL;
        neww->prev = NULL;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        before = temp->prev;
        before->next = neww;
        neww->prev = before;
        neww->next = temp;
        temp->prev = neww;
        temp = start;
    }
}
void removeAny()
{
    int poss, i = 1;
    if (start == NULL)
    {
        printf("\nlist not found\n");
    }
    else
    {
        temp = start;
        printf("\nenter the position you want to remove:");
        scanf("%d", &poss);
        while (i < poss)
        {
            temp = temp->next;
            i++;
        }
        before = temp->prev;
        after = temp->next;
        before->next = after;
        after->prev = before;
        free(temp);
    }
}
void insertAtFront()
{
    int n;
    if (start == NULL)
    {
        printf("\nlist not found\n");
    }
    else
    {
        temp = start;
        printf("\nenter the number you want to insert:");
        scanf("%d", &n);
        neww = (struct node *)(malloc(sizeof(struct node)));
        neww->data = n;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        neww->next = start;
        start->prev = neww;
        neww->prev = temp;
        temp->next = neww;
        start = neww;
    }
}
void removeFromFront()
{
    if (start == NULL)
    {
        printf("\nlist not found\n");
    }
    else
    {
        temp = start;
        before = temp->prev;
        start = temp->next;
        before->next = start;
        start->prev = before;
        free(temp);
    }
}
void insertAtEnd()
{
    int n;
    if(start==NULL)
    {
        printf("\nlist not found\n");
    }
    else
    {
        temp=start->prev;
        printf("\nenter the number you want to insert:");
        scanf("%d",&n);
        neww=(struct node*)(malloc(sizeof(struct node)));
        neww->data=n;
        neww->next=start;
        start->prev=neww;
        temp->next=neww;
        neww->prev=temp;

    }
}
void removeFromEnd()
{
    if(start==NULL)
    {
        printf("\nlist not found\n");

    }
    else
    {
        temp=start->prev;
        before=temp->prev;
        before->next=start;
        start->prev=before;
        free(temp);

    }
}
