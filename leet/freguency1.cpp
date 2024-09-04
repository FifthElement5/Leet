#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> myVector = {1, 2, 3, 2, 4, 2, 5, 1, 3, 4, 5, 5};

    std::map<int, int> countMap;
    for (int num : myVector) {
        countMap[num]++;
    }

    for (const auto& pair : countMap) {
        std::cout << "Liczba " << pair.first << " występuje " << pair.second << " razy." << std::endl;
        std::sort(pair.second.begin(), pair.second.end());
    }

    return 0;
}
