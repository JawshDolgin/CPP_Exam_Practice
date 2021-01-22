/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;


class Book
{
	private:
		int edition;
	
	public:
		string name, author;
		
		Book()
		{
			name = "";
			author = "";
			edition = 0;
		}
		
		Book(string nameOfBook, string authorName, int bookEdition)
		{
			name = nameOfBook;
			author = authorName;
			(*this).setEdition(bookEdition);
		}
		
		bool readBookFile(ifstream & fin)
		{
			if(fin >> name >> author >> edition)
				return true;
			
			return false;
		}
				
		int getEdition()
		{
			return edition;
		}
		
		void setEdition(int newEdition)
		{
			edition = newEdition;
		}
		
		bool sameBook(Book & otherBook)
		{
			if(author == otherBook.author && name == otherBook.name)
				return true;
			
			return false;
		}
};

int main()
{
	ifstream fin("booklist.txt");
	ofstream fout("bookupdate.txt");
	
	Book newList[50];
	int pointer = 0;
	
	while(newList[pointer].readBookFile(fin))
	{
		for(int checker = 0; checker < pointer; checker++)
		{
			if(newList[pointer].sameBook(newList[checker]))
			{
				newList[checker].setEdition(newList[pointer].getEdition());
				newList[pointer].setEdition(-1);
			}
		}
		pointer++;
	}
	
	for(int x = 0; x < 50; x++)
	{
		if(newList[x].getEdition() != -1)
		{
			fout << newList[x].name << " " << newList[x].author << " " << newList[x].getEdition() << endl;
		}
	}
	
	system("PAUSE");
	return EXIT_SUCCESS;
}
