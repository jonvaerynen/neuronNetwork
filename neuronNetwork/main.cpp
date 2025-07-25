#include <iostream>
#include "perceptron.h"
#include "kerros.h"
#include "neuroverkko.h"
#include <iomanip>
#include <vector>

int main() {
	Neuroverkko verkko(2,25,1);

	std::vector<std::pair<std::vector<float>, float>> data = {
	{{ 0.0f, 0.0f}, 0.0f},
	{{ 1.0f, 0.0f}, 1.0f},
	{{ 0.0f, 1.0f}, 1.0f},
	{{ 1.0f, 1.0f}, 0.0f}
	};

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\n=== Ennen ===\n";
	for (const auto& [syote, tavoite] : data) {
		auto out = verkko.laske(syote);
		std::cout << syote[0] << " " << syote[1] << " " << out[0] << "(tavoite: " << tavoite << ")\n";
	}

	float oppimisnopeus = 0.1f;
	for (int epookki = 0; epookki < 100000; ++epookki) {
		for (const auto& [syote, tavoite] : data) {
			verkko.train(syote, tavoite, oppimisnopeus);
		}
	}

	std::cout << std::fixed << std::setprecision(3);
	std::cout << "\n=== Jalkeen ===\n";
	for (const auto& [syote, tavoite] : data) {
		auto out = verkko.laske(syote);
		std::cout << syote[0] << " " << syote[1] << " " << out[0] << "(tavoite: " << tavoite << ")\n";
	}


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