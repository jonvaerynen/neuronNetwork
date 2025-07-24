#include <iostream>
#include "perceptron.h"
#include "kerros.h"
#include "neuroverkko.h"
#include <iomanip>
#include <vector>

int main() {
	Neuroverkko verkko(2,3,1);

	std::vector<float> syote { 1.0f, 0.5f };

	auto tulos = verkko.laske(syote);

	std::cout << "Tulos verkosta:\n";
	for (float arvo : tulos) {
		std::cout << arvo << "\n";
	}

	verkko.tulostaParametrit();

	return 0;
}



/*
int main() {
	int syotteidenMaara = 2;
	int neuronienMaara = 10;
	float oppimisnopeus = 0.1f;
	Kerros kerros(syotteidenMaara, neuronienMaara);

	kerros.tulostaParametrit();

	std::vector<std::pair<std::vector<float>, float>> data = {
	{{0.0f, 0.0f}, 0.0f},
	{{0.0f, 1.0f}, 0.0f},
	{{1.0f, 0.0f}, 0.0f},
	{{1.0f, 1.0f}, 1.0f}
	};

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\n=== Tulokset ennen koulutusta===\n";
	for (const auto& [syote, tavoite] : data) {
		auto tulokset = kerros.laske(syote);
		for (auto tulos : tulokset) {
			std::cout << "Syote: [" << syote[0] << "," << syote[1] << "]"
				<< "  Ennuste: " << tulos
				<< " (Tavoite: " << tavoite << ")\n";
		}
	}

	for (int epookki = 0; epookki < 10000; ++epookki) {
		for (const auto& [syote, tavoite] : data) {
			kerros.train(syote, tavoite, oppimisnopeus);
		}
	}

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\n=== Tulokset koulutuksen jalkeen===\n";
	for (const auto& [syote, tavoite] : data) {
		auto tulokset = kerros.laske(syote);
		for (auto tulos : tulokset) {
			std::cout << "Syote: [" << syote[0] << "," << syote[1] << "]"
				<< "  Ennuste: " << tulos
				<< " (Tavoite: " << tavoite << ")\n";
		}
	}



	return 0;
}

*/