    #include <iostream>
    #include <fstream>
    #include <bits/stdc++.h> 
    #include <utility> 
 
 
    using namespace std;
 
    int l1, l2;
    // int const MAX=5000;
    // char N[MAX];
    // char M[MAX];
    int detal[6][6];
    string a;
    string b;
 
    char X[] = {' ','_', 'A', 'C', 'G', 'T'};
 
    int get_id(char x){
        for (int i = 1; i <= 5; i++)
        {
            if (x == X[i])
            {
                return i;
            }
            
        }  
    }
 
    // function to find out the minimum penalty 
    int getMinimumPenalty(string x, string y, int pxy, int pgap) 
    { 
        int i, j; // intialising variables 
        
        int m = x.length(); // length of gene1 
        int n = y.length(); // length of gene2 
        
        // table for storing optimal substructure answers 
        int dp[n+m+1][n+m+1] = {0}; 
    
        // intialising the table  
        for (i = 0; i <= (n+m); i++) 
        { 
            dp[i][0] = i * pgap; 
            dp[0][i] = i * pgap; 
        }     
    
        // calcuting the minimum penalty 
        for (i = 1; i <= m; i++) 
        { 
            for (j = 1; j <= n; j++) 
            { 
                if (x[i - 1] == y[j - 1]) 
                { 
                    dp[i][j] = dp[i - 1][j - 1]; 
                } 
                else
                { 
                    dp[i][j] = min({dp[i - 1][j - 1] + pxy ,  
                                    dp[i - 1][j] + pgap    ,  
                                    dp[i][j - 1] + pgap    }); 
                } 
            } 
        } 
    
        // Reconstructing the solution 
        int l = n + m; // maximum possible length 
        
        i = m; j = n; 
        
        int xpos = l; 
        int ypos = l; 
    
        // Final answers for the respective strings 
        int xans[l+1], yans[l+1]; 
        
        while ( !(i == 0 || j == 0)) 
        { 
            if (x[i - 1] == y[j - 1]) 
            { 
                xans[xpos--] = (int)x[i - 1]; 
                yans[ypos--] = (int)y[j - 1]; 
                i--; j--; 
            } 
            else if (dp[i - 1][j - 1] + pxy == dp[i][j]) 
            { 
                xans[xpos--] = (int)x[i - 1]; 
                yans[ypos--] = (int)y[j - 1]; 
                i--; j--; 
            } 
            else if (dp[i - 1][j] + pgap == dp[i][j]) 
            { 
                xans[xpos--] = (int)x[i - 1]; 
                yans[ypos--] = (int)'_'; 
                i--; 
            } 
            else if (dp[i][j - 1] + pgap == dp[i][j]) 
            { 
                xans[xpos--] = (int)'_'; 
                yans[ypos--] = (int)y[j - 1]; 
                j--; 
            } 
        } 
        while (xpos > 0) 
        { 
            if (i > 0) xans[xpos--] = (int)x[--i]; 
            else xans[xpos--] = (int)'_'; 
        } 
        while (ypos > 0) 
        { 
            if (j > 0) yans[ypos--] = (int)y[--j]; 
            else yans[ypos--] = (int)'_'; 
        } 
    
        // Since we have assumed the answer to be n+m long,  
        // we need to remove the extra gaps in the starting  
        // id represents the index from which the arrays 
        // xans, yans are useful 
 
        int id = 1; 
        for (i = l; i >= 1; i--) 
        { 
            if ((char)yans[i] == '_' && (char)xans[i] == '_') 
            { 
                id = i + 1; 
                break; 
            } 
        } 
    
        // Printing the final answer 
        int max =0;
        for (i = id; i <= l; i++) 
        { 
            int id1= get_id(char(xans[i]));
            int id2 = get_id(char(yans[i]));
            max += detal[id1][id2];
        } 
    
        return max; 
    } 
 
 
    int main(int argc, char const *argv[])
    {
        cin >>l1;
        cin >>l2;
        for (int i = 0; i < l1; i++)
        {
            char tmp;
            cin >> tmp;
            a+=tmp;
        }
        for (int i = 0; i < l2; i++)
        {
            char tmp;
            cin >> tmp;
            b+=tmp;
        }
 
        for (int  i = 1; i <= 5; i++)
        {
            for (int j = 1; j < 6; j++)
            {
                // fi >> detal[i][j];
                cin >> detal[i][j];
            }        
        }
        // 99
        cout << endl;
        int misMatchPenalty = 7; 
        int gapPenalty = min(l1, l2); 
        if (l1 >l2)
        {
            int result = getMinimumPenalty(a, b,  
            misMatchPenalty, gapPenalty); 
            cout << result << endl;
        }
        else
        {
            int result = getMinimumPenalty(b, a,  
            misMatchPenalty, gapPenalty);
            cout << result << endl;
        }
        
        return 0;
    }