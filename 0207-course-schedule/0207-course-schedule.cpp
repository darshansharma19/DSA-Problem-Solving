class Solution {
public:
    bool dfs(vector<int>a[],vector<int> &v,int i,vector<int>&df){
        v[i]=1;
        df[i]=1;
        for(auto k:a[i]){
            if(df[k])return true;
            else if(!v[k])
            if(dfs(a,v,k,df))return true;
        }
        df[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>a[n];
        for(int i=0;i<p.size();i++){
            a[p[i][0]].push_back(p[i][1]);
        }
        vector<int>v(n,0);
        vector<int>df(n,0);
        int pa=-1;
        for(int i=0;i<n;i++){
            if(!v[i]){
                if(dfs(a,v,i,df))return false;
            }
        }
        return true;
    }
};