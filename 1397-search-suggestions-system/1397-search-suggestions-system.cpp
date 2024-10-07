class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n=searchWord.size();
        vector<vector<string>>ans;
        sort(products.begin(),products.end());

        int left=0,right=products.size()-1,count=0;
        for(int i=0;i<n;i++){
            char ch=searchWord[i];
            
            while(left<=right && (products[left].size()<=i || products[left][i]!=ch)){
                left++;
            }
            while(left<=right && (products[right].size()<=i || products[right][i]!=ch)){
                right--;
            }

            count=min(3,right-left+1);
            int l=left;
            vector<string>prefix;
            while(count){
                prefix.push_back(products[l]);
                l++;
                count--;
            }
            ans.push_back(prefix);
            prefix.clear();
        }
        
        return ans;
    }
};