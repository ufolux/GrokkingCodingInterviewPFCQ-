//
// Created by Sines on 2021/5/4.
//

using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        int window_start = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (i - window_start + 1 == k) {
                maxSum = max(maxSum, sum);
                sum -= arr[window_start];
                window_start++;
            }
        }
        return maxSum;
    }
};