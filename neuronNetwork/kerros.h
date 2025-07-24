#pragma once
#include <vector>
#include "perceptron.h"

class Kerros {
private: 
	std::vector<Perceptron> neuronit;

public:
	std::vector<Perceptron>& getNeuronit();
	Kerros(size_t syotteidenMaara, size_t neuronienMaara);
	std::vector<float> laske(const std::vector<float>& syotteet) const;
	void train(const std::vector<float>& syote, float tavoite, float oppimisnopeus);
	void tulostaParametrit() const;
};