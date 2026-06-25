
#include "../include/Perceptron.h"
#include <iostream>
#include <vector>

int main() {
    // 1. Create an AND gate dataset
    
    std::vector<std::vector<double>> X = {
        {0.0, 0.0},
        {0.0, 1.0},
        {1.0, 0.0},
        {1.0, 1.0}
    };

    // Expected Outputs (y) for an AND gate
    std::vector<int> y = {0, 0, 0, 1};

    std::cout << "=== Initializing Perceptron for AND Gate ===\n";
    Perceptron agent(2, 0.1); // 2 inputs, learning rate = 0.1

    std::cout << "\n--- Initial Weights before training ---\n";
    agent.printWeights();

    std::cout << "\n--- Starting Training Loop ---\n";
    agent.fit(X, y, 20); // Train for up to 20 epochs

    std::cout << "\n--- Final Weights after training ---\n";
    agent.printWeights();

    // 4. Verify predictions
    std::cout << "\n--- Verifying Predictions ---\n";
    for (size_t i = 0; i < X.size(); ++i) {
        int pred = agent.predict(X[i]);
        std::cout << "Input: [" << X[i][0] << ", " << X[i][1] 
                  << "] -> Predicted: " << pred 
                  << " (Expected: " << y[i] << ")\n";
    }

    return 0;
}