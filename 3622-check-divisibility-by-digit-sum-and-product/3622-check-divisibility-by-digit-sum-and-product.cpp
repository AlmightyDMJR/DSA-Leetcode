class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum=0 , mul=1 ;
        while(n>0){
            int r = n % 10;
            sum += r;
            mul *= r;
            n/=10;
        }
        int val = sum + mul;
        return original % val==0;
        
    }
};