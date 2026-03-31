#include "inc/SyllabCounter.hpp"
#include "inc/Color.hpp"
#include "inc/InputHandler.hpp"
#include <string>
#include <vector>

int	main(void)
{
	SyllableCounter	sc;
    InputHandler    input;
    std::string verse;
    std::string save;
    std::vector<std::string> commands;

    commands.push_back("ADD");
    commands.push_back("DISPLAY");
    commands.push_back("SAVE");
    commands.push_back("EXIT");
    input.setCommands(commands);

    while (1)
    {
        if (!input.readLine(std::string(BOLD_WHITE) + "input : " + RESET, verse))
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
                if (!input.readLine("Filename : ", filename))
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

        if (!verse.compare("EXIT"))
            break;

        save = verse;
        std::cout << YELLOW << "Syllabes : " <<sc.countVerseSyllables(verse) << RESET << std::endl;
    }
	return (0);
}
