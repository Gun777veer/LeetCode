class Solution {
public:
    const int MOD = 1e9 + 7;

    // Function to compute (base^exp) % MOD using binary exponentiation
    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        long long goodEven = modPow(5, evenPos);
        long long goodOdd = modPow(4, oddPos);
        return (goodEven * goodOdd) % MOD;
    }
};
