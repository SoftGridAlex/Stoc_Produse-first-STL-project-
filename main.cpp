#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <limits>

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct detalii{
    std::string titlu;
    std::string autor;
    double pret;
    int stoc;

    // Constructorul!
    detalii(std::string t = "", std::string a = "", double p = 0.0, int s = 0)
        : titlu(t), autor(a), pret(p), stoc(s) {}

};

int main()
{
    std::map<int, detalii> obiect;

    obiect[11] = {"Telefon Smart X", "Model 2023, 128GB", 1299.99, 15};
    obiect[12] = {"Castile Audio Y", "Anulare zgomot, Bluetooth", 349.50, 20};
    obiect[103] = {"Laptop Z-Pro", "Core i7, 16GB RAM", 3499.00, 8};
    obiect[201] = {"Cartea 'Calatorie in Timp'", "Autor: Maria Popescu", 45.00, 30};

    std::cout << " --- Bine ati venit! --- \n";
    int n=-1;

    while(n!=0){

        std::cout << "\n--- Meniu Principal ---\n";
        std::cout << "1. Adauga/Actualizeaza Produs\n";
        std::cout << "2. Cauta Produs dupa ID\n";
        std::cout << "3. Actualizeaza Stoc Produs\n";
        std::cout << "4. Afiseaza Toate Produsele\n";
        std::cout << "0. Iesire !\n\n";
        std::cout << "Introduceti cifra dupa nevoie dumneavoastra : ";
        std::cin >> n;

        switch(n){

            case 1:{
                std::string autorNou, titluNou;
                double pre;
                int sto;
                std::cout << "Introduceti ID-ul produsului: ";
                int id, am;
                std::cin >> id;
                clearInputBuffer();
                if(obiect.count(id)){
                    std::cout << "Exista produsul cu acest ID : " << id << "\n";
                    std::cout << "Vrei sa ii actualizezi ceva : \n";
                    std::cout << "    1 -> DAAAA \n";
                    std::cout << "    0 -> NUUUU \n";
                    std::cin >> am;
                    clearInputBuffer();
                    if(am == 1){
                        int element;
                        std::cout << "Ce vrei sa actualizezi : \n";
                        std::cout << "    1 -> titlu \n";
                        std::cout << "    2 -> autor \n";
                        std::cout << "    3 -> pret \n";
                        std::cout << "    4 -> stoc \n";
                        std::cin >> element;
                        clearInputBuffer();
                        switch(element){
                            case 1:{
                                std::cout << "Introduceti noul titlu : ";
                                std::getline(std::cin, titluNou);
                                obiect[id]=detalii(titluNou, obiect[id].autor, obiect[id].pret, obiect[id].stoc);
                                break;
                            }
                            case 2:{
                                std::cout << "Introduceti noul autor : ";
                                std::getline(std::cin, autorNou);
                                obiect[id]=detalii(obiect[id].titlu, autorNou, obiect[id].pret, obiect[id].stoc);
                                break;
                            }
                            case 3:{
                                std::cout << "Introduceti noul pret : ";
                                std::cin >>pre;
                                obiect[id].pret=pre;
                                break;
                            }
                            case 4:{
                                std::cout << "Introduceti noul stoc : ";
                                std::cin >>sto;
                                obiect[id].stoc=sto;
                                break;
                            }
                            default:{
                                std::cout << "Nu este corect introdusa alegerea! \n";
                                break;
                            }
                        }

                    }
                    else{
                        if(am==0){
                            std::cout << "OK, Puteti sa va contiunuati drumul! \n";
                        }
                        else{
                            std::cout << "Valoarea nu este corecta. \n";
                        }
                    }

                }
                else{
                    int orice;
                    std::cout << "Nu exista produs cu ID-ul : " << id << "\n";
                    std::cout << "Vreti sa il adugati in lista : \n";
                    std::cout << "    1 -> DAAAA \n";
                    std::cout << "    0 -> NUUUU \n";
                    std::cin >> orice;
                    clearInputBuffer();
                    if(orice==1){
                        std::cout << "Ok, dami datele pentru acest produs: \n";
                        std::cout << "Introduceti titlul : ";
                        std::getline(std::cin, titluNou);

                        std::cout << "Introduceti autorul : ";
                        std::getline(std::cin, autorNou);

                        std::cout << "Introduceti pretul : ";
                        std::cin >> pre;

                        std::cout << "\n";
                        std::cout << "Introduceti stocul : ";
                        std::cin >> sto;

                        std::cout << "\n";
                        std::cout << "Adaugare cu succes !\n";

                        obiect[id]=detalii(titluNou, autorNou, pre, sto);
                    }
                    else{
                        if(orice==0){
                            std::cout << "OK, Iti poti contunia drumul. \n";
                        }
                        else{
                            std::cout << "Nu exista optiunea asta ! \n";
                        }

                    }

                }

                break;
            }
            case 2:{
                int id;
                std::cout << "Introducei ID-ul al carui produs il cautati: ";
                std::cin >> id;
                if(obiect.count(id)){
                    std::cout << "Am gasit produsul cu ID-ul " << id << "\n";
                    std::cout << "-----------------------------------------------\n";
                    std::cout << "      Nume/Titlu -> " << obiect[id].titlu << "\n";
                    std::cout << "      Descriere/Autor -> " << obiect[id].autor << "\n";
                    std::cout << "      Pret  -> " << obiect[id].pret << " RON\n";
                    std::cout << "      Stoc  -> " << obiect[id].stoc << " bucati\n";
                    std::cout << "-----------------------------------------------\n";

                }
                else{
                    std::cout << "Nu avem in lista produsul cu ID-ul " << id << "\n";

                }

                break;
            }
            case 3:{

                if(obiect.empty()){
                    std::cout << "Nu avem nici un produs pe lista. Prima data introduceti unul !\n";
                }
                else{
                    int id, nr;
                    std::cout << "Introduceti ID-ul produsului : ";
                    std::cin >> id;
                    std::cout << "Produsul cu ID-ul " << id << " are in stoc : " << obiect[id].stoc << " valabile.\n";
                    std::cout << "Vreti sa ii schimbati stocul : \n";
                    std::cout << "    1 -> DAAAAA  \n";
                    std::cout << "    0 -> NUUUUU  \n";
                    std:: cin >> nr;
                    if(nr==1){
                        int num;
                        std::cout << "Introduceti stocul disponibil : ";
                        std::cin >> num;
                        obiect[id].stoc=num;
                    }
                    else{
                        if(nr==0){
                            std::cout << "OK, nu este nici o problem !\n";
                        }
                        else{
                            std::cout << "Caracterul introdus nu se potriveste !\n";
                        }
                    }

                }

                break;
            }
            case 4:{

                if(obiect.empty()){
                    std::cout << "Inventarul este gol !\n";
                }
                else{
                    std::cout << "\nToate produsele dumneavostra : \n";
                    for(const auto&produs : obiect){
                        std::cout << "-------------------------------------\n";
                        std::cout << "ID: " << produs.first<< "\n";
                        std::cout << "      Nume/Titlu -> " << produs.second.titlu << "\n";
                        std::cout << "      Descriere/Autor -> " << produs.second.autor << "\n";
                        std::cout << "      Pret  -> " << produs.second.pret << " RON\n";
                        std::cout << "      Stoc  -> " << produs.second.stoc << " bucati\n";
                        std::cout << "-------------------------------------\n";
                    }
                }
                break;
            }
            case 0:{
                std::cout << "Multumim pentru folosinta !";
                break;
            }
            default:{
                std::cout << "Ati introdus un numar invalid. Introduceti unul dupa trebuinta : ";
                break;
            }

        }

    }


    return 0;
}
