#include <iostream>
using namespace std;

int main(){

    int size;
    cin>>size;

    int queue[size];

    for(int i=0 ; i<size ; i++){
        cin>>queue[i];

    }

    int Answerrrrr[size];

    for(int i=0 ; i<size ; i++){
        
        int target = -1;

        for (int j=i-1  ; j>=0 ; j--){
            if(queue[i] >= queue[j]){
               target = queue[j];
               break;
            } 

        }

        Answerrrrr[i] = target;
    }

    for(int i=0 ; i<size ; i++){
        cout<<Answerrrrr[i]<<" ";
    }


    return 0;
}
