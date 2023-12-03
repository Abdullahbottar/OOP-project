#include <iostream>
using namespace std;
class b
{
  public:
  b()
  {
   cout<<"hello world.\n";
  }
};
int main()
{
   cout<<"hello world"<<endl;
   for(int i=0; i<5; i++)
   {
    cout<<i+5<<" ";
   }
   cout<<endl;
   int a;
   cout<<"enter a:";
   cin>>a;
   cout<<a<<endl;
   b B;
   return 0;
}



