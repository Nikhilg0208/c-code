#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void piefiller(vector<int> &pie, int size, string &substr) // sasad
    {
        int slow = 0, fast = 1;
        while (fast < size)
        {
            if (substr[slow] == substr[fast])
            {
                slow++;
                pie[fast] = slow;
                fast++;
            }
            else
            {
                if (slow == 0)
                {
                    fast++;
                }
                else
                {
                    slow = pie[slow - 1];
                }
            }
        }
 
    }
    int kmp(string str, string substr)
    {
        vector<int> pie(substr.size(), 0);
        piefiller(pie, substr.size(), substr);

        int slow = 0, i = 0;
        while (i < str.size())
        {
            if (substr[slow] == str[i])
            {
                i++;
                slow++;
            }
            else if (substr[slow] != str[i])
            {
                if (slow != 0)
                    slow = pie[slow - 1];
                else
                    i++;
            }
            if (slow == substr.size())
                return (i - substr.size());
        }
        return -1;
    }
    int kmpAlgo(string str, string substr)
    {
        return kmp(str, substr);
    }
};
int main()
{
    Solution obj;
    int val = obj.kmpAlgo("sasasadbtsad", "sasad");
    cout << val << " ";
    return 0;
}