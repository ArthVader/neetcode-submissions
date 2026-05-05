class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encodedString = "";
        for(const string & str: strs)
        {
            encodedString += to_string(str.size()) + "#" + str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {

        vector<string> decodedStrings = {};

        string numberAsString = "";
        int totalCharacters = s.size();
        for(int currentIndex = 0; currentIndex < totalCharacters; ++currentIndex)
        {
            char character = s[currentIndex];
            
            // grab each character that is a numeric value and build up the number that we will use to decode.
            if(character >= '0' && character <= '9' && character != '#')
            {
                numberAsString += character;
                continue;
            }

            int numCharacters = stoi(numberAsString);

            // pushback decoded empty string, 0# is empty string
            if(numCharacters == 0 && character == '#')
            {
                decodedStrings.push_back("");
                continue;
            }

            // decode the string
            if(character == '#')
            {
                // start at the index after # and grab the numCharacters after it.
                // insert this substring as a decoded string.
                string decodedString = s.substr(currentIndex+1, numCharacters);
                decodedStrings.push_back(decodedString);

                // move the currentIndex up by the amount of characters we grabbed a substr of.
                currentIndex += numCharacters;

                // clear out the number being built up as we read number characters since we have decoded a string.
                numberAsString = "";

                continue;
            }
        }

        return decodedStrings;
    }
};
