// Implement a circular singly linked list with operations: insert at end, delete by key, and display nodes. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;
NODE* insertend(NODE *, int);
NODE* deleteByKey(NODE *, int);
void display(NODE *);

int main() 
{
    NODE *start = NULL;
    int choice, num, key;

    while (1) {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert at end\n2. Delete by key\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &num);
                start = insertend(start, num);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                start = deleteByKey(start, key);
                break;
            case 3:
                display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to insert a node at the end
NODE* insertend(NODE *start, int n) 
{ 
    NODE *new_node, *ptr; 
    new_node = (NODE *) malloc(sizeof(NODE));  
    new_node->data = n; 

    if(start == NULL) {            
        start = new_node; 
        start->next = start; 
    } 
    else { 
        ptr = start;   
        while(ptr->next != start) { 
            ptr = ptr->next; 
        } 
        ptr->next = new_node;
        new_node->next = start; 
    } 
    return start; 
}

// Function to delete a node by key
NODE* deleteByKey(NODE *start, int key)
{
    NODE *ptr = start, *prev = NULL;

    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }

    do {
        if (ptr->data == key) {

            if (ptr == start) {
                if (start->next == start) {
                    printf("Deleted element: %d\n", start->data);
                    free(start);
                    return NULL;
                }

                prev = start;
                while (prev->next != start)
                    prev = prev->next;

                start = start->next;
                prev->next = start;
            } 
            else {
                prev->next = ptr->next;
            }

            printf("Deleted element: %d\n", ptr->data);
            free(ptr);
            return start;
        }

        prev = ptr;
        ptr = ptr->next;

    } while (ptr != start);

    printf("Key not found\n");
    return start;
}



// Function to display the circular list
void display(NODE *start) 
{ 
    NODE *ptr; 
    ptr = start; 

    if (ptr == NULL) {          
        printf("List is empty\n");  
        return;   
    } 

    printf("The list data are:\n"); 
    do { 
        printf("%d ", ptr->data); 
        ptr = ptr->next; 
    } while(ptr != start);
    printf("\n");
}

/*
--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 1
Enter number to insert: 3

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 1
Enter number to insert: 6

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 2
Enter key to delete: 6
Deleted element: 6

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 2
Enter key to delete: 3

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 2
Enter key to delete: 3
List is empty

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 3
List is empty

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 1
Enter number to insert: 2

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 1
Enter number to insert: 5

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 3
The list data are:
2 5

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 2
Enter key to delete: 7
Key not found

--- Circular Singly Linked List ---
1. Insert at end
2. Delete by key
3. Display
4. Exit
Enter your choice: 4
*/