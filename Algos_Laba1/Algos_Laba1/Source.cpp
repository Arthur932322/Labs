#include "Header.h"
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>


TSP::TSP(int numCities, int startCity) : numCities(numCities), startCity(startCity) {
    costMatrix.resize(numCities, std::vector<int>(numCities, 0));
}


void TSP::generateRandomCosts() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 100);

    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            if (i != j) {
                costMatrix[i][j] = dist(gen);
            }
            else {
                costMatrix[i][j] = 0; 
            }
        }
    }
}


int TSP::calculateCost(const std::vector<int>& path) const {
    int totalCost = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        totalCost += costMatrix[path[i]][path[i + 1]];
    }
    totalCost += costMatrix[path.back()][path[0]]; 
    return totalCost;
}


int TSP::solve() {
    std::vector<int> cities;
    for (int i = 0; i < numCities; ++i) {
        if (i != startCity) {
            cities.push_back(i);
        }
    }

    int minCost = std::numeric_limits<int>::max();

    do {
        std::vector<int> path = { startCity };
        path.insert(path.end(), cities.begin(), cities.end());
        path.push_back(startCity); // Замыкаем путь

        int currentCost = calculateCost(path);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    } while (std::next_permutation(cities.begin(), cities.end()));

    return minCost;
}


void TSP::printCostMatrix() const {
    for (const auto& row : costMatrix) {
        for (int cost : row) {
            std::cout << cost << "\t";
        }
        std::cout << std::endl;
    }
}