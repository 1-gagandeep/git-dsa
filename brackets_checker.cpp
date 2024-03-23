#include<iostream>
#include<cstring>
using namespace std;

#define MAX 100

int top = -1;
char stack[MAX];


int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(char c) {
    if(isFull()) {
        cout << "Stack overflow";
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (isEmpty()) {
        cout << "Stack underflow";
        return '\0';
    }
    c = stack[top];
    top--;
    return c;
}

int match_char(char a, char b) {
    if((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && ')')) {
        return 1;
    }
    
    else {
        return 0;
    }
}

int check_bal(char* s) {
    char temp;
    for(int i=0; i<strlen(s); i++) {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(') {
            push(s[i]);
        }
        
        else if(s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if(isEmpty()) {
                cout << "Closing brackets are more than opening.";
                return 0;
            }
            
            else {
                temp = pop();
                if(!match_char(temp, s[i])) {
                    cout << "Mismatched brackets." << endl;
                    return 0;
                }
        }
    }
}

if(isEmpty()) {
    cout << "Brackets are well balanced." << endl;
    return 1;
}

else {
    cout << "Opening brackets are more than closing." << endl;
    return 0;
}
}

int main() {
    char exp[MAX];
    cout << "Enter the expression: ";
    fgets(exp, MAX, stdin);
    int bal = check_bal(exp);
    
    if(bal == 1) {
        cout << "The expression is valid";
    }
    
    else {
        cout << "The expression is invalid";
    }
}
