class Solution {
public:
    int leftside(vector<int>& nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid  = start + (end - start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                //right side
                start = mid + 1;
            }
            else if(nums[mid] > target){
                //left side
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }

     int rightside(vector<int>& nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid  = start + (end - start)/2;
        while(start <= end){
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                //right side
                start = mid + 1;
            }
            else if(nums[mid] > target){
                //left side
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(leftside(nums,target));
        ans.push_back(rightside(nums,target));

        return ans;
        
    }
};