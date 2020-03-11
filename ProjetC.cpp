#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int gold = 500, workHours = 0, pay = 0;
int choice = 0, upgradeChoice = 0, trainingChoice = 0;
int attack = 10, defense = 10, hitPoints = 0, magic = 0, accuracy = 0;
int combatExperience = 0, defenseExperience = 0, accuracyExperience = 0, magicExperience = 0;
int swordLevel = 1, combatTraining = 0;
int shieldLevel = 1, defenseTraining = 0;
int bowLevel = 1, staffLevel = 1;
int accuracyTraining = 0, magicTraining = 0;
int swordCost = 0, shieldCost = 0, bowCost = 0, staffCost = 0;
int combatCost = 0, defenseCost = 0, accuracyCost = 0, magicCost = 0;
int combatPtsNeeded = 0;
int defensePtsNeeded = 0;
int accuracyPtsNeeded = 0;
int magicPtsNeeded = 0;
int charClass = 0;

char recreate = 'n';

string charName = "";

int charCreation()
{
    srand(time(0));
    while (recreate == 'n')
    {
        cout << "\n\n Choisissez votre nom jeune voyageur  : ";
        cin >> charName;

        cout << "Choisissez votre classe : '1' pour Warrior, '2' pour Ranger, or '3' pour Mage.\n";
        cin >> charClass;

        switch (charClass)
        {
        case 1:
            hitPoints = rand() % 50 + 50;
            attack = rand() % 15 + 5;
            defense = rand() % 15 + 5;
            magic = rand() % 15 + 5;
            accuracy = rand() % 15 + 10;

            cout << "Name: " << charName << endl;
            cout << "Class: Warrior\n";
            cout << "HP: " << hitPoints << endl;
            cout << "ATK: " << attack << endl;
            cout << "DEF: " << defense << endl;
            cout << "MGK: " << magic << endl;
            cout << "ACC: " << accuracy << endl;
            cout << "\nEtes vous sur de votre choix ? (y/n) ";

            cin >> recreate;

            if (recreate != 'n' && recreate != 'y')
            {
                cout << "\nVeuillez re-entrer votre choix.";
                recreate = 'n';
            }

            break;

        case 2:
            hitPoints = rand() % 50 + 50;
            attack = rand() % 15 + 5;
            defense = rand() % 15 + 5;
            magic = rand() % 5 + 5;
            accuracy = rand() % 20 + 20;
            cout << "Name: " << charName << endl;
            cout << "Class: Ranger\n";
            cout << "HP: " << hitPoints << endl;
            cout << "ATK: " << attack << endl;
            cout << "DEF: " << defense << endl;
            cout << "MGK: " << magic << endl;
            cout << "ACC: " << accuracy << endl;
            cout << "\nEtes vous sur de votre choix ?? (y/n) ";

            cin >> recreate;

            if (recreate != 'n' && recreate != 'y')
            {
                cout << "\nVeuillez re-entrer votre choix.";
                recreate = 'n';
            }

            break;

        case 3:
            hitPoints = rand() % 20 + 30;
            attack = rand() % 5 + 5;
            defense = rand() % 5 + 5;
            magic = rand() % 50 + 50;
            accuracy = rand() % 20 + 20;
            cout << "Name: " << charName << endl;
            cout << "Class: Mage\n";
            cout << "HP: " << hitPoints << endl;
            cout << "ATK: " << attack << endl;
            cout << "DEF: " << defense << endl;
            cout << "MGK: " << magic << endl;
            cout << "ACC: " << accuracy << endl;
            cout << "\nEtes vous sur de votre choix? (y/n) ";

            cin >> recreate;

            if (recreate != 'n' && recreate != 'y')
            {
                cout << "\nVous avez rentre une information incorrecte";
                recreate = 'n';
            }

            break;

        default:
            cout << "Vous avez rentre une information incorrecte\n\n";
            system("pause");
            return 0;
        }
    }
}

void work()
{
    cout << "\n\nCombien de temps souhaitez vous travailler jeune aventurier ? (8 heures maximum) ";
    cin >> workHours;
    pay = workHours * 100;

    if (workHours > 8)
    {
        workHours = 8;
        cout << "\n\n 8 heures maximum";
    }

    if (workHours >= 1)
    {
        cout << "\n\nVous avez travaille : " << workHours
             << " Heure(s) et vous avez gagne : " << pay << " Pieces d'Or!\n\n";

        gold += pay;
    }

    else
    {
        cout << "Whoa comment t'es faineant.\n\n";
    }
}

void shop()
{
    swordCost = swordLevel * 100;
    shieldCost = shieldLevel * 100;
    bowCost = bowLevel * 100;
    staffCost = staffLevel * 100;
    cout << "\nBienvenue au shop\n";
    cout << "Que voulez vous ameliorer ?\n\n1 - Sword\n2 - Shield\n3 - Bow\n4 - Staff\n\n";

    cin >> upgradeChoice;

    if (upgradeChoice == 1 && gold >= swordCost)
    {
        swordLevel++;
        cout << "Vous avez paye le forgeron " << swordCost
             << " Pieces d'or.\nVotre epee des tenebres est amelioree au niveau : "
             << swordLevel << "!\n\n";

        gold -= swordCost;
    }
    else if (upgradeChoice == 2 && gold >= shieldCost)
    {
        shieldLevel++;
        cout << "Vous avez paye le forgeron " << shieldCost
             << " Pieces d'or.\nVotre Shield de l'olympe est ameliore au niveau "
             << shieldLevel << "!\n\n";

        gold -= shieldCost;
    }
    else if (upgradeChoice == 3 && gold >= bowCost)
    {
        bowLevel++;
        cout << "Vous avez paye le forgeron " << bowCost
             << " Pieces d'or.\nVotre arc infernale est ameliore au niveau : "
             << bowLevel << "!\n\n";

        gold -= bowCost;
    }
    else if (upgradeChoice == 4 && gold >= staffCost)
    {
        staffLevel++;
        cout << "Vous avez paye le forgeron " << staffCost
             << " Pieces d'or.\nVotre Baton Celeste est ameliore au niveau : "
             << staffLevel << "!\n\n";

        gold -= staffCost;
    }
    else if (upgradeChoice < 1 || upgradeChoice > 4 || gold < swordCost || gold < shieldCost || gold < bowCost || gold < staffCost)
    {
        cout << "Vous avez rentre une valeur incorrecte ! ou vous n'avez pas assez d'argent , jeune voyageur .\n\n";
    }
}

void train()
{
    combatCost = attack * 10;
    defenseCost = defense * 10;
    accuracyCost = accuracy * 10;
    magicCost = magic * 10;
    combatTraining = swordLevel * 5;
    defenseTraining = shieldLevel * 5;
    accuracyTraining = bowLevel * 5;
    magicTraining = staffLevel * 5;
    cout << "\nBienvenue au Dojo!\nVous voulez entrainer votre :\n\n";
    cout << "1 - Combat\n2 - Defense\n3 - Accuracy\n4 - Magie\n\n";

    cin >> trainingChoice;

    if (trainingChoice == 1 && gold >= combatCost)
    {
        combatExperience += combatTraining;
        combatPtsNeeded = attack * 10 - combatExperience;
        cout << "Vous avez paye le maitre du dojo " << combatCost
             << " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne "
             << combatTraining << " points d'XP.\n";
        cout << "Vous avez encore besoin de : " << combatPtsNeeded
             << " points pour monter en niveau.\n\n";

        gold -= combatCost;

        if (combatPtsNeeded <= 0)
        {
            cout << "WHOAAA ! Vous venez de monter un niveau en Attaque";
            combatExperience = 0;
            ++attack;
        }
    }
    else if (trainingChoice == 2 && gold >= defenseCost)
    {
        defenseExperience += defenseTraining;
        defensePtsNeeded = defense * 10 - defenseExperience;
        cout << "Vous avez paye le maitre du dojo " << defenseCost
             << " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne "
             << defenseTraining << " points d'XP.\n";
        cout << "Vous avez encore besoin de :  " << defensePtsNeeded
             << " points pour monter en niveau.\n\n";

        gold -= defenseCost;

        if (defensePtsNeeded <= 0)
        {
            cout << "WHOAAA ! Vous venez de monter un niveau en Defense!";
            defenseExperience = 0;
            ++defense;
        }
    }
    else if (trainingChoice == 3 && gold >= accuracyCost)
    {
        accuracyExperience += accuracyTraining;
        accuracyPtsNeeded = accuracy * 10 - accuracyExperience;
        cout << "Vous avez paye le maitre du dojo " << accuracyCost
             << " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne "
             << accuracyTraining << " points d'XP.\n " ;
        cout << "Vous avez encore besoin de :  " << accuracyPtsNeeded
             << " points pour monter en niveau.\n\n";

        gold -= accuracyCost;

        if (accuracyPtsNeeded <= 0)
        {
            cout << "WHOAAA ! Vous venez de monter un niveau en Accuracy!";
            accuracyExperience = 0;
            ++accuracy;
        }
    }
    else if (trainingChoice == 4 && gold >= magicCost)
    {
        magicExperience += magicTraining;
        magicPtsNeeded = magic * 10 - magicExperience;
        cout << "Vous avez paye le maitre du dojo " << magicCost
             << " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne "
             << magicTraining << " points d'XP.\n; " ;
        cout << "Vous avez encore besoin de :  " << magicPtsNeeded
             << " points pour monter en niveau.\n\n";

        gold -= magicCost;

        if (magicPtsNeeded <= 0)
        {
            cout << "WHOAAA ! Vous venez de monter un niveau en Magie!";
            magicExperience = 0;
            ++magic;
        }
    }
    else if (trainingChoice < 1 || trainingChoice > 4 || gold < combatCost || gold < defenseCost || gold < accuracyCost || gold < magicCost)
    {
        cout << "Vous avez rentre une valeur incorrecte ! ou vous n'avez pas assez d'argent , jeune voyageur .\n\n";
    }
}

void arena()
{
    cout << "\t\t\tBienvenue dans l'arene , preparez vous a affronter des betes feroces ! " ;
    combatPtsNeeded = attack * 10 - combatExperience;
    defensePtsNeeded = defense * 10 - defenseExperience;
    magicPtsNeeded = magic * 10 - magicExperience;

}
int main()
{
    cout << "\t\t\tBienvenue Au monde des douzes jeune Vagabond! . Fait par : Walid , Mohammed ";

    charCreation();

    while (true)
    {
        cout << "\n\nHitpoints: "
             << "\nAttack: " << attack << "\nDefense: "
             << defense << "\nAccuracy: " << accuracy << "\nMagic: " << magic
             << "\nGold: " << gold << "\n\n";
        cout << "\n\nVous vous etes trouve dans ce village , que souhaitez vous faire?\n\n";
        cout << "1 - Miner\n2 - Shop\n3 - S'entrainer\n4 - Quitter\n\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            work();

            break;

        case 2:
            shop();

            break;

        case 3:
            train();

            break;

        case 4:
            cout << "\nAu revoir jeune vagabond!\n\n";

            system("pause");
            return 0;

            break;

        default:
            cout << "Vous avez rentre une mauvaise valeur.\n\n";

            system("pause");
            return 0;
        }
    }
}
