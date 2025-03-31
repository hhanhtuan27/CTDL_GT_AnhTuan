#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm tìm giá trị nhỏ nhất trong BST
int findMin(Node* root) {
    if (root == nullptr) {
        cerr << "Cây rỗng!" << endl;
        return -1; // Hoặc có thể ném exception
    }
    
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

// Hàm tìm giá trị lớn nhất trong BST
int findMax(Node* root) {
    if (root == nullptr) {
        cerr << "Cây rỗng!" << endl;
        return -1; // Hoặc có thể ném exception
    }
    
    Node* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

int main() {
    // Tạo cây nhị phân tìm kiếm từ hình ảnh
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->right = new Node(9);
    root->right->left = new Node(12);
    root->right->right = new Node(20);
    root->right->right->left = new Node(18);
    
    // Tìm và in kết quả
    cout << "Phần tử nhỏ nhất trong cây: " << findMin(root) << endl;
    cout << "Phần tử lớn nhất trong cây: " << findMax(root) << endl;
    
    return 0;
}