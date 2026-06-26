/*
 * GeeksforGeeks — Longest Subarray with Sum K  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
 *
 * Given an integer array arr[] (values may be negative) and an integer k, return the
 * length of the LONGEST contiguous subarray whose elements sum to exactly k. If no
 * such subarray exists, return 0.
 *
 * I/O contract: function-based (the GfG driver supplies main). Inputs are `arr`
 * (vector<int>) and `k` (int); output is the length (int).
 *
 * Constraints:
 *   1    <= n      <= 1e5
 *   -1e4 <= arr[i] <= 1e4
 *   -1e9 <= k      <= 1e9
 *
 * Approach: prefix sums + hash map. Because the array may contain negatives, the
 * sliding-window trick (which relies on monotonically growing sums) does not apply.
 * Instead, a subarray (i..j) sums to k iff prefix[j] - prefix[i-1] = k, i.e.
 * prefix[i-1] = prefix[j] - k. Walk left to right maintaining the running prefix sum;
 * at each j, if value (prefix - k) was seen at some earlier index, the subarray just
 * after that index up to j sums to k — take its length. Store only the FIRST index at
 * which each prefix value appears, since an earlier start yields a longer subarray.
 * Seeding the map with {0 : -1} cleanly covers subarrays that begin at index 0.
 *
 * Complexity: O(n) average time (one pass, O(1) expected map ops), O(n) space.
 * Note: the running sum uses long long — prefix and k each reach 1e9, so prefix - k
 * can reach 2e9 and brushes the 32-bit limit; 64-bit removes all overflow doubt.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> firstIdx;   // prefix sum -> earliest index it occurred at
        firstIdx.reserve(arr.size() * 2);
        firstIdx[0] = -1;                          // the empty prefix sits "before" index 0

        long long prefix = 0;
        int best = 0;

        for (int j = 0; j < (int)arr.size(); ++j) {
            prefix += arr[j];

            // If some earlier prefix equals (prefix - k), the gap between them sums to k.
            auto it = firstIdx.find(prefix - (long long)k);
            if (it != firstIdx.end())
                best = max(best, j - it->second);

            // Record only the first sighting of this prefix value, keeping the start as
            // early as possible — that is what maximizes any future subarray length.
            if (firstIdx.find(prefix) == firstIdx.end())
                firstIdx[prefix] = j;
        }

        return best;
    }
};
