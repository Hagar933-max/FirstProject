#include <iostream>
#include <string>
#include <iomanip>  // لتنسيق العرض 
using namespace std;


struct Book {
    string title;
    string author;
    string status;  // "Available" or "Borrowed"
};
const int MAX_BOOKS = 100;//أقصى عدد كتب يخزن في المكتبة
Book books[MAX_BOOKS];
int bookCount = 0; 

// دالة لإضافة كتاب جديد
void add() {
    if (bookCount < MAX_BOOKS) {
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, books[bookCount].title);
        
        cout << "Enter author name: ";
        getline(cin, books[bookCount].author);

        books[bookCount].status = "Available";  // الحالة الافتراضية
        bookCount++;
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Library is full! Cannot add more books." << endl;
    }
}

// دالة للبحث عن كتاب حسب العنوان
void search() {
    if (bookCount == 0) {
        cout << "No books in the library!" << endl;
        return;
    }
    
    string title;
    cout << "Enter book title to search: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            cout << "\nBook found!" << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Status: " << books[i].status << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

// دالة لاستعارة كتاب
void borrow() {
    if (bookCount == 0) {
        cout << "No books in the library!" << endl;
        return;
    }
    
    string title;
    cout << "Enter book title to borrow: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            if (books[i].status == "Available") {
                books[i].status = "Borrowed";
                cout << "You have successfully borrowed the book: " << title << endl;
            } else {
                cout << "The book is already borrowed!" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

// دالة لإرجاع كتاب
void returnBook() {
    
    string title;
    cout << "Enter book title to return: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].title == title) {
            if (books[i].status == "Borrowed") {
                books[i].status = "Available";
                cout << "You have successfully returned the book: " << title << endl;
            } else {
                cout << "The book is already available!" << endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found!" << endl;
    }
}

// دالة لعرض جميع الكتب
void display() {
    if (bookCount == 0) {
        cout << "No books available in the library!" << endl;
    } else {
        // طباعة رأس الجدول
        cout << left << setw(5) << "No"        // عرض الرقم
             << setw(30) << "Title"            // عرض العنوان
             << setw(25) << "Author"           // عرض المؤلف
             << setw(15) << "Status"           // عرض الحالة
             << endl;

        // طباعة فاصل بين رأس الجدول والمحتوى
        cout << string(75, '-') << endl;

        // التكرار عبر المصفوفة وعرض الكتب
        for (int i = 0; i < bookCount; i++) {
            cout << left << setw(5) << i + 1                  // الرقم التسلسلي
                 << setw(30) << books[i].title               // العنوان
                 << setw(25) << books[i].author              // المؤلف
                 << setw(15) << books[i].status              // الحالة
                 << endl;
        }
        cout << "\nTotal books: " << bookCount << endl;
    }
}

// الدالة الرئيسية لعرض القائمة والاختيارات
int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Search for a Book by Title" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Display All Books" << endl;
        cout << "6. Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                borrow();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Exiting the system..." << endl;
                
                break;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 7." << endl;
        }
    } while (choice != 6);

    return 0;
}
