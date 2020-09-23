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

/************************************
 * 
 * Merge two binary trees. 
 *
 * Example:
 * 
 * Input:
 * 
 *      Tree 1                     Tree 2                  
 *         1                         2                             
 *        / \                       / \                            
 *       3   2                     1   3                        
 *      /                           \   \                      
 *     5                             4   7  
 * 
 * Output:
 * 
 *       3
 *	    / \
 *	   4   5
 *	  / \   \ 
 *	 5   4   7 
 *
 ***********************************/
TreeNode* LC::mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr) return t2;
    if(t2 == nullptr) return t1;
    t1->val = t1->val + t2->val;
    t1->left = this->mergeTrees(t1->left, t2->left);
    t2->right = this->mergeTrees(t1->right, t2->right);

    return t1;
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
    if(left > right) return nullptr;
    int midpoint = (start+end)/2;
    TreeNode* root = new TreeNode(nums[midpoint]);
    root->left = convertToBSTHelper(nums, 0, midpoint-1);
    root->right = convertToBSTHelper(nums, midpoint+1, nums.size()-1);
    return root;

}

/*************************************
 * Single Number
 *
 * Description: 
 * Given a non-empty array of integers, 
 * every element appears twice except for one. 
 * Find that single one.
 *
 * Test Case: [2,2,1]
 * Result: 1
 ************************************/
int LC::singleNumber(vector<int>& nums) {
    map<int, int> m;

    for(int i: nums) {
        m[i]++;
    }

    for(auto i: m) {
        if(i.second != 2) return i.first;
    }

    return -1;
}

/*************************************
 * Fizz Buzz
 *
 * Description: 
 * Write a program that outputs the string 
 * representation of numbers from 1 to n.

 * But for multiples of three it should output 
 * “Fizz” instead of the number and for the multiples 
 * of five output “Buzz”. For numbers which are 
 * multiples of both three and five output “FizzBuzz”.
 * 
 ************************************/
vector<string> LC::fizzBuzz(int n) {
    vector<string> res;
    
    for(int i=1;i<=n;i++) {
        if(i % 3 == 0 && i % 5 == 0) {
            res.push_back("FizzBuzz");
        }
        else if(i % 3 == 0) {
            res.push_back("Fizz");
        }
        else if(i % 5 == 0) {
            res.push_back("Buzz");
        }
        else {
            res.push_back(to_string(i));
        }
    }
    
    return res;
}
/*************************************
 * Reverse Linked List
 *
 * Description: 
 * Reverse a singely linked list.

 * Test Case: 1->2->3->4->5->NULL
 * Result: 5->4->3->2->1->NULL
 *
 ************************************/
ListNode* LC::reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* current = head;

    while(current != nullptr) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}
/*************************************
 * Delete Node in Linked List 
 *
 * Description: 
 * Write a function to delete a node in a 
 * singly-linked list. You will not be given 
 * access to the head of the list, instead you 
 * will be given access to the node to be 
 * deleted directly.

 * It is guaranteed that the node to be deleted is not a 
 * tail node in the list.

 * For this problem, a height-balanced binary
 * tree is defined as a binary tree in which the 
 * depth of the two subtrees of every node never 
 * differ by more than 1.
 *
 ************************************/
void LC::deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}
/*************************************
 * Majority Element
 *
 * Description: 
 * Given an array of size n, find the majority element. 
 * The majority element is the element that appears more 
 * than ⌊ n/2 ⌋ times.

 * You may assume that the array is non-empty and the majority 
 * element always exist in the array.
 * 
 * Test Case: [3,2,3]
 * Result: 3
 ************************************/
int LC::majorityElement(vector<int>& nums) {
    int bound = nums.size()/2;
    map<int,int> m;

    for(int i: nums) {
        m[i]++;
    }

    for(auto it: m) {
        if(it.second > bound) return it.first;
    }

    return -1;
}

/*************************************
 * Merge Two Sorted Lists
 *
 * Description: 
 * Merge two sorted linked lists and return 
 * it as a new sorted list. The new list should 
 * be made by splicing together the nodes of 
 * the first two lists.
 ************************************/
ListNode* LC::mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummyNode(-1);
    ListNode* lastNode(&dummyNode);

    while(l1 != nullptr && l2 != nullptr) {
        if(l1->val < l2->val) {
            lastNode->next = l1;
            l1 = l1->next;
        }
        else {
            lastNode->next = l2;
            l2 = l2->next;
        }
        lastNode = lastNode->next;
    }

    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;

    return dummyNode.next;
}

/*************************************
 * Two Sum
 *
 * Description: 
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and 
 * you may not use the same element twice.

 * You can return the answer in any order.
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 ************************************/
vector<int> LC::twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    map<int, int>::iterator it;

    for(int i=0;i<nums.size();i++) {
        int complement = target - nums[i];
        it = m.find(complement);

        if(it != m.end()) {
            return vector<int>{i, it->second};
        }
        else {
            m.insert(make_pair(nums[i], i));
        }
    }

    return vector<int>{-1,-1};
}

/*************************************
 * Best Time to Buy and Stock
 *
 * Description: 
 * Say you have an array for which the ith element 
 * is the price of a given stock on day i.
 * If you were only permitted to complete at most one 
 * transaction (i.e., buy one and sell one share of the stock), 
 * design an algorithm to find the maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: 
 * Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 ************************************/
int LC::maxProfit(vector<int>& prices) {
    int minVal = INT32_MAX;
    int profit = 0;

    return 1;
}

/*************************************
 * Move Zeroes
 *
 * Description: 
 * Given an array nums, write a function to move 
 * all 0's to the end of it while maintaining the 
 * relative order of the non-zero elements.
 * 
 * Test Case: [0, 1, 0, 3, 12]
 * Result: [1, 3, 12, 0, 0]
 ************************************/
void moveZeroes(vector<int>& nums) {
    int count = 0;

    for(int i: nums) {
        if(i == 0) count++;
    }

    vector<int>::iterator it = remove(nums.begin(), nums.end(), 0);
    //1, 3, 12, null, null
    //           ^it
    nums.erase(it, nums.end());

    while(count) {
        nums.push_back(0);
    }
}
/*************************************
 * Valid Anagram
 *
 * Description: 
 * Given two strings s and t , write a 
 * function to determine if t is an anagram of s.
 * 
 * Test Case: "anagram", "nagaram"
 * Result: true
 ************************************/
bool LC::isAnagram(string s, string t) {
    map<char, int> sM;
    map<char, int> sT;

    for(char c: s) {
        sM[c]++;
    }

    for(char c: t) {
        sT[c]++;
    }

    if(sM == sT) return true;

    return false;
}

int main(void) {
    LC lc;
    lc.isAnagram("string1", "string2");

    return 0;

}