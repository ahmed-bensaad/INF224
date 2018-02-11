//
//Multimedia class
//abstract class that all other classes will inherit from
//

#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <iostream>


class Multimedia
{
private:
    std::string name;
    std::string path;
public:
    Multimedia();
    Multimedia(std::string name,std::string path);
    ~Multimedia();
    std::string getName() const;
    std::string getPath() const;
    void setName(std::string name);
    void setPath(std::string path);
    virtual void jouer()=0;
    virtual void display(std::ostream & stream) const;

};

#endif // MULTIMEDIA_H
