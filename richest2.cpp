#include <iostream>
#include <vector>
#include <algorithm> // Potrzebne do użycia std::max

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int maxWealthSoFar = 0; // Zmienna przechowująca maksymalne bogactwo

        // Iteracja po każdym kliencie (każdy klient to wektor środków w bankach)
        for (const std::vector<int>& customer : accounts) {
            int currentCustomerWealth = 0; // Zmienna przechowująca bogactwo obecnego klienta

            // Iteracja po każdym banku dla bieżącego klienta i sumowanie środków
            for (int bank : customer) {
                currentCustomerWealth += bank;
            }

            // Aktualizacja maksymalnego bogactwa, jeśli bogactwo bieżącego klienta jest większe
            maxWealthSoFar = std::max(maxWealthSoFar, currentCustomerWealth);
        }

        return maxWealthSoFar; // Zwrócenie maksymalnego bogactwa
    }
};

int main() {
    // Inicjalizacja przykładowych danych
    std::vector<std::vector<int>> accounts = {
        {7, 1, 3},
        {2, 8, 7},
        {1, 9, 5}
    };

    // Utworzenie obiektu klasy Solution
    Solution solution;
    // Wywołanie metody maximumWealth i zapisanie wyniku
    int maxWealth = solution.maximumWealth(accounts);

    // Wyświetlenie wyniku
    std::cout << "Maksymalne bogactwo: " << maxWealth << std::endl;

    return 0;
}
