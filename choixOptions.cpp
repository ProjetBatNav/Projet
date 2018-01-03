#include <iostream>
#include <fstream>
#include <string>
#include "choixOptions.h"

void choixOptions(int argc, char const **argv)
{
  std::string opt;
  opt= argv[1];
  if (opt == "-noms" || opt == "-auteurs" || opt =="-n" || opt =="-a" ){ // Donne les noms. 
    std::ifstream auteurs ("auteurs.txt");
    if(auteurs.is_open()){
      std::string ligne;
      while(getline(auteurs,ligne)){
	std::cout<<ligne<<std::endl;
      }
    }
    else{
      std::cerr<<"ERREUR d'ouverture du fichier auteurs.txt"<< std::endl;
    }
  }
  else if (opt == "-h" || opt == "-help"){ // Lit le fichier d'aide.
    std::ifstream help ("help.txt");
    if(help.is_open()){
      std::string ligne;
      while(getline(help,ligne)){
	std::cout<<ligne<<std::endl;
      }
    }
    else{
      std::cerr<<"ERREUR d'ouverture du fichier help.txt"<< std::endl;
    }
  }
  else if(opt == "-v" || opt == "-version"){ // Donne la version
    std::ifstream version ("version.txt");
    if(version.is_open()){
      std::string ligne;
      while(getline(version,ligne)){
	std::cout<<ligne<<std::endl;
      }
    }
    else{
      std::cerr<<"ERREUR d'ouverture du fichier version.txt"<< std::endl;
    }
  }
  else{
    std::cerr<<"ERREUR l'option " << opt << " n'est pas valide."<<std::endl;
    std::cout<<" Tapez '-help' pour plus d'information."<<std::endl;
  }
}
 

    
