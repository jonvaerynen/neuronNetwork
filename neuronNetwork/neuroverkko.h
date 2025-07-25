#pragma once
#include "kerros.h"
#include <vector>

class Neuroverkko {
private:
	Kerros piilokerros;
	Kerros ulostulokerros;

public:
	Neuroverkko(size_t syotteidenMaara, size_t piiloneuronit, size_t ulostuloneuronit);
	std::vector<float> laske(const std::vector<float>& syote);
	void tulostaParametrit() const;
	void train(const std::vector<float>& syote, float tavoite, float oppimisnopeus);
};