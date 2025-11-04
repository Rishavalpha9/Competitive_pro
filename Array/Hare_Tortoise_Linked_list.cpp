//T.C : O(n) Using "Hare & tortoise technique"
//S.C : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];// pointer starts at index 0
        int fast= nums[0];
        slow=nums[slow];
        fast=nums[nums[fast]];

        while(slow!=fast)
        {

            slow=nums[slow]; // 1 steps
            fast=nums[nums[fast]]; // 2 steps
        }
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow]; // 1 step 
            fast=nums[fast];  // both 1 step now
        }
        return slow;
    }
};
