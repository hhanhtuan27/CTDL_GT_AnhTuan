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

    void insert(int value) {
        root = insertRec(root, value);
    }

    double averageAll() {
        int sum = 0, count = 0;
        sumAndCount(root, sum, count);
        return count == 0 ? 0 : (double)sum / count;
    }

    double averagePositive() {
        int sum = 0, count = 0;
        sumAndCountPositive(root, sum, count);
        return count == 0 ? 0 : (double)sum / count;
    }

    double averageNegative() {
        int sum = 0, count = 0;
        sumAndCountNegative(root, sum, count);
        return count == 0 ? 0 : (double)sum / count;
    }

    double ratioPositiveNegative() {
        int sumPos = 0, sumNeg = 0;
        sumPositive(root, sumPos);
        sumNegative(root, sumNeg);
        return sumNeg == 0 ? 0 : (double)sumPos / (-sumNeg);
    }

private:
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == NULL) return new TreeNode(value);
        if (value < node->val)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }

    void sumAndCount(TreeNode* node, int &sum, int &count) {
        if (node == NULL) return;
        sum += node->val;
        count++;
        sumAndCount(node->left, sum, count);
        sumAndCount(node->right, sum, count);
    }

    void sumAndCountPositive(TreeNode* node, int &sum, int &count) {
        if (node == NULL) return;
        if (node->val > 0) {
            sum += node->val;
            count++;
        }
        sumAndCountPositive(node->left, sum, count);
        sumAndCountPositive(node->right, sum, count);
    }

    void sumAndCountNegative(TreeNode* node, int &sum, int &count) {
        if (node == NULL) return;
        if (node->val < 0) {
            sum += node->val;
            count++;
        }
        sumAndCountNegative(node->left, sum, count);
        sumAndCountNegative(node->right, sum, count);
    }

    void sumPositive(TreeNode* node, int &sum) {
        if (node == NULL) return;
        if (node->val > 0) sum += node->val;
        sumPositive(node->left, sum);
        sumPositive(node->right, sum);
    }

    void sumNegative(TreeNode* node, int &sum) {
        if (node == NULL) return;
        if (node->val < 0) sum += node->val;
        sumNegative(node->left, sum);
        sumNegative(node->right, sum);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(-3);
    tree.insert(8);
    tree.insert(-7);
    tree.insert(2);
    tree.insert(-1);
    tree.insert(10);

    cout << "Trung bình cộng tất cả các nút: " << tree.averageAll() << endl;
    cout << "Trung bình cộng các số dương: " << tree.averagePositive() << endl;
    cout << "Trung bình cộng các số âm: " << tree.averageNegative() << endl;
    cout << "Tỉ số R (tổng số dương / tổng số âm): " << tree.ratioPositiveNegative() << endl;
    
    return 0;
}
