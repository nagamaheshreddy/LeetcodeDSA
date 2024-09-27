class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int res=0,prevEnd=INT_MIN;
        for(auto interval:intervals){
            if(interval[0]>=prevEnd){
                prevEnd=interval[1];
            }else{
                res++;
                prevEnd=min(prevEnd,interval[1]);
            }
        }
        return res;
    }
};