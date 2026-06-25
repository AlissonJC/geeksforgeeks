/*
 * GeeksforGeeks — Minimum Jumps  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
 *
 * Given an array arr[] of non-negative numbers, arr[i] is the maximum number of
 * steps you may jump forward from index i (arr[i] = 3 lets you land on i+1, i+2 or
 * i+3; arr[i] = 0 means you are stuck there). Return the minimum number of jumps
 * needed to get from the first index to the last, or -1 if the last index can
 * never be reached.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the minimum jump count, or -1.
 *
 * Constraints:
 *   2 <= arr.size() <= 1e5
 *   0 <= arr[i]     <= 1e5
 *
 * Approach: a greedy breadth-first expansion of the reachable range. Walking left
 * to right, `farthest` tracks the best index any position seen so far can reach.
 * `curEnd` is the right boundary of everything reachable with the jumps taken so
 * far; once the scan index hits that boundary we are forced to spend one more jump
 * and push the boundary out to `farthest`. If on hitting the boundary nothing has
 * extended past it (farthest == i), the gap is impassable and the end is
 * unreachable. Iterating only to n-2 ensures the final jump that lands on (or past)
 * the last index is the last one counted.
 *
 * Complexity: O(n) time (single pass), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;                 // already standing on the last position

        int jumps = 0;
        int curEnd = 0;                       // farthest index reachable with `jumps` jumps
        int farthest = 0;                     // farthest index reachable with one extra jump

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + arr[i]);
            if (i == curEnd) {                // reached the edge of the current jump's range
                if (i == farthest) return -1; // nothing reaches beyond i -> end unreachable
                ++jumps;
                curEnd = farthest;            // commit one jump and extend the boundary
            }
        }
        return jumps;
    }
};
