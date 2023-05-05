class Solution {
    private:
     int kadanes_Algo(vector<int>&nums,int n){
         int maxsum=INT_MIN;
         int currsum=0;
         for(int i=0;i<n;i++){
             currsum+=nums[i];
             if(currsum>maxsum) maxsum = currsum;
             if(currsum<0) currsum=0;
         }
         return maxsum;
     }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int wrapsum=0;
        // int nonwrapsum=0;
        // int sum=0;
        // wrapsum = kadanes_Algo(nums,nums.size());
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     nums[i] = -1 * nums[i];
        // }
        // int temp = kadanes_Algo(nums,nums.size());
        // nonwrapsum = sum - (-1 * temp);
        // return max(wrapsum,nonwrapsum);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int curr_max=nums[0];
        int max_so_far=nums[0];
        int curr_min=nums[0];
        int min_so_far=nums[0];
       for(int i=1;i<nums.size();i++){
           //kanades algo for finding max subarray sum
          curr_max = max(curr_max+nums[i],nums[i]);
          max_so_far = max(max_so_far,curr_max);
          // kanades algo for finding min subarray sum
          curr_min = min(curr_min+nums[i],nums[i]);
          min_so_far = min(min_so_far,curr_min);
       } 
       if(min_so_far==sum) return max_so_far;
       return max(max_so_far,sum-min_so_far);
    }
};