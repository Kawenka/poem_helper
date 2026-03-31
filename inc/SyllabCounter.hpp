#ifndef SYLLABLECOUNTER_HPP
# define SYLLABLECOUNTER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>

class SyllableCounter
{
	public:
		SyllableCounter( void );
		SyllableCounter( SyllableCounter const &src );
		~SyllableCounter( void );
		SyllableCounter &operator=( SyllableCounter const &rhs );

		int	countVerseSyllables( std::string const &verse ) const;
        void addVerse( std::string const &verse );
        void displayPoem( void ) const;
        void savePoem( std::string &filename ) const;

        class FileNotOpenException : std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("\033[31mCould not open file.\033[0m");
                }
        };

	private:
        std::vector<std::string> _poem;
		bool	_isVowel( std::string const &s, size_t &i ) const;
		bool	_startsWithVowel( std::string const &word ) const;
		int		_countWordSyllables( std::string const &word, bool isLastWord, bool nextStartsVowel ) const;
        std::string _getTypeVerse( std::string const &verse ) const;
};

#endif
