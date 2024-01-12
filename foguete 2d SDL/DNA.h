// DNA.h
#pragma once
#include <vector>
#include <random>

class DNA {
public:
    DNA(int size);
    void randomize();
    DNA crossover(const DNA& partner) const;
    void mutate(float mutationRate);

private:
    std::vector<std::pair<float, float>> genes; // Pares de aceleração e rotação
};