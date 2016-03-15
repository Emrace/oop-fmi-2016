#include <string>
#include <iostream>
 
using namespace std;
 
class Book
{
public:
    //we make all fields public to avoid writing setters and getters
    //they should be private, and you should not be too lazy to write setters and getters
    string title;
    string author;
    int year;
    bool available;
 
    Book(string _title = "", string _author = "",
        int _year = 0, bool _available = false)
    {
        title = _title;
        author = _author;
        year = _year;
        available = _available;
 
    }
 
    //example for settters and getters, they are not used anywhere
    string get_title(){ return title; }
    void set_title(string _title) { title = _title; }
};
 
class BooksList
{
private:
    static const int SIZE = 30;
    Book books[SIZE];
 
public:
    BooksList(Book _books[], int count)
    {
        //BooksList constructor
        for (int i = 0; i < count; i++)
        {
            books[i] = _books[i];
        }
    }
       
    int getAllBooksByAuthor(string authorName,
        Book booksByAuthor[])
    {
        //in booksByAuthor we save the books we have found
        int currentIndex = 0;
 
        for (int i = 0; i < SIZE; i++)
        {
            if (!books[i].author.compare(authorName))
            {
                booksByAuthor[currentIndex] = books[i];
                currentIndex++;
            }
        }
 
        //we return the count of the found books
        return currentIndex
    }
};
 
int main()
{
    Book a("Carrie", "Stephen King", 1974, true);
    Book b("It", "Stephen King", 1981, true);
    Book c("Blood of the Elves", "Andrzej Sapkowsky", 1999, true);
    Book d("Peter Pan Must Die", "John Verdon", 2014, true);
    Book e("Robinson Cruzoe", "Daniel Defoe", 1687, true);
    Book f("Voynich Manuscript", "Unknown", 1413, false);
 
    Book books[] = { a, b, c, d, e, f };
 
    BooksList allBooks(books, 6);
 
    //book array to keep the result of getAllBooksByAuthor
    Book booksByAuthor[6];
    int bookCount = allBooks.getAllBooksByAuthor("Stephen King", booksByAuthor);
 
 
    for (int i = 0; i < bookCount; i++)
    {
        cout << booksByAuthor[i].title << endl;
    }
 
    system("pause");
    return 0;
}v