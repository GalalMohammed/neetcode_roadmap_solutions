class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        answer[0] = 1;
        answer[nums.size() - 1] = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            answer[i + 1] = nums[i] * answer[i];
        }
        int suffix = 1;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            suffix *= nums[i];
            answer[i - 1] *= suffix;
        }
        return answer;
    }
};
