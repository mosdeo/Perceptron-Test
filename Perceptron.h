#include <iostream>
#include <string>
using namespace std;

class Perceptron
{
private:
	int WeightVector[3];

public:
	Perceptron(int WeightVector0, int WeightVector1, int WeightVector2)
	{
		WeightVector[0] = WeightVector0;
		WeightVector[1] = WeightVector1;
		WeightVector[2] = WeightVector2;
	};

	string GetWeightVector(void)
	{
		string strWeightVector = std::to_string(WeightVector[0]) + "," + std::to_string(WeightVector[1]) + "," + std::to_string(WeightVector[2]);
		return strWeightVector;
	};

	int GetWeightValue(int index)
	{
		return WeightVector[index];
	}

	void SetWeightVector(int WeightVector0, int WeightVector1, int WeightVector2)
	{
		WeightVector[0] = WeightVector0;
		WeightVector[1] = WeightVector1;
		WeightVector[2] = WeightVector2;
	};

	void SubErrWeightVector(int WeightVector0, int WeightVector1, int WeightVector2)
	{
		WeightVector[0] -= WeightVector0;
		WeightVector[1] -= WeightVector1;
		WeightVector[2] -= WeightVector2;
	};

	void AddWeightVector(int WeightVector0, int WeightVector1, int WeightVector2)
	{
		WeightVector[0] += WeightVector0;
		WeightVector[1] += WeightVector1;
		WeightVector[2] += WeightVector2;
	};

	int SumOfAction(int a0, int a1, int a2=1)
	{
		return a0*WeightVector[0] + a1*WeightVector[1] + a2*WeightVector[2];
	}

};