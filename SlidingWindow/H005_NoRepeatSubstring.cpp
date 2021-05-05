//
// Created by Sines on 2021/5/5.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
public:
    static int findLength(const string& str) {
        int maxLength = 0;
        int window_start = 0;
        unordered_map<char, int> cmap;
        for (int window_end = 0; window_end < str.length(); ++window_end) {
            char rc = str[window_end];
            if (cmap.count(rc) == 0) {
                cmap[rc] = window_end;
            } else {
                maxLength = max(maxLength, window_end - window_start);
                window_start = cmap[rc] + 1;
                cmap[rc] = window_end;
            }
        }
        return maxLength;
    }
};