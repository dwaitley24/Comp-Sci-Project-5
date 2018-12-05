/*	Project:    Assignment 5
	Name:       David Waitley
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 1
*/

#include <iostream>
#include <cassert>
#include <vector>
#include <fstream>

//create h file, #include "file.h"

using namespace std;

class Allele
{
  private:
	string nucleoSequence;
	string variantName;
	string variantType;

  public:
	void SetSequence(string &nucleoSequence, string &variantName, string &variantType);
	Allele()
	{
		nucleoSequence = "";
		variantName = "";
		variantType = "";
	}
	Allele(string &n, string &vName, string &vType)
	{
		nucleoSequence = n;
		variantName = vName;
		variantType = vType;
	}
	string GetName()
	{
		return this->nucleoSequence;
		return this->variantName;
		return this->variantType;
	}
	void WriteAlleleToFile(ofstream &);
	bool &RunUnitTest();
};
class Gene
{
  private:
	Allele AlleleA;
	Allele AlleleB;

  public:
	Gene(Allele &A, Allele &B)
	{
		AlleleA = A;
		AlleleB = B;
	}
	Gene();
	//bool &RunUnitTest();
};
class Chromosome
{
  private:
	vector<Gene> genes;
	string fileName;

  public:
	Chromosome() { fileName = ""; }			   //defalut constructor
	void AnalyzeGenotype(vector<Gene> &genes); //Outputs dominant allele
	void InputFromFile(ifstream &ifs);
	void OutputToFile(ofstream &ofs);
	void AddGene(Gene g);				  //adds a new gene
	Gene FindGene(string name);			  //returns a gene with name 'name'
	Chromosome operator+(Chromosome rhs); //returns chromosome that is a recombination of 1 allele from each of 2 genes
	bool &RunUnitTest();
};
class GeneSequencer
{
	Chromosome CreateChromosome();
	Chromosome ImportChromosome(const string &fileName = "");		  //returns chromosome object from data in fileName
	void ExportChromosome(Chromosome c, const string &fileName = ""); //saves chromosome 'c' data to file fileName
	Chromosome DoMeiosis(Chromosome x, Chromosome y);				  //Returns chromosome from x and y genes - allele selection random
	void SequeunceChromosome(Chromosome c);							  //outputs genotype (dominant alleles from each gene) in c
	bool PowerOnSetTest();
};

int main()
{
	int userInput = 0;
	string name;
	string nucleoSequence;
	string trait;
	string variantName;
	string variantType;
	vector<Gene> genes;
	Chromosome myChromosome;
	Gene myGene;
	cout << "Input choice 1-6: " << endl;
	cout << "1: Create chromosome" << endl;
	cout << "2: Analyze chromosome" << endl;
	cout << "3: Output chromosome to file" << endl;
	cout << "4: Input chromosome from file" << endl;
	cout << "5: Combine chromosomes" << endl;
	cout << "6: Exit" << endl;
	cin >> userInput;
	if (userInput == 1)
	{
		Allele myAllele;
		cout << "What is the gene name?: ";
		cin >> name;
		cout << "What is the gene trait?: ";
		cin >> trait;
		cout << "Enter variant name for Allele 1: ";
		cin >> variantName;
		cout << "Enter variant type for Allele 1: ";
		cin >> variantType;
		cout << "Enter nucleotide sequence for Allele 1: ";
		cin >> nucleoSequence;
		Allele a(variantName, variantType, nucleoSequence);
		cout << "Enter variant name for Allele 2: ";
		cin >> variantName;
		cout << "Enter variant type for Allele 2: ";
		cin >> variantType;
		cout << "Enter nucleotide sequence for Allele 2: ";
		cin >> nucleoSequence;
		Allele b(variantName, variantType, nucleoSequence);
		Gene myGene(a, b);
		myChromosome.AddGene(myGene); //adds genes
	}
	else if (userInput == 2)
	{
	}
	else if (userInput == 3)
	{
	}
	else if (userInput == 4)
	{
	}
	else if (userInput == 5)
	{
	}
	else
	{
		cout << "Goodbye!";
	}
	char(c);
	cin.ignore();
	cin.get(c);
	return 0;
}