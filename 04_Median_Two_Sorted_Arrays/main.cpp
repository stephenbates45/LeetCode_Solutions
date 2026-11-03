#include <iostream>
#include <vector>
#include <cstddef>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        
        // Count the values across both sorted arrays.
        std::size_t total = nums1.size() + nums2.size();

        // Keep track of the two values around the median.
        int previous = 0;
        int current = 0;

        // Indexes of the next unused value in each array.
        size_t i = 0;
        size_t j = 0;

        // Merge only as far as the middle of the combined arrays.
        for (std::size_t k = 0; k <= total / 2; k++)
        {
            previous = current;

            // Take the smaller available value to preserve sorted order.
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j]))
            {
                current = nums1[i];
                i++;
            }
            else
            {
                current = nums2[j];
                j++;
            }
        }

        // Odd-sized input has one middle value; even-sized input has two.
        if (total % 2)
        {
            return current;
        }
        else
        {
            return (previous + current) / 2.0;
        }
    }
};

int main()
{
    Solution solution;

    // Helper that uses the shared Solution object to run one findMedianSortedArrays test case
    // and print the median value returned
    const auto runTest = [&solution](int example, std::vector<int> nums1, std::vector<int> nums2) {
        const double result = solution.findMedianSortedArrays(nums1, nums2);

        std::cout << "Example " << example << ": " << result << '\n';
    };

    // Run the 2 find median examples and print their matching indices.
    runTest(1, {1, 3}, {2});
    runTest(2, {1, 2}, {3, 4});
}
