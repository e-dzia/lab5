#pragma once
#include <vector>

using namespace std;

/*
- Stwórz klasę `Sample`, zawierajšcš:
    - zmiennš całkowitš `label`,
    - wektor liczb zmiennoprzecinkowych `features`,
- w konstruktorze klasy `Sample` przyjmuj oba te parametry,
- stwórz też dla nich *gettery*.
*/

class Sample {
	private:
		int _label;
		vector<double> _features;
	public:
		Sample(int label, vector<double> features); //konstruktor
		Sample();
		
		int label(){ //getter
			return _label;
		}
		
		vector <double> features(){ //getter
			return _features;
		}
		
		int size(){
			return _features.size();
		}
};