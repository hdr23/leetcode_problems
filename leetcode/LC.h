#ifndef LC_H
#define LC_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){};

};

class LC {
    private:
    public:
        int maxDepthBT(TreeNode* root);
        TreeNode* invertTree(TreeNode* root);
        TreeNode* invertTreeIter(TreeNode* root);
        TreeNode* convertToBST(vector<int>& nums);
        TreeNode* convertToBSTHelper(vector<int>& nums, int begin, int end);
        void reverseStr(string s);

};

#endif