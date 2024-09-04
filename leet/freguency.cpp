#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        // Tworzenie mapy do liczenia wystąpień każdej liczby
        std::map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // Przeniesienie zawartości mapy do wektora par (liczba, liczba wystąpień)
        std::vector<std::pair<int, int>> countV(countMap.begin(), countMap.end());

        // Sortowanie wektora par według liczby wystąpień (rosnąco)
        std::sort(countV.begin(), countV.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              if (a.second == b.second) {
                return a.first > b.first; // Jeśli liczby wystąpień są równe, sortuj malejąco według wartości liczby
            }
            return a.second < b.second;  // Sortowanie rosnąco według liczby wystąpień
        });

        // Tworzenie nowego wektora, który będzie zawierał liczby posortowane według częstotliwości
        std::vector<int> sorted;
        for (const auto& pair : countV) {
            for (int i = 0; i < pair.second; ++i) {
                sorted.push_back(pair.first);  // Dodawanie liczby odpowiednią liczbę razy
            }
        }

        // Zwracanie posortowanego wektora
        return sorted;
    }
};

int main()
{
    // Przykładowy wektor wejściowy
    std::vector<int> nums = {-1,1,-6,4,5,-6,1,4,1};

    // Tworzenie obiektu klasy Solution i wywołanie funkcji frequencySort
    Solution s1;
    std::vector<int> result = s1.frequencySort(nums);

    // Wypisywanie wynikowego posortowanego wektora
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
