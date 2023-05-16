#include <bits/stdc++.h>
using namespace std;

/*Find the total number of pairs in the
Array whose sum is equal to the given 
value x. 
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
   
cout<<"target:";
int target;
cin>>target;
int count=0;

   for (int i = 0; i <v.size(); i++)
   {
    for (int j = i+1; j <v.size(); j++)    {
       for (int k = j+1; k < v.size(); k++)
       {
        if (v[i]+v[j]+v[k]==target)
        {
            cout<<"["<<i<<","<<j<<","<<k<<"]"<<endl;
                    count++;
                    }
        
       }
       
    }
    
   }
   cout<<endl;
   cout<<count;
   
    return 0;
}


   