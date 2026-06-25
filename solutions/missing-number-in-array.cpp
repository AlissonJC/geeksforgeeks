/*
 * GeeksforGeeks — Missing in Array  (Difficulty: Easy)
 * https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1
 *
 * The array arr[] has size n-1 and holds distinct integers from the range 1..n,
 * i.e. it is a permutation of 1..n with exactly one value missing. Return that
 * missing value. Note that n = arr.size() + 1.
 *
 * I/O contract: function-based (the GfG driver supplies main). Input is `arr`
 * (vector<int>); output is the single integer in 1..n that does not appear.
 *
 * Constraints:
 *   1 <= arr.size() <= 1e6
 *   1 <= arr[i]     <= arr.size() + 1
 *
 * Approach: the sum of every integer from 1 to n is n*(n+1)/2. The array contains
 * all of those except one, so subtracting the array's actual sum from that
 * expected total leaves exactly the missing value. One linear pass, constant
 * extra memory.
 *
 * Complexity: O(n) time (single pass to accumulate the sum), O(1) extra space.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long n = (long long)arr.size() + 1;   // the array holds n-1 of the numbers 1..n

        // Sum of 1..n reaches ~ (1e6)^2 / 2 = 5e11, so it must be held in 64-bit;
        // doing this in a 32-bit int would overflow and silently give a wrong answer.
        long long expected = n * (n + 1) / 2;

        long long actual = 0;
        for (int x : arr) actual += x;

        return (int)(expected - actual);   // the lone value of 1..n absent from arr (fits in int)
    }
};
