#include<iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

  TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}   
};

struct StackNode {
    TreeNode* node;
    StackNode* next;

    StackNode(TreeNode* n):node(n), next(nullptr) {}
};

class CustomStack {
    public:
    CustomStack():top(nullptr) {}

    void push(TreeNode* node) {
        StackNode* newNode = new StackNode(node);

        if(top == nullptr) {
            top = newNode;
        }

        else {
            newNode -> next = top;
            top = newNode;
        }
    }

    TreeNode* pop() {
        if(isEmpty()) {
            return nullptr;
        }

        StackNode* temp = top;
        TreeNode* node = temp -> node;
            top = top -> next;
            delete temp;
            return node;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    private:
    StackNode* top;
};

void inorderNonRecursive(TreeNode* root) {
    if(!root) 
        return;

    CustomStack stack;
    TreeNode* current = root;

    while(current || !stack.isEmpty()) {
        while(current) {
            stack.push(current);

            current = current -> left;
        }

        current = stack.pop();

        cout << current -> value << " ";

        current = current -> right;
    }
}

void preorderNonRecursive(TreeNode* root) {
    if(!root)
        return;

    CustomStack stack;
    stack.push(root);

    while(!stack.isEmpty()) {
        TreeNode* current = stack.pop();

        cout << current -> value << " ";

        if(current -> right)
        stack.push(current -> right);

        if(current -> left) 
        stack.push(current -> left);
    }
}

void postorderNonRecursive(TreeNode* root) {
    CustomStack stack1, stack2;

    stack1.push(root);

    while(!stack1.isEmpty()) {
        TreeNode* current = stack1.pop();
        stack2.push(current);

        if(current -> left)
            stack1.push(current -> left);

        if(current -> right)
            stack1.push(current -> right);
    }

    while(!stack2.isEmpty()) {
        TreeNode* current = stack2.pop();
        cout << current -> value << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(30);
    root -> left -> left = new TreeNode(40);
    root -> left -> right = new TreeNode(50);
    root -> left -> right -> left = new TreeNode(60);

    cout << "Inorder (Non-Recursive): ";
    inorderNonRecursive(root);
    cout << endl;

    cout << "Preorder (Non-Recursive): ";
    preorderNonRecursive(root);
    cout << endl;

    cout << "Postorder (Non-Recursive): ";
    postorderNonRecursive(root);
    cout << endl;
}