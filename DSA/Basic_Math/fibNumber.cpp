class Solution {
public:
    int fib(int n) {
        int n1=0;
        int n2=1;
        for(int i=1;i<=n;i++){
            int nth=n1+n2;
            n1=n2;
            n2=nth;
        }

        return n1;
    }
};