/**
Brandon Erb
Description: Application that populates objects in a 3 dimensional space 
*/

#include "uniformdistribution.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{

	UniformDistribution makeBodies;
	vector<Coords> locations;
	Coords output;
	int numBodies = 2;
	int spaceSize = 10;

	//cout << "Enter number of celestial bodies";
	//cin >> numBodies;
	//cout << "Enter the size of space in light years";
	//cin >> spaceSize;

	makeBodies.numBodies = numBodies;
	makeBodies.sizeOfSpace = spaceSize;
	locations = makeBodies.Create();
	

	for (int i = 0; i < locations.size(); i++)
	{
		output = locations[i];
		cout << "[" << output.x << "]" << "[" << output.y << "]" << "[" << output.z << "]\n";
	}

	return 0;
}