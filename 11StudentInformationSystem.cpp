#include <iostream>
using namespace std;

class book {
private:
    string title;
    string author;
    string isbn;
    bool available;
  public:
    void setTitle(string a) {
      title = a;
    }
    void setAuthor(string b) {
      author = b;
    }
    void setISBN(string c) {
      isbn = c;
    }
    void setAvailable(bool d) {
      available = d;
    }

    string getTitle() {
      return title;
    }
    string getAuthor() {
      return author;
    }
    string getISBN() {
      return isbn;
    }
    bool getAvailable() {
      return available;
    }

    bool borrowBook() {
      if (available == true) {
        available = false;
        return "Available set to false.";
      }
      else {
        return "The book has been checked out.";
      }
    }

    bool returnBook() {
      if (available = false) {
        available = true;
        return "Book removed from the library";
      }
      else {
        return "The book is already unavilable.";
      }
    }
};



int main(){
  const int maxLibraryCapacity = 100;
  book *arr = new book[maxLibraryCapacity];
  int numberBooks = 0;
  int choice;

  cout << "Welcome to the Library " << endl;
  cout << endl;

  while (true) {
    cout << "Menu:" << endl;
    cout << "1. Add book" << endl;
    cout << "2. Remove Book" << endl;
    cout << "3. Search for Book" << endl;
    cout << "4. Exit" << endl;
    cout << endl;

    string bookTitle;
    string bookAuthor;
    string bookISBN;
    book bookAvailable;

    cout << "Enter Your Choice: ";
    cin >> choice;
    if (1 <= choice && choice <= 4) {
      if (choice == 1) {
        if (numberBooks < maxLibraryCapacity){
            cout << "Enter Book Title: ";
          cin >> bookTitle;

          cout << "Enter Book ISBN: ";
          cin >> bookISBN;
        
          cout << "Book Added to Library." << endl;
        }
      }
      else if (choice == 4) {
        break;
      }
    }
    else {
      cout << "Please pick a number from the menu." << endl;
      cout << endl; 
    }
  }

  cout << "Thank You for Using the Library Management System!" << endl;
  return 0;
}
