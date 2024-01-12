// DNA.cpp
#include "DNA.h"

DNA::DNA(int size) : genes(size) {
    randomize();
}

void DNA::randomize() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (auto& gene : genes) {
        gene.first = dis(gen); // Aceleração
        gene.second = dis(gen); // Rotação
    }
}

DNA DNA::crossover(const DNA& partner) const {
    DNA child(genes.size());
    int midpoint = genes.size() / 2; // Pode ser randomizado também

    for (size_t i = 0; i < genes.size(); ++i) {
        if (i > midpoint) child.genes[i] = genes[i];
        else child.genes[i] = partner.genes[i];
    }

    return child;
}

void DNA::mutate(float mutationRate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);

    for (auto& gene : genes) {
        if (dis(gen) < mutationRate) {
            gene.first = dis(gen); // Aceleração
            gene.second = dis(gen); // Rotação
        }
    }
}