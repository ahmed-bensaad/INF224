#include "multimedia.h"
Multimedia::Multimedia()
{
this->name="";
this->path="";
}
Multimedia::Multimedia(std::string name, std::string path){
    this->name=name;
    this->path=path;
}


Multimedia::~Multimedia()
{
    std::cout<<"Object Destroyed"<<std::endl;
}

std::string Multimedia::getName()const{
    return this->name;
}
std::string Multimedia::getPath()const{
    return this->path;
}
void Multimedia::setName(std::string name){
    this->name=name;
}
void Multimedia::setPath(std::string path){
    this->path=path;
}

void Multimedia::display(std::ostream& stream)const{
    stream << "Name: " << this->getName() << "\n"
    << "Path: " << this->getPath()
    << std::endl;
}
void Multimedia::jouer(){

}
