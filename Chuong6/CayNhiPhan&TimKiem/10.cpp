#include <iostream>
#include <fstream>

using namespace std;

// Cấu trúc của một nút trong cây nhị phân
struct NODE {
    double data;
    NODE* left;
    NODE* right;
};

// Hàm tạo một nút mới
NODE* createNode(double data) {
    NODE* newNode = new NODE();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Hàm duyệt cây theo phương pháp LRN và ghi ra tập tin nhị phân
void postOrderToFile(NODE* root, ofstream &file) {
    if (root == nullptr) return;
    
    postOrderToFile(root->left, file);
    postOrderToFile(root->right, file);
    file.write(reinterpret_cast<const char*>(&root->data), sizeof(root->data));
}

// Hàm kiểm tra test case 1
void testCase1() {
    NODE* root = createNode(2.5);
    root->left = createNode(1.2);
    root->right = createNode(3.8);
    ofstream file("data1.out", ios::binary);
    postOrderToFile(root, file);
    file.close();
}

// Hàm kiểm tra test case 2
void testCase2() {
    NODE* root = createNode(5.0);
    root->left = createNode(2.3);
    root->right = createNode(7.8);
    root->left->left = createNode(1.1);
    root->left->right = createNode(3.4);
    ofstream file("data2.out", ios::binary);
    postOrderToFile(root, file);
    file.close();
}

// Hàm main để gọi các test case
int main() {
    testCase1();
    testCase2();
    return 0;
}
