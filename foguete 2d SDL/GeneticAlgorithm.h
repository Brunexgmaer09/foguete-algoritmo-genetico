#pragma once
#include "Rocket.h"
#include <vector>

class GeneticAlgorithm {
public:
    GeneticAlgorithm(int populationSize, SDL_Renderer* renderer);
    void initializePopulation();
    void evaluateFitness();
    void performSelection();
    void performCrossover();
    void performMutation();
    std::vector<Rocket>& getPopulation();

private:
    std::vector<Rocket> population;
    int populationSize;
    SDL_Renderer* renderer;
    // Outras variáveis para armazenar informações sobre fitness, seleção, etc.
};
