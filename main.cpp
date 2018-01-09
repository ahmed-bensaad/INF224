//
//  main.cpp
//  

#include <iostream>
#include "multimedia.h"
#include "image.h"
#include "film.h"
#include "groupe.h"


int main(int argc, char* argv[]) {
  /*Multimedia* mult1=new Multimedia("lol","XD");
  Multimedia* mult2= new Multimedia("mdr","ff"); //crée un pointeur vers l'objet sans mettre *
  mult1->display(std::cout);
  mult2->display(std::cout);*/

  /* Multimedia** mult= new Multimedia*[4];
  unsigned int count=0;
  mult[count++]=new Image("foo","baar",100,20);
  mult[count++]=new Video("foo1","baar1",20);
  mult[count++]=new Image("foo2","baar2",20,50);
  mult[count]=new Video("foo3","baar3",50);
  for(unsigned int i=0;i<=count;i++){
      mult[i]->jouer();
      }*/
  /*int * durs=new int[4];
  durs[0]=1;
  durs[1]=2;
  durs[2]=3;
  durs[3]=4;
  Film* film= new Film("foo","baar",120,durs,4);
  const int * m = film->getChaptersDur();
  //m[1]=0; ça marche pas (cf commentaire dans film.h)

  film->display(std::cout);*/
   using FilmPtr =std::shared_ptr<Film>;
    using ImagePtr =std::shared_ptr<Image>;

    int * durs=new int[4];
      durs[0]=1;
      durs[1]=2;
      durs[2]=3;
      durs[3]=4;
      int * durs1=new int[4];
       durs1[0]=5;
       durs1[1]=6;
       durs1[2]=7;
       durs1[3]=5;

    FilmPtr film1( new Film("foo","baar",120,durs,4));
    FilmPtr film2( new Film("foo1","baar1",121,durs1,4));
    ImagePtr image1(new Image("fooimage","baarimage",100,20));
    ImagePtr image2(new Image("fooimage2","baarimage2",101,21));

   Groupe g1=Groupe("g1",3,film1,film2,image1);
   Groupe g2=Groupe("g2",3,film1,image2,image1);

   std::cout<<"Groupe1"<<"\n"<<std::endl;
   g1.display(std::cout);
   std::cout<<"Groupe2"<<"\n"<<std::endl;
   g2.display(std::cout);




}
