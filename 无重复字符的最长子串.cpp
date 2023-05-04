3. 无重复字符的最长子串
https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?company_slug=bytedance
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;// 用字典记录每个字符出现的位置
        //我们需要将哈希表中的值设置为当前字符的下一个位置。这样，当我们遇到重复的字符时，我们可以将左指针移动到该字符的下一个位置，而不是移动到该字符的当前位置。这样可以确保窗口中没有重复的字符。
        for (int i = 0, j = 0; j < n; j++) {//i是左指针,j是右指针
            if (mp.count(s[j])) {
                i = max(mp[s[j]], i);//# 如果该字符已经出现过，更新左指针i
            }
            ans = max(ans, j - i + 1);// 更新该字符出现的位置
            mp[ s[j] ] = j + 1;
        }
        return ans;
    }
};
