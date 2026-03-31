#ifndef INPUTHANDLER_HPP
# define INPUTHANDLER_HPP

# include <string>
# include <vector>

class InputHandler
{
    public:
        InputHandler();
        ~InputHandler();

        void setCommands(const std::vector<std::string> &commands);
        bool readLine(const std::string &prompt, std::string &out, bool storeInHistory = true) const;

    private:
        static InputHandler *_instance;
        std::vector<std::string> _commands;

        static char **commandCompletion(const char *text, int start, int end);
        static char *commandGenerator(const char *text, int state);
        static char *duplicateString(const std::string &value);
};

#endif