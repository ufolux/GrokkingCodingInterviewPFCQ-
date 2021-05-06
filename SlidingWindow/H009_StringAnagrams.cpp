//
// Created by Sines on 2021/5/6.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * Write a function to return a list of starting indices of the anagrams of the pattern in the given string.

Example 1:

Input: String="ppqp", Pattern="pq"
Output: [1, 2]
Explanation: The two anagrams of the pattern in the given string are "pq" and "qp".
Example 2:

Input: String="abbcabc", Pattern="abc"
Output: [2, 3, 4]
Explanation: The three anagrams of the pattern in the given string are "bca", "cab", and "abc".
 */
class StringAnagrams {
public:
    static vector<int> findStringAnagrams(const string &str, const string &pattern) {
        vector<int> resultIndices;
        unordered_map<char, int> cmap;
        for (char c: pattern) {
            cmap[c]++;
        }
        int window_start = 0;
        int match = 0;
        for (int window_end = 0; window_end < str.size(); ++window_end) {
            char rc = str[window_end];
            if (cmap.count(rc)) {
                cmap[rc]--;
                if (cmap[rc] == 0) {
                    match++;
                }
            }

            if (match == cmap.size()) {
                resultIndices.push_back(window_start);
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
        return resultIndices;
    }
};
