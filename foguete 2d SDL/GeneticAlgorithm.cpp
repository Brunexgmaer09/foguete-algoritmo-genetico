#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, SDL_Renderer* rend)
    : populationSize(populationSize), renderer(rend) {
    // Inicialização de variáveis
}

void GeneticAlgorithm::initializePopulation() {
    for (int i = 0; i < populationSize; ++i) {
        DNA dna(100);
        Rocket rocket(renderer, dna); // Use o renderer aqui
        population.push_back(rocket);
    }
}

void GeneticAlgorithm::evaluateFitness() {
    for (auto& rocket : population) {
        // Exemplo de cálculo de fitness. Você precisará substituir isso pela sua própria lógica.
        float fitness = 0.0f; // Inicializa o fitness com um valor padrão

        // Calcule o fitness aqui. Exemplo: distância até um objetivo.
        fitness = 100;

        rocket.setFitness(fitness); // Defina o fitness para o foguete
    }
}



void GeneticAlgorithm::performSelection() {
    // Implementação da seleção
}

void GeneticAlgorithm::performCrossover() {
    std::vector<Rocket> newPopulation;
    // Implementação do crossover
    population = newPopulation;
}

void GeneticAlgorithm::performMutation() {
    for (auto& rocket : population) {
        rocket.mutateDNA();
    }
}

std::vector<Rocket>& GeneticAlgorithm::getPopulation() {
    return population;
}
