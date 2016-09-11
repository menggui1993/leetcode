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
