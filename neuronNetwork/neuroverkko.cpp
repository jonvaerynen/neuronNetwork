#include "neuroverkko.h"
#include <iostream>

Neuroverkko::Neuroverkko(size_t syotteidenmaara, size_t piiloneuronit, size_t ulostuloneuronit)
	: piilokerros(syotteidenmaara, piiloneuronit),
	ulostulokerros(piiloneuronit, ulostuloneuronit) {
	std::cout << "Neuroverkko luotu: "
		<< syotteidenmaara << " syötettä, "
		<< piiloneuronit << " piiloneuronia, "
		<< ulostuloneuronit << " ulostuloa\n";
}

std::vector<float> Neuroverkko::laske(const std::vector<float>& syote) {
	auto piilotulos = piilokerros.laske(syote);
	auto ulostulo = ulostulokerros.laske(piilotulos);
	return ulostulo;
}

void Neuroverkko::train(const std::vector<float>& syote, float tavoite, float oppimisnopeus) {
	auto piilotulos = piilokerros.laske(syote);

	auto ulostulo = ulostulokerros.laske(piilotulos);

	for (size_t i = 0; i < ulostulo.size(); ++i) {
		ulostulokerros.getNeuronit()[i].train(piilotulos, tavoite, oppimisnopeus);
	}
}


void Neuroverkko::tulostaParametrit()const {
	std::cout << "=== Piilokerros ===";
	piilokerros.tulostaParametrit();

	std::cout << "=== Ulostulokerros ===";
	ulostulokerros.tulostaParametrit();
}