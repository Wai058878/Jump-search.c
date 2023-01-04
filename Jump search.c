#include "stdio.h"

int MinNum(int first,int second){
    if (first < second){
        return first;
    }else{
        return second;
    }
}

int JumpSearch(int arr[],int size,int key){
    int step = 5;
    int previous = 0;
    if(arr[previous] == key){
        return previous;
    }else if(arr[step-1] == key){
        return step-1;
    }
    while (arr[MinNum(step+1,size)-1] <= key){
        previous = step;
        if(arr[previous] == key ) {
            return previous;
        }else if(previous >= size){
                return -1;
        }else{
            step += 5;
            if(arr[step-1] == key){
                return step-1;
            }

        }
    }
    int mid = ((previous + step) / 2) ;
    while( mid >= previous || mid <= step){
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] < key){
            mid++;
        }else if(arr[mid] > key){
            mid--;
        }
    }
    return -1;

}



int main(){

    int arr[] = {10,12,14,20,60,100,101,119,148,188};
    int size = sizeof(arr) / sizeof(arr[0]);
    int Tofind = 190;
    int IndexNum = JumpSearch(arr,size,Tofind);
    if (IndexNum != -1){
        printf("We found data : %d index : %d",arr[IndexNum],IndexNum);
    }else{
        printf("We not found.");
    }


    return 0;
}
