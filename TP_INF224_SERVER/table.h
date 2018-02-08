#ifndef TABLE_H
#define TABLE_H

#include "multimedia.h"
#include "groupe.h"
#include <map>
#include "image.h"
#include "video.h"
#include "film.h"
#include "groupe.h"

using MultPtr = std::shared_ptr<Multimedia>;
using FilmPtr =std::shared_ptr<Film>;
using ImagePtr =std::shared_ptr<Image>;
using VidPtr = std::shared_ptr<Video>;
using GroupePtr=std::shared_ptr<Groupe>;


class Table{

private:
    std::map<std::string,MultPtr> m_objects;
    std::map<std::string,GroupePtr> m_groupes;

public:
    Table();
    Table(std::map<std::string,MultPtr> objects,std::map<std::string,GroupePtr> groupes);
    ImagePtr createImage(std::string name,std::string path,int longitude,int latitude);
    VidPtr createVideo(std::string name, std::string path, int duration);
    FilmPtr createFilm(std::string name, std::string path, int duration,int * chapter_dur, int nbr_chapter);
    GroupePtr createGroupe(std::string name,std::vector<MultPtr> list);
    void findItem(std::string name, std::ostream &stream);
    void playItem(std::string name, std::ostream &stream);
    void deleteMult(std::string name,std::string & response);
    void deleteGroupe(std::string name,std::string & response);
    void addObjectToGroup(std::string object_name,std::string group_name,std::ostream & stream);
    std::map<std::string,MultPtr> getObjects()const{return m_objects;};
    std::map<std::string,GroupePtr> getGroupes()const{return m_groupes;};


};

#endif // TABLE_H
