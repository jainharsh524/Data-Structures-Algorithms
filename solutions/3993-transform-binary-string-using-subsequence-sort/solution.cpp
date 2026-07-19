class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int length = s.length();
        int totalsZeros = 0;
        vector<int> sZeroPrefixes(length, 0);
        for (int i = 0; i < length; ++i) {
            if (s[i] == '0') {
                totalsZeros++;
            }
            sZeroPrefixes[i] = totalsZeros;
        }
        vector<bool> results;
        results.reserve(strs.size());
        for (const string& target : strs) {
            int existingZeros = 0;
            int questionMarks = 0;
            
            for (char c : target) {
                if (c == '0') {
                    existingZeros++;
                } else if (c == '?') {
                    questionMarks++;
                }
            }
            int neededZeros = totalsZeros - existingZeros;
            if (neededZeros < 0 || neededZeros > questionMarks) {
                results.push_back(false);
                continue;
            }
            int convertedQuestionMarks = 0;
            int runningTargetZeros = 0;
            bool isPossible = true;
            for (int i = 0; i < length; ++i) {
                if (target[i] == '0') {
                    runningTargetZeros++;
                } else if (target[i] == '?') {
                    if (convertedQuestionMarks < neededZeros) {
                        runningTargetZeros++;
                        convertedQuestionMarks++;
                    }
                }
                if (runningTargetZeros < sZeroPrefixes[i]) {
                    isPossible = false;
                    break;
                }
            }
            results.push_back(isPossible);
        }
        return results;
    }
};
