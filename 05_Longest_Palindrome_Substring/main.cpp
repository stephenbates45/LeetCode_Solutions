#include <iostream>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {

        // Early return case when passed and empty string
        if (s.empty())
        {
            return "";
        }
        
        int start = 0;
        int maxLength = 1;

        auto expand = [&](int left, int right)
        {
            while (left >= 0 &&
                right < s.size() &&
                s[left] == s[right])
            {
                int length = right - left + 1;

                if (length > maxLength)
                {
                    maxLength = length;
                    start = left;
                }

                left--;
                right++;
            }
        };

        for (int i = 0; i < s.size(); i++)
        {
            // Odd length palindrome
            expand(i, i);

            // Even length palindrome
            expand(i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};

int main()
{
    Solution solution;

    const auto runTest = [&solution](int example, const std::string& inputString) {
        const std::string result = solution.longestPalindrome(inputString);

        std::cout << "Example " << example << ": " << result << '\n';
    };

    runTest(1, "badad");
    runTest(2, "cbbd");
}
