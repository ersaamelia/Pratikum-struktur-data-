#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* insertNode(TNode* root, int value) {
    if (root == NULL) {
        return new TNode(value);
    }
    queue<TNode*> q;
    q.push(root);

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TNode(value);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TNode(value);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

TNode* findNode(TNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    TNode* leftResult = findNode(root->left, value);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(root->right, value);
}

void displayChildren(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Children of node " << node->data << ": ";
    if (node->left) {
        cout << node->left->data << " ";
    }
    if (node->right) {
        cout << node->right->data << " ";
    }
    cout << endl;
}

void displayDescendants(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    queue<TNode*> q;
    q.push(node);
    q.pop(); // Pop the node itself to avoid printing it

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left) {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }

        if (temp->right) {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    TNode *root = NULL;
    int choice, value, nodeValue;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Display PreOrder\n";
        cout << "3. Display InOrder\n";
        cout << "4. Display PostOrder\n";
        cout << "5. Display Children of a Node\n";
        cout << "6. Display Descendants of a Node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                preOrder(root);
                cout << endl;
                break;
            case 3:
                inOrder(root);
                cout << endl;
                break;
            case 4:
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter node value to find children: ";
                cin >> nodeValue;
                displayChildren(findNode(root, nodeValue));
                break;
            case 6:
                cout << "Enter node value to find descendants: ";
                cin >> nodeValue;
                displayDescendants(findNode(root, nodeValue));
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
