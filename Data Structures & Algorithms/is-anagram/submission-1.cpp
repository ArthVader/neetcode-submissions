class Solution {
public:
    bool isAnagram(string s, string t) {

        const int TotalCharsInS = s.size();
        const int TotalCharsInT = t.size();
        if(TotalCharsInS != TotalCharsInT)
        {
            return false;
        }

        map<char, int> CharacterLookup = {};

        for(int i = 0; i < TotalCharsInS; ++i)
        {
            ++CharacterLookup[s[i]];
        }

        for(int i = 0; i < TotalCharsInT; ++i)
        {
            --CharacterLookup[t[i]];
        }

        for(const auto & kv: CharacterLookup)
        {
            if(kv.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
