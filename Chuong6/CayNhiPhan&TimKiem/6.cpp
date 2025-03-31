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

// Hàm đệ quy tính số nút trong cây nhị phân tìm kiếm
int countNodes(NODE* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Hàm đệ quy tính tổng giá trị các nút trong cây nhị phân tìm kiếm
int sumNodes(NODE* root) {
    if (root == nullptr) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Hàm main để kiểm tra chương trình
int main() {
    return 0;
}
