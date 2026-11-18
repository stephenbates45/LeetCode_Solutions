
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {

        int m = s.size();
        int n = p.size();

        // dp[i][j] = does s[i:] match p[j:]?
        std::vector<std::vector<bool>> dp(
            m + 1, std::vector<bool>(n + 1, false)
        );

        // Two empty strings match.
        dp[m][n] = true;

        // Work backwards through both strings.
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {

                // Check we have not reached the end of the input string,
                // then check the characters are the same or the proposed match char
                // from p is the '.'. wild card
                bool firstMatch = i < m && (s[i] == p[j] || p[j] == '.');

                // If the next pattern is the * wildcard
                if (j + 1 < n && p[j + 1] == '*') 
                {
                    // Either ignore the * and move forward two positions or
                    // match one or more occurrences of *
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } 
                else // the pattern is not *
                {
                    // The current chars must match and the remaining parts
                    // of the string must match
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

int main(int, char**){
    Solution solution;

    // Helper that uses the shared Solution object to run the isPalindrome function test cases
    // and print the example number and returned value which is 1 if true and 0 if false.
    const auto runTest = [&solution](int example, const std::string inputStringOne, const std::string inputStringTwo) 
    {
        const bool result = solution.isMatch(inputStringOne, inputStringTwo);

        std::cout << "Example " << example << ": " << result << '\n';
    };

     // Run the three examples and print their indices and return values.
    runTest(1, "aa", "a");
    runTest(2, "aa", "a*");
    runTest(3, "ab", ".*");
}
