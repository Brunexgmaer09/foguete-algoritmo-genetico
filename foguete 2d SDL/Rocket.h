#pragma once
#ifndef ROCKET_H
#define ROCKET_H

#include <SDL.h>
#include <cmath>
#include "DNA.h"

class Rocket {
public:
    Rocket(SDL_Renderer* renderer, const DNA& dna);
    void setFitness(float fitness);
    void mutateDNA();
    ~Rocket();
    void update(const Uint8* keystates);
    void render();
    void renderBackground();

private:
    DNA dna;
    float fitness;
    float posX, posY;
    float angle;
    float velX, velY;
    float aceleracao;
    float gravidade;
    bool acelerando;
    float targetX, targetY;
    int shipWidth, shipHeight;
    int collectionWidth, collectionHeight;


    SDL_Texture* texture;
    SDL_Texture* textureAccelerating;
    SDL_Texture* backgroundTexture;
    SDL_Texture* collectionTexture;
    SDL_Texture* shipTexture;

    SDL_Renderer* renderer;

    void loadTextures();
    void freeTextures();
};

#endif