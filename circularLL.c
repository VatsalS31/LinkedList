#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

// function prototyping
struct node *create(int);
void insert_at_begin(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_at_begin();
void delete_at_end();
void delete_at_position(int);
void search(int);

void print_list();
int size_of_list();
int getData();
int getPosition();

int main()
{
   
    int user_choice;
    int data, position;

   
    do{

        printf("\n\n------ Circular Singly Linked List -------\n");
        printf("\n1. Insert a node at beginning");
        printf("\n2. Insert a node at end");
        printf("\n3. Insert a node at given position");
        printf("\n\n4. Delete a node from beginning");
        printf("\n5. Delete a node from end");
        printf("\n6. Delete a node from given position");
        printf("\n\n7. Print list");
       
        printf("\n8. Search a node data");
       
        printf("\n9. Exit");
        printf("\n\n------------------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        printf("\n------------------------------\n");
        switch (user_choice)
        {
        case 1:
            printf("\nInserting a node at beginning");
            data = getData();
            insert_at_begin(data);
            break;

        case 2:
            printf("\nInserting a node at end");
            data = getData();
            insert_at_end(data);
            break;

        case 3:
            printf("\nInserting a node at the given position");
            data = getData();
            position = getPosition();
            insert_at_position(position,data);
            break;

        case 4:
            printf("\nDeleting a node from beginning\n");
            delete_at_begin();
            break;

        case 5:
            printf("\nDeleting a node from end\n");
            delete_at_end();
            break;

        case 6:
            printf("\nDelete a node from given position\n");
            position = getPosition();
            delete_at_position(position);
            break;

        case 7:
            printf("\nPrinting the list from beginning\n\n");
            print_list();
            break;

        case 8:
            printf("\nSearching the node data");
            data = getData();
            search(data);
            break;

       

        case 9:
            printf("\nProgram was terminated\n\n");
            return 0;

        default:
            printf("\n\t Invalid Choice\n");
        }

       
    }while(user_choice!=9);

    return 0;
}

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// function to insert a new node at the beginning of the list
void insert_at_begin(int data)
{
    struct node *new_node = create(data);

    if (new_node != NULL)
    {
        struct node *last = head;

        // if the list is empty
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        // traverse to the end node
        while (last->next != head)
        {
            last = last->next;
        }

        // update  the last node to the new node
        last->next = new_node;

        // update the next pointer of the new node to the head node
        new_node->next = head;

        // update the head of the list to new node
        head = new_node;
    }
}

// function to insert a new node at the end of the list
void insert_at_end(int data)
{
    struct node *new_node = create(data);

    if (new_node != NULL)
    {

        // if the list is empty
        if (head == NULL)
        {
            head = new_node;
            new_node->next = head;
            return;
        }

        struct node *last = head;

        // traverse to the end node
        while (last->next != head)
        {
            last = last->next;
        }

        // update  the last node to the new node
        last->next = new_node;

        // update the next pointer of the new node to the head node
        new_node->next = head;
    }
}

// function to insert a new node at the given position
void insert_at_position(int position, int data)
{
    // checking if the position is valid or not
    if (position <= 0)
    {
        printf("\nInvalid Position\n");
    }
    else if (head == NULL && position > 1)
    {
        printf("\nInvalid Position\n");
    }
    else if (head != NULL && position > size_of_list())
    {
        printf("\nInvalid Position\n");
    }
    else if (position == 1)
    {
        insert_at_begin(data);
    }
    else
    {
        struct node *new_node = create(data);

        if (new_node != NULL)
        {
            struct node *temp = head, *prev = NULL;
            // Since, temp is already pointing to first node
            // then count will be start at second node
            int i = 1;

            // traverse the list to the given position
            while (++i <= position)
            {
                prev = temp;
                temp = temp->next;
            }

            // update the prev node to the new noe
            prev->next = new_node;

            // update the new node to the temp (position node)
            new_node->next = temp;
        }
    }
}

// function to delete a node from the beginning of the list
void delete_at_begin()
{
    // check where the list is empty or not
    if (head == NULL)
    {
        printf("\n List is Empty! \n");
        return;
    }

    // traverse to the end of the list
    struct node *last = head;
    struct node *temp = head;

    // if only one node in the list
    if (last->next == head)
    {
        free(last);
        head = NULL;
        return;
    }

    // traverse to the last node
    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
    temp = NULL;
}

// function to delete a node from the end of the list
void delete_at_end()
{
    // check where the list is empty or not
    if (head == NULL)
    {
        printf("\n List is Empty! \n");
        return;
    }

    // traverse to the end of the list
    struct node *prev = head;
    struct node *temp = head->next;

    // if only one node in the list
    if (prev->next == head)
    {
        free(prev);
        head = NULL;
        return;
    }

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    free(temp);
    temp = NULL;
}

// function to delete a node from the given position
void delete_at_position(int position)
{
    if (position <= 0)
    {
        printf("\n Invalid Position \n");
    }
    else if (position > size_of_list())
    {
        printf("\n Invalid position \n");
    }
    else if (position == 1)
    {
        delete_at_begin();
    }
    else if (position == size_of_list())
    {
        delete_at_end();
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        int i = 1;

        while (i < position)
        {
            prev = temp;
            temp = temp->next;
            i += 1;
        }

        prev->next = temp->next;
        free(temp);
        temp = NULL;
    }
}

// print the node values
void print_list()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\n List is Empty! \n");
        return;
    }

    printf("\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// search a data into the list
void search(int key)
{
    struct node *temp = head;

    while (temp->next != head)
    {
         temp = temp->next;
        if (temp->data == key)
        {
            printf("\n\t Data Found\n");
            return;
        }
       
    } 
    printf("\n\tData not Found\n");
}




// function to calculate the size of the list
int size_of_list()
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *temp = head;
    int count = 1;

    while (temp->next != head)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

int getData()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);

    return data;
}

int getPosition()
{
    int pos;
    printf("\n\nEnter Position: ");
    scanf("%d", &pos);

    return pos;
}