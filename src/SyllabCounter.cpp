#include "../inc/SyllabCounter.hpp"
#include "../inc/Color.hpp"
#include <fstream>

SyllableCounter::SyllableCounter(void) {}

SyllableCounter::SyllableCounter(SyllableCounter const &src)
{
	*this = src;
}

SyllableCounter::~SyllableCounter(void) {}

SyllableCounter &SyllableCounter::operator=(SyllableCounter const &rhs)
{
	(void)rhs;
	return (*this);
}

bool SyllableCounter::_isVowel(std::string const &s, size_t &i) const
{
    std::string v = "aeiouyAEIOUY";

    if (v.find(s[i]) != std::string::npos)
    {
        return (true);
    }

    if (static_cast<unsigned char>(s[i]) == 0xC3 && i + 1 < s.length())
    {
        i++;
        return (true);
    }
    return (false);
}

bool	SyllableCounter::_startsWithVowel(std::string const &word) const
{
	if (word.empty())
		return (false);
	size_t i = 0;
	return (this->_isVowel(word, i));
}

int		SyllableCounter::_countWordSyllables(std::string const &word, bool isLastWord, bool nextStartsVowel) const
{
	int count = 0;
	bool    inVowelGroup = false;

	for (size_t i = 0; i < word.length(); ++i)
	{
		size_t startIdx = i;
		if (this->_isVowel(word, i))
		{
			if (!inVowelGroup)
			{
				/* Règle de l'élision du 'e' muet */
				if ((word[startIdx] == 'e' || word[startIdx] == 'E') && startIdx == word.length() - 1)
				{
					if (isLastWord || nextStartsVowel)
						continue ;
				}
				count++;
				inVowelGroup = true;
			}
		}
		else
			inVowelGroup = false;
	}
	return (count == 0 && !word.empty() ? 1 : count);
}

int		SyllableCounter::countVerseSyllables(std::string const &verse) const
{
	std::vector<std::string>	words;
	size_t  start = 0;
	size_t  end = verse.find(' ');
	int total = 0;

	while (end != std::string::npos)
	{
		if (end > start)
			words.push_back(verse.substr(start, end - start));
		start = end + 1;
		end = verse.find(' ', start);
	}
	if (start < verse.length())
		words.push_back(verse.substr(start));

	for (size_t i = 0; i < words.size(); ++i)
	{
		bool isLastWord = (i == words.size() - 1);
		bool nextVowel = (!isLastWord && _startsWithVowel(words[i + 1]));
		total += _countWordSyllables(words[i], isLastWord, nextVowel);
	}
	return (total);
}

void SyllableCounter::addVerse(std::string const &verse)
{
    this->_poem.push_back(verse);
    std::cout << GREEN << "Added : " <<  RESET << verse << std::endl;
}

void SyllableCounter::displayPoem() const
{
    int size = this->_poem.size();
    if (!size)
        return;
    std::cout << YELLOW << "Poem : " << RESET << std::endl;
    for (int i = 0; i < size; i++)
    {
         std::cout << this->_poem.at(i) << std::endl;
    }
}

void SyllableCounter::savePoem(std::string &filename) const
{
    int size = this->_poem.size();
    if (!size)
    {
        std::cerr << RED << "Error: poem empty" << RESET << std::endl;
        return;
    }

    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
        throw SyllableCounter::FileNotOpenException();

    for (int i = 0; i < size; i++)
        outfile << this->_poem.at(i) << std::endl;
    outfile.close();
    std::cout << GREEN << "Save the poem as " << YELLOW << filename << RESET << std::endl;
}
