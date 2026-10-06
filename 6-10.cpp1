#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> orders;
    int orderNo;

    cout << "Enter 5 cancelled order numbers:" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> orderNo;
        orders.push(orderNo);
    }

    cout << "\nCancelled orders (most recent first):" << endl;

    while (!orders.empty())
    {
        cout << orders.top() << endl;
        orders.pop();
    }

    return 0;
}
