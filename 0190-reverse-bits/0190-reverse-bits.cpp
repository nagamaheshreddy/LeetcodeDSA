class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int count=32;

        while(count){
            ans=ans<<1;
            if(n&1!=0){
                ans=ans|1;
            }
            n=n>>1;
            count--;
        }
        return ans;
    }
};