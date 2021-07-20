// First line of input contain the number of segments in the array
// second line of input contain space seperated segments

// Note: Output is 1-based index

#include <iostream>
 
using namespace std;
 
int main()
{	
	int n;
    cin>>n;

    int arr[n];
    for(int j=0;j<n;j++){
        cin>>arr[j];
    }


    // skipping the expanding spiral
    int l=0,r=0,t=0,b=0,i=0;
    while(i<n){
        if(i<n && arr[i]>r){l=arr[i]; i++;}
        else break;

        if(i<n && arr[i]>b){t=arr[i]; i++;}
        else break;

        if(i<n && arr[i]>l){r=arr[i]; i++;}
        else break;

        if(i<n && arr[i]>t){b=arr[i]; i++;}
        else break;
    }

    // contracting spiral starts
    if(i==n) cout<<-1<<endl;
    else{
        if(i>3 && arr[i-2]-arr[i-4]>arr[i]){
            l=r=arr[i-1];
        }
        else if(i<=3 && arr[i]< arr[i-2]){
            l=r=arr[i-1];
        }
        else l=r=arr[i-1]-arr[i-3];

        t=b=arr[i];

        i++;
        while(i<n){
            if(i<n && arr[i]<r){l=arr[i]; i++;}
            else break;

            if(i<n && arr[i]<b){t=arr[i]; i++;}
            else break;

            if(i<n && arr[i]<l){r=arr[i]; i++;}
            else break;

            if(i<n && arr[i]<t){b=arr[i]; i++;}
            else break;
        }

        if(i==n) cout<<-1<<endl;
        else cout<<i+1<<endl;
    }

}
