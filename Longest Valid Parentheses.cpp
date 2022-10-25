class Solution {
public:
int longestValidParentheses(string s) {
	stack<int> opens;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') opens.push(i);
		else if(opens.size()) {
			s[opens.top()] = s[i] = '*';
			opens.pop();
		}
	}

	int curr = 0, res = 0;
	for(int i = 0; i <= s.size(); i++) {
		if(s[i] == '*') curr++;
		else {
			res = max(res, curr);
			curr = 0;
		}
	}

	return max(curr, res);
  }
};
