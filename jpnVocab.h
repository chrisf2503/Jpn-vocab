#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <climits>

/*
    Goal: Being able to read file and use different type of study methods.
    Trying to apply what we have learned within Csci 135-335
    
    Priority:Identifying What is/would be needed and how to make it better.
    Using what ever we have covered (if it is necassary) in order to create a sucessful program

    
*/
//template<typename Object>
class Vocab{
    public:
        //zero par
        Vocab();

        Vocab(const std::vector<std::string> &k,const std::vector<std::string> &s,const std::vector<std::string> &e){
            std::cout << "in constructor\n";
            this->numVoc = k.size();
            for(size_t i = 0; i < numVoc; i++){
                kanji.push_back(k[i]);
                simp.push_back(s[i]);
                defin.push_back(e[i]);
            }
        }     
        
        void printVoc(){
            for(size_t i = 0; i < numVoc; i++){
                std::cout << kanji[i] << " " << simp[i] << " " << defin[i] << '\n';
            }   
        }
        size_t numVocab()const{
            return this->numVoc;
        }
        //Given # of words they want, generate a ran # generater
        //that will output num # words
        //What if the same word has been choose...
        //We want to avoid including the same word!
        //Num < numVoc
        void ranWords(const size_t num){
            std::srand((unsigned) time(NULL));
            size_t i = 0;
            size_t ran;
            std::string used;
            while(i != num){
                ran = 1+(rand()%numVoc-1);
                while(used.find(kanji[ran]) != std::string::npos){
                    ran = 1+(rand()%numVoc-1);
                }
                std::cout << kanji[ran] << " " << simp[ran] << " " << defin[ran] << '\n';
                used += kanji[ran] + " ";
                i++;
            }
        }
        private:
            //We want to make the vector into a pointer so we can delete it and dont waste mem
            size_t numVoc;
            std::vector<std::string> kanji;
            std::vector<std::string> simp;
            std::vector<std::string> defin;
};