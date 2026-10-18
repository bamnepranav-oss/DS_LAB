#include<iostream>
using namespace std;

int main()
{
int stack[5];
int top = 0;
cout<<"Enter 5 sereved customer token number:\n";
for(int i=0;i<5;i++)
{
cin>>stack[top];
top++;
}
cout<<"\n===SERVICE HISTORY===\n";
while(top>0)
{
  top--;
cout<<"Token:"<<stack[top]<<endl;
}
return 0;
}
