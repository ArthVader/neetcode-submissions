
public class Solution {
    public bool IsAnagram(string s, string t) {

        int TotalCharsInS = s.Length;
        int TotalCharsInT = t.Length;
        if(TotalCharsInS != TotalCharsInT)
        {
            return false;
        }

        Dictionary<char, int> CharacterLookup = new Dictionary<char, int>();

        foreach(var character in s)
        {
            if(CharacterLookup.ContainsKey(character))
            {
                CharacterLookup[character] = CharacterLookup[character] + 1;
            }
            else
            {
                CharacterLookup[character] = 1;
            }
        }

        foreach(var character in t)
        {
            if(CharacterLookup.ContainsKey(character))
            {
                CharacterLookup[character] = CharacterLookup[character] - 1;
            }
            else
            {
                return false;
            }
        }

        foreach(var value in CharacterLookup.Values)
        {
            if(value != 0)
            {
                return false;
            }
        }

        return true;

    }
}
