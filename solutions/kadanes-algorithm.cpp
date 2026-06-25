/*
 * GeeksforGeeks — Kadane's Algorithm  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
 *
 * Given an integer array arr[] (which may contain negative values), return the
 * maximum possible sum of a non-empty contiguous subarray. Because at least one
 * element must be taken, an all-negative array returns its largest (least
 * negative) element rather than 0.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the maximum subarray sum.
 *
 * Constraints:
 *   1 <= arr.size() <= 1e5
 *   -1e4 <= arr[i]  <= 1e4
 *
 * Approach: Kadane's algorithm, a one-dimensional DP. Let cur be the best sum of a
 * subarray ending exactly at index i; then cur = max(arr[i], cur_prev + arr[i]) —
 * either start a new subarray at i, or extend the previous best ending one step
 * back. The answer is the maximum cur over all i. Seeding both `best` and `cur`
 * with arr[0] (never 0) is what keeps the all-negative case correct.
 *
 * Complexity: O(n) time (single pass), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        long long best = arr[0];   // best sum found anywhere so far
        long long cur  = arr[0];   // best sum of a subarray ending at the current index

        for (size_t i = 1; i < arr.size(); ++i) {
            // Extend the running subarray, or drop it and start fresh at arr[i] —
            // whichever yields the larger sum ending here.
            cur = max((long long)arr[i], cur + arr[i]);
            best = max(best, cur);
        }

        // The true maximum lies within +-1e9 (1e5 elements x 1e4), so it fits in int.
        return (int)best;
    }
};
