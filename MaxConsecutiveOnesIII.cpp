class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int maxfreq=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==1)maxfreq++;
            while(right-left+1-maxfreq>k){
                if(nums[left]==1)maxfreq--;
                left++;
            }

            ans=max(right-left+1,ans);
        }
        return ans;
    }
};
