#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void entry() {
  string user, pass, studentNum;
  // Account sign-up/login`
  cout << "Hello and welcome to our booking system! To sign up input 'register' "
          "Existing users type 'login' and To exit at any time input 'exit' ";
  string action;
  // Vector to store the usernames and passwords
  vector<string> usernames;
  vector<string> passwords;
  /* Checks to see whether you are logging in or registering. Pushes the
   * username and password into the vector if registering. If logging in,
   * program, checks if the username and password match to the values in the
   * vector.*/
  cin >> action;
  if (action == "exit") {
    cout << "Thank you for using our program. if you'd like to try again, "
            "please re-run the program!";
    exit(0);
  }
  if (action == "register") {
    cout << endl;
    cout << "Please enter the student number that your account will be "
            "associated with: "
         << endl;

    // Asks for student number, new username and password
    cin >> studentNum;
    if (studentNum == "exit") {
      cout << "Thank you for using our program. if you'd like to try again, "
              "please re-run the program!";
      exit(0);
    }
    cout << endl;
    cout << "Please enter the username you would like to use for our system "
            "(no spaces): ";
    cin >> user;
    if (user == "exit") {
      cout << "Thank you for using our program. if you'd like to try again, "
              "please re-run the program!";
      exit(0);
    }
    usernames.push_back(user);
    cout << "Please enter your password: ";
    cin >> pass;
    if (pass == "exit") {
      cout << "Thank you for using our program. if you'd like to try again, "
              "please re-run the program!";
      exit(0);
    }
    passwords.push_back(pass);
    cout << endl;
    cout << "Now that you have made an account, please log in to the account."
         << endl;
    cout << endl;
    cout << "Username: ";
    cin >> user;
    if (user == "exit") {
      cout << "Thank you for using our program. if you'd like to try again, "
              "please re-run the program!";
      exit(0);
    }
    cout << "Password: ";
    cin >> pass;
    if (pass == "exit") {
      cout << "Thank you for using our program. if you'd like to try again, "
              "please re-run the program!";
      exit(0);
    }
    /* If statement makes sure that the user can try again infinitely incase they
     * input the wrong username or password */
    if (usernames[0] == user && passwords[0] == pass) {
      cout << "SUCCESSFUL LOGIN: You are now logged in as: " << user << endl
           << endl
           << endl;
      cout << endl;
    } else if (usernames[0] != user) {
      cout << "This account does not exist. ";
      bool flag = true;
      while (flag) {
        cout << "Try again for username: ";
        cin >> user;
        if (user == "exit") {
          cout << "Thank you for using our program. if you'd like to try "
                  "again, please re-run the program!";
          exit(0);
        }
        if (user == usernames[0]) {
          bool fflag = true;
          cout << "Please input your password: ";
          while (flag) {
            cin >> pass;
            if (pass == "exit") {
              cout << "Thank you for using our program. if you'd like to try "
                      "again, please re-run the program!";
              exit(0);
            }
            if (pass == passwords[0]) {
              cout << endl;
              cout << "SUCCESSFUL LOGIN You are now logged in as: " << user
                   << endl;
              cout << endl;
              fflag = false;
              flag = false;
            } else {
              cout << "Wrong password. Try again: ";
            }
          }
        }
      }
    } else if (usernames[0] == user && passwords[0] != pass) {
      bool flag = true;
      while (flag) {
        cout << "The password is incorrect. Please try again: ";
        cin >> pass;
        if (pass == "exit") {
          cout << "Thank you for using our program. if you'd like to try "
                  "again, please re-run the program!";
          exit(0);
        }
        if (pass == passwords[0]) {
          cout << "SUCCESSFUL LOGIN: You are now logged in as: " << user
               << endl;
          flag = false;
        }
      }
    }
  } else if (action == "login") {
    cout << endl;
    if (usernames.size() == 0) {
      // If no accounts exist, automatically registers
      cout << "Sorry, it looks like there are no accounts in our system yet, "
              "please create a "
              "new one.\n";
      cout << endl;
      // Account is created with student number, username, and password
      cout << "Please enter your student number that your account will be "
              "associated with: ";
      cin >> studentNum;
      if (studentNum == "exit") {
        cout << "Thank you for using our program. if you'd like to try again, "
                "please re-run the program!";
        exit(0);
      }
      cout << endl;
      cout << "Please enter the username you would like to use for our system "
              "(no spaces): ";
      cin >> user;
      if (user == "exit") {
        cout << "Thank you for using our program. if you'd like to try again, "
                "please re-run the program!";
        exit(0);
      }
      usernames.push_back(user);
      cout << "Please enter your password: ";
      cin >> pass;
      if (pass == "exit") {
        cout << "Thank you for using our program. if you'd like to try again, "
                "please re-run the program!";
        exit(0);
      }
      cout << endl;
      passwords.push_back(pass);
      // Prompts user for Username and Password
      cout << "Now that you have made an account, please log in to the account."
           << endl;
      cout << "Username: ";
      cin >> user;
      if (user == "exit") {
        cout << "Thank you for using our program. if you'd like to try again, "
                "please re-run the program!";
        exit(0);
      }
      cout << "Password: ";
      cin >> pass;
      if (pass == "exit") {
        cout << "Thank you for using our program. if you'd like to try again, "
                "please re-run the program!";
        exit(0);
      }
      /* Makes sure the username and password exist within the vector and allows
       * user to mess up as many times as possible */
      if (usernames[0] == user && passwords[0] == pass) {
        cout << "SUCCESSFUL LOGIN: You are now logged in as: " << user << endl;
        cout << endl;
      } else if (usernames[0] == user && passwords[0] != pass) {
        cout << "The password is incorrect. Please try again: ";
        bool flag = true;
        while (flag) {
          cout << "The password is incorrect. Please try again: ";
          cin >> pass;
          if (pass == "exit") {
            cout << "Thank you for using our program. if you'd like to try "
                    "again, please re-run the program!";
            exit(0);
          }
          if (pass == passwords[0]) {
            cout << "SUCCESSFUL LOGIN: You are now logged in as: " << user
                 << endl;
            flag = false;
          }
        }
      } else if (usernames[0] != user) {
        cout << "This account does not exist. Please re-check the username "
                "that you typed. ";
        bool flag = true;
        while (flag) {
          cout << "Try again. Username: ";
          cin >> user;
          if (user == "exit") {
            cout << "Thank you for using our program. if you'd like to try "
                    "again, please re-run the program!";
            exit(0);
          }
          if (user == usernames[0]) {
            bool flag2 = true;
            while (flag2) {
              cout << "Wrong password. Try again. Password: ";
              cin >> pass;
              if (pass == "exit") {
                cout << "Thank you for using our program. if you'd like to try "
                        "again, please re-run the program!";
                exit(0);
              }
              if (pass == passwords[0]) {
                cout << "SUCCESSFUL LOGIN! You are now logged in as " << user
                     << endl;
                flag2 = false;
              }
            }
          }
        }
      }
    }
  }
}
// A struct to represent a book
struct Book {
    int id;
    string title;
    string author;
    string publicationDate;
    bool isAvailable;
};

// A struct to represent a user
struct User {
    int id;
    string name;
    string password;
    vector<Book> booksBorrowed;
};

// A class to represent the library
class Library {
private:
    vector<Book> books;
    vector<User> users;
    int bookCount = 0;
    int userCount = 0;
public:
    // Register a new user
    void registerUser() {
        string name, password;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter a password: ";
        getline(cin, password);
        User user;
        user.id = ++userCount;
        user.name = name;
        user.password = password;
        users.push_back(user);
        cout << "User registered successfully." << endl;
    }

    // Register a new book
    void registerBook() {
        string title, author, publicationDate;
        cout << "Enter the title of the book: ";
        getline(cin, title);
        cout << "Enter the name of the author: ";
        getline(cin, author);
        cout << "Enter the publication date (DD/MM/YYYY): ";
        getline(cin, publicationDate);
        Book book;
        book.id = ++bookCount;
        book.title = title;
        book.author = author;
        book.publicationDate = publicationDate;
        book.isAvailable = true;
        books.push_back(book);
        cout << "Book registered successfully." << endl;
    }

    // Search for a book by title or author
    void searchBook() {
        string searchTerm;
        cout << "Enter the title or author to search for: ";
        getline(cin, searchTerm);
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == searchTerm || books[i].author == searchTerm) {
                cout << "Book found! Title: " << books[i].title << ", Author: " << books[i].author << endl;
                return;
            }
        }
        cout << "No book found with that title or author." << endl;
    }

    // Issue a book to a user
    void issueBook() {
        int bookId, userId, daysToReturn;
        cout << "Enter the book ID: ";
        cin >> bookId;
        cout << "Enter the user ID: ";
        cin >> userId;
        cout << "Enter the number of days to return: ";
        cin >> daysToReturn;
        cin.ignore(); // ignore newline character
        time_t now = time(0);
        tm* ltm = localtime(&now);
        string issueDate = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == bookId && books[i].isAvailable) {
                for (int j = 0; j < users.size(); j++) {
                    if (users[j].id == userId) {
                        books[i].isAvailable = false;
                        users[j].booksBorrowed.push_back(books[i]);
                        cout << "Book issued to user " << users[j].name << " on " << issueDate << ", to be returned in " << daysToReturn << " days." << endl;

// daysToReturn days." << endl;
return;
}
}
}
}
cout << "Book not available or user not found." << endl;
}
int roombooking() {

  // declaring the arrays which are being used to store  numbers for timeslots

  int greenScreen[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int adaptiveLab[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int studyRooms[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int meetingRooms[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  int chromebookCheckout[19] = {0,  1,  2,  3,  4,  5,  6,  7,  8, 9,
                                10, 11, 12, 13, 14, 15, 16, 17, 18};
  vector<int> arr;
  vector<int> blacklist;
  // delcaring variables for user inputs, such as timeslot number, name, etc.

  int roomChoice = 0;
  int timeSlot = 0;
  int studentNumber = 0;
  int labPin = 0;
  int reOrient = 0;
  int meetingRoomPin = 0;
  int counter = 0;
  int fault = 0;
  string name;
  string choice;

pMainMenu: // used a pointer here so that the user is able to return back to the main menu tab

  // Displaying the "main menu" of the program giving users the hours of
  // operations and basic information:

  cout << "            *Welcome to the Activity Rooms Booking*\n\n";
  cout << "Hours of Operations:" << endl;
  cout << "Monday            8:30 a.m.    -    3:00 p.m.\n";
  cout << "Tuesday           8:30 a.m.    -    3:00 p.m.\n";
  cout << "Wednesday         8:30 a.m.    -    3:00 p.m.\n";
  cout << "Thursday          8:30 a.m.    -    3:00 p.m.\n";
  cout << "Friday            8:30 a.m.    -    3:00 p.m.\n";

  // Availible timings of operations for bookings

  cout << "\nWhat would you like to book?" << endl;
  cout << "1. Green Screen Room" << endl;
  cout << "2. Lab Room" << endl;
  cout << "3. Study Rooms" << endl;
  cout << "4. Meeting Rooms" << endl;
  cout << "5. Chromebook checkout" << endl << endl;
  cout << "Enter your choice: ";
  cin >> roomChoice;

  // This here request a user to pick a number according to their liking for booking a prefered room of their choice. 

  //For example: If they pick number 4 this brings up the meeting rooms tab
  if (roomChoice == 1) {

    cout << "\033[2J\033[0;0H";
    cout << "This is the green screen room booking page. Please select which "
            "timeslot you would like to book using the reference number. \n"
         << endl;

  // Here, all the time slots which can be booked are shown to the user
  pTimeSlots:
    cout << "Reference#"
         << "\t"
         << "Time Slot" << endl;

    cout << "1"
         << "\t\t\t"
         << "8:00   -  9:00"
         << "\t\t" << endl;
    cout << "2"
         << "\t\t\t"
         << "9:00   -  10:00"
         << "\t\t" << endl;
    cout << "3"
         << "\t\t\t"
         << "10:00  -  11:00"
         << "\t\t" << endl;
    cout << "4"
         << "\t\t\t"
         << "11:00  -  12:00"
         << "\t\t" << endl;
    cout << "5"
         << "\t\t\t"
         << "12:00  -  1:00"
         << "\t\t" << endl;
    cout << "6"
         << "\t\t\t"
         << "1:00   -  2:00"
         << "\t\t" << endl;
    cout << "7"
         << "\t\t\t"
         << "2:00   -  3:00"
         << "\t\t" << endl
         << endl;

    // The users input is being taken here
    cout << "Reference Number for the Timeslot: ";
    cin >> timeSlot;

    // This if statement is for confirming the booking, ther users is asked to
    // confirm their preference, or to decline the booking

    if (timeSlot == greenScreen[timeSlot]) {
      cout << "This timeslot is avaialbe for booking. Would you like to book "
              "it? (Y/N)"
           << endl;
      cin >> choice;

      if ((choice == "Y") || (choice == "y")) {
      } else {
        goto pTimeSlots;
      }

      // Asking user for the contact ionformation for the booking
      cout << "Please enter your name: ";
      cin >> name;

      cout << "Please enter your student number: ";
      cin >> studentNumber;
      cout << endl;
      // Adding the student number into a vector because its a dynamic array
      // allowing elements to be added to it
      arr.push_back(studentNumber);

      // This for loop is to check whether an user has more than 3 hours booked
      int i;
      counter = 0;
      for (i = 0; i < arr.size(); i++) {
        if (studentNumber == arr[i]) {
          counter = counter + 1;
          if (counter > 3) {
            blacklist.push_back(arr[i]);
            counter = 0;
          }
        }
      }

      for (int j = 0; j < blacklist.size(); j++) {
        if (studentNumber == blacklist[j]) {
          fault = fault + 2;
        }
      }

      // In this if statement we are telling the user that they can not book
      // more slots if they have alreaady booked 3 hours

      if (fault > 1) {
        fault = 0;
        cout << "\033[2J\033[0;0H";
        cout << "You have reached your booking limit of 3 hours. You will be "
                "redirected to the main menu now."
             << endl
             << endl;
        goto pMainMenu;
      } else {

        greenScreen[timeSlot] = 0;

        cout << "Your booking is successfull!" << endl << endl;
        cout << "Please follow the rules that are listed below:" << endl;
        cout << "1. Please ensure you have a minimum of 2 people." << endl;
        cout << "2. Food and drinks are strictly prohibited" << endl;
        cout << "3. Max booking of 3 hours." << endl;
        cout << "4. You can not switch this booking. If it is an emergency "
                "contact one of the librarians"
             << endl
             << endl;

        // After the user is done booking they are asked what they would like to
        // do next
        cout << "What would you like to do? " << endl;
        cout << "1. Book another timeslot" << endl;
        cout << "2. Return to main menu" << endl;
        cout << "3. End the program" << endl;
        cout << "Enter your choice: ";
        cin >> reOrient;

        // After they make their choice the program will go to that part of the
        // program
        if (reOrient == 1) {
          cout << "\033[2J\033[0;0H";
          goto pTimeSlots;
        } else if (reOrient == 2) {
          cout << "\033[2J\033[0;0H";
          goto pMainMenu;
        } else {
          cout << "\033[2J\033[0;0H";
          goto pEnd;
        }
      }

    } else {

      cout << endl
           << "This timeslot is already booked :(. What would you like to do?"
           << endl
           << endl;

      // The user is asked what they would like to do next
      cout << "1. Book another timeslot" << endl;
      cout << "2. Return to main menu" << endl;
      cout << "3. End the program" << endl;
      cout << "Enter your choice: ";
      cin >> reOrient;

      // After they make their choice the program will go to that part of the
      // program
      if (reOrient == 1) {
        cout << "\033[2J\033[0;0H";
        goto pTimeSlots;
      } else if (reOrient == 2) {
        cout << "\033[2J\033[0;0H";
        goto pMainMenu;
      } else {
        cout << "\033[2J\033[0;0H";
        goto pEnd;
      }
    }
  }

  // If the user enters 2 as their room choice, an if statement will be true
  // and all the contents inside will run:

  if (roomChoice == 2) {

  pLab:

    cout << "Please enter your PIN: ";
    cin >> labPin;

    if (labPin == 2005) {

      cout << "\033[2J\033[0;0H";
      cout << "This is the adaptive lab booking page. Please select which "
              "timeslot you would like to book using the reference number. \n"
           << endl;

    pTimeSlots2:

      cout << "Reference#"
           << "\t"
           << "Time Slot" << endl;

      cout << "1"
           << "\t\t\t"
           << "8:00   -  9:00"
           << "\t\t" << endl;
      cout << "2"
           << "\t\t\t"
           << "9:00   -  10:00"
           << "\t\t" << endl;
      cout << "3"
           << "\t\t\t"
           << "10:00  -  11:00"
           << "\t\t" << endl;
      cout << "4"
           << "\t\t\t"
           << "11:00  -  12:00"
           << "\t\t" << endl;
      cout << "5"
           << "\t\t\t"
           << "12:00  -  1:00"
           << "\t\t" << endl;
      cout << "6"
           << "\t\t\t"
           << "1:00   -  2:00"
           << "\t\t" << endl;
      cout << "7"
           << "\t\t\t"
           << "2:00   -  3:00"
           << "\t\t" << endl
           << endl;

      cout << "Reference Number for the Timeslot: ";
      cin >> timeSlot;

      // this is to check the array to see whether the requested time slot is
      // available
      if (timeSlot == adaptiveLab[timeSlot]) {
        cout << "This timeslot is avaialbe for booking. Would you like to "
                "book "
                "it? (Y/N)"
             << endl;
        cin >> choice;

        // This if statement is for confirming the booking, ther users is asked
        // to confirm their preference, or to decline the booking
        if ((choice == "Y") || (choice == "y")) {

          cout << "Please enter your name: ";
          cin >> name;

          cout << "Please enter your student number: ";
          cin >> studentNumber;
          cout << endl;
          arr.push_back(studentNumber);

          // This for loop is to check whether an user has more than 3 hours
          // booked

          int i;
          counter = 0;
          for (i = 0; i < arr.size(); i++) {
            if (studentNumber == arr[i]) {
              counter = counter + 1;
              if (counter > 3) {
                blacklist.push_back(arr[i]);
                counter = 0;
              }
            }
          }

          for (int j = 0; j < blacklist.size(); j++) {
            if (studentNumber == blacklist[j]) {
              fault = fault + 2;
            }
          }

          if (fault > 1) {
            fault = 0;
            cout << "\033[2J\033[0;0H";
            cout << "You have reached your booking limit of 3 hours. You will "
                    "be redirected to the main menu now."
                 << endl
                 << endl;
            goto pMainMenu;
          } else {

            adaptiveLab[timeSlot] = 0;

            cout << "Your booking is successfull!" << endl << endl;

            // Giving user options of what to do next
            cout << "What would you like to do? " << endl;
            cout << "1. Book another timeslot" << endl;
            cout << "2. Return to main menu" << endl;
            cout << "3. End the program" << endl;
            cout << "Enter your choice: ";
            cin >> reOrient;

            if (reOrient == 1) {
              cout << "\033[2J\033[0;0H";
              goto pTimeSlots;
            } else if (reOrient == 2) {
              cout << "\033[2J\033[0;0H";
              goto pMainMenu;
            } else {
              cout << "\033[2J\033[0;0H";
              goto pEnd;
            }
          }
        } else {

          cout << endl
               << "This timeslot is already booked :(. What would you like to "
                  "do?"
               << endl
               << endl;
          cout << "1. Book another timeslot" << endl;
          cout << "2. Return to main menu" << endl;
          cout << "3. End the program" << endl;
          cout << "Enter your choice: ";
          cin >> reOrient;

          if (reOrient == 1) {
            cout << "\033[2J\033[0;0H";
            goto pTimeSlots2;
          } else if (reOrient == 2) {
            cout << "\033[2J\033[0;0H";
            goto pMainMenu;
          } else {
            cout << "\033[2J\033[0;0H";
            goto pEnd;
          }
        }
      } else {

        cout << "Please enter a valid pin" << endl;
        cout << "Enter 1 to enter the pin again." << endl;
        cout << "Enter 2 to go to the main menu. " << endl;
        cin >> reOrient;

        if (reOrient == 1) {
          goto pLab;
        } else if (reOrient == 2) {
          cout << "\033[2J\033[0;0H";
          goto pMainMenu;
        }
      }
    } else {
      cout << "You have entered the wrong pin: " << endl;
      goto pLab;
    }
  }

  // If the user enters 3 as their room choice, an if statement will be true
  // and all the contents inside will run run:

  if (roomChoice == 3) {

    cout << "\033[2J\033[0;0H";
    cout << "This is the study room booking page. Please select which "
            "timeslot you would like to book using the reference number. \n"
         << endl;

  pTimeSlots3:
    cout << "Reference#"
         << "\t"
         << "Time Slot" << endl;

    cout << "1"
         << "\t\t\t"
         << "8:00   -  9:00"
         << "\t\t" << endl;
    cout << "2"
         << "\t\t\t"
         << "9:00   -  10:00"
         << "\t\t" << endl;
    cout << "3"
         << "\t\t\t"
         << "10:00  -  11:00"
         << "\t\t" << endl;
    cout << "4"
         << "\t\t\t"
         << "11:00  -  12:00"
         << "\t\t" << endl;
    cout << "5"
         << "\t\t\t"
         << "12:00  -  1:00"
         << "\t\t" << endl;
    cout << "6"
         << "\t\t\t"
         << "1:00   -  2:00"
         << "\t\t" << endl;
    cout << "7"
         << "\t\t\t"
         << "2:00   -  3:00"
         << "\t\t" << endl
         << endl;

    cout << "Reference Number for the Timeslot: ";
    cin >> timeSlot;

    if (timeSlot == studyRooms[timeSlot]) {
      cout << "This timeslot is avaialbe for booking. Would you like to book "
              "it? (Y/N)"
           << endl;
      cin >> choice;

      if ((choice == "Y") || (choice == "y")) {

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter your student number: ";
        cin >> studentNumber;
        cout << endl;
        arr.push_back(studentNumber);

        // This for loop is to check whether an user has more than 3 hours
        // booked

        int i;
        counter = 0;
        for (i = 0; i < arr.size(); i++) {
          if (studentNumber == arr[i]) {
            counter = counter + 1;
            if (counter > 3) {
              blacklist.push_back(arr[i]);
              counter = 0;
            }
          }
        }

        for (int j = 0; j < blacklist.size(); j++) {
          if (studentNumber == blacklist[j]) {
            fault = fault + 2;
          }
        }

        if (fault > 1) {
          fault = 0;
          cout << "\033[2J\033[0;0H";
          cout << "You have reached your booking limit of 3 hours. You will "
                  "be redirected to the main menu now."
               << endl
               << endl;
          goto pMainMenu;
        } else {

          studyRooms[timeSlot] = 0;

          cout << "Your booking is successfull!" << endl << endl;
          cout << "Please follow the rules that are listed below:" << endl;
          cout << "1. Please ensure you have a minimum of 2 people." << endl;
          cout << "2. Food and drinks are strictly prohibited" << endl;
          cout << "3. Max booking of 3 hours." << endl;
          cout << "4. You can not switch this booking. If it is an emergency "
                  "contact one of the librarians"
               << endl
               << endl;

          cout << "What would you like to do? " << endl;
          cout << "1. Book another timeslot" << endl;
          cout << "2. Return to main menu" << endl;
          cout << "3. End the program" << endl;
          cout << "Enter your choice: ";
          cin >> reOrient;

          if (reOrient == 1) {
            cout << "\033[2J\033[0;0H";
            goto pTimeSlots;
          } else if (reOrient == 2) {
            cout << "\033[2J\033[0;0H";
            goto pMainMenu;
          } else {
            cout << "\033[2J\033[0;0H";
            goto pEnd;
          }
        }
      } else {

        cout << endl
             << "This timeslot is already booked :(. What would you like to "
                "do?"
             << endl
             << endl;
        cout << "1. Book another timeslot" << endl;
        cout << "2. Return to main menu" << endl;
        cout << "3. End the program" << endl;
        cout << "Enter your choice: ";
        cin >> reOrient;

        if (reOrient == 1) {
          cout << "\033[2J\033[0;0H";
          goto pTimeSlots3;
        } else if (reOrient == 2) {
          cout << "\033[2J\033[0;0H";
          goto pMainMenu;
        } else {
          cout << "\033[2J\033[0;0H";
          goto pEnd;
        }
      }
    }
  }

  // If the user enters 4 as their room choice, an if statement will be true
  // and all the contents inside will run run:

  if (roomChoice == 4) {

  pMeetingRoomRedirction:

    cout << endl << "This room is only avaliable for club meetings.";
    cout << "You need enter a designated pin that are given to club "
            "presidents and executives."
         << endl;
    cout << endl << "Enter your PIN:  ";
    cin >> meetingRoomPin;

    if (meetingRoomPin == 1945) {

      cout << "\033[2J\033[0;0H";
      cout << "Welcome to the meeting room booking page. Please select "
              "which "
              "timeslot you would like to book using the reference number. "
              " ";
      cout << endl << endl;

    pTimeSlots4:

      cout << "Reference#"
           << "\t"
           << "Time Slot" << endl;

      cout << "1"
           << "\t\t\t"
           << "8:00   -  9:00"
           << "\t\t" << endl;
      cout << "2"
           << "\t\t\t"
           << "9:00   -  10:00"
           << "\t\t" << endl;
      cout << "3"
           << "\t\t\t"
           << "10:00  -  11:00"
           << "\t\t" << endl;
      cout << "4"
           << "\t\t\t"
           << "11:00  -  12:00"
           << "\t\t" << endl;
      cout << "5"
           << "\t\t\t"
           << "12:00  -  1:00"
           << "\t\t" << endl;
      cout << "6"
           << "\t\t\t"
           << "1:00   -  2:00"
           << "\t\t" << endl;
      cout << "7"
           << "\t\t\t"
           << "2:00   -  3:00"
           << "\t\t" << endl
           << endl;

      cout << "Reference Number for the Timeslot: ";
      cin >> timeSlot;

      if (timeSlot == meetingRooms[timeSlot]) {
        cout << "This timeslot is avaialbe for booking. Would you like to "
                "book "
                "it? (Y/N)"
             << endl;
        cin >> choice;

        if ((choice == "Y") || (choice == "y")) {

          cout << "Please enter your name: ";
          cin >> name;

          cout << "Please enter your student number: ";
          cin >> studentNumber;
          cout << endl;
          arr.push_back(studentNumber);

          // This for loop is to check whether an user has more than 3 hours
          // booked

          int i;
          counter = 0;
          for (i = 0; i < arr.size(); i++) {
            if (studentNumber == arr[i]) {
              counter = counter + 1;
              if (counter > 3) {
                blacklist.push_back(arr[i]);
                counter = 0;
              }
            }
          }

          for (int j = 0; j < blacklist.size(); j++) {
            if (studentNumber == blacklist[j]) {
              fault = fault + 2;
            }
          }

          // Checking if students have booked more than 3 hours, if so it does
          // not allow them to book more
          if (fault > 1) {
            fault = 0;
            cout << "\033[2J\033[0;0H";
            cout << "You have reached your booking limit of 3 hours. You "
                    "will be redirected to the main menu now."
                 << endl
                 << endl;
            goto pMainMenu;
          } else {

            meetingRooms[timeSlot] = 0;

            cout << "Your booking is successfull!" << endl << endl;

            cout << "What would you like to do? " << endl;
            cout << "1. Book another timeslot" << endl;
            cout << "2. Return to main menu" << endl;
            cout << "3. End the program" << endl;
            cout << "Enter your choice: ";
            cin >> reOrient;

            if (reOrient == 1) {
              cout << "\033[2J\033[0;0H";
              goto pTimeSlots;
            } else if (reOrient == 2) {
              cout << "\033[2J\033[0;0H";
              goto pMainMenu;
            } else {
              cout << "\033[2J\033[0;0H";
              goto pEnd;
            }
          }
        } else {

          cout << endl
               << "This timeslot is already booked :(. What would you like "
                  "to "
                  "do?"
               << endl
               << endl;
          cout << "1. Book another timeslot" << endl;
          cout << "2. Return to main menu" << endl;
          cout << "3. End the program" << endl;
          cout << "Enter your choice: ";
          cin >> reOrient;

          if (reOrient == 1) {
            cout << "\033[2J\033[0;0H";
            goto pTimeSlots;
          } else if (reOrient == 2) {
            cout << "\033[2J\033[0;0H";
            goto pMainMenu;
          } else {
            cout << "\033[2J\033[0;0H";
            goto pEnd;
          }
        }
      } else {

        cout << "Please enter a valid pin" << endl;
        cout << "Enter 1 to enter the pin again." << endl;
        cout << "Enter 2 to go to the main menu. " << endl;
        cin >> reOrient;

        if (reOrient == 1) {
          goto pMeetingRoomRedirction;
        } else if (reOrient == 2) {
          cout << "\033[2J\033[0;0H";
          goto pMainMenu;
        }
      }
    }
  }

  // If user picks option 5, the program goes to chromebook checkout

  if (roomChoice == 5) {

    // the user is welcomed to the page and given available opltion
    cout << "\033[2J\033[0;0H";
    cout << "Welcome to the chromebook checkout page. Below are listed "
            "the "
            "avaliable chromebook and their serial numbers. ";
    cout << endl << endl;

  pChromebook:

    // Displaying all the chromebooks (model, serial number)
    cout << "Reference#"
         << "\t"
         << "Time Slot"
         << "\t\t\t\t\t\t"
         << "Serial Number" << endl;

    cout << "1"
         << "\t\t\t"
         << "Acer Chromebook 314"
         << "\t\t\t\t"
         << "IPQI7TV6CXZVSR9XFV0U" << endl;
    cout << "2"
         << "\t\t\t"
         << "Acer Chromebook 314"
         << "\t\t\t\t"
         << "MFP77J9S809P8VXQ0SSI" << endl;
    cout << "3"
         << "\t\t\t"
         << "Acer Chromebook 314"
         << "\t\t\t\t"
         << "Z3WAMH9X5S3PU0IRZV93" << endl;
    cout << "4"
         << "\t\t\t"
         << "Acer Chromebook 314"
         << "\t\t\t\t"
         << "IEYZUPFS7WWEA2WK0OFR" << endl;
    cout << "5"
         << "\t\t\t"
         << "Acer Chromebook 314"
         << "\t\t\t\t"
         << "ARBZU31FAADMINBS93E4" << endl;
    cout << "6"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "P9Y3QB114STCTSFZFEJI" << endl;
    cout << "7"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "WAWKVONLAZ9FG81J4NIV" << endl;
    cout << "9"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "VXN1KWRMDHVI51JHSQM9" << endl;
    cout << "10"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "22LG95065XBZ1QG6ZVFM" << endl;
    cout << "11"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "EVHHTH62KNPJDWHEUU6S" << endl;
    cout << "12"
         << "\t\t\t"
         << "Acer Chromebook Spin 713"
         << "\t\t"
         << "AGDU9HN0S7TXL30K5ZLR" << endl;
    cout << "13"
         << "\t\t\t"
         << "Acer Chromebook 714"
         << "\t\t\t\t"
         << "WXK1E8H4W51EKH4MQDW6" << endl;
    cout << "14"
         << "\t\t\t"
         << "Acer Chromebook 714"
         << "\t\t\t\t"
         << "M7IPNX9JKP27G7AA2YQJ" << endl;
    cout << "15"
         << "\t\t\t"
         << "Acer Chromebook 714"
         << "\t\t\t\t"
         << "WM609AHMDEVXP1F8J50A" << endl;
    cout << "16"
         << "\t\t\t"
         << "Acer Chromebook 714"
         << "\t\t\t\t"
         << "HU6MHOM1H95L8FD36HZG" << endl;
    cout << "17"
         << "\t\t\t"
         << "Acer Chromebook 714"
         << "\t\t\t\t"
         << "IEYZUPFS7WWEA2WK0OFR" << endl;
    cout << "18"
         << "\t\t\t"
         << "Asus Chromebook Flip C436"
         << "\t\t"
         << "V6HCXFW8BMXOSF7BUNI7" << endl
         << endl;

    cout << "Reference Number for the Chromebook: ";
    cin >> timeSlot;

    if (timeSlot == chromebookCheckout[timeSlot]) {
      cout << "This chromebook is avaliable for checkout. Would you like "
              "to "
              "check it out? "
              "it? (Y/N)"
           << endl;
      cin >> choice;

      if ((choice == "Y") || (choice == "y")) {
        chromebookCheckout[timeSlot] = 0;

        cout << "Please enter your name: ";
        cin >> name;

        cout << "Please enter your student number: ";
        cin >> studentNumber;
        cout << endl;

        cout << "What would you like to do? " << endl;
        cout << "1. Book another chromebook" << endl;
        cout << "2. Return to main menu" << endl;
        cout << "3. End the program" << endl;
        cout << "Enter your choice: ";
        cin >> reOrient;

        if (reOrient == 1) {
          cout << "\033[2J\033[0;0H";
          goto pChromebook;
        } else if (reOrient == 2) {
          cout << "\033[2J\033[0;0H";
          goto pMainMenu;
        } else {
          cout << "\033[2J\033[0;0H";
          goto pEnd;
        }

      } else {
        goto pChromebook;
      }

    } else {

      cout << endl
           << "This chromebook is already booked :(. What would you like "
              "to "
              "do?"
           << endl
           << endl;
      cout << "1. Book another chromebook" << endl;
      cout << "2. Return to main menu" << endl;
      cout << "3. End the program" << endl;
      cout << "Enter your choice: ";
      cin >> reOrient;

      if (reOrient == 1) {
        cout << "\033[2J\033[0;0H";
        goto pChromebook;
      } else if (reOrient == 2) {
        cout << "\033[2J\033[0;0H";
        goto pMainMenu;
      } else {
        cout << "\033[2J\033[0;0H";
        goto pEnd;
      }
    }
  }

pEnd:
  cout << "Thank you for using the booking system!!";

}
// Return a book from a user
void returnBook() {
    int bookId, userId;
    cout << "Enter the book ID: ";
    cin >> bookId;
    cout << "Enter the user ID: ";
    cin >> userId;
    cin.ignore(); // ignore newline character
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string returnDate = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
    for (int i = 0; i < books.size(); i++) {
        if (books[i].id == bookId) {
            for (int j = 0; j < users.size(); j++) {
                if (users[j].id == userId) {
                    for (int k = 0; k < users[j].booksBorrowed.size(); k++) {
                        if (users[j].booksBorrowed[k].id == bookId) {
                            books[i].isAvailable = true;
                            users[j].booksBorrowed.erase(users[j].booksBorrowed.begin() + k);
                            cout << "Book returned by user " << users[j].name << " on " << returnDate << "." << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "Book not found or not borrowed by the user." << endl;
}
};

int main() {
  entry ();
Library library;
int choice;
while (true) {
cout << "Library Management System" << endl;
cout << "1. Register a new user" << endl;
cout << "2. Register a new book" << endl;
cout << "3. Search for a book by title or author" << endl;
cout << "4. Issue a book to a user" << endl;
cout << "5. Return a book from a user" << endl;
cout<< "6. Room booking menu"<< endl;
cout << "7. Exit" << endl;
cout << "Enter your choice (1-6): ";
cin >> choice;
cin.ignore(); // ignore newline character
switch (choice) {
case 1:
library.registerUser();
break;
case 2:
library.registerBook();
break;
case 3:
library.searchBook();
break;
case 4:
library.issueBook();
break;
case 5:
library.returnBook();
break;
case 6:
library.roombooking();
case 7:
return 0;
default:
cout << "Invalid choice. Please try again." << endl;
}
cout << endl;
}
return 0;
}

