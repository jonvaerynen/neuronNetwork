#pragma once
#include <vector>

class Perceptron {
private:
	std::vector<float> painot;
	float bias;

public:
	Perceptron(size_t syotteidenMaara);
	float laske(const std::vector<float>& syotteet) const;
	void train(const std::vector<float>& syote, float tavoite, float oppimisnopeus);
	void tulostaParametrit() const;
};