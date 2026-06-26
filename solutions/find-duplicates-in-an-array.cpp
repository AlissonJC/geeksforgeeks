/*
 * GeeksforGeeks — Duplicates in a Limited Range Array  (Difficulty: Easy)
 * https://www.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
 *
 * Given an array arr[] of size n whose values lie in the range 1..n and where each
 * value appears at most twice, return every value that appears exactly twice. The
 * order of the returned values does not matter (the GfG driver sorts them before
 * printing); when nothing repeats, return an empty vector.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the vector of values occurring twice.
 *
 * Constraints:
 *   1 <= n      <= 1e6
 *   1 <= arr[i] <= n
 *
 * Approach: use the array itself as a presence table, so no extra O(n) memory is
 * needed. Because every value v lies in 1..n, it maps to a valid index v-1. Walk the
 * array; for the current value v = |arr[i]|, inspect slot arr[v-1]. If that slot is
 * already negative, v was seen before and is therefore a duplicate; otherwise flip
 * the slot's sign to mark v as seen. Since each value appears at most twice, every
 * duplicate is recorded exactly once (at its second occurrence). Taking |arr[i]|
 * undoes any sign flip that may have landed on the slot we are currently reading.
 *
 * Complexity: O(n) time (single pass), O(1) extra space beyond the output vector.
 * Note: this mutates arr in place, which is safe here — the driver consumes only the
 * returned vector afterward, never the array.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> result;

        for (int i = 0; i < (int)arr.size(); ++i) {
            int v   = abs(arr[i]);   // |...| because this slot may already be sign-flipped
            int idx = v - 1;         // a value v in 1..n maps to a valid index 0..n-1

            if (arr[idx] < 0)        // slot already marked -> this is v's second sighting
                result.push_back(v);
            else
                arr[idx] = -arr[idx];   // first sighting: mark v as seen by flipping the sign
        }

        return result;
    }
};
