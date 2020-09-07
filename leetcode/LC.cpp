#include "LC.h"

#include <queue>

using namespace std;
/*************************************
 * Reverse String
 *
 * Description: 
 * Given a string, reverse it in place.
 * 
 * 
 * Test Case: string
 * Result: ngirts
 ************************************/
void LC::reverseStr(string s) {
    for(int i=0; i<s.size()/2; i++) {
        char temp = s[i];
        s[i] = s[s.size()-1 - i];
        s[s.size()-1 - i] = temp;
    }
}

/*************************************
 * Maximum Depth of Binary Tree
 *
 * Description: 
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along 
 * the longest path from the root node down to the 
 * farthest leaf node.
 * 
 * Test Case: [3,9,20,null,null,15,7]
 * Result: 3
 ************************************/
int LC::maxDepthBT(TreeNode* root) {
    if(root == nullptr) return 0;

    return 1 + max(maxDepthBT(root->left), maxDepthBT(root->right));
}
/************************************
 * 
 * Invert a binary tree.
 *
 * Example:
 * 
 * Input:
 * 
 *      3
 *    /   \
 *   9     20
 *         / \
 *        15  7
 * 
 * Output:
 * 
 *      3
 *    /   \
 *   20    9
 *  / \   
 * 7  15 
 *
 ***********************************/
TreeNode* LC::invertTree(TreeNode* root) {
    if(root == nullptr)
        return nullptr;
    
    TreeNode* left = this->invertTree(root->left);
    TreeNode* right = this->invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
}
/************************************
 * 
 * Invert a binary tree (Iterative)
 *
 ***********************************/
TreeNode * LC::invertTreeIter(TreeNode* root) {
    if(root == nullptr) return nullptr;
    queue<TreeNode*> q;
    q.emplace(root);
    
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;
        if(current->left != nullptr) q.emplace(current->left);
        if(current->right != nullptr) q.emplace(current->right);
    }

    return root;
}
/*************************************
 * Convert Sorted Array to BST
 *
 * Description: 
 * Given an array where elements are 
 * sorted in ascending order, convert it 
 * to a height balanced BST.

 * For this problem, a height-balanced binary
 * tree is defined as a binary tree in which the 
 * depth of the two subtrees of every node never 
 * differ by more than 1.
 *
 ************************************/
TreeNode* LC::convertToBST(vector<int>& nums) {
    if(nums.size() == 0) return nullptr;
    if(nums.size() == 1) return new TreeNode(nums[0]);

    return this->convertToBSTHelper(nums, 0, nums.size()-1);
}

TreeNode* LC::convertToBSTHelper(vector<int>& nums, int start, int end) {
    int midpoint = (start+end)/2;
    TreeNode* root = new TreeNode(nums[midpoint]);

}

int main(void) {
    LC lc;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    int result = lc.maxDepthBT(root);

    root = lc.invertTree(root);

    return 0;

}