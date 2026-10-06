#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> serviceHistory;
    int token;

    cout << "===== BANK SERVICE HISTORY =====\n";
    cout << "Enter 5 recently served customer token numbers:\n";

    // Store 5 token numbers in the stack
    for (int i = 0; i < 5; i++)
    {
        cin >> token;
        serviceHistory.push(token);
    }

    // Display service history from most recent
    cout << "\n===== CUSTOMER SERVICE HISTORY =====\n";

    while (!serviceHistory.empty())
    {
        cout << "Customer Token No. "
             << serviceHistory.top() << endl;

        serviceHistory.pop();
    }

    return 0;
}
