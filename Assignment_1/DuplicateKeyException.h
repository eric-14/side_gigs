
#include<exception>
#ifndef DUPL_KEY
#define DUPL_KEY

class DuplicateKeyException: public std::exception
{
    public:
    virtual const char * what() const throw(){
        return "Duplicate Exception happened";
    }
};


#endif
