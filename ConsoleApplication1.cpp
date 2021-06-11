#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

struct Probability
{
	char probabilityName[20];
	float probabilityValue;
};

void ReadFromFile()
{
	//create an array of struct Probability
	Probability probability[39];
	// reading the input file nlpProb.txt into the array of struct Probability
	string filename;
	cout << "Enter a file name: ";
	getline(cin, filename);
	if(filename.compare("nlpProb") == 0)
	{
		ifstream myFile("nlpProb.txt");
		for (int i = 0; i < 39; i++)
		{
			myFile >> probability[i].probabilityName >> probability[i].probabilityValue;
		}
		myFile.close();
	}
	//displaying the contents of the array of struct Probability
	for (int i = 0; i < 39; i++)
	{
		cout << probability[i].probabilityName << ' ' << "=" << ' ' << probability[i].probabilityValue << endl;
	}

	string inputWord;
	stringstream firstprob;
	float firstProbValue{};
	stringstream secondprob;
	float secondProbValue{};
	stringstream thirdprob;
	float thirdProb;
	float inputProb = 1;
	int index{};

	//user to input a word 
	cout << "Enter a word with letters a, b and/or c only: ";
	getline(cin, inputWord);
	//user should input a word that has letters a, b and/or c
	for (int i = 0; i < inputWord.length(); i++)
	{
		if (inputWord[i] != 'a' && inputWord[i] != 'b' && inputWord[i] != 'c')
		{
			cout << "Invalid input" << endl << "Enter a word with letters a, b and/or c only: ";
			getline(cin, inputWord);
		}
	}

	// as long as user input is not equal to quit, the user will be prompted to enter a word
	while (inputWord != "quit")
	{
		float total = 1;
		for (int i = 0; i < inputWord.length(); i++)
		{
			// user input is transformed to uppercase(capital letters)
			if (islower(inputWord[i]))
			{
				inputWord[i] = toupper(inputWord[i]);
			}
			//probability of the first letter/character of the word that the user inputted
			if (i == 0)
			{
				firstprob.str("");
				firstprob << 'P' << '(' << inputWord[i] << '|' << "nothingbefore" << ')';
				for (int j = 0; j < 39; j++)
				{
					if (firstprob.str().compare(probability[j].probabilityName) == 0)
					{
						firstprob.str() = probability[j].probabilityName;
						index = j;
					}
				}
				firstProbValue = probability[index].probabilityValue;
				cout << endl << firstprob.str() << ' ' << firstProbValue << ' ' << '*' << ' ';
			}
			//probability of the second letter/character of the word that the user inputted
			if (i == 1)
			{
				secondprob.str("");
				secondprob << 'P' << '(' << inputWord[i] << '|' << "only" << inputWord[i - 1] << "before" << ')';
				for (int j = 0; j < 39; j++)
				{
					if (secondprob.str().compare(probability[j].probabilityName) == 0)
					{
						secondprob.str() = probability[j].probabilityName;
						index = j;
					}
				}
				secondProbValue = probability[index].probabilityValue;
				cout << secondprob.str() << ' ' << secondProbValue << ' ' << '*' << ' ';
			}
			//probabilities of the letters/characters of the word that the user inputted from the third character to the last character of the word
			vector<float> thirdProbValue;
			if (i >= 2)
			{
				thirdprob.str("");
				thirdprob << 'P' << '(' << inputWord[i] << '|' << inputWord[i - 2] << inputWord[i - 1] << ')';
				for (int j = 0; j < 39; j++)
				{
					if (thirdprob.str().compare(probability[j].probabilityName) == 0)
					{
						thirdprob.str() = probability[j].probabilityName;
						index = j;
					}
				}
				thirdProb = probability[index].probabilityValue;
				thirdProbValue.push_back(thirdProb); 
				cout << thirdprob.str() << ' ' << thirdProb << ' ' << '*' << ' ';
			}
			//the product/multiplication of the probabilities of characters from third character to last character of the word
			for (float num : thirdProbValue)
			{
				total *= num;
			}
			//probability of the whole input word
			if(inputWord.length() == 1)
			{
				inputProb = firstProbValue;
			}
			else if(inputWord.length() == 2)
			{
				inputProb = firstProbValue * secondProbValue;
			}
			else 
			{
				inputProb = firstProbValue * secondProbValue * total;
			}
		}
		cout << endl << 'P' << '(' << inputWord << ')' << ' ' << '=' << ' ' << inputProb << endl;

		// as long as user input is not equal to quit the user will be prompted to enter a word and while loop will continue
		cout << endl << "Enter a word with letters a, b and/or c only: ";
		getline(cin, inputWord);
		//user should input a word that has letters a, b and/or c to get probability of the word
		for (int i = 0; i < inputWord.length(); i++)
		{
			if (inputWord[i] != 'a' && inputWord[i] != 'b' && inputWord[i] != 'c' && inputWord != "quit")
			{
				cout << "Invalid input" << endl << "Enter a word with letters a, b and/or c only: ";
				getline(cin, inputWord);
			}
		}
	}
}

int main ()
{
	ReadFromFile();
}