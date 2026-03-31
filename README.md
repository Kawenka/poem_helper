# Poem Helper

Poem Helper is a C++98 command-line assistant for writing French poetry.
It counts syllables, stores verses in memory, displays annotated lines, and exports poems to a text file.

## Features

- Syllable counting for French-like versification rules.
- Verse classification (Monosyllabe -> Alexandrin -> Vers long).
- Poem management in memory (`ADD`, `DISPLAY`).
- File export (`SAVE`).
- Interactive shell with GNU Readline:
  - Up/Down arrow history navigation.
  - Tab autocompletion for commands.
- ANSI color output for readability.

## Dependencies

- C++ compiler (`c++`) with C++98 support.
- GNU Readline development library.

On Debian/Ubuntu:

```sh
sudo apt update
sudo apt install build-essential libreadline-dev
```

## Build And Run

```sh
make
./poem_helper
```

Useful targets:

```sh
make clean
make fclean
make re
```

## Commands

At the main prompt (`input :`):

- `ADD`: add the last entered verse to the poem buffer.
- `DISPLAY`: show all stored verses with syllable count and verse type.
- `SAVE`: ask for a filename and export the poem.
- `EXIT`: quit the program.

Keyboard behavior:

- `Tab`: autocomplete available commands.
- `Up` / `Down`: navigate command history.
- `Ctrl+D`: quit (EOF).

## Example Session

```text
input : Demain des l'aube
Syllabes : 4
input : ADD
Added : Demain des l'aube
input : DISPLAY
Poem :
1. Demain des l'aube Count : 4 (Tetrasyllabe)
input : SAVE
Filename : mon_poeme.txt
Save the poem as mon_poeme.txt
input : EXIT
```

## Project Structure

- `main.cpp`: interactive application flow.
- `inc/SyllabCounter.hpp`: syllable counter class and custom exception.
- `src/SyllabCounter.cpp`: syllable and verse-type logic.
- `inc/InputHandler.hpp`: C++ wrapper for interactive input.
- `src/InputHandler.cpp`: Readline integration (history + completion).
- `inc/Color.hpp`: terminal color macros.
- `Makefile`: build rules and linker flags.

## Syllable Counting Rules (Current Implementation)

1. Consecutive vowels are grouped as one sound unit.
2. Silent final `e` can be ignored:
   - at end of verse,
   - or before a following word starting with a vowel.
3. UTF-8 accented vowels are handled as vowel units.

## Errors And Exceptions

`SAVE` throws `FileNotOpenException` if output file creation/open fails.

## Notes

- The `ADD` command stores the last non-command input currently held in memory.
- Syllabification is heuristic and may differ from strict literary scansion in edge cases.
