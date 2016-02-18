// Tony Davidson February 9, 2014
#ifndef RANDOMNUMBERGENERATOR_H 
#define RANDOMNUMBERGENERATOR_H 
								
#include <random>

class RandomNumberGenerator
{
private: // required data members are all private
	int m_CurrentRandomNumber;
	double m_CurrentDecimalRandomNumber;
	std::mt19937 m_MT;
	std::uniform_int_distribution<int>		m_UniformDistribution;
	std::uniform_real_distribution<double>	m_UniformDistributionDecimal;

public: // overloaded constructor declarations
	RandomNumberGenerator();	// the default constructor (takes NO arguments)
	RandomNumberGenerator(const int maxValue);
	RandomNumberGenerator(const int minValue , const int maxValue);
	RandomNumberGenerator(const double & min , const double & maxValue);


	// overloaded method declarations note: all pass by reference
	void Generate(double & randomNumber);
	void Generate(int & randomNumber);
	// inline methods
	void GetCurrentRandomNumber(double & randomNumber) { randomNumber = m_CurrentDecimalRandomNumber; }
	void GetCurrentRandomNumber(int & randomNumber) { randomNumber = m_CurrentRandomNumber; }
};

#endif