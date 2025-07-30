//tried map before , but got to know that vector is better for this kind of problems as it is faster and can be compared using '==' operator easily.


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())return {};
        vector<int> freq_p(26,0),freq_s(26,0);
        for(auto x:p){
            freq_p[x-'a']++;
        }
        for(int x=0;x<p.size();x++){
            freq_s[s[x] -'a']++;
        }
        vector<int> ans;
        for(int i = 0;i<=s.size()-p.size();i++){
            if(freq_p==freq_s)ans.push_back(i);
            if (i < s.size() - p.size()) {
                freq_s[s[i] - 'a']--;
                freq_s[s[i + p.size()] - 'a']++;
            }
        }
        return ans;

    }
};
