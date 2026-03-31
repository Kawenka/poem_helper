#include "inc/SyllabCounter.hpp"
#include "inc/Color.hpp"
#include <string>

int	main(void)
{
	SyllableCounter	sc;
    std::string verse;
    std::string save;

    while (1)
    {
        std::cout << BOLD_WHITE << "input : " << RESET;
        if (!std::getline(std::cin, verse))
            break;

        if (!verse.compare("ADD"))
        {
            sc.addVerse(save);
            continue;
        }

        if (!verse.compare("DISPLAY"))
        {
            sc.displayPoem();
            continue;
        }

        if (!verse.compare("SAVE"))
        {
            try
            {
                std::string filename;
                std::cout << "Filename : ";
                if (!std::getline(std::cin, filename))
                {
                    std::cout << RED << "Failed" << RESET << std::endl;
                    continue;
                }
                sc.savePoem(filename);
                continue;
            }
            catch(const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                continue;
            }
        }

        save = verse;
        std::cout << YELLOW << "Syllabes : " <<sc.countVerseSyllables(verse) << RESET << std::endl;
    }
	return (0);
}
