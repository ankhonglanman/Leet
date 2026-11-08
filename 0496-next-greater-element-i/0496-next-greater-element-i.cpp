class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idx2;
        for (int i = 0; i < nums2.size(); i++) {
            idx2[nums2[i]] = i;
        }

        vector<int> res;
        res.reserve(nums1.size());
        for (const auto& num : nums1) {
            int nextGreater = -1;
            for (int i = idx2[num]; i < nums2.size(); i++) {
                if (nums2[i] > num) {
                    nextGreater = nums2[i];
                    break;
                }
            }

            res.push_back(nextGreater);
        }

        return res;
    }
};