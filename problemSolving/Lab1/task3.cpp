#include<iostream>
using namespace std;

void linearSearch(int array[],int n, int target){
    int count = 0;
    for ( int i = 0 ; i < n; i++){
        if (array[i] == target){
            cout<< "The element is found at position "<<i+1<<endl;
            count = count + 1;
        }
    }
    if (count == 0 )
    cout<< "The element is not present in the array"<<endl;
}
int main(){
    int target;

    int array[10] = {12,44,32,16,17,20,29,30,66,99};
    int n = sizeof(array)/ sizeof(array[0]);
    target = 16;
    linearSearch(array,n,target);
    target = 20;
    linearSearch(array,n,target);
}