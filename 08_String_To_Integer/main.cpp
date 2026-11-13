#include <iostream>
#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        
         int i = 0;
        int n = s.length();

        // 1. Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine the sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits into an integer
        int result = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            // 4. Check for integer overflow before multiplying
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;

            i++;
        }

        return result * sign;
    }
};

int main()
{
    Solution solution;

    // Helper that uses the shared Solution object to run the myAtoi function test cases
    // and print the example number and returned value.
    const auto runTest = [&solution](int example, const std::string inputString) {
        const int result = solution.myAtoi(inputString);

        std::cout << "Example " << example << ": " << result << '\n';
    };

     // Run the three examples and print their indices and return values.
    runTest(1, "42");
    runTest(2, " -042");
    runTest(3, "1337c0d3");
    runTest(4, "0-1");
    runTest(5, "words and 987");
}
