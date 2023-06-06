class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int a=arr[0];
        int d=arr[1]-arr[0];
        for(int i=1;i<n;i++)
          if(arr[i-1]+d!=arr[i])
              return false;
        return true;

    }
};