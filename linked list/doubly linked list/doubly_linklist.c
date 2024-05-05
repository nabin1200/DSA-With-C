// doubly linear list implementation using linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL, *temp, *before, *after, *neww;

void create();
void display();
void displayReverse();
void insertAtFront();
void insertAtEnd();
void insertAtMiddle();
void deletFromFirst();
void deletFromMiddle();
void deletFromLast();

int main()
{
    char ch;
    do
    {
        printf("\n-----------------------menu----------------------\n");
        printf("here is your menu");
        printf("\n1.create\n2.display\n3.display ulto\n4.insert at front\n5.insert at end \n6.insert at middle\n7.delet from first\n8.delet from middle\n9.delet from last\n10.exit");
        printf("\nenter your choice");
        ch = getche();
        switch (ch)
        {
        case '1':
            create();
            break;
        case '2':
            display();
            break;
        case '3':
            displayReverse();
            break;
        case '4':
            insertAtFront();
            break;
        case '5':
            insertAtEnd();
            break;
        case '6':
            insertAtMiddle();
            break;
        case '7':
            deletFromFirst();
            break;
        case '8':
            deletFromMiddle();
            break;
        case '9':
            deletFromLast();
            break;
        case '10':
            exit(0);
            break;
        default:
            printf("\nwrong choice\n");
            break;
        }
    } while (ch != '10');
    return 0;
}
void create()
{
    int n;
    char ch;
    printf("\nenter the element ");
    scanf("%d", &n);
    start = (struct node *)(malloc(sizeof(struct node)));
    start->data = n;
    start->prev = NULL;
    start->next = NULL;
    temp = start;
    printf("do you want to continue?");
    ch = getche();
    while (ch == 'y' || ch == 'Y')
    {
        printf("\nenter the element you want insert:");
        scanf("%d", &n);
        neww = (struct node *)(malloc(sizeof(struct node)));
        neww->data = n;
        neww->prev = temp;
        neww->next = NULL;
        temp->next = neww;
        temp = temp->next;
        printf("do you want to continue?");
        ch = getche();
    }
}
void display()
{
    if (start == NULL)
    {
        printf("list not found");
    }
    else
        printf("\nhere is your list\n");
    temp = start;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void displayReverse()
{
    if (start == NULL)
    {
        printf("list not found");
    }
    else

        printf("\nhere is your list\n");

    while (temp != start)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
}

void insertAtFront()
{
    int n;
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp = start;
        printf("\nenter the number you want insert");
        scanf("%d", &n);
        start = (struct node *)(malloc(sizeof(struct node)));
        start->data = n;
        start->prev = NULL;
        start->next = temp;
    }
}
void insertAtEnd()
{
    int n;
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
        temp = start;
    printf("\nenter the number you want to insert");
    scanf("%d", &n);
    neww = (struct node *)(malloc(sizeof(struct node)));
    neww->data = n;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = neww;
    neww->prev = temp;
    neww->next = NULL;
}
void insertAtMiddle()
{
    int n, poss, i = 1;
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        printf("\nenter the position you want to insert");
        scanf("%d", &poss);
        printf("\nenter the number you want to insert");
        scanf("%d", &n);
        temp = start;
        neww = (struct node *)(malloc(sizeof(struct node)));
        neww->data = n;
        neww->next = NULL;
        neww->prev = NULL;
        while (i < poss)
        {
            temp = temp->next;
            i++;
        }
        before = temp->prev;
        before->next = neww;
        neww->prev = before;
        neww->next = temp;
        temp->prev = neww;
    }
}
void deletFromFirst()
{
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp = start;
        start = temp->next;
        start->prev = NULL;
        temp->next = NULL;
        free(temp);
    }
}
void deletFromMiddle()
{
    int poss, i = 1;
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp = start;
        printf("\nenter the position you want to delet:");
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
void deletFromLast()
{
    if (start == NULL)
    {
        printf("\nlist not found");
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        before = temp->prev;
        before->next = NULL;
        free(temp);
    }
}
