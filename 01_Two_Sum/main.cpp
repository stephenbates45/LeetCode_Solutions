#include <iostream>
#include <vector>
#include <unordered_map>


class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::unordered_map<int, int> numMap;

        for ( int i = 0; i < nums.size(); i++)
        {
            // Calculate the complement value, which is the value we are looking for
            int compliment = target - nums[i];

            // Check the map to see if this value exists and if so return it and the index of the current value
            if (numMap.count(compliment))
            {
                return { numMap[compliment], i};
            }
            numMap[nums[i]] = i;
        }

        // No result obtained, return an empty vector
        return {};
    }
};

int main(int, char**)
{
    Solution solution;

    // Helper that uses the shared Solution object to run one Two Sum test case
    // and print the example number and returned indices.
    const auto runTest = [&solution](int example, std::vector<int> nums, int target) {
        const std::vector<int> result = solution.twoSum(nums, target);

        std::cout << "Example " << example << ": [";
        for (std::size_t i = 0; i < result.size(); ++i)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << result[i];
        }
        std::cout << "]\n";
    };

    // Run the three Two Sum examples and print their matching indices.
    runTest(1, {2, 7, 11, 15}, 9);
    runTest(2, {3, 2, 4}, 6);
    runTest(3, {3, 3}, 6);
}
