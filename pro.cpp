#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct book {
    char name[30];
    char author[30];
    int id;
    book *next;
};

struct student {
    char name[30];
    char email[20];
    char book[20];
    char a[30];
    int id;
    student *next;
};

book *start_lib = nullptr;
student *start = nullptr;

book* initialize_lib(book *);
student* book_issue(student *);
student* book_return(student *);
book* display_lib(book *);
book* delete_book(int);
book* add_book(char [], char [], int);
void display(student *);
void greetings();
void main_menu();

int main() {
    start_lib = initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

void greetings() {
    cout << "\n\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\t\t\t     *                                      *\n";
    cout << "\t\t\t     *     WELCOME TO STUDENT LIBRARY       *\n";
    cout << "\t\t\t     ****************************************\n";
    cout << "\n\n";
    cout << "\t\t\t     Address: Mumbai, Maharashtra, India     \n";
    cout << "\t\t\t     Email: studentlib@gmail.com             \n";
    cout << "\t\t\t     Contact: 8800991010                    \n";
    cout << "\n\t\t\t             Press any key to continue: ";
    cin.get();
}

void main_menu() {
    int choice;
    do {
        cout << "\n\n";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      MAIN MENU: ";
        cout << "\n\t\t\t\t     1. ISSUE OF BOOKS ";
        cout << "\n\t\t\t\t     2. RETURN OF BOOKS ";
        cout << "\n\t\t\t\t     3. DISPLAY STUDENT DETAILS ";
        cout << "\n\t\t\t\t     4. EXIT\n ";
        cout << "\n\t\t\t*************************************************\n";
        cout << "\n\t\t\t\t      Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                start = book_issue(start);
                break;
            }
            case 2: {
                start = book_return(start);
                break;
            }
            case 3: {
                display(start);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                cout << "\n\t\t\t\t      ...Invalid Option!...\n";
                cout << "\n\t\t\t\t      Press any key to try again: ";
                cin.get();
                cin.get();
            }
        }
    } while (choice != 4);
}

book* initialize_lib(book *start) {
    book *ptr, *new_book1, *new_book2, *new_book3, *new_book4, *new_book5;

    new_book1 = new book();
    new_book1->next = nullptr;
    start_lib = new_book1;
    strcpy(new_book1->name, "The Kite Runner");
    strcpy(new_book1->author, "Khaled Hosseini");
    new_book1->id = 101;
    ptr = new_book1;

    new_book2 = new book();
    new_book2->next = nullptr;
    strcpy(new_book2->name, "To Kill A Mockingbird");
    strcpy(new_book2->author, "Harper Lee");
    new_book2->id = 102;
    ptr->next = new_book2;
    ptr = new_book2;

    new_book3 = new book();
    new_book3->next = nullptr;
    strcpy(new_book3->name, "The Alchemist");
    strcpy(new_book3->author, "Paulo Coelho");
    new_book3->id = 103;
    ptr->next = new_book3;
    ptr = new_book3;

    new_book4 = new book();
    new_book4->next = nullptr;
    strcpy(new_book4->name, "Pride And Prejudice");
    strcpy(new_book4->author, "Jane Austen");
    new_book4->id = 104;
    ptr->next = new_book4;
    ptr = new_book4;

    new_book5 = new book();
    new_book5->next = nullptr;
    strcpy(new_book5->name, "A Tale Of Two Cities");
    strcpy(new_book5->author, "Charles Dickens");
    new_book5->id = 105;
    ptr->next = new_book5;

    return start_lib;
}

student* book_issue(student *start) {
    book *ptr;
    student *ptr2, *new_student;
    int i = 1, id, flag = 0;
    if (start_lib == nullptr) {
        cout << "\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
    } else {
        system("cls");
        ptr = start_lib;
        cout << "\n\t*************** Books Available: ****************\n";
        while (ptr != nullptr) {
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Book " << i;
            cout << "\n\t Book Title: " << ptr->name;
            cout << "\n\t Name of Author: " << ptr->author;
            cout << "\n\t Book ID: " << ptr->id;
            cout << "\n\t_________________________________________________\n";
            ptr = ptr->next;
            i++;
        }
        cout << "\n\n\t Enter the Book ID: ";
        cin >> id;
        ptr = start_lib;
        while (ptr != nullptr) {
            if (ptr->id == id) {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 1) {
            ptr = start_lib;
            while (ptr->id != id) {
                ptr = ptr->next;
            }
            new_student = new student();
            cout << "\n\t Enter Student Details:\n ";
            cout << "\n\t Enter your Name: ";
            cin >> new_student->name;
            cout << "\n\t Enter your Email: ";
            cin >> new_student->email;
            strcpy(new_student->book, ptr->name);
            strcpy(new_student->a, ptr->author);
            new_student->id = ptr->id;
            new_student->next = nullptr;
            cout << "\n\t Issue of Book ID " << new_student->id << " done successfully!\n";
            cout << "\n\n\t*************************************************\n";
            if (start == nullptr) {
                start = new_student;
            } else {
                ptr2 = start;
                while (ptr2->next != nullptr) {
                    ptr2 = ptr2->next;
                }
                ptr2->next = new_student;
            }
            start_lib = delete_book(new_student->id);
            cout << "\n\n\t Press any key to go to the main menu: ";
            cin.get();
            cin.get();
            system("cls");
        } else {
            cout << "\n\t\t      ...Invalid Option!...\n";
            cout << "\n\t\t      Press any key to try again: ";
            cin.get();
            cin.get();
            system("cls");
        }
    }
    return start;
}

student* book_return(student *start) {
    student *ptr, *preptr;
    char bookname[30], authorname[30];
    int flag = 0, id, identity, c = 0, d = 1;
    cout << "\n\n\t*************** Books Submission: ****************\n";
    cout << "\n\n\t Enter your Book ID: ";
    cin >> identity;
    ptr = start;
    while (ptr != nullptr) {
        if (ptr->id == identity) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 1) {
        ptr = start;
        while (ptr != nullptr) {
            c++;
            ptr = ptr->next;
        }
        ptr = start;
        while (ptr->id != identity) {
            d++;
            ptr = ptr->next;
        }
        ptr = start;
        if (d == 1) {
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Student Name: " << start->name;
            cout << "\n\t Email: " << start->email;
            cout << "\n\t Book Issued: " << start->book;
            cout << "\n\t Author: " << start->a;
            cout << "\n\t Book ID: " << start->id;
            cout << "\n\t_________________________________________________\n";
            start = start->next;
        } else {
            while (ptr->id != identity) {
                preptr = ptr;
                ptr = ptr->next;
            }
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Student Name: " << ptr->name;
            cout << "\n\t Email: " << ptr->email;
            cout << "\n\t Book Issued: " << ptr->book;
            cout << "\n\t Author: " << ptr->a;
            cout << "\n\t Book ID: " << ptr->id;
            cout << "\n\t_________________________________________________\n";
            preptr->next = ptr->next;
        }
        cout << "\n\t Enter the Name of Book: ";
        cin >> bookname;
        cout << "\n\t Enter the Name of Author: ";
        cin >> authorname;
        cout << "\n\t Book Return successful!\n";
        start_lib = add_book(bookname, authorname, identity);
        cout << "\n\n\t*************************************************\n";
        cout << "\n\n\t Press any key to go to the main menu: ";
        cin.get();
        cin.get();
        system("cls");
    } else {
        cout << "\n\t\t      ...Invalid Option!...\n";
        cout << "\n\t\t      Press any key to try again: ";
        cin.get();
        cin.get();
        system("cls");
    }
    return start;
}

void display(student *start) {
    student *ptr;
    int i = 1;
    ptr = start;
    if (start == nullptr) {
        cout << "\n\t\t\t   ...No Records Found...\n";
        cout << "\n\t\t\t   Press any key to continue: ";
        cin.get();
        cin.get();
        system("cls");
    } else {
        cout << "\n\n\t*************** Details of Students: ****************\n";
        while (ptr != nullptr) {
            cout << "\n\t_________________________________________________\n";
            cout << "\n\t Record " << i;
            cout << "\n\t Student Name: " << ptr->name;
            cout << "\n\t Email: " << ptr->email;
            cout << "\n\t Book Issued: " << ptr->book;
            cout << "\n\t Author: " << ptr->a;
            cout << "\n\t Book ID: " << ptr->id;
            cout << "\n\t_________________________________________________\n";
            ptr = ptr->next;
            i++;
        }
        cout << "\n\n\t*************************************************\n";
        cout << "\n\n\t Press any key to go to the main menu: ";
        cin.get();
        cin.get();
        system("cls");
    }
}

book* add_book(char name[30], char author[30], int id) {
    book *new_book, *ptr;
    new_book = new book();
    strcpy(new_book->name, name);
    strcpy(new_book->author, author);
    new_book->id = id;
    new_book->next = nullptr;
    if (start_lib == nullptr) {
        start_lib = new_book;
    } else {
        ptr = start_lib;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new_book;
    }
    return start_lib;
}

book* delete_book(int id) {
    book *ptr, *preptr;
    ptr = start_lib;
    if (ptr->id == id) {
        start_lib = start_lib->next;
    } else {
        while (ptr->id != id) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
    }
    return start_lib;
}
