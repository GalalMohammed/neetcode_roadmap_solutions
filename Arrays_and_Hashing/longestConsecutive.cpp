class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> sorted_nums;
        map<int, bool>::iterator it;
        for(int i : nums)
        sorted_nums[i] = 1;
        int longest = 0, counter = 0;
        int prev;
        for(it = sorted_nums.begin(); it != sorted_nums.end(); it++)
        {
            if(it != sorted_nums.begin())
            {
                if(it->first - prev != 1)
                {
                    longest = longest > counter? longest : counter;
                    counter = 0;
                }
            }
            counter++;
            prev = it->first;
        }
        return longest > counter? longest : counter;
    }
};
