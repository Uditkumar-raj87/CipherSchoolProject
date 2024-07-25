#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BST {
private:
    TreeNode* root;
    TreeNode* insertRecursive(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }
        if (key < root->val) {
            root->left = insertRecursive(root->left, key);
        } else {
            root->right = insertRecursive(root->right, key);
        }
        return root;
    }

    TreeNode* searchRecursive(TreeNode* root, int key) {
        if (root == nullptr || root->val == key) {
            return root;
        }
        if (key < root->val) {
            return searchRecursive(root->left, key);
        } else {
            return searchRecursive(root->right, key);
        }
    }

    TreeNode* deleteRecursive(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->val) {
            root->left = deleteRecursive(root->left, key);
        } else if (key > root->val) {
            root->right = deleteRecursive(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteRecursive(root->right, temp->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            inorderRecursive(root->left);
            cout << root->val << " ";
            inorderRecursive(root->right);
        }
    }

    void preorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " ";
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    void postorderRecursive(TreeNode* root) {
        if (root != nullptr) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            cout << root->val << " ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    TreeNode* search(int key) {
        return searchRecursive(root, key);
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    void preorderTraversal() {
        preorderRecursive(root);
        cout << endl;
    }

    void postorderTraversal() {
        postorderRecursive(root);
        cout << endl;
    }
};
void takeUserInput(BST& bst) {
    int choice;
    int key;
    do {
        cout << "\nBinary Search Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (bst.search(key)) {
                    cout << "Key " << key << " found in the tree." << endl;
                } else {
                    cout << "Key " << key << " not found in the tree." << endl;
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.remove(key);
                cout << "Key " << key << " deleted from the tree." << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                bst.inorderTraversal();
                break;
            case 5:
                cout << "Preorder Traversal: ";
                bst.preorderTraversal();
                break;
            case 6:
                cout << "Postorder Traversal: ";
                bst.postorderTraversal();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid choice." << endl;
        }
    } while (choice != 7);
}
int main() {
    BST bst;
    takeUserInput(bst);
    return 0;
}
