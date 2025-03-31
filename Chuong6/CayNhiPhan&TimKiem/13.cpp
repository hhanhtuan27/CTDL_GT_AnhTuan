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

// Hàm lưu cây xuống tập tin nhị phân theo thứ tự NLR
void saveTree(ofstream &file, NODE* root) {
    if (root == nullptr) {
        double nullMarker = -1.0; // Dùng giá trị đặc biệt để đánh dấu nút null
        file.write(reinterpret_cast<const char*>(&nullMarker), sizeof(nullMarker));
        return;
    }
    file.write(reinterpret_cast<const char*>(&root->data), sizeof(root->data));
    saveTree(file, root->left);
    saveTree(file, root->right);
}

// Hàm đọc cây từ tập tin nhị phân
NODE* loadTree(ifstream &file) {
    double value;
    file.read(reinterpret_cast<char*>(&value), sizeof(value));
    if (file.eof() || value == -1.0) return nullptr; // Nếu gặp nullMarker, trả về nullptr
    
    NODE* root = createNode(value);
    root->left = loadTree(file);
    root->right = loadTree(file);
    return root;
}