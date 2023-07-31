class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int cnt = 0; 
        int longest = 1;
        int lastsmaller = INT_MIN;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n; i++){
            if(nums[i]-1 == lastsmaller){
                cnt = cnt + 1;
                lastsmaller = nums[i];
            }
            if(nums[i] != lastsmaller){
                cnt = 1;
                lastsmaller = nums[i];
            }
               longest = max(longest,cnt);
        }
     
        return longest;
    }
};