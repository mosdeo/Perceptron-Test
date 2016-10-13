#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include "Perceptron.h"

using namespace std;

FILE *cfPtr;

int Classification;

class StepFeature
{
public:
	StepFeature()
	{
	}
	static int UpperDataCounter;
	static int DownDataCounter;
	int BMI;
	int AccelerationPeakToPeak;
	int label;
};
int StepFeature::UpperDataCounter=0;
int StepFeature::DownDataCounter=0;

struct Pocket
{
	int Vector[3];
	int counter;
}Pocket;

vector<StepFeature> vTrainingSet;

int main(void)
{
	cout << "Pocket Perceptron Verify\n\n" ;
	srand((unsigned)time(NULL));
	Perceptron* p1 = new Perceptron(0,0,0);
	Perceptron* p2 = new Perceptron(0, 0, 0);
	printf("First,%s\n",p1->GetWeightVector().c_str());
	_sleep(1000);

	if( (cfPtr = fopen("../�W�U�ӱ�S�x��(��l�ƾ�).txt","r")) == NULL)
	{
		cout << "�䤣���ɮ�";
		system("PAUSE");
	}
	else
	{
		while(!feof(cfPtr))
		{
			int n,AccPtoP,BMI;
			char c;
			StepFeature tempStepFeature;

			fscanf(cfPtr,"%d%d%c%d%d%c%d",&Classification,&n,&c,&AccPtoP,&n,&c,&BMI); //Ū�J�Ĥ@�ӼƦr�A�P�O�����@��?
			printf("��%d AccPtoP=%d BMI=%d\n",Classification,AccPtoP,BMI);
			tempStepFeature.AccelerationPeakToPeak = AccPtoP;
			tempStepFeature.BMI=BMI;

			switch(Classification)  //�w�藍�P��
			{
				case 1://�W�ӱ�
					tempStepFeature.label=1;
					StepFeature::UpperDataCounter++;
					break;
				case 2://�U�ӱ�
					tempStepFeature.label=-1;
					StepFeature::DownDataCounter++;
					break;
			}

			vTrainingSet.push_back(tempStepFeature);
		}
		fclose(cfPtr);
	} //Ū������

	printf("��1�`�@%d�����\n",StepFeature::UpperDataCounter);
	printf("��2�`�@%d�����\n",StepFeature::DownDataCounter);
	_sleep(1000);

	while(1)
	{//���հj��
		p1->SetWeightVector(-124, -85, 11840);
		p2->SetWeightVector(-154, 400, 3666);
		//p1->SetWeightVector(-130, -61, 11710);
		//p->SetWeightVector(-26, 90, 42);
		//p->SetWeightVector(-154, 400, 3666);
		int Tcounter=0;
		int Fcounter=0;
		int Down=0;
		int Upper=0;

		for(vector<StepFeature>::iterator it=vTrainingSet.begin();it!=vTrainingSet.end();it++)
		{
			int innerProduct1 = p1->SumOfAction(it->AccelerationPeakToPeak,it->BMI);
			int innerProduct2 = p2->SumOfAction(it->AccelerationPeakToPeak, it->BMI);

			//if(innerProduct2<0)Down++;
			//if(innerProduct2>0)Upper++;
			
			//if(innerProduct1<0)Down++;
			//if(innerProduct1>0)Upper++;

			int ThisLoopRecognitionResult;
			if (innerProduct1 < 0 && innerProduct2 < 0)
			{
				Down++;
				ThisLoopRecognitionResult = -1;
			}
			else
			{
				Upper++;
				ThisLoopRecognitionResult = +1;
			}

			if(it->label == ThisLoopRecognitionResult)
			//if(it->label * innerProduct1 > 0)
			//if(it->label * innerProduct2 > 0)
			{//�������T
				Tcounter++;//���T�@���[�@��
			}
			else
			{//�������~
				Fcounter++;
			}
		}

		printf("Down=%d, Upper=%d\n",Down,Upper);
		printf("T=%d,F=%d,���T�v=%d",Tcounter,Fcounter,(Tcounter*100)/(Tcounter+Fcounter));
		system("PAUSE");
	}
}