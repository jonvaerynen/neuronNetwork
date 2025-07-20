#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include "perceptron.h"

/*
Perceptron::Perceptron(size_t syotteidenMaara) {
	
	bias = 0.5f;

	painot = std::vector<float>(syotteidenMaara, 1.0f);

	std::cout << "Perceptron luotu. Syotteita: " << syotteidenMaara << '\n';

}
*/
float Perceptron::laske(const std::vector<float>& syotteet) const {

	if (syotteet.size() != painot.size()) {
		throw std::runtime_error("Syotteiden ja painojen maara ei tasmaa");
	}

	float summa = bias;
	for (size_t i = 0; i < syotteet.size(); i++) {
		summa += syotteet[i] * painot[i];
	}

	// Sigmoid
	float tulos = 1.0f / (1.0f + std::exp(-summa));
	return tulos;

}
Perceptron::Perceptron(size_t syotteidenMaara) {
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
	
	// arvotaan bias satunnaisesti
	bias = dist(gen);

	// Alustetaan painot satunnaisilla arvoilla
	painot.resize(syotteidenMaara);
	for (float& w : painot) {
		w = dist(gen);
	}

	std::cout << "Perceptron luotu satunnaisilla arvoilla.\n";
}

void Perceptron::train(const std::vector<float>& syote, float tavoite, float oppimisnopeus) {

	float output = laske(syote);
	float virhe = tavoite - output;

	// päivitetään painot
	for (size_t i = 0; i < painot.size(); ++i) {
		painot[i] += oppimisnopeus * virhe * syote[i];
	}
	// päivitetään bias
	bias += oppimisnopeus * virhe;

}

void Perceptron::tulostaParametrit() const {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Bias: " << bias << "\n";
	std::cout << "Painot: ";
	for (float w : painot) 7,
		std::cout << w << " ";
	std::cout << "\n";
}