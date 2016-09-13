class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int begin1 = 0;
        int end1 = nums1.size() - 1;
        int begin2 = 0;
        int end2 = nums2.size() - 1;
        int len1, len2, reduce;
        do{
            len1 = end1 - begin1 + 1;
            len2 = end2 - begin2 + 1;
            if (len1 <= 2){
                nums2.insert(nums2.begin()+end2+1, nums1.begin()+begin1, nums1.begin()+end1+1);
                sort(nums2.begin()+begin2, nums2.begin()+begin2+len1+len2);
                return (nums2[begin2+(len1+len2-1)/2] + nums2[begin2+(len1+len2)/2] + 0.0) / 2;
            }
            if (len2 <= 2){
                nums1.insert(nums1.begin()+end1+1, nums2.begin()+begin2, nums2.begin()+end2+1);
                sort(nums1.begin()+begin1, nums1.begin()+begin1+len1+len2);
                return (nums1[begin1+(len1+len2-1)/2] + nums1[begin1+(len1+len2)/2] + 0.0) / 2;
            }
            reduce = 0;
            if ((len1-1)/2 > (len2-1)/2){
                reduce = (len2-1)/2;
            }
            else{
                reduce = (len1-1)/2;
            }
            if (nums1[begin1+(len1-1)/2] > nums2[begin2+(len2-1)/2]){
                end1 -= reduce;
                begin2 += reduce;
            }
            else{
                begin1 += reduce;
                end2 -= reduce;
            }
        } while (1);
    }

};
