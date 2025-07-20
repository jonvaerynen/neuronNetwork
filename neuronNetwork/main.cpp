#include <iostream>
#include "perceptron.h"
#include "kerros.h"

void neuron();

int main() {
	Kerros kerros(3, 4);

	kerros.tulostaParametrit();

	std::vector<float> syotteet = { 1.0f, 0.5f, 0.2f };
	std::vector<float> tulokset = kerros.laske(syotteet);

	std::cout << "Kerroksen tulokset:\n";
	for (size_t i = 0; i < tulokset.size(); ++i) {
		std::cout << "Neuroni " << i << ": " << tulokset[i] << "\n";
	}

	return 0;
}