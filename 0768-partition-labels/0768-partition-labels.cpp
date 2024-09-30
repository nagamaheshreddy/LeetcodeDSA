class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>last;

        for(int i=0;i<n;i++){
            last[s[i]]=i;
        }
        vector<int>ans;

        int size=0,start=0,end=0;
        for(int i=0;i<n;i++){
            size++;
            end=max(end,last[s[i]]);
            if(end==i){
                ans.push_back(size);
                size=0;
                start=i+1;
                end=i+1;
            }

        }

        return ans;

    }
};