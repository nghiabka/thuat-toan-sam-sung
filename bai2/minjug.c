


int minSteps(int m, int n, int d) 
{ 
    // To make sure that m is smaller than n 
    if (m > n) 
        swap(m, n); 
  
    // For d > n we cant measure the water 
    // using the jugs 
    if (d > n) 
        return -1; 
  
    // If gcd of n and m does not divide d 
    // then solution is not possible 
    if ((d % gcd(n,m)) != 0) 
        return -1; 
  
    // Return minimum two cases: 
    // a) Water of n litre jug is poured into 
    //    m litre jug 
    // b) Vice versa of "a" 
    return min(pour(n,m,d),   // n to m 
               pour(m,n,d));  // m to n 
}

// Driver code to test above 
int main() 
{ 
    int n = 3, m = 5, d = 4; 
  
    printf("Minimum number of steps required is %d", 
           minSteps(m, n, d)); 
  
    return 0; 
} 