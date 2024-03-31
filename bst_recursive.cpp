#include<iostream>
#include<stdlib.h>

using namespace std;

struct BST {

    int data;
    struct BST *lc, *rc;
}*temp, *root;

void search(struct BST *t);
void create(int value) {

    temp = new BST;

    temp -> data = value;
    temp -> lc = NULL;
    temp -> rc = NULL;

    if(root == NULL) {
        root = temp;
    }

    else {
        search(root);
    }

}

void search(struct BST *t)
{
    if(temp -> data < t -> data && t -> lc == NULL) {
        t -> lc = temp;
    }

    else if(temp -> data < t -> data && t -> lc != NULL) {
        search(t -> lc);
    }

    if(temp -> data > t -> data && t -> rc == NULL) {
        t -> rc = temp;
    }

    else if(temp -> data > t -> data && t -> rc != NULL) {
        search(t -> rc);
    }
}

void preorder(struct BST *t)
{
    if(root == NULL) {
        cout << "Tree is not created" << endl;
    }
    else {
        // root
        cout << t -> data << "-> \t";

        // left
        if(t -> lc != NULL) {
            preorder(t -> lc);
        }

        // right
        if(t -> rc != NULL) {
            preorder(t -> rc);
        }
    }

}

void inorder(struct BST *t) 
{
    if(root == NULL) {
        cout << "Tree is not created";
    }

    else {
        // left
        if(t -> lc != NULL) {
            inorder(t -> lc);
        }

        // root
        cout << t->data << "-> \t";

        // right
        if(t -> rc != NULL) {
            inorder(t -> rc);
        }
    }
}

void postorder(struct BST *t) 
{
    if(root == NULL) {
        cout << "Tree is not created";

    }

    else {
        // left
        if(t -> lc != NULL) {
            postorder(t -> lc);
        }

        // right
        if(t -> rc != NULL) {
            postorder(t -> rc);
        }

        // root
        cout << t->data << "-> \t";
    }
}

void search_element(struct BST *t, int ele)
{
    if(root == NULL) {
        cout << "Tree is not created";
    }

    else if(t -> data == ele) {
        cout << "\n" << ele << " found ";
    }

    else {
        // left
        if(t -> lc != NULL) {
            search_element(t -> lc, ele);
        }

        // right
        if(t -> rc != NULL) {
            search_element(t -> rc, ele);
        }
    }
}

int main() {
    create(70);
    create(10);
    create(0);
    create(30);
    create(20);
    create(40);
    create(50);
    create(60);
    create(90);
    create(80);
    create(100);

    cout << " \n\n Pre order ";
    preorder(root);
    cout << " \n\n In order ";
    inorder(root);
    cout << " \n\n Post order ";
    postorder(root);
    search_element(root, 910);

}
