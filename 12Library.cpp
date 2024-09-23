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
      if (!available) {
        available = true;
        cout << "Book removed from the library" << endl;
      }
      else {
        cout << "The book is already unavilable." << endl;
      }
    }
};

void removeBook(book arr[], int &size, int element) {
  for (int i = element; i < size - 1; ++i) {
      arr[i] = arr[i + 1];
  }
  --size;
  cout << "Book has been removed." << endl;
}



int main(){
  const int maxLibraryCapacity = 100;
  book books[maxLibraryCapacity];
  int numberBooks = 0;

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
    int element;
    string undo;
    
    int choice;
    cout << "Enter Your Choice: ";
    cin >> choice;

    if (choice == 1) {
      if (numberBooks < maxLibraryCapacity){
        cout << "Enter Book Title: ";
        cin >> bookTitle;

        cout << "Enter The book's Author: ";
        cin >> bookAuthor;

        cout << "Enter Book ISBN: ";
        cin >> bookISBN;

        books[numberBooks].setTitle(bookTitle);
        books[numberBooks].setAuthor(bookAuthor);
        books[numberBooks].setISBN(bookISBN);
        numberBooks++;
        cout << "Book Added Successfully" << endl;
      }
      else {
        cout << "Library is full. Can not add anymore books.";
      }
    }
    else if (choice == 2) {
      if (numberBooks > 0) {
        cout << "Enter the array index number of the book you want to delete: ";
        cin >> element;
        if (element >= 1 && element <= numberBooks) {
          removeBook(books, numberBooks, element -1);
        }
        else {
          cout << "Invalid Number. Please Try again" << endl;
        }
      }
      else {
        cout << "There are no books to remove. Please enter a book before trying to remove a book.";
      }
    }
    else if (choice == 3) {
      cout << "Enter the ISBN number: ";
      cin >> undo;
      bool find = false;
      for (int i = 0; i < numberBooks; i++) {
        if (undo == books[i].getISBN()) {
          find = true;
          cout << "Book found." << endl;
          cout << "Book title: " << books[i].getTitle() << endl;
          cout << "Author: " << books[i].getAuthor() << endl;
          cout << "ISBN: " << books[i].getISBN() << endl;
          cout << "Availability: " << books[i].getAvailable() << endl;
          break; 
        }
      }
      if (!find) {
        cout << "Book is not found in the library" << endl;
      }
    }
    else if (choice == 4) {
      break;
    }
    else {
      cout << "Please pick a number from the menu." << endl;
      cout << endl; 
    }
  }

  cout << "Thank You for Using the Library Management System!" << endl;
  return 0;
}
