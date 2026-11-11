class Solution {
using ll = long long;
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long minCost = 0;
        while (need1 > 0 || need2 > 0) {
            if (need1 > 0 && need2 > 0) {
                if (costBoth < cost1 + cost2) {
                    long long sub = min(need1, need2);
                    need1 -= sub;
                    need2 -= sub;
                    minCost += (ll)sub * (ll)costBoth;
                }
                else if (costBoth <= cost1 || costBoth <= cost2) {
                    long long sub = min(need1, need2);
                    need1 -= sub;
                    need2 -= sub;
                    minCost += (ll)costBoth * (ll)sub;
                }
                else {
                    minCost += (ll)need1 * (ll)cost1;
                    minCost += (ll)need2 * (ll)cost2;
                    need1 = 0;
                    need2 = 0;
                    break;  
                }
            }
            else {
                if (need1 > 0) {
                    minCost += (ll)min(cost1, costBoth) * (ll)need1;
                    need1 = 0;
                }
                else if (need2 > 0) {
                    minCost += (ll)min(cost2, costBoth) * (ll)need2;
                    need2 = 0;
                }
                else break;
            }
        } 

        return minCost;
    }
};