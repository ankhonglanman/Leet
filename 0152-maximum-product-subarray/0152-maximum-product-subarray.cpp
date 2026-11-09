class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int curMin = 1;
        int curMax = 1;

        int res = INT_MIN;

        for (const auto& num : nums) {
            int temp = curMax * num;
            curMax = max(temp, max(curMin * num, num));
            curMin = min(temp, min(curMin * num, num));

            res = max(curMax, res);
        }

        return res;
    }
};