class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int sum=0;
        int min_len=numeric_limits<int>::max();
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                if(i-start+1 <min_len){
                    min_len=i-start+1;
                }
                sum-=nums[start];
                start++;
            }
        } 
        return min_len !=numeric_limits<int>::max() ? min_len:0;
    }
};
