#include <exception>
#ifndef NO_KEY
#define NO_KEY
class NoKeyException : public std::exception
// Exception class thrown by remove if no record is found.
{
    public:
    virtual const char * what() const throw(){
        return "No key exception";
    }

};
#endif
