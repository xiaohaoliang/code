#include <iostream>
#include <vector>
#include <map>
#include <stdint.h>
#include <assert.h>

std::vector<int> getNext(const std::string& pattern)
{
    std::vector<int> next;
    next.emplace_back(-1); //  nerver be used 
    int i = 1; //cur
    int p = 0; //how many pattern
    int length = pattern.length();
    next.emplace_back(0); // real first must be 0 
    while (i < length)
    {
        if (p > 0 && pattern[i] != pattern[p])
        {
            p = 0;
        }
        if (pattern[i] == pattern[p])
        {
            ++p;
        }
        next.emplace_back(p);
        i++;
    }
    //debug
    std::cout << " " << pattern <<std::endl;
    for(int j=0; j< length; j++){
        std::cout << next[j] ;
    }
    std::cout << std::endl;
    //debug--end----
    return next;
}


int kmp_strStr(const std::string& str,const std::string& pattern)
{
    std::vector<int> next = getNext(pattern);
    int p_length = pattern.length();
    int s_length = str.length();
    int p = 0; //cur of pattern
    for (int i = 0; i < s_length; i++)
    {
        if (p > 0 && str[i] != pattern[p])
        {
            p = next.at(p);
        }
        if (str[i] == pattern[p])
        {
            p++;
        }
        if (p == p_length)
        {
            return (i-p+1);
        }
    }
    return -1;
}


bool unittest_strStr(){
    assert(-1 == kmp_strStr("",""));
    assert(2 == kmp_strStr("hello","ll"));
    assert(-1 == kmp_strStr("aaaaaaa","bba"));
    return true;
}

int main()
{
    unittest_strStr();
    
    char a[] = "aabdabd abdabdc adaabdaabdcaabdc";
    char b[] = "aabdaabdca";
    std::cout << kmp_strStr(a, b) << std::endl;
}
