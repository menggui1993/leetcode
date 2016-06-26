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
Complexity: <img src="http://chart.googleapis.com/chart?cht=tx&chl= \mathcal{O}(n^2)" style="border:none;">

### 2.2. Using Map

One traverse through the array, push the number into the map. Search target-number in the map.  
Complexity: <img src="http://chart.googleapis.com/chart?cht=tx&chl= \mathcal{O}(n)" style="border:none;">

## 3. Code

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> rv;
        for (int i = 0; i < nums.size(); i ++){
            if (m.find(target-nums[i]) != m.end()){
                rv.push_back(m[target-nums[i]]);
                rv.push_back(i + 1);
                return rv;
            }
            else
                m[nums[i]] = i + 1;
        }
    }
};
```
