#include <iostream>
#include <fstream>

using namespace std;

// Cấu trúc của một nút trong cây nhị phân tìm kiếm
struct BST_NODE {
    int Key; // Khóa của nút
    int So_lan; // Số lần xuất hiện
    BST_NODE* Left;
    BST_NODE* Right;
};

// Cấu trúc cây nhị phân tìm kiếm
struct BST_TREE {
    BST_NODE* pRoot; // Nút gốc của cây
};

// Hàm tạo một nút mới
BST_NODE* createNode(int key) {
    BST_NODE* newNode = new BST_NODE();
    newNode->Key = key;
    newNode->So_lan = 1;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
}

// Hàm tìm phần tử tận cùng bên trái của cây con phải
BST_NODE* findMinRightSubtree(BST_NODE* root) {
    while (root->Left != nullptr)
        root = root->Left;
    return root;
}

// Hàm tìm và xóa phần tử có khóa X trong cây
BST_NODE* deleteNode(BST_NODE* root, int X) {
    if (root == nullptr) {
        cout << "Phan tu " << X << " khong ton tai trong cay.\n";
        return root;
    }
    if (X < root->Key)
        root->Left = deleteNode(root->Left, X);
    else if (X > root->Key)
        root->Right = deleteNode(root->Right, X);
    else {
        if (root->So_lan > 1) {
            root->So_lan--; // Giảm số lần xuất hiện
            return root;
        }
        if (root->Left == nullptr) {
            BST_NODE* temp = root->Right;
            delete root;
            return temp;
        } else if (root->Right == nullptr) {
            BST_NODE* temp = root->Left;
            delete root;
            return temp;
        }
        BST_NODE* temp = findMinRightSubtree(root->Right);
        root->Key = temp->Key;
        root->So_lan = temp->So_lan;
        temp->So_lan = 1;
        root->Right = deleteNode(root->Right, temp->Key);
    }
    return root;
}

// Hàm in cây theo thứ tự NLR
void printNLR(BST_NODE* root) {
    if (root == nullptr)
        return;
    cout << root->Key << "(" << root->So_lan << ") ";
    printNLR(root->Left);
    printNLR(root->Right);
}

// Hàm chèn một phần tử vào cây
BST_NODE* insert(BST_NODE* root, int key) {
    if (root == nullptr)
        return createNode(key);
    if (key < root->Key)
        root->Left = insert(root->Left, key);
    else if (key > root->Key)
        root->Right = insert(root->Right, key);
    else
        root->So_lan++;
    return root;
}

int main() {
    BST_TREE t;
    t.pRoot = nullptr;
    
    // Chèn một số phần tử
    t.pRoot = insert(t.pRoot, 10);
    t.pRoot = insert(t.pRoot, 5);
    t.pRoot = insert(t.pRoot, 15);
    t.pRoot = insert(t.pRoot, 10);
    t.pRoot = insert(t.pRoot, 12);
    t.pRoot = insert(t.pRoot, 17);
    
    cout << "Cay truoc khi xoa:\n";
    printNLR(t.pRoot);
    cout << endl;
    
    // Xóa một phần tử có hai con
    t.pRoot = deleteNode(t.pRoot, 10);
    
    cout << "Cay sau khi xoa:\n";
    printNLR(t.pRoot);
    cout << endl;
    
    return 0;
}