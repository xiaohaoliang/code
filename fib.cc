#include <iostream>
#include <vector>
#include <stdint.h>
#include <assert.h>


std::vector<uint64_t> gen_fib(int n){
    if(n <=0) {
        std::vector<uint64_t> res;
        return res;
    }
    std::vector<uint64_t> res(n);
    res[0]=0;
    if(n ==1){
        return res;
    }
    res[1]=1;
    for(int i=2;i<n;i++){
        res[i] = res[i-1]+res[i-2];
    }
    return res;
}

bool unittest_gen_fib(){
    std::vector<uint64_t> res = gen_fib(-1);
    assert(res.size()==0);
    res = gen_fib(0);
    assert(res.size()==0);
    res = gen_fib(1);
    assert(res.size()==1 && res.at(0)==0);
    res = gen_fib(2);
    assert(res.size()==2 && res[0]==0 && res[1]==1);
    res = gen_fib(3);
    assert(res.size()==3 && res[0]==0 && res[1]==1 && res[2]==1);
    res = gen_fib(6);
    assert(res.size()==6 && res[5]==5);
    return true;
}

int main(){
    
    unittest_gen_fib();

    int n=10;
    std::vector<uint64_t> fib = gen_fib(n);
    for(int i=0;i<n;i++){
        std::cout <<fib[i] << std::endl;
    }
}
