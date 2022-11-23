#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <vector>
#include <string>

#include "figurageometrica.h"

class interpreter
{
public:
    int x, y, z;
    float r, g, b, a;

    interpreter();
    ~interpreter();

    std::vector <FiguraGeometrica*> parse(std::string filename);

    int getx();
    int gety();
    int getz();
};

#endif // INTERPRETER_H
