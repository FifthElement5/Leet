#include <iostream>
#include <vector>

// Definiowanie klasy Solution, która zawiera metodę twoSum
class Solution {
public:
    // Metoda twoSum, która przyjmuje wektor liczb całkowitych (nums) i liczbę całkowitą (target)
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Zmienna przechowująca rozmiar wektora nums
        int sizeNums = nums.size();

        // Pętla iterująca przez elementy wektora nums
        for (int i = 0; i < sizeNums; i++) {
            // Wewnętrzna pętla iterująca przez kolejne elementy wektora nums zaczynając od i+1
            for (int j = i + 1; j < sizeNums; j++) {
                // Pobieranie wartości pierwszego elementu
                int first = nums[i];
                // Pobieranie wartości drugiego elementu
                int second = nums[j];

                // Sprawdzanie, czy suma pierwszego i drugiego elementu jest równa target
                if ((first + second) == target) {
                    // Jeśli warunek jest spełniony, wyświetlenie indeksów i, j oraz zwrócenie ich w formie wektora
                    std::cout << "Wynik to: " << i << ", " << j << std::endl;
                    return {i, j};
                }
            }
        }

        // Jeśli żadne dwa elementy nie sumują się do target, wyświetlenie informacji o braku wyniku i zwrócenie pustego wektora
        std::cout << "No target found.\n";
        return {};
    }
};

// Funkcja main, która uruchamia program
int main() {
    // Tworzenie obiektu klasy Solution
    Solution s1;
    // Definiowanie wektora liczb całkowitych do przeszukania
    std::vector<int> nums = {2, 11, 7, 15};
    // Definiowanie wartości docelowej
    int target = 9;
    // Wywołanie metody twoSum na obiekcie s1 z wektorem nums i wartością target jako argumenty
    s1.twoSum(nums, target);

    // Zwracanie wartości 0, aby wskazać, że program zakończył się pomyślnie
    return 0;
}
