#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap; // Mapa do przechowywania wartości i ich indeksów

        for (int i = 0; i < nums.size(); i++) {
            int result = target - nums[i]; // Obliczamy wartość potrzebną do osiągnięcia targetu

            if (numMap.find(result) != numMap.end()) {
                // Jeśli znaleziono uzupełnienie w mapie, zwracamy indeksy
                std::cout << "Wynik to: " << numMap[result] << ", " << i << std::endl;
                return {numMap[result], i};
            }

            // Jeśli nie znaleziono, dodajemy aktualną liczbę i jej indeks do mapy
            numMap[nums[i]] = i;
        }

        std::cout << "No target found.\n";
        return {};
    }
};

int main() {
    Solution s1;
    std::vector<int> nums = {2, 11, 7, 15};
    int target = 9;
    s1.twoSum(nums, target); // Wywołanie funkcji

    return 0;
}
