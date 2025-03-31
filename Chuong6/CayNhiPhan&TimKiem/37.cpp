#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

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

// Hàm tính chiều cao của một nút
int ChieuCao(BST_NODE* p) {
    if (p == nullptr)
        return 0;
    return 1 + max(ChieuCao(p->Left), ChieuCao(p->Right));
}

// Hàm kiểm tra cây có cân bằng hay không
bool isBalanced(BST_NODE* root) {
    if (root == nullptr)
        return true;
    int leftHeight = ChieuCao(root->Left);
    int rightHeight = ChieuCao(root->Right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return isBalanced(root->Left) && isBalanced(root->Right);
}

// Hàm duyệt cây theo thứ tự NLR không dùng đệ quy (dùng stack)
void preorderTraversal(BST_NODE* root) {
    if (root == nullptr)
        return;
    stack<BST_NODE*> s;
    s.push(root);
    while (!s.empty()) {
        BST_NODE* current = s.top();
        s.pop();
        cout << current->Key << " ";
        if (current->Right)
            s.push(current->Right);
        if (current->Left)
            s.push(current->Left);
    }
}

// Hàm duyệt cây theo mức không dùng đệ quy (dùng queue)
void levelOrderTraversal(BST_NODE* root) {
    if (root == nullptr)
        return;
    queue<BST_NODE*> q;
    q.push(root);
    while (!q.empty()) {
        BST_NODE* current = q.front();
        q.pop();
        cout << current->Key << " ";
        if (current->Left)
            q.push(current->Left);
        if (current->Right)
            q.push(current->Right);
    }
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
    
    cout << "Duyet cay theo NLR (khong de quy): ";
    preorderTraversal(root);
    cout << endl;
    
    cout << "Duyet cay theo muc (khong de quy): ";
    levelOrderTraversal(root);
    cout << endl;
    
    cout << "Cay co can bang khong? ";
    cout << (isBalanced(root) ? "Co" : "Khong") << endl;
    
    return 0;
}