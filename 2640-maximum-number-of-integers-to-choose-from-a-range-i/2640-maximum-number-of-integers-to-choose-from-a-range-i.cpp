class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s;
        for(int i=1;i<=n;i++){
            s.insert(i);
        }
        for(int num:banned)s.erase(num);
        int count=0,sum=0;
        for(int num:s){
            if(sum+num<=maxSum){
                sum+=num;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
};