/*

* -------------The countPairs function works as follows--------------------------------
 * 1. Sort the array in ascending order to apply the two-pointer technique.
 * 2. Initialize two pointers:
 *    - `s` (start) points to the beginning of the array.
 *    - `e` (end) points to the last element of the array.
 * 3. Use a while loop to iterate until the start pointer crosses the end pointer:
 *    - If the sum of arr[s] and arr[e] is greater than or equal to the target, decrement `e` to reduce the sum.
 *    - If the sum of arr[s] and arr[e] is less than the target, count all pairs (s, e), (s, e-1), ..., (s, s+1)
 *      by adding `e - s` to the count and increment `s`.
 * 4. Return the total count of pairs.


* -------------Complexity Analysis--------------------------------
   * - Time Complexity: O(n log n) for sorting + O(n) for the two-pointer traversal, making the overall complexity O(n log n).
   * - Space Complexity: O(1) additional space, as the sorting is done in-place.



*/

//  Date :- 01/jan/ 2025


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Sort the array to apply the two-pointer technique
        sort(arr.begin(), arr.end());
        
        int count = 0;
        int s = 0;
        int e = arr.size() - 1;
        
        while (s < e) {
            // Check if the current pair's sum is greater than or equal to the target
            if (arr[s] + arr[e] >= target) {
                e--; // Decrease the end pointer
            } else {
                // Count all pairs between s and e
                count += e - s;
                s++; // Move the start pointer forward
            }
        }
        
        return count;
    }
};

int main() {
    // Input array and target
    vector<int> arr = {7, 2, 5, 3};
    int target = 8;

    // Create an instance of the Solution class
    Solution solution;
    
    // Call the countPairs method
    int result = solution.countPairs(arr, target);
    
    // Print the result
    cout << "Number of pairs with sum less than " << target << " is: " << result << endl;

    return 0;
}
