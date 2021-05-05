//
// Created by Sines on 2021/5/5.
//

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
public:
    /**
     * 解释一下原理
     * 中心思想就是要找到包含重复字母数量最多的滑动窗口，然后看下替换 k 个字符是否可以让整个窗口都变成这个重复的字母，
     * 如果不能，那窗口肯定是大了，就让窗口的 start 边界向后移动来缩窄窗口
     * @param str
     * @param k
     * @return
     */
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        int window_start = 0;
        int max_freq = 0;
        unordered_map<char, int> cmap;
        for (int window_end = 0; window_end < str.length(); ++window_end) {
            char rc = str[window_end];
            cmap[rc]++;
            max_freq = max(max_freq, cmap[rc]);
            if (window_end - window_start + 1 - max_freq > k) {
                char lc = str[window_start];
                cmap[lc]--;
                window_start++;
            }
            maxLength = max(maxLength, window_end - window_start + 1);
        }
        return maxLength;
    }
};
