class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int totalCharactersInS = s.size();
        int totalCharactersInT = t.size();

        if(totalCharactersInS > totalCharactersInT)
        {
            return false;
        }
    
        int indexInS = 0;
        for(int indexInT = 0; indexInT < totalCharactersInT; ++indexInT)
        {
            if(indexInS < totalCharactersInS && s[indexInS] == t[indexInT])
            {
                ++indexInS;
            }
        }

        if(indexInS == totalCharactersInS)
        {
            return true;
        }

        return false;
    }
};