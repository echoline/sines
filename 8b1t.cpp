#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

float rate = 8000.0f;

void tone(float hz, float l, double vol) {
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
		output = (unsigned char)(sin(acc) * vol * 127.0) + 128;
		cout << output;
	}
}

int main(int argc, char **argv) {
	int i;
	float hz, length, volume;
	char buf[128];

	for (i = 1; i < argc; i++) {
		if (!strcasecmp(argv[i], "-h")) {
			cerr << "usage:\t" << argv[0] << " [-r rate]\n";
			return -1;
		}
		if ((i + 1) < argc) {
			if (!strcasecmp(argv[i], "-r"))
				rate = atof(argv[i+1]);
		}
	}
	i = 0;
	while (cin.good()) {
		cin >> buf;
		if (buf[0] == '#') {
			while (buf[0] != '\n' && cin.good())
				buf[0] = cin.get();
			continue;
		}
		switch(i % 3) {
		case 0:
			hz = atof(buf);
			i++;
			break;
		case 1:
			length = atof(buf);
			i++;
			break;
		case 2:
			volume = atof(buf);
			tone(hz, length, volume);
			i = 0;
			break;
		}
	}
	return 0;
}

