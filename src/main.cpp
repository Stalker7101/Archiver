#ifndef STATARCHIVER
#define STATARCHIVER
    #include "../headers/Stat/StatArchiver.h"
#endif

#ifndef DYNARCHIVER
#define DYNARCHIVER
    #include "../headers/Dyn/DynArchiver.h"
#endif

#ifndef IOSTREAM
#define IOSTREAM
    #include <iostream>
#endif

int main() {

    int c = 0; 
    std::string nof;

    std::cout << "Choose archiver 0 - stat, 1 - dyn : ";
    std::cin >> c;

    if(c == 1){

        DynArchiver darchiver;

        std::cout << "If you want to archive - enter 1, else - 0 : ";
        std::cin >> c;

        if(c == 1){

            std::cout << "Enter name of file which you want to archive : ";
            std::cin >> nof;
            std::cout << "\nArchiving...";
            darchiver.arch(nof);
            std::cout << std::endl << "Done!";

        } else if(c == 0) {

            std::cout << "Enter name of file which you want to unarchive : ";
            std::cin >> nof;
            std::cout << "\nUnrchiving...";
            darchiver.unarch(nof);
            std::cout << std::endl << "Done!";
        }

    } else {

        StatArchiver sarchiver;

        std::cout << "If you want to archive - enter 1, else - 0 : ";
        std::cin >> c;

        if(c == 1){

            std::cout << "Enter name of file which you want to archive : ";
            std::cin >> nof;
            std::cout << "\nArchiving...";
            sarchiver.arch(nof);
            std::cout << std::endl << "Done!";

        } else if(c == 0) {

            std::cout << "Enter name of file which you want to unarchive : ";
            std::cin >> nof;
            std::cout << "\nUnrchiving...";
            sarchiver.unarch(nof);
            std::cout << std::endl << "Done!";
        }
    }

    return 0;
}
