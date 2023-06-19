class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // let's solve together
        
        int ans = INT_MIN;
        int preSum = 0;
        
        for(int i = 0; i < gain.size(); i++){
            
            ans = max(preSum,ans);
            preSum += gain[i];
            
        }
        
        if(preSum > ans)
            ans = preSum;
        
        
        return ans;
    }
};

//subscribe my channel 