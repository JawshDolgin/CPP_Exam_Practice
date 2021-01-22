/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void sort(double & l, double & w, double & h)
{
}

class Box
{
	private:
		double height, length, width;
	public:
		Box()
		{
			height = 0;
			length = 0;
			width - 0;
		}
		
		Box(double length0, double width0, double height0)
		{
			sort(length0, width0, height0);
			height = height0;
			length = length0;
			width = width0;
		}
		
		double getHeight() const
		{
			return height;
		}
		
		double getLength() const
		{
			return length;
		}
		
		double getWidth() const
		{
			return width;
		}
		
		void outputBox(ostream & out) const
		{
			out << "Length: " << length << " Width: " << width << " Height: " <<
			height;
		}
		
		void scaleBox(double scaleFactor)
		{
			height *= scaleFactor;
			length *= scaleFactor;
			width *= scaleFactor;
		}
		
		double volume() const
		{
			return length * width * height;
		}
		
		bool contains(Box const & otherBox) const
		{
			if(otherBox.getHeight() < height && otherBox.getLength() < length && 
			otherBox.getWidth()< width)
				return true;
			else
				return false;
		}
};

int main()
{
	ifstream fin("boxes.txt");
	
	double length = 0, width = 0, height = 0;
	
	int numBoxes = 0;
	Box compBox(0.5, 0.75, 1);
	
	while(fin >> length >> width >> height)
	{
		Box newBox(length, width, height);
		
		newBox.outputBox(cout);
		cout << " Volume: " << newBox.volume() << endl;
		
		if(compBox.contains(newBox))
			numBoxes++;
	}
	
	cout << numBoxes << endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}


