// Julian Gardner
// 102215161
// CSCI 2312 002 Intermediate Programming
// Last modified Mar. 1, 2016

// Implementation file for the Cluster class, which represents a collection of Point objects.

#include <iostream>
#include "Point.h"
#include "Cluster.h"
using Clustering::Point;

const Point s(5); // This global const Point is to make sure the stub operator[] has something to return

namespace Clustering
{
	// constructor for node
	LNode::LNode(const Point & p, LNodePtr n) : point(p), next(n) {}

	// Stubs begin here

	void Cluster::__del()
	{

	}

	void Cluster::__cpy(LNodePtr pts)
	{

	}

	bool Cluster::__in(const Point & p) const
	{
		return false;
	}

	Cluster::Cluster()
	{

	}

	Cluster::Cluster(const Cluster& c)
	{

	}

	Cluster& Cluster::operator=(const Cluster & c)
	{
		return *this;
	}

	Cluster::~Cluster()
	{

	}

	int Cluster::getSize() const
	{
		return 0;
	}

	void Cluster::add(const Point & p)
	{

	}

	const Point& Cluster::remove(const Point & p)
	{
		return p;
	}

	bool Cluster::contains(const Point & p)
	{
		return false;
	}

	const Point& Cluster::operator[](unsigned int index) const
	{
		return s;
	}

	Cluster& Cluster::operator+=(const Point & p)
	{
		return *this;
	}

	Cluster& Cluster::operator-=(const Point & p)
	{
		return *this;
	}

	Cluster& Cluster::operator+=(const Cluster & c)
	{
		return *this;
	}

	Cluster& Cluster::operator-=(const Cluster & c)
	{
		return *this;
	}

	std::ostream &operator<<(std::ostream & os, const Cluster & c)
	{
		return os;
	}

	std::istream &operator>>(std::istream & istr, Cluster & c)
	{
		return istr;
	}

	bool operator==(const Cluster & c, const Cluster & d)
	{
		return false;
	}

	bool operator!=(const Cluster & c, const Cluster & d)
	{
		return false;
	}

	const Cluster operator+(const Cluster & c, const Point & p)
	{
		return c;
	}

	const Cluster operator-(const Cluster & c, const Point & p)
	{
		return c;
	}

	const Cluster operator+(const Cluster & c, const Cluster & d)
	{
		return c;
	}

	const Cluster operator-(const Cluster & c, const Cluster & d)
	{
		return c;
	}

}