//
// Table class
// table will contain all created files and groups
//

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
    /// @brief creates an image and adds it to the table.
    /// @param name image name.
    /// @param path path of the image.
    /// @param longitude the longitude of the image
    /// @param latitude the latitude of the image
    /// @return a smart pointer to the created image.
    ImagePtr createImage(std::string name,std::string path,int longitude,int latitude);
    /// @brief Creates a vidoe and adds it to the table.
    /// @param name video name
    /// @param path video path.
    /// @param duration the length of the video
    /// @return a smart pointer to the created video.
    VidPtr createVideo(std::string name, std::string path, int duration);
    /// @brief Creates a film and adds it to the table
    /// @param name film name.
    /// @param path film path.
    /// @param duration film duration.
    /// @param chapter_dur the duration of each chapter.
    /// @param nbr_chapter the number of chapters.
    /// @return a smart pointer to the created film.
    FilmPtr createFilm(std::string name, std::string path, int duration,int * chapter_dur, int nbr_chapter);
    /// @brief Creates a group and adds it to the table.
    /// @param name grop name.
    /// @param list the list of the files to add to the group.
    /// @return a samrt pointer to the created group.
    GroupePtr createGroupe(std::string name,std::vector<MultPtr> list);
    /// @brief find the item in the table and displays it if it is found.
    /// @param name the name of the item.
    void findItem(std::string name, std::ostream &stream);
    /// @brief Finds item and plays it.
    /// @param name the name of the file.
    /// @param stream output stream that will play the file.
    void playItem(std::string name, std::ostream &stream);
    /// @brief Deletes file if it exists.
    /// @param name the name of the file.
    /// @param response takes an error message if the file is not found.
    void deleteMult(std::string name,std::string & response);
    /// @brief Deletes group if it exists.
    /// @param name the name of the file.
    /// @param response takes an error message if the group is not found.    
    void deleteGroupe(std::string name,std::string & response);
    /// @brief add file to existing group
    /// @param object_name the name of the file.
    /// @param group_name name of the group.
    /// @param stream server response    
    void addObjectToGroup(std::string object_name,std::string group_name,std::ostream & stream);
    std::map<std::string,MultPtr> getObjects()const{return m_objects;};
    std::map<std::string,GroupePtr> getGroupes()const{return m_groupes;};


};

#endif // TABLE_H
