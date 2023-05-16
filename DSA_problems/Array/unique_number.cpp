#include <bits/stdc++.h>
using namespace std;

/*Find the unique number in a given Array where all the
elements are being repeated twice with one value
being unique.
input =[3,4,6,7,1] , target =7
ouput=[3,4][6,1]

 */
int main()
{

    vector<int> v;
    int n;
    cout << "enter size of array:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        v.push_back(element);
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i]<<" ";
    }
   

int count=0;

   for (int i = 0; i <v.size(); i++)
   {
    for (int j = i+1; j <v.size(); j++)    {
    if (v[i]==v[j])
    {
        v[i]=v[j]=-1;
    }        
    }
   }
   for (int i = 0; i <v.size(); i++){
    if (v[i]>=0)
    {
       cout<<endl<<v[i]<<" ";
    }
    
   }

   
    return 0;
}


   