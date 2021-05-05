//
// Created by Sines on 2021/5/5.
//

using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
public:
    static int findLength(const vector<int>& arr, int k) {
        int maxLength = 0;
        int max_freq = 0;
        int window_start = 0;
        for (int window_end = 0; window_end < arr.size(); ++window_end) {
            int lc = arr[window_end];
            if (lc == 1) {
                max_freq++;
            }
            if (window_end - window_start + 1 - max_freq > k) {
                if (arr[window_start] == 1) max_freq--;
                window_start++;
            }
            maxLength = max(maxLength, window_end - window_start + 1);
        }
        return maxLength;
    }
};