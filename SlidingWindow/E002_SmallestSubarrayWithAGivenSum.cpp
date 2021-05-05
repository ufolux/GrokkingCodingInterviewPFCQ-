//
// Created by Sines on 2021/5/4.
//

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        int min_size = numeric_limits<int>::max();
        int sum = 0;
        int window_size = 1;
        int window_start = 0;
        bool has = false;
        for (int i = window_start; i < arr.size(); ++i) {
            sum += arr[i];
            while (sum >= S) {
                has = true;
                window_size = i - window_start + 1;
                min_size = min(window_size, min_size);
                sum -= arr[window_start];
                window_start++;
            }
        }

        return has ? min_size : -1;
    }
};
