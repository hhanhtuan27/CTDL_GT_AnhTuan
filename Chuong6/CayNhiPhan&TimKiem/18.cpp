#include <iostream>
#include <vector>

using namespace std;

// Cấu trúc của một nút trong cây nhị phân tìm kiếm
struct BST_NODE {
    int Key; // Khóa của nút
    BST_NODE* Left;
    BST_NODE* Right;
};

// Hàm tạo một nút mới
BST_NODE* createNode(int key) {
    BST_NODE* newNode = new BST_NODE();
    newNode->Key = key;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
}

// Hàm chèn một phần tử vào cây
BST_NODE* insert(BST_NODE* root, int key) {
    if (root == nullptr)
        return createNode(key);
    if (key < root->Key)
        root->Left = insert(root->Left, key);
    else if (key > root->Key)
        root->Right = insert(root->Right, key);
    return root;
}

// Hàm duyệt cây theo thứ tự LNR và đưa các phần tử vào mảng
void inorderTraversal(BST_NODE* root, vector<int>& arr) {
    if (root == nullptr)
        return;
    inorderTraversal(root->Left, arr);
    arr.push_back(root->Key);
    inorderTraversal(root->Right, arr);
}

// Hàm tạo cây từ mảng
BST_NODE* buildBSTFromArray(const vector<int>& arr) {
    BST_NODE* root = nullptr;
    for (int key : arr) {
        root = insert(root, key);
    }
    return root;
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 3, 7, 9};
    cout << "Mang ban dau: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    // Xây dựng cây BST từ mảng
    BST_NODE* root = buildBSTFromArray(arr);
    
    // Duyệt cây theo thứ tự LNR để đưa phần tử vào mảng
    vector<int> sortedArr;
    inorderTraversal(root, sortedArr);
    
    cout << "Mang sau khi sap xep: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
