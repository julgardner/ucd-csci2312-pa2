// Julian Gardner
// 102215161
// CSCI 2312 002 Intermediate Programming
// Last modified Feb. 22, 2016

// Implementation file for the Point class, which is a representation of a point in n-dimensional space.

#include <iostream> // Needed for istreams and ostreams
#include <cmath> // Needed for square root function sqrt()
#include "Point.h" // Needed for Point declaration

namespace Clustering
{
	// VARIABLE DECLARATIONS

	// next id to be assigned
	unsigned int Point::__idGen = 0;


	// CONSTRUCTORS

	// creates a point with dims dimensions 
	Point::Point(int dims)
	{
		__dim = dims; // make sure the object knows how many dimensions it has
		__values = new double[__dim]; // create the array holding the coordinates
		__id = __idGen; // assign the id
		++__idGen; // since the id in __idGen is now used, the program needs to increment __idGen
	}

	// creates a point with dims dimensions and a set of coordinates
	Point::Point(int dims, double* dataPtr)
	{
		__dim = dims; // make sure the object knows how many dimensions it has
		__values = new double[__dim]; // create the array
		__id = __idGen; // assign the id
		++__idGen; // since the id in __idGen is now used, the program needs to increment __idGen
		for (int i = 0; i < __dim; ++i) // now the program copies all elements of the array dataPtr points to into its data
		{
			__values[i] = dataPtr[i];
		}
	}


	// COPY CONSTRUCTOR, ASSIGNMENT OPERATOR, & DESTRUCTOR

	// copy constructor
	Point::Point(const Point& other)
	{
		__dim = other.getDims();
		__values = new double[__dim];
		__id = other.getId(); // not getting a new id, only copying the other point's id
		for (int i = 0; i < __dim; ++i) // copy the values
		{
			__values[i] = other.getValue(i);
		}
	}

	// assignment operator
	Point& Point::operator=(const Point& other)
	{
		delete[] __values; // we don't want the point's values anymore because we're assigning
		__dim = other.getDims();
		__values = new double[__dim];
		__id = other.getId(); // not getting a new id, only copying the other point's id
		for (int i = 0; i < __dim; ++i) // copy the values
		{
			__values[i] = other.getValue(i);
		}
		return *this;
	}

	// destructor
	Point::~Point()
	{
		delete[] __values;
	}


	// ACCESSORS & MUTATORS

	int Point::getId() const
	{
		return __id;
	}

	int Point::getDims() const
	{
		return __dim;
	}

	void Point::setValue(int index, double data)
	{
		__values[index] = data;
	}

	double Point::getValue(int index) const
	{
		return __values[index];
	}


	// MEMBER FUNCTIONS

	// computes distance to another Point
	double Point::distanceTo(const Point& other) const
	{
		double squareSum; // the sum of the squares of the distances
		double result;
		for (int i = 0; i < __dim; ++i)
		{
			squareSum += std::pow(__values[i] - other.getValue(i), 2.0);
		}
		result = std::sqrt(squareSum);
		return result;
	}


	// OPERATORS

	// each coordinate of the calling object is multiplied by multiplier
	Point& Point::operator*=(double multiplier)
	{
		for (int i = 0; i < __dim; ++i)
		{
			__values[i] *= multiplier;
		}
		return *this;
	}

	// each coordinate of the calling object is divided by divisor
	Point& Point::operator/=(double divisor)
	{
		*this *= (1.0 / divisor); // multiplying each coordinate by divisor's reciprocal is the same as dividing each coordinate by divisor
		return *this;
	}

	// each coordinate of the calling object is multiplied by multiplier
	const Point Point::operator*(double multiplier) const
	{
		return Point(*this) *= multiplier;
	}

	// each coordinate of the calling object is divided by divisor
	const Point Point::operator/(double divisor) const
	{
		return Point(*this) /= divisor;
	}

	// returns the coordinate at index
	double& Point::operator[](int index)
	{
		return __values[index];
	}


	// FRIENDS - TODO


}