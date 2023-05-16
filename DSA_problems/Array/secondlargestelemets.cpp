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
   int mx=0;
   //int mx_index;
for (int i = 0; i <v.size(); i++)
{
if(v[i]>mx){
    mx=v[i];
}   
}
int sx=0;
for (int i = 0; i < v.size(); i++)
{
    if (v[i]>sx &&v[i]!=mx)
    {
        sx=v[i];
    }
    
}
cout<<endl;
cout<<sx<<" ";
    return 0;
}


   