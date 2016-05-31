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
