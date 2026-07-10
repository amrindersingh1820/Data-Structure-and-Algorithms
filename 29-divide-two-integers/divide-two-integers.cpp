class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = llabs((long long) dividend);
        long long dvs = llabs((long long) divisor);

        long long quotient = 0;

        for(int i = 31; i >= 0; i--){
            if((dvd >> i) >= dvs){
                quotient += (1LL << i);
                dvd -= (dvs << i);
            }
        }
        return negative ? -quotient : quotient;
    }
};
