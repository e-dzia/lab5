#pragma once
#include "Sample.h"
#include <vector>

using namespace std;

/*
- Stwórz klasę `Dataset`, zawierajšcš:
    - wektor obiektów klasy `Sample`,
    - metodę `push_back()`, dodajšcš nowš próbkę do wektora:
        - metoda ta powinna sprawdzać, czy wektor `features` dla każdej z wprowadzanych próbek jest tej samej długoci.
*/

class Dataset {
	private:
		vector <Sample> _vectorOfSamples;
		
	public:
		Dataset(vector <Sample> vectorOfSamples); //konstruktor
		Dataset(); //konstruktor domyslny
		
		void push_back(Sample sampleToAdd);
		int size();
		Sample operator[](int element); //do usuniecia
};