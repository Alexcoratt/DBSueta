#ifndef DELETE_PERSON_COMMAND_HPP
#define DELETE_PERSON_COMMAND_HPP

#include "i_command.hpp"

class DeletePersonCommand : public ICommand {
public:
    DeletePersonCommand(unsigned id);
    ~DeletePersonCommand();



private:
    unsigned id_;
};

#endif // DELETE_PERSON_COMMAND_HPP
