# 001 Two Sum

Difficulty: Easy

## 1. Problem Statement

Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
You may assume that each input would have exactly one solution.  
Example:
> Given nums = [2, 7, 11, 15], target = 9,  
> Because nums[0] + nums[1] = 2 + 7 = 9,  
> return [0, 1].

## 2. Thoughts

### 2.1. Naive Way

Two nested For loops.  
Complexity: O(n^2)

### 2.2. Using Map

One traverse through the array, push the number into the map. Search target-number in the map.  
Complexity: O(n)

## 3. Code

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        map<int, int>::iterator it;
        vector<int> rv;
        for (int i = 0; i < nums.size(); i ++){
            if ((it = m.find(nums[i])) != m.end()){
                rv.push_back(it->second);
                rv.push_back(i);
            }
            m[target-nums[i]] = i;
        }
        return rv;
    }
};
```
