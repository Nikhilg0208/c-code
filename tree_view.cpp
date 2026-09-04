#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left, *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class Solution {
public:
  vector<int> leftView(TreeNode *root) {
    vector<int> ans;

    if (!root)
      return ans;

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
      int size = que.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();

        // First node of every level
        if (i == 0) {
          ans.push_back(node->val);
        }

        if (node->left)
          que.push(node->left);

        if (node->right)
          que.push(node->right);
      }
    }

    return ans;
  }

  vector<int> rightView(TreeNode *root) {
    vector<int> ans;

    if (!root)
      return ans;

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
      int size = que.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = que.front();
        que.pop();

        // Last node of every level
        if (i == size - 1) {
          ans.push_back(node->val);
        }

        if (node->left)
          que.push(node->left);

        if (node->right)
          que.push(node->right);
      }
    }

    return ans;
  }

  vector<int> topView(TreeNode *root) {
    vector<int> ans;

    if (!root)
      return ans;

    map<int, int> mp;
    queue<pair<TreeNode *, int>> que;

    que.push({root, 0});

    while (!que.empty()) {
      auto [node, hd] = que.front();
      que.pop();

      if (mp.find(hd) == mp.end()) {
        mp[hd] = node->val;
      }

      if (node->left) {
        que.push({node->left, hd - 1});
      }

      if (node->right) {
        que.push({node->right, hd + 1});
      }
    }

    for (auto it : mp) {
      ans.push_back(it.second);
    }

    return ans;
  }
};

void printVector(vector<int> v) {
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

int main() {

  /*
                  1
             /         \
            2           3
          /   \       /   \
         4     5     6     7
        / \     \   /       \
       8   9    10 11        12
      /         /    \       /
     13        14     15    16
                  \
                   17
                     \
                      18

  */

  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);

  root->left->right->right = new TreeNode(10);

  root->right->left->left = new TreeNode(11);

  root->right->right->right = new TreeNode(12);

  root->left->left->left->left = new TreeNode(13);

  root->left->right->right->left = new TreeNode(14);

  root->right->left->left->right = new TreeNode(15);

  root->right->right->right->left = new TreeNode(16);

  root->left->right->right->left->right = new TreeNode(17);

  root->left->right->right->left->right->right = new TreeNode(18);

  Solution obj;

  // ---------- LEFT VIEW ----------
  cout << "Left View" << endl;

  cout << "Your Answer     : ";
  printVector(obj.leftView(root));

  cout << "Expected Answer : ";
  printVector({1, 2, 4, 8, 13, 17, 18});

  cout << endl;

  // ---------- RIGHT VIEW ----------
  cout << "Right View" << endl;

  cout << "Your Answer     : ";
  printVector(obj.rightView(root));

  cout << "Expected Answer : ";
  printVector({1, 3, 7, 12, 16, 17, 18});

  cout << endl;

  // ---------- TOP VIEW ----------
  cout << "Top View" << endl;

  cout << "Your Answer     : ";
  printVector(obj.topView(root));

  cout << "Expected Answer : ";
  printVector({13, 8, 4, 2, 1, 3, 7, 12});

  return 0;
}