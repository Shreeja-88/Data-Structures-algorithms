//count the number of leaf nodes in the bst
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
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
int totalleafnodes(struct node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        printf("Leaf Node: %d\n", root->data);
        return 1;
    }
    return totalleafnodes(root->left) + totalleafnodes(root->right);
}
int main(){
    struct node* root = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values: \n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        root = insertnode(root, data);
    }
    printf("Total leaf nodes in the BST: %d\n", totalleafnodes(root));
    return 0;
}

/*
Enter the number of nodes: 5
Enter 5 values: 
1 4 5 2 3 
Leaf Node: 3
Leaf Node: 5
Total leaf nodes in the BST: 2
*/