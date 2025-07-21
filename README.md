Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107


⏱️ Time Complexity: O(n)
1.We iterate through the array nums only once (n elements), using a single loop.
2.All operations inside the loop — updating currentSum, checking the hash map, and updating the map — take constant time, O(1) on average.

📦 Space Complexity: O(n)
1.We're using a unordered_map<int, int> (hash map) called prefixSumCount to store the frequency of prefix sums.

2.In the worst case, all prefix sums are unique, and we store n keys in the map.
