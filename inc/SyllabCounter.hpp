#ifndef SYLLABLECOUNTER_HPP
# define SYLLABLECOUNTER_HPP

# include <iostream>
# include <string>
# include <vector>

class SyllableCounter
{
	public:
		SyllableCounter(void);
		SyllableCounter(SyllableCounter const &src);
		~SyllableCounter(void);
		SyllableCounter &operator=(SyllableCounter const &rhs);

		int	countVerseSyllables(std::string const &verse) const;

	private:
		bool	_isVowel(std::string const &s, size_t &i) const;
		bool	_startsWithVowel(std::string const &word) const;
		int		_countWordSyllables(std::string const &word, bool isLastWord, bool nextStartsVowel) const;
};

#endif
