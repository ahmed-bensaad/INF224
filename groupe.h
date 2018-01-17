#ifndef GROUPE_H
#define GROUPE_H
#include <iostream>
#include <stdarg.h>
#include "multimedia.h"
#include <list>
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
    Groupe(std::string name,unsigned int argv, ...):Groupe(){
        this->m_name=name;
        va_list v1;
        va_start(v1,argv);
        for(unsigned int i=0;i<argv;i++){
            auto element=va_arg(v1,MultPtr);
            this->push_back(element);
        }
        va_end(v1);
    };
   std::string getName()const{
        return this->m_name;
    };

   void setName(std::string name){
       this->m_name=name;
   };
   void display(std::ostream & stream){
       for (std::list<MultPtr>::iterator it=this->begin(); it != this->end(); ++it)
       {
         (*it)->display(stream);
       }
   };

};

#endif // GROUPE_H
