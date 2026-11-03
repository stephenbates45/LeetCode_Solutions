#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm> 

class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];

            if (lastSeen.count(c))
            {
                left = std::max(left, lastSeen[c] + 1);
            }

            lastSeen[c] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }

        return maxLen;
    }

};

int main()
{
    Solution solution;

    const auto runTest = [&solution](int example, const std::string& inputString) {
        const int result = solution.lengthOfLongestSubstring(inputString);

        std::cout << "Example " << example << ": " << result << '\n';
    };

    runTest(1, "abcabcbb");
    runTest(2, "bbbbb");
    runTest(3, "pwwkew");
}
