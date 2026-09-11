class Solution {
public:
    int totalNumbers(vector<int>& digits) {
          int ans = 0;

        // Try every 3-digit number
        for (int num = 100; num <= 999; num++) {

            // Last digit must be even
            if (num % 2 != 0)
                continue;

            int temp = num;
            vector<int> need(10, 0);

            // Count digits needed for this number
            for (int i = 0; i < 3; i++) {
                need[temp % 10]++;
                temp /= 10;
            }

            // Count digits available
            vector<int> have(10, 0);
            for (int d : digits)
                have[d]++;

            // Check if we have enough copies
            bool possible = true;

            for (int i = 0; i < 10; i++) {
                if (need[i] > have[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};