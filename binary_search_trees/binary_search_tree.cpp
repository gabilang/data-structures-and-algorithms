#include<iostream>

// Node structure for BST
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {

    private:
        Node* root;
        
        Node* insertRecursive(Node* root, int key) {
            if (root == nullptr) {
                return new Node(key);
            }
            if (key < root->key) {
                root->left = insertRecursive(root->left, key);
            } else if (key > root->key) {
                root->right = insertRecursive(root->right, key);
            }
            return root;
        }

    void inOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        std::cout << root->key << " ";
        inOrderTraversal(root->right);
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* findMax(Node* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    Node* findSuccessor(Node* node) {
        if (node->right != nullptr) {
            return findMin(node->right);
        }
        Node* successor = nullptr;
        Node* ancestor = root;

        while (ancestor != node) {
            if (node->key < ancestor->key) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }

    Node* findPredecessor(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->key == key) {
            if (root->left != nullptr) {
                return findMax(root->left);
            }
        }
        if (root->key > key) {
            return findPredecessor(root->left, key);
        }
        Node* predecessor = findPredecessor(root->right, key);
        if (predecessor == nullptr) {
            return root;
        }
        return predecessor;
    }

    public:
        BinarySearchTree() : root(nullptr) {}

        void insert(int key) {
            root = insertRecursive(root, key);
        }

        void inOrder() {
            inOrderTraversal(root);
        }

        int findMin() {
            Node* minNode = findMin(root);
            return minNode->key;
        }

        int findMax() {
            Node* maxNode = findMax(root);
            return maxNode->key;
        }

        int findSuccessor(int key) {
            Node* successor = findSuccessor(root);
            return successor->key;
        }

        int findPredecessor(int key) {
            Node* predecessor = findPredecessor(root, key);
            return predecessor->key;
        }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(10);
    bst.insert(40);
    bst.insert(70);
    bst.insert(55);
    bst.insert(60);
    bst.insert(80);
    bst.insert(90);

    std::cout << "In-order traversal of BST: \n";
    bst.inOrder();

    std::cout << "\nMin element in BST: " << bst.findMin();

    std::cout << "\nMax element in BST: " << bst.findMax();

    std::cout << "\nSuccessor of 50: " << bst.findSuccessor(50);

    std::cout << "\nPredecessor of 50: " << bst.findPredecessor(50) << "\n";

    return 0;
}