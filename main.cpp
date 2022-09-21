#include <iostream>
#include <fstream>
#include "jpnVocab.h"
#include <cstdlib>
#include <climits>
#include <vector>
//Make a function that can read the file and store value in a vector
//The it should return the 
Vocab Uverb(){
    std::vector<std::string> k,s,e;
    std::string kj,sm,eng,get;
    std::ifstream v("Verbs.txt");
    std::string trash;
    getline(v, trash);
    size_t i = 0;
    if(!v.is_open()){
        std::cerr << "File failed to open\n";
        exit(1);
    }
    while(v >> kj >> sm >> eng){
        getline(v,get);
        eng += get;
        k.push_back(kj);
        s.push_back(sm);
        e.push_back(eng);
    }
    v.close();
    Vocab u(k,s,e);
    return u;
}
//This will check if num > numVoc
void check1(size_t &num, const size_t&& size){
    while(num > size){
        std::cout << "This exceed the number of words we currently have!\n";
        std::cout << "Enter number of random words you want to make sentences with: ";
        std::cin >> num;
    }   
}
int main(){
    std::cout << "行く" << '\n';
    std::string in,k,s,e;
    Vocab Uverbs = Uverb();
    size_t num;
    std::string usr;
    while(usr != "yes"){
        std::cout << "Welcome to JPN study method!\n";
        std::cout << "We have " << Uverbs.numVocab() << " Words Currently!\n";
        std::cout << "Enter number of random words you want to make sentences with: ";
        std::cin >> num;
        check1(num, Uverbs.numVocab());
        std::cout << "Right now, on a sheet of paper, use the following in a sentence!\n";
        Uverbs.ranWords(num);
        std::cout << "Do you wish to exit: ";
        std::cin >> usr;
    }
    //Uverbs.printVoc();
        
}