#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left, *right;

  TreeNode(int x)
  {
    val = x;
    left = right = nullptr;
  }
};

class Solution
{
public:
  // ---------- Morris ----------

  vector<int> morrisInorder(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *cur = root;

    while (cur != NULL)
    {
      if (cur->left == NULL)
      {
        ans.push_back(cur->val);
        cur = cur->right;
      }
      else
      {
        TreeNode *prev = cur->left;
        while (prev->right && prev->right != cur)
        {
          prev = prev->right;
        }
        if (prev->right == NULL)
        {
          prev->right = cur;
          cur = cur->left;
        }
        else
        {
          prev->right = NULL;
          ans.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return ans;
  }

  vector<int> morrisPreorder(TreeNode *root)
  {
    vector<int> ans;
    TreeNode *cur = root;

    while (cur != NULL)
    {
      if (cur->left == NULL)
      {
        ans.push_back(cur->val);
        cur = cur->right;
      }
      else
      {
        TreeNode *prev = cur->left;
        while (prev->right && prev->right != cur)
        {
          prev = prev->right;
        }
        if (prev->right != cur)
        {
          ans.push_back(cur->val);
        }
        if (prev->right == NULL)
        {
          prev->right = cur;
          cur = cur->left;
        }
        else
        {
          prev->right = NULL;
          cur = cur->right;
        }
      }
    }
    return ans;
  }

  vector<int> morrisPostorder(TreeNode *root)
  {
    vector<int> ans;

    TreeNode dummy(0);
    dummy.left = root;

    TreeNode *cur = &dummy;

    while (cur != NULL)
    {
      if (cur->left == NULL)
      {
        cur = cur->right;
      }
      else
      {
        TreeNode *prev = cur->left;

        while (prev->right && prev->right != cur)
        {
          prev = prev->right;
        }

        if (prev->right == NULL)
        {
          prev->right = cur;
          cur = cur->left;
        }
        else
        {
          // Reverse path from cur->left to prev
          TreeNode *first = cur->left;
          TreeNode *second = prev;

          TreeNode *p = first;
          TreeNode *q = first->right;

          while (p != second)
          {
            TreeNode *temp = q->right;
            q->right = p;
            p = q;
            q = temp;
          }

          // Add nodes in reversed order
          TreeNode *node = second;

          while (true)
          {
            ans.push_back(node->val);

            if (node == first)
              break;

            node = node->right;
          }

          // Restore the reversed path
          p = second;
          q = second->right;

          while (p != first)
          {
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

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    inorderHelper(root, ans);
    return ans;
  }

  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    preorderHelper(root, ans);
    return ans;
  }

  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    postorderHelper(root, ans);
    return ans;
  }

  // ---------- Iterative ----------

  vector<int> inorderIterative(TreeNode *root)
  {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
      while (curr != nullptr)
      {
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

  vector<int> preorderIterative(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
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

  vector<int> postorderIterative(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
      TreeNode *node = st1.top();
      st1.pop();

      st2.push(node);

      if (node->left)
        st1.push(node->left);
      if (node->right)
        st1.push(node->right);
    }

    while (!st2.empty())
    {
      ans.push_back(st2.top()->val);
      st2.pop();
    }

    return ans;
  }

  // ---------- Vertical Traversal ----------

  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    vector<vector<int>> ans;

    map<int, map<int, multiset<int>>> nodes;

    queue<pair<TreeNode *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {
      auto it = q.front();
      q.pop();

      TreeNode *node = it.first;
      int row = it.second.first;
      int col = it.second.second;

      nodes[col][row].insert(node->val);

      if (node->left)
      {
        q.push({node->left, {row + 1, col - 1}});
      }

      if (node->right)
      {
        q.push({node->right, {row + 1, col + 1}});
      }
    }

    for (auto &col : nodes)
    {
      vector<int> vertical;

      for (auto &row : col.second)
      {
        for (int value : row.second)
        {
          vertical.push_back(value);
        }
      }

      ans.push_back(vertical);
    }

    return ans;
  }

  vector<vector<int>> allTraversals(TreeNode *root)
  {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    if (root == NULL)
    {
      return {};
    }

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
      auto it = st.top();
      st.pop();
      if (it.second == 1)
      {
        preorder.push_back(it.first->val);
        it.second = 2;
        st.push(it);

        if (it.first->left != NULL)
        {
          st.push({it.first->left, 1});
        }
      }

      else if (it.second == 2)
      {
        inorder.push_back(it.first->val);
        it.second = 3;
        st.push(it);

        if (it.first->right != NULL)
        {
          st.push({it.first->right, 1});
        }
      }

      else
      {
        postorder.push_back(it.first->val);
      }
    }

    vector<vector<int>> result;
    result.push_back(preorder);
    result.push_back(inorder);
    result.push_back(postorder);
    return result;
  }

private:
  void inorderHelper(TreeNode *root, vector<int> &ans)
  {
    if (!root)
      return;
    inorderHelper(root->left, ans);
    ans.push_back(root->val);
    inorderHelper(root->right, ans);
  }

  void preorderHelper(TreeNode *root, vector<int> &ans)
  {
    if (!root)
      return;
    ans.push_back(root->val);
    preorderHelper(root->left, ans);
    preorderHelper(root->right, ans);
  }

  void postorderHelper(TreeNode *root, vector<int> &ans)
  {
    if (!root)
      return;
    postorderHelper(root->left, ans);
    postorderHelper(root->right, ans);
    ans.push_back(root->val);
  }
};

int main()
{

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
  cout << endl
       << endl;

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
  cout << endl
       << endl;

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
  cout << endl
       << endl;

  vector<vector<int>> answer = obj.verticalTraversal(root);

  cout << "Your Answer     : ";

  for (auto &col : answer)
  {
    cout << "[ ";

    for (int x : col)
      cout << x << " ";

    cout << "] ";
  }

  cout << endl;

  cout << "Expected Answer : ";
  cout << "[ 9 ] [ 2 11 ] [ 1 10 ] [ 8 ] [ 12 ]";

  cout << endl
       << endl;

  vector<vector<int>> traversals = obj.allTraversals(root);

  cout << "\nAll Traversals in One Traversal:" << endl;

  cout << "Preorder  : ";
  for (int x : traversals[0])
    cout << x << " ";
  cout << endl;

  cout << "Inorder   : ";
  for (int x : traversals[1])
    cout << x << " ";
  cout << endl;

  cout << "Postorder : ";
  for (int x : traversals[2])
    cout << x << " ";
  cout << endl;

  cout << "\nExpected:" << endl;
  cout << "Preorder  : 1 2 9 10 11 8 12" << endl;
  cout << "Inorder   : 9 2 11 10 1 8 12" << endl;
  cout << "Postorder : 9 11 10 2 12 8 1" << endl;

  return 0;
}