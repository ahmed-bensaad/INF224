#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include "multimedia.h"
#include <cstring>

class Image : public Multimedia
{
private:
    int longitude=0;
    int latitude=0;

public:
    Image():Multimedia() {
        longitude = 0;
        latitude = 0;
    }
    Image(std::string name,std::string path,int longitude ,int latitude):Multimedia(name,path){
        this->longitude=longitude;
        this->latitude=latitude;
    }
    int  getLongitude() const {
        return longitude;
    }
    int  getLatitude() const {
        return latitude;
    }

    void setDuration(int l){
        longitude=l;
    }
    void setLatitude(int l){
        latitude=l;
    }
    void display(std::ostream& stream) const override {
        Multimedia::display(stream);
        stream<<"Longitude: "<<  getLongitude() <<"\n"
             <<"Latitude: "<< getLatitude() <<std::endl;
    }

    void jouer() override{
        system(("imagej "+getPath()+"/"+getName()+" &").c_str());
    }
};



#endif // IMAGE_H
