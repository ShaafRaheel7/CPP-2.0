#include<iostream>
using namespace std;

int main(){
    int size;
    cout << "Enter the size of dynamic array:";
    cin>>size;

    int* dynamicArray = new int[size];
    cout<<"Enter elements for the dynamic array:"<<endl;
    for (int i = 0; i < size; ++i){
        cout<< "Enter Element at index "<<i+1<< ": ";
        cin>> dynamicArray[i];
    } 

    cout<< "------------------------------------"<<endl;
    cout<< "Dynamic Array Elements:" ;
    for ( int i = 0; i < size; i++){
        cout << dynamicArray[i]<< " ";
    }

    delete[] dynamicArray;
}