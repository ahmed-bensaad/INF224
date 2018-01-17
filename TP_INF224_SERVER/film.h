#ifndef FILM_H
#define FILM_H
#include "video.h"

class Film : public Video
{
private:
    int * chapters_dur;
    int nbr_chapters;
public:
    Film():Video(){
        nbr_chapters=0;
        chapters_dur= new int[nbr_chapters];
    }
    Film(std::string name,std::string path,int duration,int * chapters_dur,int nbr_chapters):Video(name,path,duration){
        this->nbr_chapters=nbr_chapters;
        this->chapters_dur= chapters_dur;
    }
    void setChaptersDur(const int * chapters_dur){
        for(int i=0;i<this->nbr_chapters;i++){
            this->chapters_dur[i]=chapters_dur[i];
        }
    }

    int getNbrChapters()const{
        return this->nbr_chapters;
    }
    const int * getChaptersDur()const{
        return this->chapters_dur; //Le const avant la declaration signifie que l'objet renvoyé ne peut pas être modifié
    }
    void display(std::ostream& stream) const override {
        Video::display(stream);
        int nbr= getNbrChapters();
        const int * chapters=getChaptersDur();
        for(int i=0;i<nbr;i++){
                stream<<"Duration of chapter "<< i+1 <<": " <<chapters[i] <<std::endl;
            }

    }
};

#endif // FILM_H
