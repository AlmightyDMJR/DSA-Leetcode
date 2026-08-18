class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string result;
        sort(str.begin(),str.end());
        string first = str[0];
        string last = str[str.size()-1];
        
        int minlen = min(first.length(),last.length());

        for(int i=0;i<minlen;i++){
            if(first[i]!=last[i]) break;
            result+=first[i];
        }
        return result;
    }
};