#include "table.h"



using FilmPtr =std::shared_ptr<Film>;
using ImagePtr =std::shared_ptr<Image>;
using MultPtr = std::shared_ptr<Multimedia>;
using VidPtr = std::shared_ptr<Video>;
using GroupePtr=std::shared_ptr<Groupe>;


Table::Table(){
    m_objects={};
    m_groupes={};

}

Table::Table(std::map<std::string,MultPtr> objects,std::map<std::string,Groupe> groupes){
    m_objects=objects;
    m_groupes=groupes;
}

ImagePtr Table::createImage(std::string name,std::string path,int longitude ,int latitude){
    ImagePtr image(new Image(name,path,longitude,latitude));
    m_objects[name]=image;
    return image;
}

VidPtr Table::createVideo(std::string name,std::string path,int duration){
    Video video(new Video(name,path,duration));
    m_objects[name]=video;
    return video;
}

FilmPtr Table::createFilm(std::string name, std::string path, int duration, int nbr_chapters,int* chapters_dur){
    Film film (new(Film(name,path,duration,nbr_chapters,chapters_dur));
    m_objects[name]=film;
    return film;
}

GroupePtr Table::createGroupe(std::string name,unsigned int argv, ...){
    Groupe groupe (new(Groupe(name,argv,...));
    m_groupes[name]=groupe;
    return groupe;
}

void Table::findItem(std::string name){

}

void Table::playItem(std::string name){

}

