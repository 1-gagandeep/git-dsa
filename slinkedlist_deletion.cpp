#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

void insert_beg(struct node* &head) {
    struct node* temp = new node();

    int ele;
    cin >> ele;

    if(temp == NULL) {
        temp -> data = ele;
        temp -> next = NULL;
        head = temp;
    }

    else {
        temp -> data = ele;
        temp -> next = head;
        head = temp;
    }

}

void traverse(struct node* &head) {
    struct node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void delete_beg(struct node* &head) {
    struct node* temp;

    if(head == NULL) {
        cout << "List is empty";
        return;
    }

    else {
        temp = head;
        head = head -> next;
        free(temp);
    }
}

void delete_end(struct node* &head) {
    struct node* temp = head;
    struct node* temp1;

    while(temp -> next != NULL) {
        temp1 = temp;
        temp = temp -> next;
    }

    temp1 -> next = NULL;
    free(temp);
}

void delete_after(struct node* &head, int ele) {
    struct node* temp = head;
    struct node* loc;
    
    while(temp != NULL) {
        loc = temp -> next;

        if(loc -> data == ele) {
            temp -> next = loc -> next;
            free(loc);
            break;
        }
        temp = temp -> next;
    }
}
int main() {
    struct node* head = NULL;
    insert_beg(head);
    insert_beg(head);
    insert_beg(head);
    insert_beg(head);
    insert_beg(head);

    cout << "Data after insertion ";
    traverse(head);

    delete_beg(head);
    cout << "Data after start deletion ";
    traverse(head);

    delete_end(head);
    cout << "Data after end deletion ";
    traverse(head);

    delete_after(head, 30);
    cout << "Data after after deletion ";
    traverse(head);
}