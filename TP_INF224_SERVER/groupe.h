#ifndef GROUPE_H
#define GROUPE_H
#include <iostream>
#include <stdarg.h>
#include "multimedia.h"
#include <list>
#include <vector>
#include<memory>
using MultPtr = std::shared_ptr<Multimedia>;
class Groupe : public std::list<MultPtr>
{
private:
    std::string m_name;

public:
    Groupe():std::list<MultPtr>(){
        m_name="";
    };
    Groupe(std::string name,std::vector<MultPtr> list):Groupe(){
        this->m_name=name;
        for(unsigned int i=0;i<list.size();i++){
            auto element=list[i];
            this->push_back(element);
        }
    };
   std::string getName()const{
        return this->m_name;
    };

   void setName(std::string name){
       this->m_name=name;
   };
   void display(std::ostream & stream){
       unsigned int i =1;
       for (std::list<MultPtr>::iterator it=this->begin(); it != this->end(); ++it)
       {
         stream<< "Item"<<" "<<i<<"\n"<<std::endl;
         (*it)->display(stream);
         stream<<"\n"<<std::endl;
         i++;
       }
   };

};

#endif // GROUPE_H
