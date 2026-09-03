class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mnOdd = INT_MAX;
        int mnEven = INT_MAX;

        
        for (int x : nums1) {
            if (x % 2 == 0)
                mnEven = min(mnEven, x);
            else
                mnOdd = min(mnOdd, x);
        }

        
        bool allOdd = true;

        for (int x : nums1) {
            if (x % 2 == 0) {
                
                if (mnOdd >= x) {
                    allOdd = false;
                    break;
                }
            }
        }

        if (allOdd)
            return true;

        
        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 == 1) {
                
                if (mnOdd >= x) {
                    allEven = false;
                    break;
                }
            }
        }

        return allEven;
    }
};