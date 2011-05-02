#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

float rate = 8000.0f;

void hertz(float hz, float l, double vol) {
	double p;
	static double acc = 0;
	double dur = rate * l; 
	double o = 2 * M_PI;
	double inc;
	unsigned char output;
	int loop = 0;

	if (hz != 0) {
		p = rate / hz;
		inc = o / p;
	} else {
		acc = 0;
		inc = 0;
	}
	for (; loop < dur; acc += inc, loop++) {
		output = (unsigned char)((sin(acc) + 1.0) * 127.0 * vol);
		write(1, &output, 1);
	}
}

int main(int argc, char **argv) {
	int i;
	float hz, length, volume;
	while (cin.good()) {
		cin >> hz >> length >> volume;
		hertz(hz, length, volume);
	}
	return 0;
}
