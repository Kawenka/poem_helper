# Poem Helper

Poem Helper is a command-line tool developed in C++ (C++98 standard) designed to assist in poem composition. It calculates syllable counts based on French versification rules, manages poem storage in memory, and allows for file exportation.

## Features

- Syllable Counting: Accurate count based on vowel groups and specific rules for the silent 'e'.
- Poem Management: Store multiple verses in a sequence using a dedicated container.
- File Export: Save your composed poem into an external text file.
- Error Handling: Custom exception implementation for file stream management.
- Terminal Styling: ANSI escape codes for clear and structured output.
- UTF-8 Support: Proper handling of French accented characters (multi-byte sequences).

## Compilation

The project includes a Makefile that follows 42 school standards.

1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd poem_helper
    ```

2. Compile the project:
    ```sh
    make
    ```

3. Run the executable:
    ```sh
    ./poem_helper
    ```

## Usage

The program runs in an interactive loop. Type your verse to see the syllable count immediately.

Special Commands:
- ADD: Stores the last entered verse into the poem.
- DISPLAY: Prints the current state of the stored poem.
- SAVE: Triggers the file export process (asks for a filename).
- CTRL+D: Exits the program.

Example:
Input: Demain des l'aube
Syllables: 4
Input: ADD
Added: Demain des l'aube

## Project Structure

- inc/SyllabCounter.hpp: Class declaration and exception definitions.
- inc/Color.hpp: ANSI color macros.
- src/SyllabCounter.cpp: Core logic and syllable counting algorithms.
- main.cpp: User interface and command loop.
- Makefile: Build instructions.

## Algorithmic Logic

The syllable counting engine follows these principles:
1. Vowel Grouping: Consecutive vowels (e.g., "eau", "ai") are counted as a single phonetic unit.
2. Silent 'e' Rules: 
   - A final 'e' is ignored if it is at the end of a verse.
   - A final 'e' is ignored if the following word starts with a vowel (Elision).
3. UTF-8 Management: Manual offset handling for two-byte characters like 'é' or 'à' to prevent indexing errors.

## Exception Management

The program implements a custom exception, FileNotOpenException, which inherits from std::exception. It is thrown during the SAVE process if the output stream fails to initialize or the file cannot be accessed.

---
