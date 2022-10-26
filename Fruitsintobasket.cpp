// Question:-You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.
//Code:-
int totalFruit(vector<int>& fruits) {
        // unordered_map stores no. of types of fruits in the current window
        // here key is the type of the fruit 
        // and value is the number of fruits of 'key' type in the current window
        unordered_map<int,int>m;
        
        // 'i' is the left and 'j' is the right pointer of thw window
        // 'ans' will be the answer
        int i=0,j=0,ans=0;
        while(j<fruits.size())
        {
            m[fruits[j]]++;
            // as long as there are more than 2 types of fruit, shrink the window
            while(m.size()>2)
            {
                if(m[fruits[i]]==1)
                {
                    m.erase(fruits[i]);
                }
                else
                {
                    m[fruits[i]]--;
                }
                i++;
            }
            
            // take the max of already encountered window and current window
            ans=max(ans,j-i+1);
            
            // move the right pointer
            j++;
        }
        
        // finally return the answer
        return ans;
    }
