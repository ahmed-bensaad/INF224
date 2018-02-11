//
//Video class
//

#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include "multimedia.h"
#include <string>


class Video : public Multimedia{
private:
    int duration=0;
public:
    Video():Multimedia() {
        duration = 0;
    }
    Video(std::string name,std::string path,int duration):Multimedia(name,path){
        this->duration=duration;
    }
    int  getDuration() const {
        return duration;
    }
    void setDuration(int d){
        duration=d;
    }
    void display(std::ostream& stream) const override {
        Multimedia::display(stream);
        stream<<"Duration: "<<  std::to_string(getDuration()) <<std::endl;
    }
    void jouer() override{
        system(("mpv "+getPath()+"/"+getName()+" &").c_str());
    }


};

#endif // VIDEO_H
