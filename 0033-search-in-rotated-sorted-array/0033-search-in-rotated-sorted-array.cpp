class Solution {
public:

  int getpivot(vector<int> &nums, int n) {
  int start = 0;
  int end = n - 1;
  int mid = start + (end - start) / 2;
  while (start < end) {
    if (nums[mid] >= nums[0]) {
      start = mid + 1;
    } 
    else {
      end = mid;
    }
    mid = start + (end - start) / 2;
  }
  return start;
}
 
int binarysearch(vector<int> &nums, int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (nums[mid] == key)
        {
            return mid;
        }
        else if (nums[mid] < key)
        {
            // right wale part me aagye
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int pivot = getpivot(nums, nums.size());
        if(target >= nums[pivot] && target <=nums[nums.size()-1]){
            return binarysearch(nums,pivot,nums.size()-1,target);
        }
        else{
            return binarysearch(nums,0,pivot-1,target);
        }
        
    }
};