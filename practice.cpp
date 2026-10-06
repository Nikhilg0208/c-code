#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    stack<char> st;
    for (auto chr : s) {
      if (chr == '(') {
        st.push('(');
      } else {
        if (!st.empty() && st.top() == '(') {
          st.pop();
        } else {
          st.push(')');
        }
      }
    }

    return st.size();
  }
};

int main() {
  Solution sol;

  vector<pair<string, int>> testCases = {
      {"())", 1},        // Example 1: One extra ')'
      {"(((", 3},        // Example 2: Three extra '('
      {"()", 0},         // Single balanced pair
      {"()))((", 4},     // Unmatched close and open
      {"((())", 1},      // One extra '('
      {")(", 2},         // Reversed order: need '(' before and ')' after
      {"((()))", 0},     // Fully balanced nested
      {"()()()", 0},     // Multiple adjacent balanced
      {"", 0},           // Empty string: already valid
      {"))))", 4},       // Only closing brackets
      {"((((", 4},       // Only opening brackets
      {"()))))", 4},     // One balanced pair, 4 extra ')'
      {"((((()", 4},     // One balanced pair, 4 extra '('
      {"())(()", 2},     // Mixed balanced with extra brackets
      {"))((", 4}        // Two ')' then two '('
  };

  for (int i = 0; i < testCases.size(); i++) {
    string s = testCases[i].first;
    int expected = testCases[i].second;
    int actual = sol.minAddToMakeValid(s);

    cout << "Test Case " << i + 1 << ": s = \"" << s << "\"" << endl;
    cout << "  Expected: " << expected << endl;
    cout << "  Actual  : " << actual << endl;
    cout << "  Status  : " << (actual == expected ? "PASSED" : "FAILED") << endl
         << endl;
  }

  return 0;
}