#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {

        int t = x;
        long rev = 0;
    
        if (x < 0)
        {
            // Negative number so can't be a palindrome
            return false;
        }
        else 
            while (t > 0)
            {
                long dig = t % 10;
                rev = rev * 10 + dig;
                t /= 10;
            }
        
        // Test Criteria
        if (x == rev)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};

int main()
{
    Solution solution;

    // Helper that uses the shared Solution object to run the isPalindrome function test cases
    // and print the example number and returned value which is 1 if true and 0 if false.
    const auto runTest = [&solution](int example, const int inputValue) 
    {
        const bool result = solution.isPalindrome(inputValue);

        std::cout << "Example " << example << ": " << result << '\n';
    };

     // Run the three examples and print their indices and return values.
    runTest(1, 121);
    runTest(2, -121);
    runTest(3, 10);
}
