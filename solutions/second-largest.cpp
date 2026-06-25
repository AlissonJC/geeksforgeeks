/*
 * GeeksforGeeks — Second Largest  (Difficulty: Easy)
 * https://www.geeksforgeeks.org/problems/second-largest3735/1
 *
 * Given an array arr[] of positive integers, return the second largest element —
 * meaning the largest value that is strictly smaller than the maximum. Duplicates
 * of the maximum do not count, so for [10, 5, 10] the answer is 5 and for
 * [10, 10, 10] no such value exists. Return -1 when there is no element smaller
 * than the maximum.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the second largest distinct value, or -1.
 *
 * Constraints:
 *   2 <= arr.size() <= 1e5
 *   1 <= arr[i]     <= 1e5
 *
 * Approach: a single linear scan keeping the two best values seen so far — `first`
 * (the maximum) and `second` (the best value strictly below it). When an element
 * exceeds `first`, the old maximum slides into `second`; when it lies strictly
 * between `second` and `first`, it becomes the new `second`; elements equal to
 * `first` are skipped so the runner-up never ties the maximum.
 *
 * Complexity: O(n) time (one pass), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int first = -1, second = -1;   // sentinels; safe because every arr[i] >= 1

        for (int x : arr) {
            if (x > first) {           // found a new maximum: previous max becomes runner-up
                second = first;
                first = x;
            } else if (x < first && x > second) {   // strictly between the two -> new runner-up
                second = x;
            }
            // x == first is intentionally ignored: the runner-up must be < the maximum
        }

        return second;                 // stays -1 when no element is smaller than the maximum
    }
};
