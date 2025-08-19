#include<iostream>
using namespace std;
struct tree {
    tree *left, *right;
    int data;
};

tree *root = NULL;

void create(tree *&root) {
    int value;
    char ch;

    if (root == NULL) {
        root = new tree;
        cout << "\n Enter the value of the root node: ";
        cin >> root->data;
        root->left = root->right = NULL;
    }

    do {
        tree *p = root;
        cout << "\n Enter the value of the node: ";
        cin >> value;

        while (p) {
            if (value < p->data) {
                if (p->left == NULL) {
                    p->left = new tree;
                    p = p->left;
                    p->data = value;
                    p->left = p->right = NULL;
                    cout << "\n Value entered in left";
                    break;
                } else {
                    p = p->left;
                }
            } else if (value > p->data) {
                if (p->right == NULL) {
                    p->right = new tree;
                    p = p->right;
                    p->data = value;
                    p->left = p->right = NULL;
                    cout << "\n Value entered in right";
                    break;
                } else {
                    p = p->right;
                }
            } else {
                cout << "\n Duplicate value encountered. Ignoring.\n";
                break;
            }
        }

        cout << "\n Do you want to continue (y/n)? ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void inorder(tree *p) {
    if (p != NULL) {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}

void preorder(tree *p) {
    if (p != NULL) {
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(tree *p) {
    if (p != NULL) {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
}

int main() {
    create(root);

    cout << "\n Printing traversal in inorder: ";
    inorder(root);

    cout << "\n Printing traversal in preorder: ";
    preorder(root);

    cout << "\n Printing traversal in postorder: ";
    postorder(root);

    return 0;
}
