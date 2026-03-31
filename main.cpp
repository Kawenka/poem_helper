#include "inc/SyllabCounter.hpp"
#include "inc/Color.hpp"
#include <string>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

static bool readPromptLine(const std::string &prompt, std::string &out)
{
    char *line = readline(prompt.c_str());

    if (!line)
        return (false);
    out = line;
    if (!out.empty())
        add_history(line);
    std::free(line);
    return (true);
}

int	main(void)
{
	SyllableCounter	sc;
    std::string verse;
    std::string save;

    while (1)
    {
        if (!readPromptLine(std::string(BOLD_WHITE) + "input : " + RESET, verse))
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
                if (!readPromptLine("Filename : ", filename))
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
