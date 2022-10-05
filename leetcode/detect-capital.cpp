/*
    name= detect capital
    link- https://leetcode.com/problems/detect-capital/ 
    author- Parth garg
    time complexity- o(n) n= string length
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool detectCapitalUse(string word) { 
        bool first;
        if(word[0]-'a'>=0) first= false;
        else first= true;
        cout<<first<<endl;
        if(first)
        {
            bool t1= true,t2= true;
            for(int i=1;i<word.length();i++)
            {
                if(word[i]-'a' < 0) 
                {t1= false;
                 break;}
            }
            for(int i=1;i<word.length();i++)
            {
                if('Z'- word[i]< 0)  
                {t2= false;
                 break;}
            }
            if(t1 || t2) return true;
        }
        else
        {
            bool t3= true;
            for(int i=1;i<word.length();i++)
            {
                if(word[i]-'a' <  0)  
                {t3= false;
                 break;}
            }
            if(t3) return true;
        }
        return false;
    }
};