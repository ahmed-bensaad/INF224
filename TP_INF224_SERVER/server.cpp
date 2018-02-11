//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "tcpserver.h"
#include "table.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

class MyBase {
private:
    Table * table;
public:

    MyBase(){table=new Table();}
    ~MyBase(){delete table;}

  /* Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
   * Ca doit etre une methode de la classe qui gere les données, afin qu'elle
   * puisse y accéder.
   *
   * Arguments:
   * - 'request' contient la requête
   * - 'response' sert à indiquer la réponse qui sera renvoyée au client
   * - si la fonction renvoie false la connexion est close.
   *
   * Cette fonction peut etre appelée en parallele par plusieurs threads (il y a
   * un thread par client).
   *
   * Pour eviter les problemes de concurrence on peut créer un verrou en creant
   * une variable Lock **dans la pile** qui doit etre en mode WRITE (2e argument = true)
   * si la fonction modifie les donnees.
   */
  bool processRequest(TCPConnection& cnx, const string& request, string& response)
  {
    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream stream(request);
    stringstream response_stream ;
    string type;
    stream>>type;
    if ((type != "Add") && (type != "Delete") && (type != "Find") && (type != "Play")&&(type!="Insert")) {
             response = "Error: Request not defined !";
             return true;
         }
    bool write=false; //true si on modifie la table

    if ((type == "Add") || (type == "Delete"))
        write = true;

    TCPLock lock(cnx, write);

    string fileName="";
    string filePath="";
    string fileType="";
    bool found=false;

    if (type=="Add"){
        stream>>fileType>>fileName;

        if (fileType=="group"){
            map<std::string,GroupePtr> groupes=table->getGroupes();
            for(map<std::string,GroupePtr>::iterator it = groupes.begin(); it != groupes.end(); ++it) {
                if(it->first==fileName){
                    response="Error: Group name already exists !";
                    found=true;
                    break;
                }

            }
            if(!found){
                vector<MultPtr> list;
                table->createGroupe(fileName,list);
                response="Group successfully added";
            }

        }
    else{
            map<std::string,MultPtr> mults=table->getObjects();
            for(map<std::string,MultPtr>::iterator it = mults.begin(); it != mults.end(); ++it) {
                if(it->first==fileName){
                    response="Error: File name already exists !";
                    found=true;
                    break;
                }

        }
            if(!found){
                if(fileType=="image"){
                    int height;
                    int width;
                    stream >> filePath >> width >> height;
                    table->createImage(fileName,filePath,height,width);
                    response="Image successfully added";
                }
                else if(fileType=="video"){
                    int duration = 0;
                    stream >> filePath >> duration;
                    table->createVideo(fileName,filePath,duration);
                    response="Video successfully added";
                }
                else if(fileType=="film"){
                    int numberOfChapters;
                    int duration;
                    stream >> filePath >> duration >>numberOfChapters;
                    int* chapters_dur = new int[numberOfChapters];
                    for (int i = 0 ; i < numberOfChapters; i++)
                        stream >> chapters_dur[i];
                    table->createFilm(fileName,filePath,duration,chapters_dur,numberOfChapters);
                    response = "Film successfully added";

                }
                else{
                    response="Error: Type not defined !";
                }
            }

    }


}
    else if(type=="Delete"){
        stream>>fileType>>fileName;
        if (fileType=="group"){
            table->deleteGroupe(fileName,response);
        }else if((fileType=="image")||(fileType=="video")||(fileType=="film")){
            table->deleteMult(fileName,response);
            response="File successfully deleted"
        }else{
            response="Error: File type not defined !";
        }
    }
    else if(type=="Find"){
        stream>>fileName;
        table->findItem(fileName,response_stream);
    }
    else if (type=="Play"){
        stream>>fileName;
        table->playItem(fileName,response_stream);

    }
    else if(type=="Insert"){
        string mult_name;
        string group_name;
        stream>>mult_name>>group_name;
        table->addObjectToGroup(mult_name,group_name,response_stream);
    }

    string response2=response_stream.str();
    replace(response2.begin(), response2.end(), '\n', ';');
    if (response==""){response=response2;}
    else if (response2!=""){response+=";"+response2;}
    cerr << "response: " << response <<endl;
    
    // renvoyer false si on veut clore la connexion avec le client
    return true;
  }
};


int main(int argc, char* argv[])
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());
  
  // cree l'objet qui gère les données
  shared_ptr<MyBase> base(new MyBase());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*base, &MyBase::processRequest);
  
  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);
  
  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }
  
  return 0;
}

