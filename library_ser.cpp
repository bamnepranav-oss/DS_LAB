#include <iostream>
using namespace std;

int main() {
    int book[5];
    int searchID;
    bool found = false;

    cout << "Enter 5 Book IDs:\n";

    for (int i = 0; i < 5; i++) {
        cin >> book[i];
    }

    cout << "\nEnter Book ID to search: ";
    cin >> searchID;

    for (int i = 0; i < 5; i++) {
        if (book[i] == searchID)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Book Found";
    else
        cout << "Book not Found";

    return 0;
}
