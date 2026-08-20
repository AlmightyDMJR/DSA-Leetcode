class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start=0;
        int maxlen=1;

        for(int i=0;i<n;i++){

            int left=i;
            int right=i;

            while(left>=0 && right<=n && s[left]==s[right] ){
                if(right-left+1>maxlen){
                start = left;
                maxlen = right-left+1;
                }
                right++;
                left--;
            }

            left=i;
            right=i+1;

            while(left>=0 && right<=n && s[left]==s[right] ){
                if(right-left+1>maxlen){
                start = left;
                maxlen = right-left+1;
                }
                right++;
                left--;
            }
        }
        return s.substr(start,maxlen);
    }
};