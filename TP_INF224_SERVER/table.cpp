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

Table::Table(std::map<std::string,MultPtr> objects,std::map<std::string,GroupePtr> groupes){
    m_objects=objects;
    m_groupes=groupes;
}

ImagePtr Table::createImage(std::string name,std::string path,int longitude ,int latitude){
    ImagePtr image(new Image(name,path,longitude,latitude));
    m_objects[name]=image;
    return image;
}

VidPtr Table::createVideo(std::string name,std::string path,int duration){
    VidPtr video(new Video(name,path,duration));
    m_objects[name]=video;
    return video;
}

FilmPtr Table::createFilm(std::string name, std::string path, int duration,int* chapters_dur, int nbr_chapters){
    FilmPtr film (new Film(name,path,duration,chapters_dur,nbr_chapters));
    m_objects[name]=film;
    return film;
}

GroupePtr Table::createGroupe(std::string name,std::vector<MultPtr> list){
    GroupePtr groupe (new Groupe(name,list));
    m_groupes[name]=groupe;
    return groupe;
}
void Table::deleteGroupe(std::string name,std::string & response){
    auto item=m_objects.find(name);
    if(item!=m_objects.end()){
    m_groupes.erase(name);
    }else{
        response="Error: Item not found !";
    }
}
void Table::deleteMult(std::string name,std::string & response){
    auto item=m_objects.find(name);
    if(item!=m_objects.end()){
    m_objects.erase(name);
    }else{
        response="Error: Item not found !";
    }
}
void Table::addObjectToGroup(std::string object_name,std::string group_name,std::ostream & stream){
    m_groupes[group_name]->push_back(m_objects[object_name]);
    stream<<"Group updated"<<std::endl;
}
void Table::findItem(std::string name,std::ostream & stream){
    auto item=m_objects.find(name);
    if(item!=m_objects.end()){
       stream<<"Item found"<<std::endl;
       (item->second)->display(stream);
    }else{
        auto item2=m_groupes.find(name);
        if (item2!=m_groupes.end()){
            stream<<"Group found"<<std::endl;
            (item2->second)->display(stream);
        }
        else{
            stream<<"Item does not exist"<<std::endl;

        }
    }

}

void Table::playItem(std::string name,std::ostream & stream){
    auto item=m_objects.find(name);
    if(item!=m_objects.end()){
       stream<<"Item found"<<std::endl;
       (item->second)->jouer();
    }else{
    stream<<"Item not found"<<std::endl;
    }

}

