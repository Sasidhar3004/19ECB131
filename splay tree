SPLAY TREE


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *l_node, *r_node, *p_node;
} node;

typedef struct {
    node *root_node;
} sPlayTree_DS;

node* n_node(int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->p_node = n->l_node = n->r_node = NULL;
    return n;
}

sPlayTree_DS* new_sPlayTree_DS() {
    sPlayTree_DS *t = malloc(sizeof(sPlayTree_DS));
    t->root_node = NULL;
    return t;
}

node* maximum(node *x) {
    while (x && x->r_node) x = x->r_node;
    return x;
}

void l_node_rotate(sPlayTree_DS *t, node *x) {
    node *y = x->r_node;
    x->r_node = y->l_node;
    if (y->l_node) y->l_node->p_node = x;
    y->p_node = x->p_node;
    if (!x->p_node) t->root_node = y;
    else if (x == x->p_node->l_node) x->p_node->l_node = y;
    else x->p_node->r_node = y;
    y->l_node = x;
    x->p_node = y;
}

void r_node_rotate(sPlayTree_DS *t, node *x) {
    node *y = x->l_node;
    x->l_node = y->r_node;
    if (y->r_node) y->r_node->p_node = x;
    y->p_node = x->p_node;
    if (!x->p_node) t->root_node = y;
    else if (x == x->p_node->r_node) x->p_node->r_node = y;
    else x->p_node->l_node = y;
    y->r_node = x;
    x->p_node = y;
}

void splay(sPlayTree_DS *t, node *n) {
    while (n->p_node) {
        if (!n->p_node->p_node) {
            if (n == n->p_node->l_node) r_node_rotate(t, n->p_node);
            else l_node_rotate(t, n->p_node);
        } else {
            node *p = n->p_node, *g = p->p_node;
            if (n == p->l_node && p == g->l_node) {
                r_node_rotate(t, g); r_node_rotate(t, p);
            } else if (n == p->r_node && p == g->r_node) {
                l_node_rotate(t, g); l_node_rotate(t, p);
            } else if (n == p->r_node && p == g->l_node) {
                l_node_rotate(t, p); r_node_rotate(t, g);
            } else {
                r_node_rotate(t, p); l_node_rotate(t, g);
            }
        }
    }
}

void insert(sPlayTree_DS *t, node *n) {
    node *temp = t->root_node, *y = NULL;
    while (temp) {
        y = temp;
        temp = (n->data < temp->data) ? temp->l_node : temp->r_node;
    }
    n->p_node = y;
    if (!y) t->root_node = n;
    else if (n->data < y->data) y->l_node = n;
    else y->r_node = n;
    splay(t, n);
}

node* search(sPlayTree_DS *t, int x) {
    node *n = t->root_node, *last = NULL;
    while (n) {
        last = n;
        if (x == n->data) {
            splay(t, n);
            return n;
        }
        n = (x < n->data) ? n->l_node : n->r_node;
    }
    if (last) splay(t, last);
    return NULL;
}

void delete(sPlayTree_DS *t, node *n) {
    splay(t, n);
    node *l = n->l_node, *r = n->r_node;
    if (l) l->p_node = NULL;
    if (r) r->p_node = NULL;
    free(n);

    if (!l) {
        t->root_node = r;
    } else {
        node *m = maximum(l);
        splay(t, m);
        m->r_node = r;
        if (r) r->p_node = m;
        t->root_node = m;
    }
}

void inorder(node *n) {
    if (n) {
        inorder(n->l_node);
        printf("%d ", n->data);
        inorder(n->r_node);
    }
}

int main() {
    sPlayTree_DS *tree = new_sPlayTree_DS();

    insert(tree, n_node(10));
    insert(tree, n_node(20));
    insert(tree, n_node(30));
    insert(tree, n_node(40));
    insert(tree, n_node(50));

    printf("Before deletion:\n");
    inorder(tree->root_node);
    printf("\n");

    node *n = search(tree, 10); if (n) delete(tree, n);
    n = search(tree, 50); if (n) delete(tree, n);

    printf("After deletion:\n");
    inorder(tree->root_node);
    printf("\n");

    return 0;
}
