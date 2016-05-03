#include "Dataset.h"
#include <vector>
#include <iostream> //do usuniecia potem

Dataset::Dataset(vector <Sample> vectorOfSamples){
	_vectorOfSamples = vectorOfSamples;
}

Dataset::Dataset(){
	;
}

void Dataset::push_back(Sample sampleToAdd){
	if (_vectorOfSamples.size()== 0 || sampleToAdd.size()==((_vectorOfSamples.back()).size())){
		_vectorOfSamples.push_back(sampleToAdd);
	}
		
}

int Dataset::size(){
	return _vectorOfSamples.size();
}

Sample Dataset::operator[](int element){ //do usuniecia
	return _vectorOfSamples[element];
}