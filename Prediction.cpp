#include "Prediction.h"
#include <vector>


Prediction::Prediction(int label, vector <double> features, int pred)
:Sample(label,features)
{
	_prediction = pred;
}

Prediction::Prediction(){
	;
}

double Prediction::accuracy(vector <Prediction*> vectorOfPredictions){
	int sum = 0;
	for (int i = 0; i < vectorOfPredictions.size(); i++){
		if (vectorOfPredictions[i]->label() == vectorOfPredictions[i]->prediction())
			sum++;
	}
	double result = sum*1.0/vectorOfPredictions.size();
	return result;
}