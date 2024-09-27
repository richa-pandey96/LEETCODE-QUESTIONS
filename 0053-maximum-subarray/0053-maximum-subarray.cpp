class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
//   bruteforceapproach      int maxsum=INT_MIN;
//     for(int start=0; start<n; start++){
//         int currsum=0;
    
//         for(int end=start; end<n;end++){
//             currsum+=nums[end];
//             maxsum=max(currsum,maxsum);
            
            
//         }
//     }
//         cout<<maxsum;
        
  //by  kadane's algo      
        int currsum=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            maxsum=max(currsum, maxsum);
            
            if(currsum<0)
                currsum=0;
        }
        return maxsum;
        
    }
};