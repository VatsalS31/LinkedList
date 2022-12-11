#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data_stored;
    struct NODE *ptr_linkNext;
    struct NODE *ptr_linkPrev;
} Node;
Node *ptr_Head = NULL;

int Function_countNode()
{
    int counter_node = 0;
    Node *ptr_Mover;
    ptr_Mover = ptr_Head;
    while (ptr_Mover != NULL)
    {
        ptr_Mover = ptr_Mover->ptr_linkNext;
        counter_node++;
    }
    return counter_node;
}

void Function_printer()
{
    printf("\n");
    if (ptr_Head == NULL)
        printf("\nList is empty!");
    else
    {
        Node *ptr_tempNode;
        ptr_tempNode = ptr_Head;
        while (ptr_tempNode != NULL)
        {
            printf("%d  ", ptr_tempNode->data_stored);
            ptr_tempNode = ptr_tempNode->ptr_linkNext;
        }
    }
}

void Function_insertFront()
{
    int value_input;
    Node *ptr_tempNode;
    ptr_tempNode = (Node *)malloc(sizeof(Node));
    printf("\nEnter the number to be inserted:: ");
    scanf("%d", &value_input);
    ptr_tempNode->data_stored = value_input;
    if (ptr_Head == NULL)
    {
        ptr_tempNode->ptr_linkPrev = NULL;
        ptr_tempNode->ptr_linkNext = NULL;
        ptr_Head = ptr_tempNode;
    }
    else
    {
        ptr_tempNode->ptr_linkNext = ptr_Head;
        ptr_tempNode->ptr_linkPrev = NULL;
        ptr_Head->ptr_linkPrev = ptr_tempNode;
        ptr_Head = ptr_tempNode;
    }
}

void Function_insertEnd()
{
    int value_input;
    printf("\nEnter the number to be inserted:: ");
    scanf("%d", &value_input);
    Node *ptr_tempNode, *ptr_Mover;
    ptr_tempNode = (Node *)malloc(sizeof(Node));
    ptr_tempNode->ptr_linkPrev = NULL;
    ptr_tempNode->ptr_linkNext = NULL;
    ptr_tempNode->data_stored = value_input;
    ptr_Mover = ptr_Head;
    while (ptr_Mover->ptr_linkNext != NULL)
        ptr_Mover = ptr_Mover->ptr_linkNext;
    ptr_Mover->ptr_linkNext = ptr_tempNode;
    ptr_tempNode->ptr_linkPrev = ptr_Mover;
}

void Function_insertPosition()
{
    int value_position;
    printf("\nEnter the position:: ");
    scanf("%d", &value_position);
    if (ptr_Head == NULL || value_position == 1)
        Function_insertFront();
    else
    {
        int value_input, counter_position = 1;
        Node *ptr_tempNode, *ptr_newNode;
        ptr_newNode = (Node *)malloc(sizeof(Node));
        ptr_newNode->ptr_linkNext = NULL;
        ptr_newNode->ptr_linkPrev = NULL;
        printf("\nEnter the number you want to insert:: ");
        scanf("%d", &value_input);
        ptr_newNode->data_stored = value_input;
        ptr_tempNode = ptr_Head;
        while (counter_position < value_position - 1)
        {
            ptr_tempNode = ptr_tempNode->ptr_linkNext;
            counter_position++;
        }
        ptr_newNode->ptr_linkNext = ptr_tempNode->ptr_linkNext;
        ptr_newNode->ptr_linkPrev = ptr_tempNode;
        ptr_tempNode->ptr_linkNext = ptr_newNode;
        ptr_tempNode->ptr_linkNext->ptr_linkPrev = ptr_newNode;
    }
}

void Function_deleteFront()
{
    Node *ptr_tempNode;
    if (ptr_Head == NULL)
        printf("\nThe list is empty!");
    else
    {
        ptr_tempNode = ptr_Head;
        ptr_Head = ptr_Head->ptr_linkNext;
        if (ptr_Head != NULL)
            ptr_Head->ptr_linkPrev = NULL;
        free(ptr_tempNode);
    }
}

void Function_deleteEnd()
{
    if (ptr_Head == NULL)
        printf("\nThe list is empty!");
    else
    {
        Node *ptr_tempNode, *ptr_prevNode;
        ptr_tempNode = ptr_Head->ptr_linkNext;
        ptr_prevNode = ptr_Head;
        while (ptr_tempNode->ptr_linkNext != NULL)
        {
            ptr_tempNode = ptr_tempNode->ptr_linkNext;
            ptr_prevNode = ptr_prevNode->ptr_linkNext;
        }
        ptr_prevNode = ptr_tempNode->ptr_linkPrev;
        free(ptr_tempNode);
        ptr_prevNode->ptr_linkNext = NULL;
    }
}

void Function_deletePosition()
{
    int value_position;
    printf("\nEnter the position:: ");
    scanf("%d", &value_position);
    if (ptr_Head == NULL)
        printf("The list is empty!");
    else if (value_position == 1)
        Function_deleteFront();
    else
    {
        int counter_position = 1;
        Node *ptr_tempNode, *ptr_positionNode;
        ptr_tempNode = ptr_Head;
        while (counter_position < value_position - 1)
        {
            ptr_tempNode = ptr_tempNode->ptr_linkNext;
            counter_position++;
        }
        ptr_positionNode = ptr_tempNode->ptr_linkNext;
        if (ptr_positionNode->ptr_linkNext != NULL)
            ptr_positionNode->ptr_linkNext->ptr_linkPrev = ptr_tempNode;
        ptr_tempNode->ptr_linkNext = ptr_positionNode->ptr_linkNext;
        free(ptr_positionNode);
    }
}

const char *Function_valueSearch()
{
    Node *ptr_moverNode;
    ptr_moverNode = ptr_Head;
    int value_search;
    printf("\nEnter the value you want to search:: ");
    scanf("%d", &value_search);
    int checker_finder = 0;
    while (ptr_moverNode != NULL && checker_finder != 1)
    {
        if (ptr_moverNode->data_stored == value_search)
            checker_finder = 1;
        ptr_moverNode = ptr_moverNode->ptr_linkNext;
    }
    if (checker_finder == 0)
        return "Value not found!";
    else
        return "Value found!";
}

int main()
{
Start:
    printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n5. Exit\nPlease enter your choice:: ");
    int choice;
    scanf("%d", &choice);
    int type = 0;
    switch (choice)
    {
    case 1:
    Case1:
        printf("\n1. Begining Insertion\n2. Position Insertion\n3. End Insertion\n4. Go back to main menu\nPlease enter your choice:: ");
        scanf("%d", &type);
        switch (type)
        {
        case 1:
            Function_insertFront();
            goto Case1;
        case 2:
            printf("\nCurrent Last node at %d.", Function_countNode());
            Function_insertPosition();
            goto Case1;
        case 3:
            Function_insertEnd();
            goto Case1;
        case 4:
            goto Start;
        }
    case 2:
    Case2:
        printf("\nCurrent Last node at %d.", Function_countNode());
        printf("\n1. Begining Deletion\n2. Position Deletion\n3. End Deletion\n4. Go back to main menu\nPlease enter your choice:: ");
        scanf("%d", &type);
        switch (type)
        {
        case 1:
            Function_deleteFront();
            goto Case2;
        case 2:
            Function_deletePosition();
            goto Case2;
        case 3:
            Function_deleteEnd();
            goto Case2;
        case 4:
            goto Start;
        }
        break;
    case 3:
        printf("\nCurrent Last node at %d.", Function_countNode());
        printf("\n%s", Function_valueSearch());
        goto Start;
    case 4:
        Function_printer();
        goto Start;
    case 5:
        return 0;
    }
}