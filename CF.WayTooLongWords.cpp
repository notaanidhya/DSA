#include <iostream>
using namespace std;

class Solution {
public:
    string Waytoolongwords(string word) {
        if (word.size()>10) {
            return string(1,word[0])+ to_string(word.size()-2)+string(1,word.back());
        }
        return word;
    }
};

int main() {
    Solution s;
    int n;
    string word;
    cin>>n;
    while (n--) {
        cin>>word;
        s.Waytoolongwords(word);
        cout << s.Waytoolongwords(word) << "\n";
    }

}
