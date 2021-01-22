/*
 Josh Dolgin
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;
const int MAX_BOOKS = 50;

class Book
{
	private:
		int edition;
	public:
		string author, title;
		
		Book()
		{
			edition = 0;
			author = "NONE";
			title = "NONE";
		}
		
		Book(string title0, string author0, int edition0)
		{
			title = title0;
			author = author0;
			edition = edition0;
		}
		
		int getEdition() const
		{
			return edition;
		}
		
		void setEdition(int edition0) 
		{
			edition = edition0;
		}
		
		bool readBook(ifstream & fin)
		{
			return fin >> title >> author >> edition;
		}
		
		void outBook(ofstream & fout) const
		{
			fout << title << " " << author << " " << edition << endl;
		}
		
		bool isSame(Book const & otherBook) const
		{
			return (author == otherBook.author && title == otherBook.title);
		}
};

int main()
{
	ifstream fin("booklist.txt");
	ofstream fout("bookUpdate.txt");
	
	Book list[MAX_BOOKS];
	
	Book newBook;
	
	while(newBook.readBook(fin))
	{
		bool foundBook = false;
		for(int index = 0; index < MAX_BOOKS  && !foundBook; index++)
		{
			if(newBook.isSame(list[index]))
			{
				list[index].setEdition(newBook.getEdition()); 
				foundBook = true;
			}
		}
	}
	
	int pointer = 0;
	while(list[pointer].author != "NONE")
	{
		list[pointer].outBook(fout);
		pointer++;
	}
	
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}

/*

*/
