# 003 Longest Substr Without Repeating Characters

Difficulty: Medium

## 1. Problem Statement

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

## 2. Thoughts

Traverse the string and keep a current str. Every time a repeat happens, cut the cstr at the repeated character.

## 3. Code

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string cs = "";
        int max = 0;
        for (int i = 0; i < s.size(); i ++){
            if (cs.find(s[i]) != string::npos){
                if (cs.size() > max){
                    max = cs.size();
                }
                cs = cs.substr(cs.find(s[i]) + 1, i - cs.find(s[i]) - 1);
            }
            cs += s[i];
        }
        if (cs.size() > max){
            max = cs.size();
        }
        return max;
    }
};
```
