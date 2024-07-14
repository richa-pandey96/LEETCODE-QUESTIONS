class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int k=st.size();
        set<int>::iterator it;  // Creating the iterator.
    int j=0;	
    for (it = st.begin(); it != st.end(); it++)
    {
    	nums[j]=*it;
        j++;
    }
    
    return k;
        
    }
};