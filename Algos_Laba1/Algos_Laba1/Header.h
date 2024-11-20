#pragma once
#ifndef TSP_H
#define TSP_H

#include <vector>
#include <iostream>
#include <limits>

class TSP {
public:
    TSP(int numCities, int startCity);
    void generateRandomCosts();               
    int solve();                              
    void printCostMatrix() const;            

private:
    int numCities;                            
    int startCity;                            
    std::vector<std::vector<int>> costMatrix; 

    int calculateCost(const std::vector<int>& path) const; 
};

#endif 