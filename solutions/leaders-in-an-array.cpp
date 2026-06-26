/*
 * GeeksforGeeks — Array Leaders  (Difficulty: Easy)
 * https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
 *
 * Given an array arr[] of non-negative integers, return every "leader": an element
 * that is greater than or equal to all elements to its right. The rightmost element
 * is therefore always a leader. Equality still qualifies, so in [10, 4, 2, 4, 1]
 * both 4s are leaders. Leaders are returned in their original left-to-right order.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the vector of leaders in left-to-right order.
 *
 * Constraints:
 *   1 <= arr.size() <= 1e6
 *   0 <= arr[i]     <= 1e6
 *
 * Approach: scan once from right to left, tracking the maximum value seen so far to
 * the right. An element is a leader exactly when it is >= that running maximum (>=,
 * not >, so an element equal to the current max still counts). Collecting in this
 * direction yields the leaders right-to-left, so reverse the result at the end to
 * restore the array's original order.
 *
 * Complexity: O(n) time (one pass + one reversal), O(1) extra space beyond the output.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int maxRight = INT_MIN;        // nothing sits to the right of the last element yet

        // Walk from the rightmost element toward the left.
        for (int i = (int)arr.size() - 1; i >= 0; --i) {
            if (arr[i] >= maxRight) {  // >= keeps elements that merely tie the max (e.g. the 2nd 4)
                result.push_back(arr[i]);
                maxRight = arr[i];     // raise the bar for everything further to the left
            }
        }

        reverse(result.begin(), result.end());  // built right-to-left -> restore original order
        return result;
    }
};
