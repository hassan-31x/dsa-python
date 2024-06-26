//? 1. Use binary search to lower the search range
//! TC: O(nlog(max(piles))) SC: O(1)
// https://leetcode.com/problems/koko-eating-bananas/submissions/1298301827

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    
    int low = 1;
    int high = 0;
    for (int i = 0; i < n; i++) {
        high = max(high, piles[i]);
    }
    
    int result = high;
    
    while (low <= high) {
        int k = low + (high - low) / 2;
        long int hours = 0;
        for (int i = 0; i < n; i++) {
            hours += ceil((double) piles[i] / k);
        }
        if (hours <= h) {
            result = min(result, k);
            high = k - 1;
        } else {
            low = k + 1;
        }
    }
    
    return result;
}