class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore Voting Algorithm
        int count = 0;
        int el = 0;
        int n = nums.size();
        for (auto i = 0; i < n; i++) {

            if (count == 0) {
                count = 1;
                el = nums[i];
            } else if (nums[i] == el) {
                count++;
            } else
                count--;
        }

        int a = 0;
        for (auto i = 0; i < n; i++) {

            if (nums[i] == el) {

                a++;
            }
            if (a > n / 2) {

                return el;
            }
        }
        return -1;
    }
};
