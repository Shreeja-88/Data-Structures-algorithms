#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;

struct node *createnode(int data){
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node* insertnode(struct node *root, int data){
    if(root == NULL){
        return createnode(data);
    }
    if(data < root->data){
        root->left = insertnode(root->left, data);
    } else {
        root->right = insertnode(root->right, data);
    }
    return root;
}
/*struct node *insertnode(struct node *root, int data){
    struct node *nn, *ptr, *temp;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->left = NULL;
    nn->right = NULL;
    if(root == NULL){
        root = nn;
    } else {
        ptr = root;
        while(ptr!= NULL){
            temp = ptr;
            if(data < ptr->data){
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if(data < temp->data){
            temp->left = nn;
        } else {
            temp->right = nn;
        }
    }
    return root;
}
    */

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int choice, data;
    root = NULL;
    while(1){
        printf("\n1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertnode(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 5

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 2

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 5

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 1
Enter data to insert: 3

1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 2
Inorder Traversal: 2 3 5 5 
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 3
Preorder Traversal: 5 2 3 5 
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 4
Postorder Traversal: 3 2 5 5 
1. Insert
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Exit
Enter your choice: 5
*/