//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
     int partition(char arr[], int start, int end, char pivot) {

        // here i is for smaller values

        int i = start;

        for(int j=start;j<end;j++) {

            if(arr[j]<pivot) {

                swap(arr, i, j);

                i++;

            } else if(arr[j]==pivot) {

// if the same element found then put it at last index i.e. original position of the pivot in quick sort algorithm

// and to keep the j pointer at same we have used j-- as it is a for loop

                swap(arr, j, end);

                j--;

            }

        }

        

        // swapping the pivot to its correct index

        swap(arr, i, end);

        return i;

    }
    void swap(char arr[], int a, int b) {

        char ch = arr[a];

        arr[a] = arr[b];

        arr[b] = ch;

    }
void matchPais(char nuts[], char bolts[],int low, int high)
{
    if (low < high)
    {
        int pivot = partition(nuts, low, high, bolts[high]);
        int bo= partition(bolts, low, high, nuts[pivot]);
        matchPais(nuts, bolts, low, pivot-1);
        matchPais(nuts, bolts, pivot + 1, high);
    }
}

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    matchPais(nuts,bolts,0,n-1);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends