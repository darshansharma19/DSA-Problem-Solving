class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        
        // Create a vector of pairs to associate each number with its cost
        vector<pair<int, int>> numsWcost(n);
        for (int i = 0; i < n; i++)
            numsWcost[i] = { nums[i], cost[i] };
        
        // Sort the vector in ascending order based on the numbers
        sort(numsWcost.begin(), numsWcost.end(), less<>());
        
        // Define a lambda function to calculate the cost based on the target number
        function<long long(int)> f = [&](int x) {
            long long sum = 0LL;
            for (auto& [n, c] : numsWcost) {
                sum += llabs(n - x) * c; // Calculate the cost as absolute difference multiplied by the cost
            }
            return sum;
        };
        
        // Set the left and right boundaries for binary search
        int l = numsWcost[0].first; // First element in sorted numsWcost
        int r = numsWcost[n - 1].first; // Last element in sorted numsWcost
        
        // Handle a very extreme case where all numbers are the same
        if (l == r)
            return f(l);
        
        long long ans;
        // Perform binary search to find the minimum cost
        while (l < r) {
            int mid = (r + l) / 2; // Calculate the midpoint
            
            // Calculate the cost of choosing mid as the target number
            long long f1 = f(mid);
            
            // Calculate the cost of choosing mid+1 as the target number
            long long f2 = f(mid + 1);
            
            // Store the minimum cost between f1 and f2
            ans = min(f1, f2);
            
            if (f1 > f2)
                l = mid + 1; // Minimum cost lies to the right of mid
            else
                r = mid; // Minimum cost lies to the left of mid
        }
        
        // Return the minimum cost
        return ans;
    }
};

