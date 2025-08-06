class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }

        unordered_map<string, int> counts;
        for (const string& word : words) {
            counts[word]++;
        }

        vector<int> ans;
        int sLen = s.length();
        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;

        if (sLen < totalLen) {
            return {};
        }

        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seen;
            int left = i;
            int wordsFound = 0;

            for (int j = i; j <= sLen - wordLen; j += wordLen) {
                string currentWord = s.substr(j, wordLen);
                
                if (counts.count(currentWord)) {
                    seen[currentWord]++;
                    wordsFound++;

                    while (seen[currentWord] > counts[currentWord]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        wordsFound--;
                        left += wordLen;
                    }

                    if (wordsFound == numWords) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        wordsFound--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    wordsFound = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};
