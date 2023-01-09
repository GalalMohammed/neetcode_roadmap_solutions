class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> f;
        map<int, int>::iterator it;
        for(int i : nums)
        {
            if(f.count(i) > 0)
            {
                f[i]++;
            }
            else
            {
                f[i] = 1;
            }
        }
        vector<int> ans;
        map<int, int>::iterator max;
        for(int i = 0; i < k; i++)
        {
            max = f.begin();
            for(it = ++f.begin(); it != f.end(); it++)
            {
                if(it->second > max->second)
                {
                    max = it;
                }
            }
            ans.push_back(max->first);
            f.erase(max->first);
        }
        return ans;
    }
};
