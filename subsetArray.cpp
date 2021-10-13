#include <bits/stdc++.h>
using namespace std;
int main()
{
    //program to find subsets of an array
    /*
 for example: {2,3}
 the subsets are :
{_, _}
{_, 3}
{2, _}
{2, 3}

for example: {1,2,3}
_       _       _
_       _       3
_       2       _
_       2       3
1       _       _
1       _       3
1       2       _
1       2       3

and so on

logic explaination at the end of program
 */
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int limit = (int)pow(2, n);//total number of subsets
    for (int i = 0; i < limit; i++)//to find the values for each subset
    {
        string set = "";
        int temp = i;
        for (int j = n - 1; j >= 0; j--)// for using binary number conversion logic
        {
            int r = temp % 2;
            temp = temp / 2;
            if (r == 0)
            {   // adding _
                set = "_\t" + set;
            }
            else
            {   //adding number 
                ostringstream str1;
                str1 << arr[j];
                string geek = str1.str();
                string s = "";
                s = s + geek;
                set = s + "\t" + set;
            }
        }
        cout << set << endl;
    }
}
//logic explaination
/*
for an array containing 2 elements, number of subsets is 4(i.e. 2^2)
for an array containing 3 elements, number of subsets is 8(i.e. 2^3)
for an array containing n elements, number of subsets is 4(i.e. 2^n)
also for array of 2 elements(say a,b) were {0,0},{0,b},{a,0},{a,b}
similar to binary numbers for 0,1,2,3
so by using binaryy conversion of index we came forward with each subset
for i=2
binary number=10
hence subset using the same logic will be a _  
for i=3
binary number=11
hence subset using the same logic will be a b  
and so on.
*/