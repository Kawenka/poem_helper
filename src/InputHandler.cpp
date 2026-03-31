#include "../inc/InputHandler.hpp"
#include <readline/readline.h>
#include <readline/history.h>
#include <cstdlib>
#include <cstring>

InputHandler *InputHandler::_instance = 0;

InputHandler::InputHandler()
{
    _instance = this;
    rl_attempted_completion_function = InputHandler::commandCompletion;
}

InputHandler::~InputHandler()
{
    if (_instance == this)
        _instance = 0;
}

void InputHandler::setCommands(const std::vector<std::string> &commands)
{
    _commands = commands;
}

bool InputHandler::readLine(const std::string &prompt, std::string &out, bool storeInHistory) const
{
    char *line = readline(prompt.c_str());

    if (!line)
        return (false);
    out = line;
    if (storeInHistory && !out.empty())
        add_history(line);
    std::free(line);
    return (true);
}

char *InputHandler::duplicateString(const std::string &value)
{
    char *copy = static_cast<char *>(std::malloc(value.size() + 1));

    if (!copy)
        return (0);
    std::memcpy(copy, value.c_str(), value.size() + 1);
    return (copy);
}

char *InputHandler::commandGenerator(const char *text, int state)
{
    static size_t index;
    static size_t len;

    if (!_instance)
        return (0);
    if (!state)
    {
        index = 0;
        len = std::strlen(text);
    }
    while (index < _instance->_commands.size())
    {
        const std::string &command = _instance->_commands[index++];
        if (!command.compare(0, len, text))
            return (duplicateString(command));
    }
    return (0);
}

char **InputHandler::commandCompletion(const char *text, int start, int end)
{
    (void)end;
    if (start == 0 && _instance && !_instance->_commands.empty())
        return (rl_completion_matches(text, InputHandler::commandGenerator));
    return (0);
}