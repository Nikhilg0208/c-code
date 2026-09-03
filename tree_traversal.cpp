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
  // ---------- Morris ----------

  vector<int> morrisInorder(TreeNode *root) {
    vector<int> ans;
    TreeNode *cur = root;

    while (cur != NULL) {
      if (cur->left == NULL) {
        ans.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *prev = cur->left;
        while (prev->right && prev->right != cur) {
          prev = prev->right;
        }
        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = NULL;
          ans.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return ans;
  }

  vector<int> morrisPreorder(TreeNode *root) {
    vector<int> ans;
    TreeNode *cur = root;

    while (cur != NULL) {
      if (cur->left == NULL) {
        ans.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *prev = cur->left;
        while (prev->right && prev->right != cur) {
          prev = prev->right;
        }
        if (prev->right != cur) {
          ans.push_back(cur->val);
        }
        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = NULL;
          cur = cur->right;
        }
      }
    }
    return ans;
  }

  vector<int> morrisPostorder(TreeNode *root) {
    vector<int> ans;

    TreeNode dummy(0);
    dummy.left = root;

    TreeNode *cur = &dummy;

    while (cur != NULL) {
      if (cur->left == NULL) {
        cur = cur->right;
      } else {
        TreeNode *prev = cur->left;

        while (prev->right && prev->right != cur) {
          prev = prev->right;
        }

        if (prev->right == NULL) {
          prev->right = cur;
          cur = cur->left;
        } else {
          // Reverse path from cur->left to prev
          TreeNode *first = cur->left;
          TreeNode *second = prev;

          TreeNode *p = first;
          TreeNode *q = first->right;

          while (p != second) {
            TreeNode *temp = q->right;
            q->right = p;
            p = q;
            q = temp;
          }

          // Add nodes in reversed order
          TreeNode *node = second;

          while (true) {
            ans.push_back(node->val);

            if (node == first)
              break;

            node = node->right;
          }

          // Restore the reversed path
          p = second;
          q = second->right;

          while (p != first) {
            TreeNode *temp = q->right;
            q->right = p;
            p = q;
            q = temp;
          }

          prev->right = NULL;
          cur = cur->right;
        }
      }
    }

    return ans;
  }

  // ---------- Recursive ----------

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    inorderHelper(root, ans);
    return ans;
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    preorderHelper(root, ans);
    return ans;
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    postorderHelper(root, ans);
    return ans;
  }

  // ---------- Iterative ----------

  vector<int> inorderIterative(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty()) {
      while (curr != nullptr) {
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();

      ans.push_back(curr->val);
      curr = curr->right;
    }

    return ans;
  }

  vector<int> preorderIterative(TreeNode *root) {
    vector<int> ans;
    if (!root)
      return ans;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();

      ans.push_back(node->val);

      if (node->right)
        st.push(node->right);
      if (node->left)
        st.push(node->left);
    }

    return ans;
  }

  vector<int> postorderIterative(TreeNode *root) {
    vector<int> ans;
    if (!root)
      return ans;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
      TreeNode *node = st1.top();
      st1.pop();

      st2.push(node);

      if (node->left)
        st1.push(node->left);
      if (node->right)
        st1.push(node->right);
    }

    while (!st2.empty()) {
      ans.push_back(st2.top()->val);
      st2.pop();
    }

    return ans;
  }

private:
  void inorderHelper(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    inorderHelper(root->left, ans);
    ans.push_back(root->val);
    inorderHelper(root->right, ans);
  }

  void preorderHelper(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    ans.push_back(root->val);
    preorderHelper(root->left, ans);
    preorderHelper(root->right, ans);
  }

  void postorderHelper(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    postorderHelper(root->left, ans);
    postorderHelper(root->right, ans);
    ans.push_back(root->val);
  }
};

int main() {

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(10);
  root->left->right->left = new TreeNode(11);
  root->right->right = new TreeNode(12);

  Solution obj;
  vector<int> ans;

  // Recursive
  ans = obj.inorderTraversal(root);
  cout << "Recursive Inorder   : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.preorderTraversal(root);
  cout << "Recursive Preorder  : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.postorderTraversal(root);
  cout << "Recursive Postorder : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl << endl;

  // Iterative
  ans = obj.inorderIterative(root);
  cout << "Iterative Inorder   : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.preorderIterative(root);
  cout << "Iterative Preorder  : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.postorderIterative(root);
  cout << "Iterative Postorder : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl << endl;

  ans = obj.morrisInorder(root);
  cout << "Morris Inorder : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.morrisPreorder(root);
  cout << "Morris Preorder : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  ans = obj.morrisPostorder(root);
  cout << "Morris Postorder : ";
  for (int x : ans)
    cout << x << " ";
  cout << endl;

  return 0;
}