#include<iostream>
using namespace std;

int main()
{
int stack[5];
int top;
cout<<"Enter 5 cancelled order numbers:\n";
for(int i=0;i<5;i++)
{
top++;
cin>>stack[top];
}
cout<<"\n===CANCELLED ORDERS===\n";
while(top>=0)
{
cout<<"Order:"<<stack[top]<<endl;
top--;
}
return 0;
}
