#include "inc/SyllabCounter.hpp"
#include <string>

int	main(void)
{
	SyllableCounter	sc;
    std::string ver;

    while (1)
    {
        if (!std::getline(std::cin, ver))
            break;
        std::cout << "Syllabes : " <<sc.countVerseSyllables(ver) << std::endl;
    }
	return (0);
}
