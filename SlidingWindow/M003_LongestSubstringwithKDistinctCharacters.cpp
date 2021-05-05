//
// Created by qingshuihe on 2021/5/4.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
public:
    // Input: String="araaci", K=1
    // Output: 2
    // Explanation: The longest substring with no more than '1' distinct characters is "aa".
    static int findLength(const string& str, int k) {
        unordered_map<char, int> cmap;
        int max_len = 0;
        int window_start = 0;
        for (int i = 0; i < str.size(); ++i) {
            char rc = str[i];
            cmap[rc]++;
            while (cmap.size() > k) {
                char lc = str[window_start];
                cmap[lc]--;
                if (cmap[lc] == 0) {
                    cmap.erase(lc);
                }
                window_start++;
            }
            max_len = max(max_len, i - window_start + 1);
        }
        return max_len;
    }
};