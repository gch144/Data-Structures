#include <bits/stdc++.h>
using namespace std;

/*

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
    cout<<endl;
   int k;
   cout<<"K"<<endl;
   cin>>k;
   k%=v.size();
   reverse(v.begin(),v.end());
   reverse(v.begin(),v.begin()+k);
   reverse(v.begin()+k,v.end());


for (int i = 0; i <v.size(); i++)
{
cout<<v[i]<<" ";
}
cout<<endl;

    return 0;
}


   