#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        // Tworzymy wektor indeksów
        std::vector<int> index(names.size());
        for (int i = 0; i < index.size(); ++i) {
            index[i] = i;
        }

        // Sortujemy wektor indeksów malejąco według wartości heights
        std::sort(index.begin(), index.end(), [&heights](int a, int b) {
            return heights[a] > heights[b];
        });

        // Tworzymy wektor na posortowane nazwy
        std::vector<std::string> sorted(names.size());
        for (int i = 0; i < index.size(); ++i) {
            sorted[i] = names[index[i]];
        }

        return sorted;
    }
};

int main() {
    // Przykład użycia
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    std::vector<int> heights = {190, 180, 175};

    Solution solution;
    std::vector<std::string> sortedNames = solution.sortPeople(names, heights);

    // Wyświetlamy posortowane nazwy
    for (const auto& name : sortedNames) {
        std::cout << name << std::endl;
    }

    return 0;
}
