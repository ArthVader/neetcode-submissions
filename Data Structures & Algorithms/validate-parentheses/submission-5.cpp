class Solution {
public:

    inline bool isOpeningBracket(const char& c)
    {
        if (c == '[' || c == '(' || c== '{')
        {
            return true;
        }
        
        return false;
    }

    bool isValid(string s) {
        
        // check if it is even amount of characters
        if(s.size() % 2 != 0)
        {
            return false;
        }

        stack<char> stackOfOpenBrackets = {};
        int totalChars = s.size();

        for(int i = 0; i < totalChars; ++i)
        {
            if(isOpeningBracket(s[i]))
            {
                stackOfOpenBrackets.push(s[i]);
            }
            else if(!isOpeningBracket(s[i]) && stackOfOpenBrackets.size() == 0)
            {
                return false;
            }
            else if(stackOfOpenBrackets.size() != 0)
            {
                switch (s[i])
                {
                    case ']':
                    {
                        if(stackOfOpenBrackets.top() == '[')
                        {
                            stackOfOpenBrackets.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                    case '}':
                    {
                        if(stackOfOpenBrackets.top() == '{')
                        {
                            stackOfOpenBrackets.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                    case ')':
                    {
                        if(stackOfOpenBrackets.top() == '(')
                        {
                            stackOfOpenBrackets.pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }

        if(stackOfOpenBrackets.size() != 0)
        {
            return false;
        }

        return true;
    }
};
