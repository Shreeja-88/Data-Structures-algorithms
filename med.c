#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct Medicine {
    int id;
    char name[MAX];
    char expiry[MAX];
    int quantity;
    struct Medicine *next;
} Medicine;

Medicine *head = NULL;
Medicine* createNode() {
    Medicine *n = (Medicine*)malloc(sizeof(Medicine));

    printf("\n--- Enter Medicine Details ---\n");

    printf("Step 1: Enter Batch ID: ");
    scanf("%d", &n->id);

    printf("Step 2: Enter Medicine Name: ");
    scanf("%s", n->name);

    printf("Step 3: Enter Expiry Date (YYYY-MM-DD): ");
    scanf("%s", n->expiry);

    printf("Step 4: Enter Quantity: ");
    scanf("%d", &n->quantity);

    n->next = NULL;
    return n;
}
void addMedicine() {
    printf("\nAdding a new medicine...\n");

    Medicine *n = createNode();

    if (head == NULL) {
        head = n;
        printf("Medicine added as first record successfully \n");
        return;
    }

    Medicine *t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
    printf("Medicine added to inventory successfully \n");
}
void display() {
    printf("\nDisplaying all medicines...\n");

    if (head == NULL) {
        printf("No medicines available \n");
        return;
    }

    Medicine *t = head;
    int count = 1;

    while (t != NULL) {
        printf("\nMedicine %d:", count++);
        printf("\n  ID       : %d", t->id);
        printf("\n  Name     : %s", t->name);
        printf("\n  Expiry   : %s", t->expiry);
        printf("\n  Quantity : %d\n", t->quantity);
        t = t->next;
    }
}
void search() {
    int id;
    printf("\n Searching medicine...\n");

    printf("Enter Batch ID to search: ");
    scanf("%d", &id);

    Medicine *t = head;

    while (t != NULL) {
        if (t->id == id) {
            printf("\nMedicine Found ");
            printf("\nName     : %s", t->name);
            printf("\nExpiry   : %s", t->expiry);
            printf("\nQuantity : %d\n", t->quantity);
            return;
        }
        t = t->next;
    }

    printf("Medicine not found \n");
}
void deleteMedicine() {
    int id;
    printf("\nDeleting medicine...\n");

    printf("Enter Batch ID to delete: ");
    scanf("%d", &id);

    Medicine *t = head, *p = NULL;

    while (t != NULL && t->id != id) {
        p = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Medicine not found \n");
        return;
    }

    if (p == NULL)
        head = t->next;
    else
        p->next = t->next;

    free(t);
    printf("Medicine deleted successfully \n");
}
void sortByQuantity() {
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    Medicine *ptr1;
    Medicine *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->quantity > ptr1->next->quantity) {

                int id = ptr1->id;
                char name[MAX], expiry[MAX];
                int quantity = ptr1->quantity;

                strcpy(name, ptr1->name);
                strcpy(expiry, ptr1->expiry);

                ptr1->id = ptr1->next->id;
                strcpy(ptr1->name, ptr1->next->name);
                strcpy(ptr1->expiry, ptr1->next->expiry);
                ptr1->quantity = ptr1->next->quantity;

                ptr1->next->id = id;
                strcpy(ptr1->next->name, name);
                strcpy(ptr1->next->expiry, expiry);
                ptr1->next->quantity = quantity;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    display();
}
int main() {
    int ch;

    while (1) {
        printf("\n===============================");
        printf("\n MEDICINE INVENTORY SYSTEM");
        printf("\n===============================");
        printf("\n1. Add Medicine");
        printf("\n2. Delete Medicine");
        printf("\n3. Search Medicine");
        printf("\n4. Display Medicines");
        printf("\n5. Sort by Quantity");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &ch);

        switch (ch) {
            case 1: addMedicine(); break;
            case 2: deleteMedicine(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: sortByQuantity(); break;
            case 6:
                printf("\nExiting program... Thank you \n");
                exit(0);
            default:
                printf("Invalid choice  Please try again\n");
        }
    }
}