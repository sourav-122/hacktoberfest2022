// Problem Statement
//  A message containing letters from A-Z can be encoded 
//  into numbers using the following mapping:
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits 
// must be grouped then mapped back into letters using the 
// reverse of the mapping above (there may be multiple ways). 
// For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" 
// cannot be mapped into 'F' since "6" is different from "06".

// In addition to the mapping above, an encoded message may contain the '*' character, which can represent any digit from '1' to '9' ('0' is excluded). For example, the encoded message "1*" may represent any of the encoded messages "11", "12", "13", "14", "15", "16", "17", "18", or "19". Decoding "1*" is equivalent to decoding any of the encoded messages it can represent.

// Given a string s consisting of digits and '*' characters, 
// return the number of ways to decode it.

// Since the answer may be very large, return it modulo 109 + 7.
  int dp[100001];
  const int mod=1e9+7;
  int get(string &s,int i)
    {
        if(s[i]=='0')
        {
            return 0;
        }
        if(i>=s.size())
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=0,x=0;
        if(s[i]=='*')
        {
             int prev=x;
                    
            for(int dig=1;dig<=9;dig++)
            {
                
                if((prev*10)+(dig)<=26)
                {
                   int y=prev*10+(dig);
                    x=y;
                    ans+=get(s,i+1);
                    ans%=mod;
                    if(i+1<s.size()&&(s[i+1]=='*'))
                    {
                        for(int dig2=1;dig2<=9;dig2++)
                        {
                            if(y*10+(dig2)<=26)
                            {
                                ans+=get(s,i+2);
                                ans%=mod;
                            }
                        }
                    }
                    else if(i+1<s.size()&&(s[i+1]!='*'))
                    {
                        if(y*10+(s[i+1]-'0')<=26)
                        {
                            ans+=get(s,i+2);
                            ans%=mod;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            
        }
        else
        {
            if((x*10+(s[i]-'0'))<=26)
            {
                x=x*10+(s[i]-'0');
                ans+=get(s,i+1);
                if(i+1<s.size()&&(s[i+1]=='*'))
                {
                    for(int dig=1;dig<=9;dig++)
                    {
                        if(x*10+(dig)<=26)
                        {
                            ans+=get(s,i+2);
                            ans%=mod;
                        }
                    }
                }
                else if(i+1<s.size()&&(s[i+1]!='*'))
                {
                    if(x*10+(s[i+1]-'0')<=26)
                    {
                        ans+=get(s,i+2);
                        ans%=mod;
                    }
                }
                
            }
        }
        
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof(dp));
        return get(s,0);
    }
