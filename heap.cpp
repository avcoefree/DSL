#include<iostream>
#define MAX 100
using namespace std;
class mark{
    public:
    int arr[MAX],n,left,right,z,largest,temp;
    
    void hfy(int i){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){ 
            largest=right;
        }
        if(i!=largest){
            temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            hfy(largest);
        }
    }
    void create(){
        cout<<"enter number of students :";
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"enter marks of students no. "<<i+1<<"=";
            cin>>arr[i];
        }
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            hfy(i);
        }
        z=n;
        for(int i=n-1;i>=0;i--){
            temp=arr[i];
            arr[i]=arr[0];
            arr[0]=temp;
            n--;
            hfy(0);
        }
        cout<<"maximum marks obtained in subject :"<<endl;
        cout<<arr[z-1]<<endl;
        cout<<"minimum marks obtained in subject :"<<endl;
        cout<<arr[0];

    } 
};
int main(){
    mark m;
    m.create();
   
}