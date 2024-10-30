#include "Header.h"
#include <iostream>
#include <chrono>

int main() {
    setlocale(LC_ALL, "Russian");
    for (int numCities = 4; numCities <= 12; ++numCities) {
        TSP tsp(numCities, 0);
        tsp.generateRandomCosts();

        std::cout << "Количество городов: " << numCities << std::endl;
        tsp.printCostMatrix();

        auto start = std::chrono::high_resolution_clock::now();
        int minCost = tsp.solve();
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Минимальная стоимость маршрута: " << minCost << std::endl;
        std::cout << "Время выполнения: " << elapsed.count() << " секунд\n\n";

        if (elapsed.count() > 10.0) {
            std::cout << "Время выполнения слишком велико для " << numCities << " городов. Остановка эксперимента." << std::endl;
            break;
        }
    }

    return 0;
}
