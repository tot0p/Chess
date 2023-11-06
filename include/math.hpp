#pragma once

#include <iostream>

using namespace std;

struct Vector2f // Structure pour les vecteurs 2D
{
    Vector2f() : x(0.0), y(0.0) {} // Constructeur par défaut

    Vector2f(float p_x, float p_y) : x(p_x), y(p_y) {}

    void print() { cout << "x: " << x << ", y: " << y << endl; }

    float x;
    float y;
};
