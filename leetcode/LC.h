#ifndef LC_H
#define LC_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){};
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right){};
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x), next(next) {};
};

class LC {
    private:
    public:
        vector<string> fizzBuzz(int n);
        int maxDepthBT(TreeNode* root);
        int singleNumber(vector<int>& nums);
        int majorityElement(vector<int>& nums);
        bool isAnagram(string s, string t);
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
        TreeNode* invertTree(TreeNode* root);
        TreeNode* invertTreeIter(TreeNode* root);
        TreeNode* convertToBST(vector<int>& nums);
        TreeNode* convertToBSTHelper(vector<int>& nums, int begin, int end);
        ListNode* reverseList(ListNode* head);
        void reverseStr(string s);
        void deleteNode(ListNode* node);

};

#endif