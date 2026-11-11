class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = nums.size();
        int prevOneIdx = -(k + 1);
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) {
                if (i - prevOneIdx - 1 < k) return false;
                prevOneIdx = i;
            }
        }

        return true;
    }
};