// Implement a doubly linked list with operations: insert at front, insert to the left of a key 
//node, delete by value, and display. 

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *leftlink;
    int data;
    struct node *rlink;
};
typedef struct node NODE;

NODE *insertfront(NODE*, int);
NODE *insertBefore(NODE*, int /* key */, int /* n */);
NODE *del_by_value(NODE*, int);
void display(NODE*);

void main(){
    NODE *start = NULL;
    int num, choice;

    while(1){
        printf("\nEnter your choice:\n");
        printf("1. Insert at front\n");
        printf("2. Insert to the left of the keynode\n");
        printf("3. Delete by value\n");
        printf("4. Display\n");
        printf("5. Stop\n\n");
        
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &num);
                start = insertfront(start, num);
                break;
            case 2:
                {
                    int key;
                    printf("Enter the key: ");
                    scanf("%d", &key);
                    printf("Enter the number to be inserted: ");
                    scanf("%d", &num);
                    start = insertBefore(start, key, num);
                }
                break;
            case 3:
                {
                    int val;
                    printf("Enter the value to be deleted: ");
                    scanf("%d", &val);
                    start = del_by_value(start, val);
                }
                break;
            case 4:
                display(start);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

NODE* insertfront(NODE *start, int n) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if(new_node == NULL){
        printf("Memory allocation failed.\n");
        return start;
    }
    new_node->data = n;
    new_node->leftlink = NULL;
    new_node->rlink = NULL;

    if(start == NULL){
        start = new_node;
    } else {
        new_node->rlink = start;
        start->leftlink = new_node;
        start = new_node;
    }
    return start;
}

/* Insert `n` to the left of the node whose data == key.
   Signature is (start, key, n) to match the call site in main. */
NODE* insertBefore(NODE *start, int key, int n) {
    NODE *new_node, *temp, *ptr;
    if(start == NULL){
        printf("List empty. Cannot insert to the left of key %d.\n", key);
        return start;
    }

    /* allocate node */
    new_node = (NODE *) malloc(sizeof(NODE));
    if(new_node == NULL){
        printf("Memory allocation failed.\n");
        return start;
    }
    new_node->data = n;
    new_node->leftlink = NULL;
    new_node->rlink = NULL;

    /* if key is at start, insert at front */
    if(start->data == key) {
        new_node->rlink = start;
        start->leftlink = new_node;
        start = new_node;
        return start;
    }

    /* traverse to find key */
    ptr = start;
    temp = NULL;
    while(ptr != NULL && ptr->data != key) {
        temp = ptr;
        ptr = ptr->rlink;
    }
    if(ptr == NULL) {
        printf("Invalid key: %d\n", key);
        free(new_node);
    } else {
        /* insert between temp and ptr */
        new_node->rlink = ptr;
        new_node->leftlink = temp;
        temp->rlink = new_node;
        ptr->leftlink = new_node;
    }

    return start;
}

NODE *del_by_value(NODE *start, int key) {
    NODE *ptr, *temp;
    if(start == NULL) {
        printf("List empty\n");
        return start;
    }

    /* if first node holds the key */
    if(start->data == key) {
        ptr = start;
        start = start->rlink;
        if(start != NULL) {
            start->leftlink = NULL;
        }
        printf("Item deleted: %d\n", ptr->data);
        free(ptr);
        return start;
    }

    /* traverse to find key */
    ptr = start;
    temp = NULL;
    while(ptr != NULL && ptr->data != key) {
        temp = ptr;
        ptr = ptr->rlink;
    }
    if(ptr == NULL) {
        printf("Invalid key number: %d\n", key);
    } else {
        temp->rlink = ptr->rlink;
        if(ptr->rlink != NULL) {
            ptr->rlink->leftlink = temp;
        }
        printf("Item deleted: %d\n", ptr->data);
        free(ptr);
    }
    return start;
}

void display(NODE *start) {
    NODE *ptr = start;
    if(start == NULL){
        printf("List is empty\n");
        return;
    }
    printf("The list data are: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->rlink;
    }
    printf("\n");
}
