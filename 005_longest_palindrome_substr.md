# 005 Longest Palindrome substring

Difficulty: Medium

## 1. Problem Statement

## 2. Thoughts

### 2.1 Dynamic Programming
Let p[i, j] = 1 when substring(i, j) is palindrome and 0 otherwise.

Base case: p[i, i] = 1

Base case: p[i, i+1] = (s[i]==s[i+1])

Update p[i, j] = p[i+1, j-1] && s[i] == s[j]

Time complexity: O(n^2)

Space complexity: O(n^2)

### 2.2 Center Expansion
Two loops to find palindrome from center.

Center at i: check s[i-k] == s[i+k]

Center at i,i+1: check s[i-k] == s[i+1+k]

Time complexity: O(n^2)

Space complexity: O(n)

## 3. Code

### 3.1 DP
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int ** p = new int*[s.size()];
        for (int i = 0; i < s.size(); i++){
            p[i] = new int[s.size()];
        }
        for (int i = 0; i < s.size(); i++){
            p[i][i] = 1;
        }
        for (int i = 0; i < s.size()-1; i++){
            if (s[i] == s[i + 1]) p[i][i+1] = 1;
            else p[i][i+1] = 0;
        }
        for (int k = 2; k < s.size(); k++){
            for (int i = 0; i < s.size()-k; i++){
                if (s[i] == s[i+k] && p[i+1][i+k-1] == 1) p[i][i+k] = 1;
                else p[i][i+k] = 0;
            }
        }
        int len = 0;
        string longest = "";
        for (int i = 0; i < s.size(); i ++){
            for (int j = i; j < s.size(); j ++){
                if (p[i][j] == 1 && j-i+1 > len){
                    len = j - i + 1;
                    longest = s.substr(i, len);
                }
            }
        }
        return longest;
    }
};
```

### 3.2 Center
```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0;
        int first;
        int k;
        for (int i = 0; i < s.size(); i ++){
            k = 0;
            while (i - k >= 0 && i + k < s.size()){
                if (s[i-k] == s[i+k]){
                    if (2*k + 1 > len){
                        len = 2*k + 1;
                        first = i - k;
                    }
                    k ++;
                }
                else{
                    break;
                }
            }
        }
        for (int i = 0; i < s.size()-1; i ++){
            if (s[i] != s[i+1]) continue;
            k = 0;
            while (i - k >= 0 && i + 1 + k < s.size()){
                if (s[i-k] == s[i+1+k]){
                    if (2*k + 2 > len){
                        len = 2*k + 2;
                        first = i - k;
                    }
                    k ++;
                }
                else{
                    break;
                }
            }
        }
        return s.substr(first, len);
    }
};
```
