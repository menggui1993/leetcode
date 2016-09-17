class Solution {
public:
    string convert(string s, int numRows) {
        string strs[numRows];
        int i = 0;
        while (i < s.size()){
            for (int j = 0; i < s.size() && j < numRows; j ++){
                strs[j] += s[i++];
            }
            for (int j = numRows - 2; i < s.size() && j > 0; j --){
                strs[j] += s[i++];
            }
        }
        string rs = "";
        for (int j = 0; j < numRows; j ++){
            rs += strs[j];
        }
        return rs;
    }
};
