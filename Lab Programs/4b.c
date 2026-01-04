// Implement a circular doubly linked list with operations: insert at front/end, delete by key, and display nodes in forward and
//reverse directions.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *rlink;     // next pointer
    struct node *leftlink;  // previous pointer
} NODE;

// Insert at front
NODE* insertfront(NODE *start, int n) {
    NODE *new_node, *ptr;
    new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = n;
    new_node->rlink = new_node->leftlink = NULL;

    if (start == NULL) {
        start = new_node;
        start->rlink = start;
        start->leftlink = start;
    } else {
        ptr = start;
        while (ptr->rlink != start) {
            ptr = ptr->rlink;
        }
        ptr->rlink = new_node;
        new_node->leftlink = ptr;
        new_node->rlink = start;
        start->leftlink = new_node;
        start = new_node;  // new node becomes start
    }
    return start;
}

// Insert at end
NODE* insertend(NODE *start, int n) {
    NODE *new_node, *ptr;
    new_node = (NODE *) malloc(sizeof(NODE));
    new_node->data = n;
    new_node->rlink = new_node->leftlink = NULL;

    if (start == NULL) {
        start = new_node;
        start->rlink = start;
        start->leftlink = start;
    } else {
        ptr = start;
        while (ptr->rlink != start) {
            ptr = ptr->rlink;
        }
        ptr->rlink = new_node;
        new_node->leftlink = ptr;
        new_node->rlink = start;
        start->leftlink = new_node;
    }
    return start;
}

// Delete by key
NODE* deletekey(NODE *start, int key) {
    NODE *ptr = start, *temp;

    if (start == NULL) {
        printf("List Empty\n");
        return start;
    }

    do {
        if (ptr->data == key) {
            // Case: only one node
            if (ptr->rlink == ptr && ptr->leftlink == ptr) {
                printf("Item deleted: %d\n", ptr->data);
                free(ptr);
                return NULL;
            }

            // Case: deleting start node
            if (ptr == start) {
                temp = start;
                while (temp->rlink != start) {
                    temp = temp->rlink;
                }
                start = start->rlink;
                temp->rlink = start;
                start->leftlink = temp;
                printf("Item deleted: %d\n", ptr->data);
                free(ptr);
                return start;
            }

            // Case: deleting middle/end node
            ptr->leftlink->rlink = ptr->rlink;
            ptr->rlink->leftlink = ptr->leftlink;
            printf("Item deleted: %d\n", ptr->data);
            free(ptr);
            return start;
        }
        ptr = ptr->rlink;
    } while (ptr != start);

    printf("Key %d not found\n", key);
    return start;
}

// Display forward
void displayForward(NODE *start) {
    NODE *ptr = start;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Forward traversal:\n");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->rlink;
    } while (ptr != start);
    printf("\n");
}

// Display reverse
void displayReverse(NODE *start) {
    NODE *ptr;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    ptr = start->leftlink;  // last node

    printf("Reverse traversal:\n");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->leftlink;
    } while (ptr != start->leftlink);

    printf("\n");
}

// Menu-driven main
int main() {
    NODE *start = NULL;
    int choice, val;

    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Key\n");
        printf("4. Display Forward\n");
        printf("5. Display Reverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                start = insertfront(start, val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                start = insertend(start, val);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &val);
                start = deletekey(start, val);
                break;
            case 4:
                displayForward(start);
                break;
            case 5:
                displayReverse(start);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

/*
output:
--- Circular Doubly Linked List Menu ---
1. Insert at Front
2. Insert at End
3. Delete by Key
4. Display Forward
5. Display Reverse
6. Exit
Enter your choice: 1
Enter value to insert at front: 10

Enter your choice: 2
Enter value to insert at end: 20

Enter your choice: 4
Forward traversal:
10 20

Enter your choice: 5
Reverse traversal:
20 10

Enter your choice: 3
Enter key to delete: 10
Item deleted: 10

Enter your choice: 4
Forward traversal:
20
*/