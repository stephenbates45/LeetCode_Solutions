#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(const std::string& s, int numRows)
    {
        // With one row, or fewer characters than rows, the zigzag is unchanged.
        if (numRows <= 1 || static_cast<std::size_t>(numRows) >= s.size())
        {
            return s;
        }

        const std::size_t rows = static_cast<std::size_t>(numRows);

        // One full zigzag cycle goes down the rows, then back up,
        // without counting either endpoint row twice.
        const std::size_t cycle = 2 * rows - 2;

        std::string result;
        result.reserve(s.size());

        // Read the characters row by row to build the converted string directly.
        for (std::size_t row = 0; row < rows; ++row)
        {
            // Each row's vertical characters are one cycle apart.
            for (std::size_t i = row; i < s.size();)
            {
                result.push_back(s[i]);

                // Interior rows also have a diagonal character between
                // their vertical characters. The first and last rows do not.
                const std::size_t diagonalOffset = cycle - 2 * row;

                if (row > 0 && row + 1 < rows && diagonalOffset < s.size() - i)
                {
                    result.push_back(s[i + diagonalOffset]);
                }

                // Avoid advancing past the end or overflowing the index.
                if (cycle >= s.size() - i)
                {
                    break;
                }

                i += cycle;
            }
        }

        return result;
    }
};


int main()
{

    Solution solution;

    const auto runTest = [&solution](int example, const std::string& inputString, int numRows) {
        const std::string result = solution.convert(inputString, numRows);

        std::cout << "Example " << example << ": " << result << '\n';
    };

    runTest(1, "PAYPALISHIRING", 3);
    runTest(2, "PAYPALISHIRING", 4);
    runTest(3, "A", 1);

}
