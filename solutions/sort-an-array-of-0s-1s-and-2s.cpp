/*
 * GeeksforGeeks — Sort 0s, 1s and 2s  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
 *
 * Given an array arr[] that contains only the values 0, 1, and 2, sort it in
 * ascending order in place, without calling any built-in sort. The follow-up asks
 * for a single pass using only constant extra space.
 *
 * I/O contract: function-based (the GfG driver supplies main). The function returns
 * void and rearranges `arr` (vector<int>) in place; the driver prints it afterward.
 *
 * Constraints:
 *   1 <= arr.size() <= 1e5
 *   0 <= arr[i]     <= 2
 *
 * Approach: Dutch National Flag partitioning with three indices. `low` marks the end
 * of the 0s region, `high` the start of the 2s region, and `mid` scans the unknown
 * middle. On a 0, swap it down to `low` and advance both low and mid; on a 1, it is
 * already in its final region, so just advance mid; on a 2, swap it up to `high` and
 * shrink high WITHOUT advancing mid — the element pulled in from `high` is still
 * unexamined and must be inspected next iteration. The loop ends when mid passes high.
 *
 * Complexity: O(n) time (each element is settled within one pass), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low  = 0;                    // everything before low is a settled 0
        int mid  = 0;                    // [low, mid) is all 1s; mid scans the unknown region
        int high = (int)arr.size() - 1;  // everything after high is a settled 2

        while (mid <= high) {
            if (arr[mid] == 0) {         // send this 0 down into the 0s block
                swap(arr[low], arr[mid]);
                ++low;
                ++mid;
            } else if (arr[mid] == 1) {  // a 1 already lies in its final region
                ++mid;
            } else {                     // arr[mid] == 2 -> send it up into the 2s block
                swap(arr[mid], arr[high]);
                --high;                  // do NOT advance mid: the swapped-in value is unexamined
            }
        }
    }
};
