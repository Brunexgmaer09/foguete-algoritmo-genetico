#include "GeneticAlgorithm.h"

GeneticAlgorithm::GeneticAlgorithm(int populationSize, SDL_Renderer* rend)
    : populationSize(populationSize), renderer(rend) {
    // Inicializa��o de vari�veis
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
        // Exemplo de c�lculo de fitness. Voc� precisar� substituir isso pela sua pr�pria l�gica.
        float fitness = 0.0f; // Inicializa o fitness com um valor padr�o

        // Calcule o fitness aqui. Exemplo: dist�ncia at� um objetivo.
        fitness = 100;

        rocket.setFitness(fitness); // Defina o fitness para o foguete
    }
}



void GeneticAlgorithm::performSelection() {
    // Implementa��o da sele��o
}

void GeneticAlgorithm::performCrossover() {
    std::vector<Rocket> newPopulation;
    // Implementa��o do crossover
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
