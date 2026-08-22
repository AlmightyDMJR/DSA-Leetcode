class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) cnt1++;
            else if(arr[i]==1) cnt2++;
            else cnt3++;

        }

        for(int i=0;i<cnt1;i++) arr[i]=0;
        for(int i = cnt1; i< cnt1+cnt2 ; i++) arr[i]=1;
        for(int i= cnt1+cnt2 ; i<n; i++) arr[i]=2;
    }
};