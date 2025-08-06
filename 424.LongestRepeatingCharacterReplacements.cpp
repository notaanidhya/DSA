class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charcount(26,0);
        int start=0;
        int maxfreq=0,maxlen=0;
        for(int i = 0;i<s.size();i++){
            charcount[s[i]-'A']++;
            maxfreq= max(maxfreq,charcount[s[i]-'A']);
            if((i-start+1)-maxfreq>k){
                charcount[s[start]-'A']--;
                start++;}
            maxlen=max(maxlen,i-start+1);
    }return maxlen;}
};
