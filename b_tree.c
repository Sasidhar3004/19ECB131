B TREE



#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
    int val[MAX + 1], count;
    struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

// Create a node
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
    struct BTreeNode *newNode = malloc(sizeof(struct BTreeNode));
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = root;
    newNode->link[1] = child;
    return newNode;
}

// Insert node
void insertNode(int val, int pos, struct BTreeNode *node, struct BTreeNode *child) {
    for (int j = node->count; j > pos; j--) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
    }
    node->val[pos + 1] = val;
    node->link[pos + 1] = child;
    node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct BTreeNode *node, struct BTreeNode *child, struct BTreeNode **newNode) {
    int median = (pos > MIN) ? MIN + 1 : MIN;
    *newNode = malloc(sizeof(struct BTreeNode));
    for (int j = median + 1; j <= MAX; j++) {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    insertNode(val, pos - median, (pos <= MIN) ? node : *newNode, child);
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

// Set the value
int setValue(int val, int *pval, struct BTreeNode *node, struct BTreeNode **child) {
    if (!node) {
        *pval = val;
        *child = NULL;
        return 1;
    }

    int pos = (val < node->val[1]) ? 0 : node->count;
    while (pos > 1 && val < node->val[pos]) pos--;
    if (val == node->val[pos]) {
        printf("Duplicates not allowed\n");
        return 0;
    }

    if (setValue(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            insertNode(*pval, pos, node, *child);
        } else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

// Insert value into tree
void insert(int val) {
    int flag, i;
    struct BTreeNode *child;
    flag = setValue(val, &i, root, &child);
    if (flag) root = createNode(i, child);
}

// Search for value
void search(int val, struct BTreeNode *node) {
    if (!node) return;
    int pos = (val < node->val[1]) ? 0 : node->count;
    while (pos > 1 && val < node->val[pos]) pos--;
    if (val == node->val[pos]) {
        printf("%d found\n", val);
        return;
    }
    search(val, node->link[pos]);
}

// Traversal
void traversal(struct BTreeNode *node) {
    if (!node) return;
    for (int i = 0; i < node->count; i++) {
        traversal(node->link[i]);
        printf("%d ", node->val[i + 1]);
    }
    traversal(node->link[node->count]);
}

int main() {
    int vals[] = {8, 9, 10, 11, 15, 16, 17, 18, 20, 23};
    for (int i = 0; i < 10; i++) insert(vals[i]);

    traversal(root);
    printf("\n");

    search(11, root);
    return 0;
}
