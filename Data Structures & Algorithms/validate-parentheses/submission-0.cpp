class Solution {
public:
    bool isValid(string s) {
        stack<char> brac;
        for(char c : s){
            if(c=='{' || c=='(' || c=='[')
            {
                brac.push(c);
            }
            else if(c=='}' || c==']' || c==')'){
                if(!brac.empty())
                {
                    char k=brac.top();

                    if(c=='}' && k=='{')
                    {
                        brac.pop();
                    }
                     else if(c==']' && k=='[')
                    {
                        brac.pop();
                    }
                     else if(c==')' && k=='(')
                    {
                        brac.pop();
                    }
                    else
                    {
                        break;
                    }

                }
                else
                {
                    return false;
                }

                


            }
        }
        if(brac.empty())
        {
            return true;
        }
        return false;
    }
};
