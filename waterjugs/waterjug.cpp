    #include <iostream>
    #include <algorithm>


    using namespace std;
    int n;
    int result[10000];


    int min_val(int a, int b){
        return a>b?b:a;
    }


    void swap(int * a, int*b){
        int tmp = *a;
        *a =*b;
        *b = tmp;
    }


    int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
    }

    int pour(int a, int b, int c){
        // khoi tao luong nuoc ban dau cua hai binh
        int from1 = a;
        int to1 = 0;
        int from2 = b;
        int to2 = 0;
        //buoc 1 do day binh from cap
        int step = 1;
        // cout <<"(" <<fromCap <<", 0)" << endl;

        while(from1 !=c && to1 != c){
            // tinh so lit co the do tu from sang tocap
            int tmp1 = min_val(from1, b - to1);

            // do tmp lit tu fromCap sang toCap
            to1 += tmp1;
            from1 -= tmp1;
            step ++;
            // cout <<from <<" " << to << endl;
            if (from1 ==c || to1 == c)
            {
                break;
            }
            // neu binh fromcap rong do day np
            if (from1 == 0)
            {
                from1 = b;
                step++;
            }
            // neu binh toCap day lam rong no
            if(to1 == b){
                to1 =0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int a, int b, int c){
        if (a < b)
        {
            swap(&a, &b); // dam bao a is larger than b
        }
        if(c >a){
            return -1; // khong co loi giai
        }

        // if
        if ((c%__gcd(a,b) != 0))
        {
            return 0;
        }

        int i1 = pour(a, b, c);
        int i2 = pour(b, a, c);
        return min_val(i1, i2);   
    }

    int main(int argc, char const *argv[])
    {
        // cin >> n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            scanf("%d", &a) ;
            scanf("%d", &b) ;
            scanf("%d", &c) ;
            result[i] = minSteps(a, b, c);

        }
        for (int  i = 0; i < n; i++)
        {
            if (i < n-1)
            {
                printf("%d\n", result[i]);

            }else
            {
                printf("%d", result[i]);

            }
            
            
        }
        
        return 0;
    }
