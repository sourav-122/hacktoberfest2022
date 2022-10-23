
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int item)
{

    if (s.empty())
    {
        s.push(item);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, item);
    s.push(top);
}
 

void reverseStack(stack<int> &s)
{
    // base case: stack is empty
    if (s.empty()) {
        return;
    }
    int item = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, item);
}
 
int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }
 
    reverseStack(s);
 
    cout << "Reversed stack is ";
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
 
    return 0;
}
