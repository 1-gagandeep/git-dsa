#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

void insert_beg(struct node* &head) {
    struct node *temp;

    int ele;
    cin >> ele;

    temp = new node();

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

void insert_end(struct node* &head) {
    struct node* temp = new node();

    int ele;
    cin >> ele;

    temp -> next = NULL;
    temp -> data = ele;

    if(head == NULL) {
        head = temp;
    }

    else {
        struct node* tail = head;
        while(tail -> next != NULL) {
            tail = tail -> next;
        }
        tail -> next = temp;
    }
}

void insert_after(struct node* &head) {
    struct node* temp = new node();
    

    int ele;
    cin >> ele;

    int item;
    cin >> item;

    temp -> data = ele;

    if(head == NULL) 
    {
        head = temp;
        temp -> next = NULL;
    }

    else {
        struct node* current = head;
        while(current != NULL) {
            if(current->data == item) {
                temp->next = current->next;
                current->next=temp;
                break;
            }

            current=current->next;
        }
    }
}

void traverse(struct node* &head) {
    struct node *temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    struct node *head = NULL;

    insert_beg(head);
    insert_beg(head);
    insert_beg(head);
    insert_beg(head);
    
    cout << "Data after beginning insertion: ";
    traverse(head);

    insert_end(head);
    insert_end(head);
    cout << "Data after end insertion: ";
    traverse(head);

    insert_after(head);
    cout << "Data after after insertion: ";
    traverse(head);

}
