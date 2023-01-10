//problem number 368 on leetcode

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int idx=0,len=1;
        int n=nums.size();
        pair<int,int> dp[n];
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            dp[i].second=1;
            dp[i].first=i;

            int maxLen=1;

            for(int j=i-1;j>=0;j--){
                if((max(nums[i],nums[j])%(nums[i],nums[j]))==0&& maxLen<1+dp[j].second){
                    maxLen=1+dp[j].second;
                    dp[i]={j,maxLen};
                }
            }

            if(maxLen>len){
                idx=i;
                len=maxLen;
            }
        }

        vector<int> ans;

        while(dp[idx].first!=idx){
            ans.push_back(nums[idx]);
            idx=dp[idx].first;
        }

        ans.push_back(nums[idx]);

        return ans;
    }
};