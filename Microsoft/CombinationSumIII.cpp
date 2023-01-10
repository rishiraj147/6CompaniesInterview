class Solution {
public:
    void fun(int ele,int k,int n,vector<vector<int>>&ans,vector<int> inst){
        //base case
        if(n==0&&k==0){
            ans.push_back(inst);
            return;
        }
        if(ele>9||k==0) return;

        //exclude
        fun(ele+1,k,n,ans,inst);

        //include
        if(n>=ele){
            inst.push_back(ele);
            fun(ele+1,k-1,n-ele,ans,inst);
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> inst;

        fun(1,k,n,ans,inst);
        return ans;
    }
};