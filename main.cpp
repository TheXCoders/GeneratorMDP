#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "random.hpp"

using namespace std;
using Random = effolkronium::random_static;


string mdpLv1(int t)
{
    int taille = t;
    string mdp;
    srand((unsigned int)time(nullptr));
    char alphabet[26] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    if(taille == 0)
    {
        taille = Random::get(6, 10);
    }

    for(int i = 0; i < taille; i++)
    {
        mdp += alphabet[rand()%26 + 0];
    }

    return mdp;
}

string mdpLv2(int t)
{
    int taille = t;
    string mdp;
    char alphabet[26] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char chiffre[10] {'0','1','2','3','4','5','6','7','8','9'};

    if(taille == 0)
    {
        taille = Random::get(6, 10);
    }

    for(int i = 0; i < taille; i++)
    {
        int type = Random::get(1, 2);

        if(type == 1)
            mdp += alphabet[Random::get(0, 25)];
        else
            mdp += chiffre[Random::get(0, 9)];
    }

    return mdp;
}

string mdpLv3(int t)
{
    int taille = t;
    string mdp;
    char alphabet[26] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetUp[26] {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char charSp[5] {'&','~','@','*','%'};

    if(taille == 0)
    {
        taille = Random::get(6, 10);
    }

    for(int i = 0; i < taille; i++)
    {
        int type = Random::get(1, 3);

        if(type == 1)
            mdp += alphabet[Random::get(0, 25)];
        else if (type == 2)
            mdp += alphabetUp[Random::get(0, 25)];
        else
            mdp += charSp[Random::get(0, 4)];
    }

    return mdp;
}

string mdpLv4(int t)
{
    int taille = t;
    string mdp;
    char alphabet[26] {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alphabetUp[26] {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char chiffre[10] {'0','1','2','3','4','5','6','7','8','9'};
    char charSp[5] {'&','~','@','*','%'};

    if(taille == 0)
    {
        taille = Random::get(6, 10);
    }

    for(int i = 0; i < taille; i++)
    {
        int type = Random::get(1, 4);

        if(type == 1)
            mdp += alphabet[Random::get(0, 25)];
        else if (type == 2)
            mdp += alphabetUp[Random::get(0, 25)];
        else if (type == 3)
            mdp += chiffre[Random::get(0, 9)];
        else
            mdp += charSp[Random::get(0, 4)];
    }

    return mdp;
}

int main(int argc, char *argv[])
{ 
    vector <string> arg{};

    for(int i = 0; i < argc; i++)
    {
        arg.push_back(argv[i]);
    }
    int taille = 0;
    cout << "Bienvenue dans le g" <<char (0x82)<< "n" <<char (0x82)<<"rateur de mot de passe" << endl;
    if(argc == 1)
    {
        cout << " \n -taille / t : D"<< char (0x82)<<"finie la taille du mot de passe, si aucun arguments n'est passé alors la taille sera d'un longueur al" <<char (0x82)<< "atoire entre 6 et 10 compris.\n"

                "-niveau / nv : D"<< char (0x82)<<"finie la duret"<< char (0x82) << " du mot de passe, de 1 "<< char (0x85)<<" 4.\n"

                "       -1 mdp simple sans chiffres ni caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. \n"

                "       -2 mdp avec chiffres mais sans caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. \n"

                "       -3 mdp avec caract"<< char (0x8A)<<"re sp"<< char (0x82)<<"ciaux sans chiffres. \n"

                "       -4 mdp avec des chiffres et des caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. " << endl;
    }
    else
    {
        for(int i = 0; i < arg.size(); i++)
        {
            if(arg[i] == "t" || arg[i] == "taille")
                taille = atoi(arg[i+1].c_str());
        }

        for(int i = 0; i < arg.size(); i++)
        {
            if(arg[i] == "nv" || arg[i] == "niveau")
            {
                if(arg[i+1] == "1")
                {

                   cout << "Votre mot de passe est : " << mdpLv1(taille) << endl;
                }
                else if(arg[i+1] == "2")
                {
                   cout << "Votre mot de passe est : " << mdpLv2(taille) << endl;

                }
                else if(arg[i+1] == "3")
                {
                    cout << "Votre mot de passe est : " << mdpLv3(taille) << endl;

                }
                else if(arg[i+1] == "4")
                {
                    cout << "Votre mot de passe est : " << mdpLv4(taille) << endl;
                }
                else
                {
                    cout << "-taille / t : D"<< char (0x82)<<"finie la taille du mot de passe, si aucun arguments n'est pass"<< char (0x82) << " alors la taille sera d'un longueur al" <<char (0x82)<< "atoire entre 6 et 10 compris.\n"

                            "-niveau / nv : D"<< char (0x82)<<"finie la duret"<< char (0x82) << " du mot de passe, de 1 "<< char (0x85)<<" 4.\n"

                            "       -1 mdp simple sans chiffres ni caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. \n"

                            "       -2 mdp avec chiffres mais sans caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. \n"

                            "       -3 mdp avec caract"<< char (0x8A)<<"re sp"<< char (0x82)<<"ciaux sans chiffres. \n"

                            "       -4 mdp avec des chiffres et des caract"<< char (0x8A)<<"res sp"<< char (0x82)<<"ciaux. " << endl;
                }
            }
        }


    }

    return 0;
}

