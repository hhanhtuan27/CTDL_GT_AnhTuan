#include <iostream>

using namespace std;

// Cấu trúc của một nút trong cây nhị phân
struct NODE {
    int data;
    NODE* left;
    NODE* right;
};

// Hàm tạo một nút mới
NODE* createNode(int data) {
    NODE* newNode = new NODE();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Hàm tính tổng số nút có một nhánh con (sử dụng duyệt NLR - gốc trước)
int countOneChildNodes(NODE* root) {
    if (root == nullptr) return 0;
    
    int count = 0;
    if ((root->left == nullptr && root->right != nullptr) ||
        (root->left != nullptr && root->right == nullptr)) {
        count = 1;
    }
    
    return count + countOneChildNodes(root->left) + countOneChildNodes(root->right);
}

// Hàm main để kiểm tra chương trình
int main() {
    // Tạo cây nhị phân mẫu
    NODE* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->right = createNode(5);
    root->right->right->left = createNode(6);
    
    cout << "So nut co mot nhanh con: " << countOneChildNodes(root) << endl;
    
    return 0;
}