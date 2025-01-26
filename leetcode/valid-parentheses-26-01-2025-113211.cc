// https://leetcode.com/problems/valid-parentheses/

#include <stack>
#include <string>

class Solution
{
public:
  bool isValid(std::string s)
  {
    std::stack<char> charStack;

    for (char &c : s)
    {
      // Check for opening
      if (c == '(' || c == '{' || c == '[')
      {
        charStack.push(c);
        continue;
      }
      else
      {
        // Closing but stack is empty
        if (charStack.empty())
        {
          return false;
        }
        // Closing
        switch (c)
        {
        case ')':
          if (!(charStack.top() == '('))
          {
            return false;
          }
          charStack.pop();
          break;
        case '}':
          if (!(charStack.top() == '{'))
          {
            return false;
          }
          charStack.pop();
          break;
        case ']':
          if (!(charStack.top() == '['))
          {
            return false;
          }
          charStack.pop();
          break;
        default:
          continue;
        }
      }
    }

    return charStack.empty();
  }
};