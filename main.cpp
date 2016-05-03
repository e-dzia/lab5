#include "Sample.h"
#include "Dataset.h"
#include "Prediction.h"

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

/*
- Jako argumenty wiersza poleceń programu, przekaż nazwę pliku oraz liczbę całkowitš `k`,
- dla celów testowych, w repozytorium znajduje się plik `wine.csv`,
- wczytaj plik `wine.csv` do wektora obiektów typu `Sample` tak, aby pierwsza jego kolumna okrelała `label`, a pozostałe znalazły się w wektorze `features`,
- stwórz dwa obiekty klasy `Dataset`. Pierwszy nazwij `train`, drugi `test`,
- do `train` wprowad losowe 20% wczytanych z pliku obiektów, a do `test`, resztę,
*/


using namespace std;

vector <Prediction *> knn(Dataset *train, Dataset *test, int k);
double distance(vector <double> v1, vector <double> v2);
void sort(double arr[][2], int size);

int main(int argc, char const *argv[]) 
{
	int k = atoi(argv[2]);
	string filename = argv[1];
	ifstream Wine;
	Wine.open(filename.c_str());	
	vector <Sample> vectorOfSamples;
	
	vector<double> vectorOfFeatures;
	while (!Wine.eof()){
		string line;
		getline(Wine,line);
		if (line == "") break;
		int label = line[0] - '0';
		int i = 1;
		do {
			string feature = "";
			while (line[i]==',') i++;
			do{
				feature += line[i];
				i++;
			}while(line[i]!=',' && i < line.length());
			vectorOfFeatures.push_back(stod(feature));
		}while (i<line.length());
		vectorOfSamples.push_back(Sample(label, vectorOfFeatures));
		vectorOfFeatures.clear();
	}
	srand(time(NULL));
	Dataset train;
	Dataset test;
	int sizeOfSamples = vectorOfSamples.size();
	int max = 0.2*sizeOfSamples;
	for (int i = 0; i < max; i++){
		int j = rand()%sizeOfSamples;
		train.push_back(vectorOfSamples[j]);
		vectorOfSamples.erase(vectorOfSamples.begin()+j);
	}
	for (int i = 0; i < vectorOfSamples.size(); i++){
		test.push_back(vectorOfSamples[i]);
	}

/*
- Wywietl użytkownikowi informacje o zbiorze 
(nazwa pliku, liczba próbek, liczba cech) 
oraz jakoć klasyfikacji (`accuracy()`).
*/

	cout << "Nazwa pliku: " << filename << endl;
	cout << "Liczba probek: " << sizeOfSamples << endl;
	cout << "Liczba cech: " << test[0].size() << endl;
	cout << "Jakosc klasyfikacji: " << Prediction::accuracy(knn(&train, &test, k)) << endl;

}

/*- zaimplementuj funkcję `knn()`, zwracajšcš wektor obiektów klasy `Prediction` 
przyjmujšcš jako argumenty dwa obiekty typu `Dataset` (`train` i `test`) 
i zmiennš całkowitš `k`:
    - utwórz w niej wektor `predictions`:
    - do utworzonego wektora wprowad kopie wszystkich obiektów 
    (majš typ `Sample`) znajdujšcych się w `test`, uzupełniajšc dla nich 
    wartoć `prediction`, według następujšcego schematu:
>   Dla każdego obiektu ze zbioru testowego znajd `k` obiektów ze zbioru 
uczšcego, którego cechy (`features`) znajdujš się w najmniejszej od niego 
[odległoci](https://pl.wikipedia.org/wiki/Odległoć). Za `prediction` uznaj 
`label`, który powtarza się najczęciej wród znalezionych.
>   */

vector <Prediction *> knn(Dataset *train, Dataset *test, int k)
{
	vector <Prediction *> predictions;
	for (int i = 0; i < test->size(); i++){
		double dist[train->size()][2];
		for (int j = 0; j < train->size(); j++){
			dist[j][0] = distance(test[0][i].features(),train[0][j].features());
			dist[j][1] = j;
		}
		sort(dist,train->size()); //sortowanie wg distance
		for (int j = 0; j < train->size(); j++){
		}
		int max[3] = {0, 0, 0}; //Bo label to tylko 1, 2, 3
		for (int j = 0; j < k; j++){ //tutaj szukam tego, ktory sie powtarza najczesciej
			max[train[0][dist[j][1]].label()-1]++;
			//cout << "** " <<  train[0][dist[j][1]].label()-1 << " ** " << max[train[0][dist[j][1]].label()-1] << " ** \n";
		}
		
		int predict = 1; //ten label ktory powtarza sie najczesciej
		for (int j = 1; j < 3; j++){
			if (max[j] > max[predict-1]) 
				predict = j + 1;
		}
		Prediction *tmp = new Prediction(test[0][i].label(), test[0][i].features(),predict);
		//cout << test[0][i].label() << " " << predict << endl;
		predictions.push_back(tmp);
	}
	return predictions;
}

double distance(vector <double> v1, vector <double> v2)
{
	double sum = 0;
	for (int i = 0; i < v1.size(); i++){
		sum += (v1[i]-v2[i])*(v1[i]-v2[i]);
	}
	return sqrt(sum);
}

void sort(double arr[][2], int size) //sortowanie babelkowe :o
{
	for (int i = 0; i < size; i++){
		for (int j = 1; j < size; j++){ 
			if (arr[j][0] < arr[j-1][0]){
				double tmp = arr[j-1][0];
				arr[j-1][0] = arr[j][0];
				arr[j][0] = tmp;

				tmp = arr[j-1][1];
				arr[j-1][1] = arr[j][1];
				arr[j][1] = tmp;
			}
		}
	}
}