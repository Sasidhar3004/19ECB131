BINARY SEARCH TREE 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* new_node(int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

struct node* insert(struct node *root, int x) {
    if (!root) return new_node(x);
    if (x > root->data) root->right = insert(root->right, x);
    else root->left = insert(root->left, x);
    return root;
}

struct node* search(struct node *root, int x) {
    if (!root || root->data == x) return root;
    return x > root->data ? search(root->right, x) : search(root->left, x);
}

struct node* find_minimum(struct node *root) {
    while (root && root->left) root = root->left;
    return root;
}

struct node* delete(struct node *root, int x) {
    if (!root) return NULL;
    if (x > root->data) root->right = delete(root->right, x);
    else if (x < root->data) root->left = delete(root->left, x);
    else {
        if (!root->left && !root->right) { free(root); return NULL; }
        if (!root->left || !root->right) {
            struct node *temp = root->left ? root->left : root->right;
            free(root); return temp;
        }
        struct node *temp = find_minimum(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = new_node(20);
    int keys[] = {5, 1, 15, 9, 7, 12, 30, 25, 40, 45, 42};
    for (int i = 0; i < 11; i++) insert(root, keys[i]);

    inorder(root); printf("\n");

    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);

    inorder(root); printf("\n");

    return 0;
}
