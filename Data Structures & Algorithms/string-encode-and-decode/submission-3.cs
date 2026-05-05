public class Solution {

    public string Encode(IList<string> strs) {
        string encodedString = string.Empty;
        foreach(string str in strs)
        {
            encodedString += $"{str.Length}#{str}";
        }

        Console.WriteLine(encodedString);
        return encodedString;
    }

    public List<string> Decode(string s) {
        List<string> decodedStringList = new List<string>();

        string numberOfCharactersAsString = string.Empty;
        int totalCharacters = s.Length;
        for(int currentIndex = 0; currentIndex < totalCharacters; ++currentIndex)
        {
            char character = s[currentIndex];
            if(character >= '0' && character <= '9')
            {
                numberOfCharactersAsString += character;
                continue;
            }

            int numberOfCharacters = Convert.ToInt32(numberOfCharactersAsString);

            if(character == '#')
            {
                if(numberOfCharacters == 0)
                {
                   decodedStringList.Add("");
                }
                else
                {
                    decodedStringList.Add(s.Substring(currentIndex+1, numberOfCharacters));
                    currentIndex += numberOfCharacters;
                }

                numberOfCharactersAsString = string.Empty;
            }
        }

        return decodedStringList;
   }
}
