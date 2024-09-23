class Solution {
public:
    bool isPossible(int k,vector<int>&piles,int h){
        long long reqHours=0;

        for(int i=0;i<piles.size();i++){
            reqHours+=ceil(double(piles[i])/k);
        }
        return reqHours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int mid,ans;

        while(low<=high){
            mid=low+(high-low)/2;
            if(isPossible(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }else {
                low=mid+1;
            }
        }
        return ans;
    }
};