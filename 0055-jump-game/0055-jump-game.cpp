class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        int finalposition=nums.size()-1;
        
        for(int idx=nums.size()-2;idx>=0;idx--){
            
            
            if(idx+nums[idx]>=finalposition){
                finalposition=idx;
            }
        }
        return finalposition==0;
        
    }
};