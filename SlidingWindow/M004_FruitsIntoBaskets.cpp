//
// Created by Sines on 2021/5/4.
//

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
public:
    static int findLength(const vector<char>& arr) {
        int maxLength = 0;
        int window_start = 0;
        unordered_map<char, int> cmap;
        for (int window_end = 0; window_end < arr.size(); ++window_end) {
            char rc = arr[window_end];
            cmap[rc]++;
            while (cmap.size() > 2) {
                char lc = arr[window_start];
                cmap[lc]--;
                if (cmap[lc] == 0) {
                    cmap.erase(lc);
                }
                window_start++;
            }
            maxLength = max(maxLength, window_end - window_start + 1);
        }
        return maxLength;
    }
};