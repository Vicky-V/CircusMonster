// Tony Davidson February 9, 2014
#include "RandomNumberGenerator.h"

// The default constructor uses int and sets the range to the minimum and maximum allowed values
RandomNumberGenerator::RandomNumberGenerator() : m_CurrentRandomNumber(0), m_CurrentDecimalRandomNumber(0.0) , m_UniformDistribution( std::numeric_limits<int>::min(), std::numeric_limits<int>::max() )
{
	// note: the uniform_real_distribution will use its default constructor so it does not need to be initialized
	std::random_device rd;
	m_MT.seed(rd());
}

// This constructor uses integer value 1 as the minimum value so only the maximum is required
RandomNumberGenerator::RandomNumberGenerator(const int maxValue) :  m_CurrentRandomNumber(0), m_CurrentDecimalRandomNumber(0.0) , m_UniformDistribution(1 , maxValue)
{
	// note: the uniform_real_distribution will use its default constructor so it does not need to be initialized
	std::random_device rd;
	m_MT.seed(rd());
}

// This constructor requires an integer value for the minimum and maximum values allowing the user complete control over the range
RandomNumberGenerator::RandomNumberGenerator(const int minValue , const int maxValue) :  m_CurrentRandomNumber(0), m_CurrentDecimalRandomNumber(0.0) , m_UniformDistribution(minValue , maxValue)
{
	// note: the uniform_real_distribution will use its default constructor so it does not need to be initialized
	std::random_device rd;
	m_MT.seed(rd());
}

// This constructor requires a double (decimal) value for the minimum and maximum values allowing the user complete control over the range which will generate a real (decimal) random number.
RandomNumberGenerator::	RandomNumberGenerator(const double & minValue , const double & maxValue) :  m_CurrentRandomNumber(0), m_CurrentDecimalRandomNumber(0.0) , m_UniformDistributionDecimal(minValue , maxValue)
{
	// note: the uniform_int_distribution will use its default constructor so it does not need to be initialized
	std::random_device rd;
	m_MT.seed(rd());
}

// overloaded method definitions note: all pass by reference
void RandomNumberGenerator::Generate(int & randomNumber)
{
	m_CurrentRandomNumber = m_UniformDistribution(m_MT);
	randomNumber = m_CurrentRandomNumber;
}

void RandomNumberGenerator::Generate(double & randomNumber)
{
	m_CurrentDecimalRandomNumber = m_UniformDistributionDecimal(m_MT);
	randomNumber = m_CurrentDecimalRandomNumber;
}


