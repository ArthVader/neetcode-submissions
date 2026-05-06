public class Solution {

    private bool IsOpenBracket(char c)
    {
        return c == '[' || c == '(' || c == '{';
    }

    public bool IsValid(string s) {
        
        // check if it is even amount of characters
        if(s.Length % 2 != 0)
        {
            return false;
        }

        Stack<char> stackOfChars = new Stack<char>();

        for(int i = 0; i < s.Length; ++i)
        {
            if(IsOpenBracket(s[i]))
            {
                stackOfChars.Push(s[i]);
            }
            else if (!IsOpenBracket(s[i]) && stackOfChars.Count == 0)
            {
                return false;
            }
            else if(stackOfChars.Count != 0)
            {
                switch (s[i])
                {
                    case ']':
                    {
                        if(stackOfChars.Peek() == '[')
                        {
                            stackOfChars.Pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                    case '}':
                    {
                        if(stackOfChars.Peek() == '{')
                        {
                            stackOfChars.Pop();
                        }
                        else
                        {
                            return false;
                        }
                        break;
                    }
                    case ')':
                    {
                        if(stackOfChars.Peek() == '(')
                        {
                            stackOfChars.Pop();
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

        return stackOfChars.Count == 0;
    }
}
