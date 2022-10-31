class Solution 
{
    public boolean isValid(String s) 
    {
        Stack<Character> stack = new Stack<>();
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            char ch = s.charAt(i);
            if(ch == '(' || ch =='{' || ch == '[')
                stack.push(ch);
            else
            {
                if(ch == ')')
                {
                    if(!stack.isEmpty() && stack.peek() == '(')
                        stack.pop();
                    else
                        stack.push(ch);
                }
                else if(ch == '}')
                {
                    if(!stack.isEmpty() && stack.peek() == '{')
                        stack.pop();
                    else
                        stack.push(ch);
                }
                else
                {
                    if(!stack.isEmpty() && stack.peek() == '[')
                        stack.pop();
                    else
                        stack.push(ch);
                }
            }
        }
        return stack.isEmpty();
    }
}
