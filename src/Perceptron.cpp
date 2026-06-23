#include "../include/Perceptron.h"
#include <iostream>
#include <random>

Perceptron::Perceptron(int num_inputs, double lr) : learning_rate(lr) {
    // 1. Set up random number engine using a random device seed
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // 2. Define a normal distribution (mean = 0.0, std_dev = 1.0)
    std::normal_distribution<double> dist(0.0, 1.0);

    // 3. Populate the weights vector with random values
    for (int i = 0; i < num_inputs; ++i) {
        weights.push_back(dist(gen));
    }

    // 4. Initialize bias randomly
    bias = dist(gen);

    std::cout << "Perceptron initialized with " << num_inputs << " random weights.\n";
}

void Perceptron::printWeights() const {
    std::cout << "Weights: [ ";
    for (double w : weights) {
        std::cout << w << " ";
    }
    std::cout << "] | Bias: " << bias << "\n";
}
int Perceptron::predict(const std::vector<double>& inputs) const {

    double linear_output = std::inner_product(inputs.begin(), inputs.end(), weights.begin(), bias);
    
    return (linear_output >= 0.0) ? 1 : 0;
}

void Perceptron::fit(const std::vector<std::vector<double>>& X, const std::vector<int>& y, int epochs) {
    for (int epoch = 1; epoch <= epochs; ++epoch) {
        int total_errors = 0;

        for (size_t i = 0; i < X.size(); ++i) {
            int prediction = predict(X[i]);
            int error = y[i] - prediction; // Target - Predicted

            if (error != 0) {
                total_errors++;
                // Update weights: w = w + lr * error * x
                for (size_t j = 0; j < weights.size(); ++j) {
                    weights[j] += learning_rate * error * X[i][j];
                }
                
                bias += learning_rate * error;
            }
        }

        std::cout << "Epoch " << epoch << "/" << epochs << " - Errors: " << total_errors << "\n";
        
        
        if (total_errors == 0) {
            std::cout << "Converged early at epoch " << epoch << "!\n";
            break;
        }
    }
}
