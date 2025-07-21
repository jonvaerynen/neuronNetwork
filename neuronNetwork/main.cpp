#include <iostream>
#include "perceptron.h"
#include "kerros.h"
#include <iomanip>
#include <vector>

void neuron();

int main() {
	Perceptron p(2);

	std::vector<std::pair<std::vector<float>, float>> data = {
		{{0.0f, 0.0f}, 0.0f},
		{{0.0f, 1.0f}, 0.0f},
		{{1.0f, 0.0f}, 0.0f},
		{{1.0f, 1.0f}, 1.0f}
	};

	float oppimisnopeus = 0.1f;

	for (int epookki = 0; epookki < 10000; ++epookki) {
		for (const auto& [syote, tavoite] : data) {
			p.train(syote, tavoite, oppimisnopeus);
		}
	}

	// Tulokset koulutuksen jälkeen
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\n=== Tulokset koulutuksen jalkeen===\n";
	for (const auto& [syote, tavoite] : data) {
		float tulos = p.laske(syote);
		std::cout << "Syote: [" << syote[0] << "," << syote[1] << "]"
			<< "  Ennuste: " << tulos
			<< " (Tavoite: " << tavoite << ")\n";
	}

	std::cout << "\nPainot ja bias koulutuksen jalkeen:\n";
	p.tulostaParametrit();

	return 0;
}

/*	Kerros kerros(3, 4);

	kerros.tulostaParametrit();

	std::vector<float> syotteet = { 1.0f, 0.5f, 0.2f };
	std::vector<float> tulokset = kerros.laske(syotteet);

	std::cout << "Kerroksen tulokset:\n";
	for (size_t i = 0; i < tulokset.size(); ++i) {
		std::cout << "Neuroni " << i << ": " << tulokset[i] << "\n";
	}
*/