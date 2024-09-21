class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+1,1);
        vector<int>right(n+1,1);

        
        for(int i=0;i<n;i++){
            if(i==0){
                left[i]=1;
            }else{
             left[i]=left[i-1]*nums[i-1];  
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=1;
            }else{
                right[i]=right[i+1]*nums[i+1];  
            }
        }
        vector<int>ans(n,1);
        
        for(int i=0;i<n;i++){
            ans[i]=left[i]*right[i];
        }
        return ans;
    }
};