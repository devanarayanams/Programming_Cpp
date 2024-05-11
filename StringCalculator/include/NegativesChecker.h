#ifndef GETNEGATIVES_H
#define GETNEGATIVES_H

#include <string>

class GetNegatives {
private:
    std::string negatives;

public:
    void operator()(int i);
    operator std::string();
};

#endif // GETNEGATIVES_H
