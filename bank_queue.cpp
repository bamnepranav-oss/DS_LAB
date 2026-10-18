#include<iostream>
using namespace std;

int main()
{
int queue[5];
int front=0;
int rear=0;

cout<<"\nEnter 5 customer token number:\n";

for (int i=0;i<5;i++)
{
cin>>queue[rear];

rear++;
}
cout<<"/n===CUSTOMER SERVICES===:/n";
while(front<rear)
{
cout<<"\nServing Token:"<<queue[front]<<endl;
front++;
} 
return 0;
}
