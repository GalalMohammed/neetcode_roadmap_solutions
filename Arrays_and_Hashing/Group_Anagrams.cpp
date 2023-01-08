class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sorted_str;
        for(string s : strs)
        {
            sort(s.begin(), s.end());
            sorted_str.push_back(s);
        }
        vector<vector<string>> ans;
        int s = strs.size();
        vector<short> checked(s, 0);
        bool f;
        for(int i = 0; i < sorted_str.size(); i++)
        {
            if(checked[i] == 0)
            {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                for(int j = i + 1; j < sorted_str.size(); j++)
                {
                    if(checked[j] == 0 && sorted_str[i].length() == sorted_str[j].length())
                    {
                        f = true;
                        for(int k = 0; k < sorted_str[i].length(); k++)
                        {
                            if(sorted_str[i][k] != sorted_str[j][k])
                            {
                                f = false;
                                break;
                            }
                        }
                        if(f)
                        {
                            checked[j] = 1;
                            tmp.push_back(strs[j]);
                        }
                    }
                }
                ans.push_back(tmp);
            }        
        }
        return ans;
    }
};
