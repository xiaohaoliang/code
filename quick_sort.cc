#include <iostream>
#include <vector>
#include <stdint.h>

void print(const int& data){
    std::cout << data << ";";
}


void QuickSort(std::vector<int>& array,int left, int right){
    int len = right - left;
    if(len <= 0){
        return;
    }
    int old_l=left;
    int old_r=right;
    // base num is array[right]
    int base = right;
    while(left<right){
        while(array[left] <= array[base] && left<right){
            left++;
        }
        //swap left 
        int tmp = array[left];
        array[left] = array[base];
        array[base] = tmp;
        base = left;
        while(array[right] >= array[base] && left<right){
            right--;
        }
        tmp = array[right];
        array[right] = array[base];
        array[base] = tmp;
        base = right;
    }
    //print(base);
    QuickSort(array,old_l,base-1);
    QuickSort(array,base+1,old_r);

    return;
}

void createVector(std::vector<int>& array){
    array.clear();
    array.emplace_back(5);
    array.emplace_back(4);
    array.emplace_back(7);
    array.emplace_back(9);
    array.emplace_back(6);
    array.emplace_back(0);
    array.emplace_back(11);
    return ;
}



int main(){
    std::vector<int> array;
    createVector(array);
    for(const int& i : array){
        print(i);
    }
    std::cout << std::endl;
    QuickSort(array,0,array.size()-1);
    for(const int& i : array){
        print(i);
    }
    std::cout << std::endl;
}