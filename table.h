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

class Table{

private:
    std::map<std::string,MultPtr> m_objects;
    std::map<std::string,Groupe> m_groupes;

public:
    Table();
    Table(std::map<std::string,MultPtr> objects,std::map<std::string,Groupe> groupes);
    Image createImage(std::string name,std::string path,int longitude,int latitude);
    Video createVideo(std::string name, std::string path, int duration);
    Film createFilm(std::name, std::string path, int duration, int nbr_chapter,int * chapter_dur);
    Groupe createGroupe(std::string name,unsigned int argv, ...);
    void findItem(std::string name);
    void playItem(std::string name);


};

#endif // TABLE_H
