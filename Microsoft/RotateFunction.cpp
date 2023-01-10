//problem number 396 on leetcode
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int preFun=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            preFun+=(i*nums[i]);
            sum+=nums[i];
        }

        int ans=preFun;
      //  cout<<ans;
        for(int i=n-1;i>0;i--){
            int curr= preFun+sum-(n*nums[i]);
            ans=max(ans,curr);
            preFun=curr;
        }
        return ans;  
    }
};