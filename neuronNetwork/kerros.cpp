#include "kerros.h"
#include <iostream>

std::vector<Perceptron>& Kerros::getNeuronit()  {
	return neuronit;
}

Kerros::Kerros(size_t syotteidenMaara, size_t neuronienMaara) {
	
	neuronit.reserve(neuronienMaara);

	for (size_t i = 0; i < neuronienMaara; ++i) {
		neuronit.emplace_back(syotteidenMaara);
	}

}
std::vector<float> Kerros::laske(const std::vector<float>& syotteet) const {
	std::vector<float> tulokset;
	tulokset.reserve(neuronit.size());

	for (const auto& neuroni : neuronit) {
		float tulos = neuroni.laske(syotteet);
		tulokset.push_back(tulos);
	}
	return tulokset;
}

void Kerros::train(const std::vector<float>& syote, float tavoite, float oppimisnopeus) {
	
	for (auto& neuroni : neuronit) {
		neuroni.train(syote, tavoite, oppimisnopeus);
	}
}


void Kerros::tulostaParametrit() const {
	std::cout << "=== Kerroksen parametrit ===\n";
	
	for (size_t i = 0; i < neuronit.size(); ++i) {
		std::cout << "Neuroni " << i+1 << "\n";
		neuronit[i].tulostaParametrit();
	}

	std::cout << std::endl;
}