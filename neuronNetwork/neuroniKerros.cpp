#include <iostream>
#include <cmath>

float sigmoid(float x) {
	return 1.0f / (1.0f + std::exp(-x));
}

void neuron() {
	// Syötteet
	float x1 = 1.0f;
	float x2 = 0.5f;
	float x3 = -0.2f;

	// Painot
	float w1 = 0.8f;
	float w2 = -0.4f;
	float w3 = 0.3f;

	// bias
	float b = 0.1f;

	// Painotettu summa z
	float z = x1 * w1 + x2 * w2 + x3 * w3 + b;

	std::cout << "Painotettu summa (z) =  " << z << '\n';

	// aktivoinit a = sigmoid (z)
	float a = sigmoid(z);

	std::cout << "Sigmoid-aktivointi (a) = " << a << '\n';
}