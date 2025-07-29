#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> maps;
        int start = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((maps.count(s[i]) && maps[s[i]] >= start))
            {
                start = maps[s[i]] + 1;
                maps[s[i]] = i;
                std::cout << "!";
            }
            else
            {
                std::cout << "&";
                maps[s[i]] = i;
                maxLen = max(maxLen, i - start + 1);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabc");
    return 0;
}