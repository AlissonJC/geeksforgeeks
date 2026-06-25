/*
 * GeeksforGeeks — Indexes of Subarray Sum  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
 *
 * Given an array arr[] of non-negative integers and a value `target`, find the
 * first contiguous subarray whose elements add up to exactly `target` and return
 * the 1-based indices [left, right] of its endpoints. If no such subarray exists,
 * return [-1].
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>) and `target` (int); output is a vector<int> holding {left, right}
 * as 1-based indices, or {-1} when there is no answer.
 *
 * Constraints:
 *   1 <= arr.size() <= 1e6
 *   0 <= arr[i]     <= 1e3
 *   0 <= target     <= 1e9
 *
 * Approach: sliding window with two pointers. Every element is non-negative, so a
 * window's sum only grows when the right end extends and only drops when the left
 * end advances — it is monotonic with respect to each pointer. Extend `end` one
 * element at a time; whenever the window sum overshoots `target`, drop elements
 * from the left until it no longer does. The first window whose sum equals
 * `target` is the answer: because it is returned at the smallest reachable `end`,
 * it is the first such subarray.
 *
 * Complexity: O(n) time — each index enters the window once and leaves at most
 * once, so the two pointers together advance at most 2n steps. O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        long long sum = 0;   // window sum; up to 1e6 * 1e3 = 1e9, kept in 64-bit to be safe
        int start = 0;       // left end of the window (0-based)

        for (int end = 0; end < n; ++end) {
            sum += arr[end];

            // Shrink from the left while we have overshot the target. Keep at least
            // one element in the window (start < end) so that a lone element bigger
            // than target simply fails to match and we slide past it.
            while (sum > target && start < end) {
                sum -= arr[start];
                ++start;
            }

            if (sum == target) {
                return {start + 1, end + 1};   // convert the 0-based window to 1-based endpoints
            }
        }

        return {-1};   // no contiguous subarray adds up to target
    }
};
