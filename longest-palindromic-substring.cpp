class Solution {
public:
    string lp(string s) {
        int n=s.size();
        
        bool table[n][n];
        
        int max1=1;
        int start=0;
        
        memset(table, 0, sizeof(table));
        
        for(int i=0;i<n;i++)
        {
            table[i][i]=true;
            
            if(i<n-1 && s[i] == s[i+1])
            {
                table[i][i+1]=true;
                max1=2;
                start=i;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;

                if( table[i+1][j-1] == true && s[i] == s[j] )
                {
                    table[i][j]=true;
                    
                    if(k>max1)
                    {
                        max1=k;
                        start=i;
                    }
                }
                
            }
            
        }
        
        cout << start << max1;
        return s.substr(start, max1);
        
        
    }
    string longestPalindrome(string s) {
        return lp(s);
            int max1=1;
    int left=0;
    int right=0;
    for(int i=0;i<s.size();i++){
    
        for(int cas=0;cas<=1;cas++)
        {
            int start1=i-cas;
            int start2=i+1;
            while(start1 >= 0 && start2 < s.size() && s[start1]== s[start2])
            {
                if( (start2 - start1 + 1) > max1)
                {
                    max1=start2-start1+1;
                    left=start1;
                    right=start2;
                }
                --start1;
                ++start2;
            }
            
        }
        
    }
        
    return s.substr(left, right-left+1);
    }
};
