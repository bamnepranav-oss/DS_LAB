#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> tokens;
    int choice;
    int tokenNumber = 1;

    do
    {
        cout << "\n===== BANK TOKEN MANAGEMENT SYSTEM =====\n";
        cout << "1. Issue a Token\n";
        cout << "2. Display All Tokens\n";
        cout << "3. Serve a Customer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                tokens.push(tokenNumber);
                cout << "Token " << tokenNumber
                     << " has been issued.\n";
                tokenNumber++;
                break;

            case 2:
                if (tokens.empty())
                {
                    cout << "No customers are waiting.\n";
                }
                else
                {
                    queue<int> temp = tokens;

                    cout << "Waiting tokens: ";

                    while (!temp.empty())
                    {
                        cout << temp.front() << " ";
                        temp.pop();
                    }

                    cout << endl;
                }
                break;

            case 3:
                if (tokens.empty())
                {
                    cout << "No customers to serve.\n";
                }
                else
                {
                    cout << "Serving customer with Token "
                         << tokens.front() << ".\n";

                    tokens.pop();
                }
                break;

            case 4:
                cout << "Thank you for using the Bank Token System.\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
