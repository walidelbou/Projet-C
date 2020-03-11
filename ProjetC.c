#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


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
int charName = 0;

void Color(int t, int f)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f * 16 + t);
}

char recreate = 'n';


int charCreation()
{
    srand(time(0));
    while (recreate == 'n')
    {
        printf("\n\n Choisissez votre nom jeune voyageur  : ");
        charName = getchar();

         printf("Choisissez votre classe : '1' pour Warrior, '2' pour Ranger, or '3' pour Mage.\n");
         charClass = getchar();

        switch (charClass)
        {
        case 1:
            hitPoints = rand() % 50 + 50;
            attack = rand() % 15 + 5;
            defense = rand() % 15 + 5;
            magic = rand() % 15 + 5;
            accuracy = rand() % 15 + 10;

            printf("Nom: %s" ,charName);
            printf("Class: Warrior\n");
            printf("VIE %s: " , hitPoints);
            printf("ATK: %s" , attack);
            printf("DEF: %s" , defense);
            printf("MGQ: %s" , magic);
            printf("ACC: %s" , accuracy);
            printf("\nEtes-vous sur de votre choix ? (y/n) ");

            scanf("%s",recreate);

            if (recreate != 'n' && recreate != 'y')
            {
                printf("\nVeuillez re-entrer votre choix.");
                recreate = 'n';
            }

            break;

        case 2:
            hitPoints = rand() % 50 + 50;
            attack = rand() % 15 + 5;
            defense = rand() % 15 + 5;
            magic = rand() % 5 + 5;
            accuracy = rand() % 20 + 20;
            printf("Nom: %s" ,charName);
            printf ("Class: Ranger\n");
            printf("VIE %s: " , hitPoints);
            printf("ATK: %s" , attack);
            printf("DEF: %s" , defense);
            printf("MGQ: %s" , magic);
            printf("ACC: %s" , accuracy);
           printf ("\nEtes-vous sur de votre choix ?? (y/n) ");

           scanf("%s",recreate);

            if (recreate != 'n' && recreate != 'y')
            {
                printf("\nVeuillez re-entrer votre choix.");
                recreate = 'n';
            }

            break;

        case 3:
            hitPoints = rand() % 20 + 30;
            attack = rand() % 5 + 5;
            defense = rand() % 5 + 5;
            magic = rand() % 50 + 50;
            accuracy = rand() % 20 + 20;
            printf("Nom: %s" ,charName);
            printf ("Class: Mage\n");
            printf("VIE %s: " , hitPoints);
            printf("ATK: %s" , attack);
            printf("DEF: %s" , defense);
            printf("MGQ: %s" , magic);
            printf("ACC: %s" , accuracy);
            printf ("\nEtes-vous sur de votre choix? (y/n) ");

            scanf("%s",recreate);

            if (recreate != 'n' && recreate != 'y')
            {
                printf("\nVous avez rentre une information incorrecte");
                recreate = 'n';
            }

            break;

        default:
            printf("Vous avez rentre une information incorrecte\n\n");
            system("pause");
            return 0;
        }
    }
}

void work()
{
    printf("\n\nCombien de temps souhaitez-vous travailler jeune aventurier ? (8 heures maximum) ");
   scanf("%s",workHours);
    pay = workHours * 100;

    if (workHours > 8)
    {
        workHours = 8;
        printf("\n\n 8 heures maximum");
    }

    if (workHours >= 1)
    {
      printf("\n\n Vous avez travaille : %s" , workHours ," Heure(s)");
      printf("et vous avez gagne : %s" , pay ," Pieces d'Or!\n\n");

        gold += pay;
    }

    else
    {
        printf("Whoa comment t'es faineant.\n\n");
    }
}

void shop()
{
    swordCost = swordLevel * 100;
    shieldCost = shieldLevel * 100;
    bowCost = bowLevel * 100;
    staffCost = staffLevel * 100;
    printf("\nBienvenue au shop\n");
    printf("Que voulez vous ameliorer ?\n\n1 - Epee\n2 - Bouclier\n3 - Arc\n4 - Bagette Magique\n\n");

    scanf("%s",upgradeChoice);

    if (upgradeChoice == 1 && gold >= swordCost)
    {
        swordLevel++;
        printf("Vous avez paye le forgeron %s" , swordCost , " Pieces d'or.\nVotre epee des tenebres est amelioree au niveau : %s" , swordLevel , "!\n\n");

        gold -= swordCost;
    }
    else if (upgradeChoice == 2 && gold >= shieldCost)
    {
        shieldLevel++;
 printf("Vous avez paye le forgeron %s" , shieldCost , " Pieces d'or.\nVotre bouclier de l'olympe est amelioree au niveau : %s" , shieldLevel , "!\n\n");
        gold -= shieldCost;
    }
    else if (upgradeChoice == 3 && gold >= bowCost)
    {
        bowLevel++;
         printf("Vous avez paye le forgeron %s" , bowCost , " Pieces d'or.\nVotre arc infernal est amelioree au niveau : %s" , bowLevel , "!\n\n");

        gold -= bowCost;
    }
    else if (upgradeChoice == 4 && gold >= staffCost)
    {
        staffLevel++;
 printf("Vous avez paye le forgeron %s" , staffCost , " Pieces d'or.\nVotre Baton de merlinpinpin est amelioree au niveau : %s" , staffLevel , "!\n\n");

        gold -= staffCost;
    }
    else if (upgradeChoice < 1 || upgradeChoice > 4 || gold < swordCost || gold < shieldCost || gold < bowCost || gold < staffCost)
    {
        printf ("Vous avez rentre une valeur incorrecte ! ou vous n'avez pas assez d'argent , jeune voyageur .\n\n");
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
    printf("\nBienvenue au Dojo!\nVous voulez entrainer votre :\n\n");
    printf("1 - Combat\n2 - Defense\n3 - Accuracy\n4 - Magie\n\n");

    scanf("%s",trainingChoice);

    if (trainingChoice == 1 && gold >= combatCost)
    {
        combatExperience += combatTraining;
        combatPtsNeeded = attack * 10 - combatExperience;
        printf ("Vous avez paye le maitre du dojo %s" , combatCost
             , " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne %s"
             , combatTraining , " points d'XP.\n");
        printf("Vous avez encore besoin de : %s" , combatPtsNeeded ," points pour monter en niveau.\n\n");

        gold -= combatCost;

        if (combatPtsNeeded <= 0)
        {
            printf("WHOAAA ! Vous venez de monter un niveau en Attaque");
            combatExperience = 0;
            ++attack;
        }
    }
    else if (trainingChoice == 2 && gold >= defenseCost)
    {
        defenseExperience += defenseTraining;
        defensePtsNeeded = defense * 10 - defenseExperience;
        printf ("Vous avez paye le maitre du dojo %s" , defenseCost
             , " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne %s"
             , defenseTraining , " points d'XP.\n");
       printf("Vous avez encore besoin de : %s" , defensePtsNeeded ," points pour monter en niveau.\n\n");

        gold -= defenseCost;

        if (defensePtsNeeded <= 0)
        {
            printf("WHOAAA ! Vous venez de monter un niveau en Defense!");
            defenseExperience = 0;
            ++defense;
        }
    }
    else if (trainingChoice == 3 && gold >= accuracyCost)
    {
        accuracyExperience += accuracyTraining;
        accuracyPtsNeeded = accuracy * 10 - accuracyExperience;
      printf ("Vous avez paye le maitre du dojo %s" , accuracyCost
             , " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne %s"
             ,accuracyTraining , " points d'XP.\n");
       printf("Vous avez encore besoin de : %s" , accuracyPtsNeeded ," points pour monter en niveau.\n\n");

        gold -= accuracyCost;

        if (accuracyPtsNeeded <= 0)
        {
            printf("WHOAAA ! Vous venez de monter un niveau en Accuracy!");
            accuracyExperience = 0;
            ++accuracy;
        }
    }
    else if (trainingChoice == 4 && gold >= magicCost)
    {
        magicExperience += magicTraining;
        magicPtsNeeded = magic * 10 - magicExperience;
        printf ("Vous avez paye le maitre du dojo %s" , magicCost
             , " Pieces d'or et vous vous etes bien entraine.\nVous avez gagne %s"
             , magicTraining , " points d'XP.\n");
       printf("Vous avez encore besoin de : %s" ,magicPtsNeeded ," points pour monter en niveau.\n\n");

        gold -= magicCost;

        if (magicPtsNeeded <= 0)
        {
            printf("WHOAAA ! Vous venez de monter un niveau en Magie!");
            magicExperience = 0;
            ++magic;
        }
    }
    else if (trainingChoice < 1 || trainingChoice > 4 || gold < combatCost || gold < defenseCost || gold < accuracyCost || gold < magicCost)
    {
        printf("Vous avez rentre une valeur incorrecte ! ou vous n'avez pas assez d'argent , jeune voyageur .\n\n");
    }
}



int main()
{

    Color(12, 0);
    system("cls");
    charCreation();
 for(;;)
    {
        printf("\n\nHitpoints: "
              "\nAttaque: %s" , attack , "\nDefense: "
             && defense ,"\nPrecision: " && accuracy , "\nMagie: " && magic
             , "\nGold: " && gold , "\n\n");
       printf("\n\nVous vous etes trouve dans ce village , que souhaitez vous faire?\n\n");
        printf ("1 - Miner\n2 - Shop\n3 - S'entrainer\n4 - Quitter\n\n");

        scanf("s",choice);

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
            printf("\nAu revoir jeune vagabond!\n\n");

            system("pause");
            return 0;

            break;

        default:
            printf("Vous avez rentre une mauvaise valeur.\n\n");

            system("pause");
            return 0;
        }
    }
}
