/*
 * GeeksforGeeks — Majority Element  (Difficulty: Medium)
 * https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
 *
 * Given an array arr[], return the value that appears STRICTLY more than n/2 times
 * (n = arr.size()). Such an element is unique when it exists; if none qualifies,
 * return -1.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the majority value, or -1 when there is none.
 *
 * Constraints:
 *   1 <= n      <= 1e5
 *   1 <= arr[i] <= 1e5
 *
 * Approach: Boyer-Moore voting in two passes. Pass 1 distils a single CANDIDATE: keep
 * a running count that increments on a match and decrements otherwise; whenever it hits
 * 0, adopt the current element as the new candidate. Any value occurring more than n/2
 * times necessarily survives this pairwise cancellation. Because the statement does NOT
 * guarantee a majority exists, pass 2 recounts the candidate's true frequency and keeps
 * it only when that frequency exceeds n/2, otherwise returns -1. Using strict > n/2 with
 * integer division is exact: for n=7, n/2=3, so a count of 4 (> 3.5) passes while 3 does
 * not; for n=2, n/2=1, so a count must reach 2 to qualify.
 *
 * Complexity: O(n) time (two linear passes), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int candidate = arr[0];   // safe to seed: n >= 1 by constraints
        int count = 0;

        // Pass 1 — Boyer-Moore: pairwise-cancel distinct values; one survivor remains.
        for (int x : arr) {
            if (count == 0) candidate = x;          // no active candidate -> adopt this one
            count += (x == candidate) ? 1 : -1;
        }

        // Pass 2 — the survivor is only a *possible* majority; verify its real frequency,
        // since the statement permits the case where no element exceeds n/2.
        int freq = 0;
        for (int x : arr)
            if (x == candidate) ++freq;

        // Strict majority = strictly more than half; integer n/2 makes the test exact.
        return (freq > (int)arr.size() / 2) ? candidate : -1;
    }
};
