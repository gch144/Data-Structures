#include <bits/stdc++.h>
using namespace std;
int main()
{

    /* vector<int>v;
     cout<<"size: "<<v.size()<<endl;
     cout<<"capacity: "<<v.capacity()<<endl;

     v.push_back(1);
     cout<<"size: "<<v.size()<<endl;
     cout<<"capacity: "<<v.capacity()<<endl;

      v.push_back(2);
     cout<<"size: "<<v.size()<<endl;
     cout<<"capacity: "<<v.capacity()<<endl;

      v.push_back(3);
     cout<<"size: "<<v.size()<<endl;
     cout<<"capacity: "<<v.capacity()<<endl;

      v.resize(5);
      cout<<"size: "<<v.size()<<endl;
     cout<<"capacity: "<<v.capacity()<<endl;

 */

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
   /* cout << endl;
   cout<<"Enter x:";
   int x;
   cin>>x;
   //int occ=-1;
   int count=0;
   for (int i = 0; i <v.size(); i++)   {
    
    if(x<v[i]){
        cout<<i<<" ";
       count++;
       //break;
    }

   }
   cout<<endl;
   cout<<count<<endl;
*/
 /*bool t =true;
for (int i = 0; i <v.size(); i++)   {
    if(v[i]<=v[i-1]){
        t=false;
    }
}
cout<<endl;
cout<< t;
*/
/*
int sum_odd=0;
int sum_even=0;
int difference=0;
for (int i = 0; i <v.size(); i++)   {
    if(v[i]%2==0){
        sum_even+=v[i];
    }
    else{
        sum_odd+=v[i];
    }
    
    }
    if (sum_odd>=sum_even)
    {
        difference=sum_odd-sum_even;
    }
    else{
        difference=sum_even-sum_odd;
    }
    cout<<endl;
    cout<<"difference :"<<difference;
    return 0;
}
*/
}
   