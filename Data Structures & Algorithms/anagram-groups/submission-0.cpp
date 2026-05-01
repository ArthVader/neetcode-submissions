class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<string> sortedStrs = {};
        vector<vector<string>> groupedAnagrams = {};
        int TotalStrs = strs.size();

        // populate sortedStringLookup
        for(int i = 0; i < TotalStrs; ++i)
        {
            // sort the characters of the string before inserting to map
            string str = strs[i];
            sort(str.begin(), str.end());
            sortedStrs.push_back(str);
        }

        // track which indexes are invalid with unordered_set
        unordered_set<int> IndexOfStringAlreadyGrouped = {};

        // check each string against all other strings when they are sorted
        for(int i = 0; i < TotalStrs; ++i)
        {
            // If the string has already been grouped, skip.
            if(IndexOfStringAlreadyGrouped.contains(i))
            {
                continue;
            }

            const string& sortedStr = sortedStrs[i];
            vector<string> anagrams = {};
            
            for(int j = i+1; j < TotalStrs; ++j)
            {
                // If the string has already been grouped, skip.
                if(IndexOfStringAlreadyGrouped.contains(j))
                {
                    continue;
                }

                const string& sortedStrToCompare = sortedStrs[j];
                if(sortedStr == sortedStrToCompare)
                {
                    // if the first string has not been grouped insert it.
                    if(anagrams.size() == 0)
                    {
                        anagrams.push_back(strs[i]);
                        IndexOfStringAlreadyGrouped.insert(i);
                    }
                    anagrams.push_back(strs[j]);
                    IndexOfStringAlreadyGrouped.insert(j);
                }
            }


            // if the anagrams list is empty, insert the str with no anagrams into the list.
            if(anagrams.empty())
            {
                anagrams.push_back(strs[i]);
            }

            // insert the anagrams grouped together into the list of anagram lists.
            groupedAnagrams.push_back(anagrams);
        }

        return groupedAnagrams;
    }
};
