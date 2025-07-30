class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq_s1(26,0),freq_s2(26,0);
        if(s1.size()>s2.size())return false;
        for(char x:s1){
            freq_s1[x-'a']++;
        }
        for(int x;x<s1.size();x++){
            freq_s2[s2[x]-'a']++;
        }
        for(int i = 0;i<=s2.size()-s1.size();i++){
            if(freq_s1==freq_s2)return true;
            if (i < s2.size() - s1.size()) {
                freq_s2[s2[i] - 'a']--; 
                freq_s2[s2[i + s1.size()] - 'a']++; 
            }
        }
        return false;

    }
};
