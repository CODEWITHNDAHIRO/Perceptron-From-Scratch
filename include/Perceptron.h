#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>

class Perceptron {
private:
    std::vector<double> weights;
    double bias;
    double learning_rate;

public:
    // Constructor: sets up weights randomly based on the number of inputs
    Perceptron(int num_inputs, double lr = 0.1);

    // Core AI signatures we will implement on Day 6
    int predict(const std::vector<double>& inputs) const;
    void fit(const std::vector<std::vector<double>>& X, const std::vector<int>& y, int epochs);

    // Getters to inspect the model's brain
    void printWeights() const;
};

#endif