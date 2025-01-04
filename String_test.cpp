#include "String.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>

void display(const string str);
//friend string operator_concat(const string &str, const char* ptr);


int main(){
  //TESTS CONSTRUCTORS AND DESTRUCTOR
  std::cout<<"Début des tests CONSTRUCTEURS ET DESTRUCTEUR"<<std::endl;
  std::cout<<std::endl;
  //test default constructor
  std::cout<<"Début test constructeur par défaut"<<std::endl;
  string str;
  std::cout<<"Affichage du pointer initialisé : "<<*str.string_ptr_<<std::endl;
  std::cout<<"Affichage de l'objet string initialisé : "<<std::endl;
  str.display();
  std::cout<<"Taille : "<< str.size() << std::endl;
  std::cout<<"Fin test constructeur par défaut"<<std::endl;
  std::cout<<std::endl;
  //test copy constructor
  std::cout<<"Début test copy constructor"<<std::endl;
  std::cout<<"String copié : "<<str.string_ptr_<<" , taille : "<<str.size()<<std::endl;
  string copy_str(str);
  std::cout<<"Copie : "<<copy_str.string_ptr_<<" , taille : "<<copy_str.size()<<std::endl;
  std::cout<<"Fin test copy constructor"<<std::endl;
  std::cout<<std::endl;
  //test constructor from c-string
  std::cout<<"Début test constructeur à partir d'une c-string"<<std::endl;
  char cstr[51] = " ";
  std::cout << "Please write a word of maximum 50 characters, with no space in between the letters, right here :" << std::endl;
  std::cin >> cstr;
  string str_bis(cstr);
  std::cout<<"Affichage de l'objet string initialisé à partir de votre c-string en entrée: "<<std::endl;
  str_bis.display();
  std::cout<<"Fin test constructeur à partir d'une c-string"<<std::endl;
  std::cout<<std::endl;

  //TESTS ACCESSORS
  std::cout<<"Début des tests ACCESSEURS"<<std::endl;
  std::cout<<std::endl;
  string str0;
  std::cout<<"Appel du constructeur par défaut au préalable"<<std::endl;
  std::cout<<"Affichage de l'objet string str0 initialisé : "<<std::endl;
  str0.display();
  std::cout<<std::endl;
  //test length accessor
  std::cout<<"Début test length accessor"<<std::endl;
  std::cout<<"Affichage de length_ grâce à l'accesseur : "<<std::endl;
  std::cout<<str.length()<<std::endl;
  std::cout<<"Fin test length accessor"<<std::endl;
  std::cout<<std::endl;
  //test size accessor
  std::cout<<"Début test size accessor"<<std::endl;
  std::cout<<"Affichage de size_ grâce à l'accesseur : "<<std::endl;
  std::cout<<str.size()<<std::endl;
  std::cout<<"Fin test size accessor"<<std::endl;
  std::cout<<std::endl;
  //test maximum size accessor
  std::cout<<"Début test maximum size accessor"<<std::endl;
  std::cout<<"Affichage de max_size_ grâce à l'accesseur : "<<std::endl;
  std::cout<<str.max_size()<<std::endl;
  std::cout<<"Fin test maximum size accessor"<<std::endl;
  std::cout<<std::endl;
  //test capacity accessor
  std::cout<<"Début test capacity accessor"<<std::endl;
  std::cout<<str.capacity()<<std::endl;
  std::cout<<"Fin test capacity accessor"<<std::endl;
  std::cout<<std::endl;



  //TESTS OTHER MEMBER FUNCTIONS
  std::cout<<"Début des tests AUTRES FONCTIONS MEMBRES"<<std::endl;
  std::cout<<std::endl;
  // test reserve function
  std::cout<<"Début test fonction reserve"<<std::endl;
  std::cout<<"Appel du constructeur par défaut au préalable"<<std::endl;
  string str_test;
  std::cout<<"Affichage de l'objet string str_test initialisé : "<<std::endl;
  str_test.display();
  std::cout<<"Capacité initiale : "<< str_test.capacity()<<std::endl;
  std::cout<<"Test 1 : augmenter la capacité de la string jusqu'à 30"<<std::endl;
  str_test.reserve(30);
  std::cout<<"Nouvelle capacité : "<< str_test.capacity()<<std::endl;
  std::cout<<"Test 2 : réduire la capacité de la string à 10"<<std::endl;
  str_test.reserve(10);
  std::cout<<"Fin test fonction reserve"<<std::endl;
  std::cout<<std::endl;

  //test resize function
  std::cout<<"Début test fonction resize"<<std::endl;
  std::cout<<"Appel du constructeur par défaut au préalable"<<std::endl;
  string str1;
  std::cout<<"Affichage de l'objet string str1 initialisé : "<<std::endl;
  str1.display();
  std::cout<<"Taille initiale : "<< str1.length()<<std::endl;
  std::cout<<"Test 1 : augmenter la taille de la string à 30"<<std::endl;
  str1.resize(30,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : " << str1.length()<<std::endl;
  std::cout<<"Test 2 : diminuer la taille de la string à 3"<<std::endl;
  str1.resize(3,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"Test 3 : essayer de redimensionner à une taille interdite"<<std::endl;
  str1.resize(130,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"Test 4 : essayer de redimensionner à la taille limite supérieure (max = 100)"<<std::endl;
  str1.resize(100,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"Test 5 : essayer de redimensionner à la taille limite inférieure (min = 0)"<<std::endl;
  str1.resize(0,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"Test 6 : essayer de redimensionner à une valeur négative (-6 par exemple)"<<std::endl;
  str1.resize(-6,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"Le paramètre négatif est traité comme s'il s'agissait d'un nombre supérieur à la taille maximum."<<std::endl;
  std::cout<<"Test 7 : essayer de redimensionner à une valeur non entière (2.7 par exemple)"<<std::endl;
  str1.resize(2.7,'c');
  std::cout<<"Affichage de l'objet string str1 modifié : "<<std::endl;
  str1.display();
  std::cout<<"Nouvelle taille : "<<str1.length()<<std::endl;
  std::cout<<"La fonction s'effectue sur la partie entière de la taille donnée en paramètre."<<std::endl;
  std::cout<<"Fin test fonction resize"<<std::endl;
  std::cout<<std::endl;

  //test clear fonction
  std::cout<<"Début test fonction clear"<<std::endl;
  string str_clear;
  std::cout<<"Affichage string initialisé  : "<<str_clear.string_ptr_<<std::endl;
  std::cout<<"Taille : "<<str_clear.size()<<std::endl;
  str_clear.clear();
  std::cout<<"Affichage string aprés utilisation de la fonction clear : "<<str_clear.string_ptr_<<std::endl;
  std::cout<<"Taille : "<<str_clear.size()<<std::endl;
  std::cout<<"Fin test clear"<<std::endl;
  std::cout<<std::endl;

  //test empty function
  string str_empty_test;
  std::cout<<"Début test empty"<<std::endl;
  std::cout<<"Taille str_empty_test : "<<str_empty_test.length()<<std::endl;
  std::cout<<"str_empty_test empty ? : "<<str_empty_test.empty()<<std::endl;
  str_empty_test.clear();
  std::cout<<"Taille str_empty_test : "<<str_empty_test.length()<<std::endl;
  std::cout<<"str_empty_test empty ? : "<<str_empty_test.empty()<<std::endl;
  std::cout<<"Fin test empty"<<std::endl;
  std::cout<<std::endl;

  /*
  //test operator=(char) fonction
  std::cout<<"Début test fonction operator=(char)"<<std::endl;
  string str_ope;
  std::cout<<"Affichage du string : "<<str_ope.string_ptr_<<" de taille : "<<str_ope.size()<<std::endl;
  char v = 'v';
  str_ope.operator=(v);
  std::cout<<"Charactère remplaçant : "<<v<<std::endl;
  std::cout<<"Affichage du string aprés application de la fonction : "<<str_ope.string_ptr_<<" de taille : "<<str_ope.size()<<std::endl;
  std::cout<<"Fin test operator=(char)"<<std::endl;
  std::cout<<std::endl;

  //test c_str function
  std::cout<<"Début test fonction c_str"<<std::endl;
  const char* c_str = str.c_str();
  std::cout<<"Application sur le string : "<<str.string_ptr_<<std::endl;
  std::cout<<"c_str : ";
  std::cout<<c_str<<std::endl;
  delete[] c_str;
  std::cout<<"Fin test c_str"<<std::endl;
  std::cout<<std::endl;

  //test operator+(const string&, const char*) fonction
  std::cout<<"Début test fonction operator+(const string&, const char*)"<<std::endl;
  const char p = 'p';
  const char* p_ptr = &p;
  string str_ope_concat;
  std::cout<<"Ajout du caractére p à la fin du string : "<<str_ope_concat.string_ptr_<<" de la taille : "<<str_ope_concat.size()<<std::endl;
  str_ope_concat.operator_concat(p_ptr);
  std::cout<<"Résultat aprés application de la fonction : "<<str_ope_concat.string_ptr_<<std::endl;
  std::cout<<"Size de la chaine de caractéres : "<<str_ope_concat.size()<<std::endl;
  std::cout<<"Fin test operator+(const string&, const char*)"<<std::endl;
  std::cout<<std::endl;
  //test operator= from a string
  std::cout<<"Début test operator=(const string& new_str)"<<std::endl;
  string str2;
  str2.resize(4,'c');
  std::cout<<"Initialisation d'un objet str2 de taille 4"<<std::endl;
  std::cout<<"Affichage de l'objet string str2 initialisé : "<<std::endl;
  str2.display();
  string str3;
  std::cout<<"Appel du constructeur par défaut pour créer une string str3"<<std::endl;
  std::cout<<"Affichage de l'objet string str3 initialisé : "<<std::endl;
  str3.display();
  str3.operator=(str2);
  std::cout<<"Application de l'opérateur qui remplace str3 par str2 "<<std::endl;
  std::cout<<"Affichage de l'objet string str3 (valeur remplacée par celle de str2) : "<<std::endl;
  str3.display();
  std::cout<<"Test supplémentaire : passer un objet différent d'une string (par exemple : un entier, un caractère...)";
  str3.operator=(3);
  str3.display();
  std::cout<<"La fonction ne tourne pas dans ce cas (paramètre ne répondant pas aux spécifications)";
  std::cout<<"Fin test operator=(const string& new_str)"<<std::endl;
  std::cout<<std::endl;

  //test operator+ from a string and a char
  std::cout<<"Début test operator+(char c)"<<std::endl;
  string str4;
  std::cout<<"Appel du constructeur par défaut pour créer une string str3"<<std::endl;
  std::cout<<"Affichage de l'objet string str3 initialisé : "<<std::endl;
  str4.display();
  str4.operator+('g');
  std::cout<<"Application de l'opérateur qui concatène le caractère 'g' à str4 "<<std::endl;
  std::cout<<"Affichage de l'objet string str4 modifié par concaténation : "<<std::endl;
  str4.display();
  std::cout<<"Test supplémentaire : passer un objet différent d'une string (par exemple : un entier, un caractère...)"<<std::endl;
  str4.operator+(3);
  str4.display();
  std::cout<<"La fonction ne tourne pas dans ce cas (paramètre ne répondant pas aux spécifications)"<<std::endl;
  std::cout<<"Fin test operator+(char c)"<<std::endl;

  std::cout<<"Début test operator=(const char* s)"<<std::endl;
  string str5;
  std::cout<<"Affichage de l'objet string str5 initialisé : "<<std::endl;
  str5.display();
  std::cout<<"Affichage de l'objet string str_bis initial: "<<std::endl;
  str_bis.display();
  std::cout<<"Création du pointeur vers str_bis: "<<std::endl;
  const char* s = str_bis.c_str();
  std::cout<<"*s : ";
  std::cout<<*s<<std::endl;
  std::cout<<"s : ";
  std::cout<<s<<std::endl;
  std::cout<<"Application de l'opérateur qui remplace le contenu de str5 par celui du pointeur de str_bis "<<std::endl;
  str5.operator=(s);
  std::cout<<"Affichage de l'objet string str5 modifié : "<<std::endl;
  str5.display();
  std::cout<<"Taille : "<<str5.size()<<std::endl;
  std::cout<<"Capacité : "<<str5.capacity()<<std::endl;
  std::cout<<"Fin test operator=(const char* s) \n"<<std::endl;

  std::cout<<"Début test operator+(const string& str)"<<std::endl;
  string str6;
  std::cout<<"Taille : "<<str6.size()<<std::endl;
  std::cout<<"Capacité : "<<str6.capacity()<<std::endl;
  std::cout<<"Application de l'opérateur de concaténation "<<std::endl;
  str6.operator+(str5);
  std::cout<<"Nouvelle taille : "<<str6.size()<<std::endl;
  std::cout<<"Nouvelle capacité : "<<str6.capacity()<<std::endl;
  std::cout<<"Affichage de l'objet string str6 modifié : "<<std::endl;
  str6.display();
  std::cout<<"Fin test operator+(const string& str)"<<std::endl;

  delete[] s;
  */

}
