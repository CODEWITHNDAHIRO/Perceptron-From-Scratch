#include "../include/Perceptron.h"
#include <iostream>

int main() {
    std::cout << "--- Initializing Perceptron (3 Inputs) ---\n";
    
    // Create a perceptron that expects 3 input features
    Perceptron p(3, 0.01);

    // Inspect the random starting parameters
    p.printWeights();

    return 0;
}