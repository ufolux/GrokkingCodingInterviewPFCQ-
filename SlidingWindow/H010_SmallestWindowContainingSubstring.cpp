//
// Created by Sines on 2021/5/6.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

/**
 * Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.

Example 1:

Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"
Example 2:

Input: String="abdbca", Pattern="abc"
Output: "bca"
Explanation: The smallest substring having all characters of the pattern is "bca".
Example 3:

Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern.
 */
class MinimumWindowSubstring {
public:
    static string findSubstring(const string &str, const string &pattern) {
        unordered_map<char, int> cmap;
        for (char c: pattern) {
            cmap[c]++;
        }
        int window_start = 0;
        int match = 0;
        int min_len = numeric_limits<int>::max();
        int substr_start;
        for (int window_end = 0; window_end < str.length(); ++window_end) {
            char rc = str[window_end];
            if (cmap.count(rc)) {
                cmap[rc]--;
                if (cmap[rc] >= 0) {
                    match++;
                }
            }

            while (match == pattern.length()) {
                int len = window_end - window_start + 1;
                if (len < min_len) {
                    min_len = len;
                    substr_start = window_start;
                }

                char lc = str[window_start++];
                if (cmap.count(lc)) {
                    if (cmap[lc] == 0) {
                        match--;
                    }
                    cmap[lc]++;
                }
            }
        }
        return min_len > str.length() ? "" : str.substr(substr_start, min_len);
    }
};