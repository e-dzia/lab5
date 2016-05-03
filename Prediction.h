#pragma once
#include "Sample.h"

using namespace std;

/*
- Stwórz klasę `Prediction`, dziedziczšcš po klasie `Sample`, dodajšcš do niej zmiennš `prediction`,
- Rozszerz jš o metodę statycznš `accuracy()`, przyjmujšcš wektor obiektów klasy `Prediction`, 
informujšcš o tym, w jakim odsetku ich zmienne `label` i `prediction` majš tę samš wartoć.
*/

class Prediction: public Sample
{
	private:
		int _prediction;
		
	public:
		Prediction(int label, vector <double> features, int prediction = 0); //konstruktor
		Prediction();
		
		int prediction(){ //getter
			return _prediction;
		}
		
		static double accuracy(vector <Prediction*> vectorOfPredictions); //wylicza ile % ma label == prediction
		
};