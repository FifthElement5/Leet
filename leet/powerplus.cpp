#include <iostream>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Zwróć false dla n <= 0

        while (n % 2 == 0) { // Dziel przez 2, aż nie będzie to możliwe
            n /= 2;
        }

        if (n == 1) {
            std::cout << "Jest potęgą 2" << std::endl;
            return true;
        } else {
            std::cout << "Nie jest potęgą 2" << std::endl;
            return false;
        }
    }
};

int main() {
    Solution checker;
    int n = 4;
    checker.isPowerOfTwo(n);
    return 0;
}
