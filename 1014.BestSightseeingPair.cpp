class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxscore=0;
        int maxval=values[0];
        for(int j =1;j<values.size();j++){
            maxscore = max(maxscore,maxval+values[j]-j);
            maxval=max(maxval,values[j]+j);
        }
        return maxscore;
    }
};
