class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int prevOneIdx = -(k + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - prevOneIdx - 1 < k) return false;
                prevOneIdx = i;
            }
        }

        return true;
    }
};