#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(NULL) {}

    TreeNode* insert(TreeNode* node, int value) {
        if (node == NULL) return new TreeNode(value);
        if (value < node->val)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void buildTree() {
        root = insert(root, 10);
        root = insert(root, 5);
        root = insert(root, 15);
        root = insert(root, 3);
        root = insert(root, 9);
        root = insert(root, 7);
        root = insert(root, 12);
        root = insert(root, 18);
        root = insert(root, 20);
    }

    void transformTree() {
        TreeNode* newRoot = root;
        TreeNode* temp = root->left; 
        root->left = root->right;
        root->right = temp;
    }

    void inorder(TreeNode* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void printTree() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.buildTree();
    cout << "Cay ban dau: ";
    tree.printTree();
    
    tree.transformTree();
    cout << "Cay sau khi bien doi: ";
    tree.printTree();
    
    return 0;
}