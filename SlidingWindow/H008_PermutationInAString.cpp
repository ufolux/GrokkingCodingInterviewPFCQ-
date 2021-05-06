//
// Created by Sines on 2021/5/6.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

/**
 * Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
Example 3:

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.
Example 4:

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.
 */

class StringPermutation {
public:
    static bool findPermutation(const string &str, const string &pattern) {
        unordered_map<char, int> cmap;
        for (char c : pattern) {
            cmap[c]++;
        }
        int window_start = 0;
        int match = 0;
        for (int window_end = 0; window_end < str.size(); window_end++) {
            char rc = str[window_end];
            if (cmap.count(rc)) {
                if (cmap[rc] == 0) {
                    match++;
                } else {
                    cmap[rc]--;
                }
            }
            if (match == cmap.size()) {
                return true;
            }

            if (window_end >= pattern.size() - 1) {
                char lc = str[window_start++];
                if (cmap.count(lc)) {
                    if (cmap[lc] == 0) {
                        match--;
                    }
                    cmap[lc]++;
                }
            }
        }
        return false;
    }
};