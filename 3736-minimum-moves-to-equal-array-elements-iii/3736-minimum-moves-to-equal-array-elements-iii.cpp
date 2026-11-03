class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = INT_MIN;

        for (const auto& num : nums) {
            if (num > max) max = num;
        }

        int minMoves = 0;

        for (const auto& num : nums) {
            minMoves += max - num;
        }

        return minMoves;
    }
};