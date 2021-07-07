#include "../headers/Stat/StatArchiver.h"
#include "../headers/Dyn/DynArchiver.h"

#include <limits>

#ifndef IOSTREAM
#define IOSTREAM
    #include <iostream>
#endif

int IntConsoleInput(const std::string& message) {
    
    int c = 0;
    std::cout << message;

    std::cin >> c;

    while (std::cin.fail()) {
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Incorrect input! Repeat" << std::endl;
        std::cout << message;
        std::cin >> c;
    }

    return c;
}

bool ChoiceConsoleInput(const std::string& message, const std::string& incorrect) {

    int c = IntConsoleInput(message);

    while((c != 1) && (c != 0)){

        std::cout << std::endl << incorrect << std::endl;
        c = IntConsoleInput(message);
    }

    return static_cast<bool>(c);
}

void ChoiceArchUnarch(Archiver& archiver) {

    std::string nof = "";
    std::string message_c = "If you want to archive - enter 1, unarchive - 0 : ";

    std::string incorrect = "Choose 0 or 1!";

    bool c = ChoiceConsoleInput(message_c, incorrect);

    bool success = false;
    bool exit = false;
    bool no_except = true;

    if (c) {

        while (!success && !exit) {

            no_except = true;

            std::cout << "Enter name of file which you want to archive : ";
            std::cin >> nof;

            try {

                archiver.arch(nof);

            } catch (Archiver::cant_open_file_error& cant_open) {

                no_except = false;

                std::cout << cant_open.what() << " : " << cant_open.get_nof() << std::endl;

                std::string message_e = "Try again - 1, exit - 0\n";
                exit = !ChoiceConsoleInput(message_e, incorrect);
                
            } catch (Archiver::write_in_exist_file_error& arch_file_exist) {
                
                no_except = false;

                std::cout << arch_file_exist.what() << " : " << arch_file_exist.get_nof() << std::endl;
                std::cout << "Delete it or move to another dir before archiving" << std::endl;
            
                exit = true;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (no_except) {

                success = true;
                std::cout << "<< Archiving done! >>" << std::endl;
            }
        }

    } else {

        std::string un_nof = "";

        while (!success && !exit) {

            no_except = true;

            std::cout << "Enter name of file which you want to unarchive : ";
            std::cin >> nof;

            std::string message_un = "Name of unarchived file 1 - custom, 0 - standart : ";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (ChoiceConsoleInput(message_un, incorrect)) {

                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cin >> un_nof;
            }

            try {

                archiver.unarch(nof, un_nof);

            } catch (Archiver::cant_open_file_error& cant_open) {

                no_except = false;

                std::cout << cant_open.what() << " : " << cant_open.get_nof() << std::endl;

                std::string message_e = "Try again - 1, exit - 0\n";
                exit = !ChoiceConsoleInput(message_e, incorrect);
                
            } catch (Archiver::write_in_exist_file_error& arch_file_exist) {
                
                no_except = false;

                std::cout << arch_file_exist.what() << " : " << arch_file_exist.get_nof() << std::endl;
                std::cout << "Delete it or move to another dir before unarchiving" << std::endl;
            
                exit = true;

            } catch (Archiver::file_is_not_archive& file_not_arch) {

                no_except = false;

                std::cout << file_not_arch.what() << " : " << file_not_arch.get_nof() << std::endl;

                std::string message_e = "Try again - 1, exit - 0\n";
                exit = !ChoiceConsoleInput(message_e, incorrect);
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (no_except) {

                success = true;
                std::cout << "<< Unarchiving done! >>" << std::endl;
            }
        }
    }
}

void ConsoleMenu() {

    std::cin.sync();

    std::string message = "Choose archiver dyn - 1, stat - 0 : ";
    std::string incorrect = "Choose 0 or 1!";

    bool c = ChoiceConsoleInput(message, incorrect);

    if (c) {

        DynArchiver darch;
        ChoiceArchUnarch(darch);

    } else {

        StatArchiver sarch;
        ChoiceArchUnarch(sarch);
    }
}

void InteractArchiver(Archiver& archiver, const std::vector<std::string>& args) {

    if (args[1] == "-a") {

        try {

            archiver.arch(args[2]);

        } catch (Archiver::cant_open_file_error& cant_open) {

            std::cout << cant_open.what() << " : " << cant_open.get_nof() << std::endl;
            
        } catch (Archiver::write_in_exist_file_error& arch_file_exist) {
            
            std::cout << arch_file_exist.what() << " : " << arch_file_exist.get_nof() << std::endl;
            std::cout << "Delete it or move to another dir before archiving" << std::endl;
        }

    } else if (args[1] == "-u") {

        try {

            archiver.unarch(args[2], "");

        } catch (Archiver::cant_open_file_error& cant_open) {

            std::cout << cant_open.what() << " : " << cant_open.get_nof() << std::endl;
            
        } catch (Archiver::write_in_exist_file_error& arch_file_exist) {
            
            std::cout << arch_file_exist.what() << " : " << arch_file_exist.get_nof() << std::endl;
            std::cout << "Delete it or move to another dir before unarchiving" << std::endl;

        } catch (Archiver::file_is_not_archive& file_not_arch) {

            std::cout << file_not_arch.what() << " : " << file_not_arch.get_nof() << std::endl;
        }

    } else {

       std::cout << "Incorrect argument! Type -h for help";
    }
}

void LinuxStyleMenu(const std::vector<std::string>& args) {

    if (args[0] == "-s") {
        
        StatArchiver sarchiver;
        InteractArchiver(sarchiver, args);

    } else if (args[0] == "-d") {

        DynArchiver darchiver;
        InteractArchiver(darchiver, args);

    } else {

        std::cout << "Incorrect argument! Type -h for help";
    }
}

void Help() {

    std::cout << "-h -- for help" << std::endl;
    std::cout << "-s -a [name_of_file] -- make archive with static method" << std::endl;
    std::cout << "-s -u [name_of_stat_archive] -- unarchive static archive" << std::endl;
    std::cout << "-d -a [name_of_file] -- make archive with dynamic method" << std::endl;
    std::cout << "-d -u [name_of_dyn_archive] -- unarchive dynamic archive" << std::endl;
}

int main(int argc, char * argv[]) {

    const int needLStyleNumOfArgs = 4;

    if ((argc > needLStyleNumOfArgs) || (argc == 3)) {

        std::cout << "Incorrect number of arguments! Type -h for help";
        return 0;
    }

    std::vector<std::string> args;

    for (int i = 1; i < argc; ++i) {
        
        args.emplace_back(argv[i]);
    }

    if (argc == 1) {

        ConsoleMenu();

    } else if (argc == 2) {

        if (args[0] == "-h") {

            Help();

        } else {

            std::cout << "Incorrect argument! Type -h for help";
        }

    } else {

        LinuxStyleMenu(args);
    }

    return 0;
}
