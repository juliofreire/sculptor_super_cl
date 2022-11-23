#include <iostream>
#include <vector>
#include <string>

#include "figurageometrica.h"
#include "interpreter.h"
#include "sculptor.h"

int main(){
    Sculptor *s;

    interpreter prsr;

    std::vector<FiguraGeometrica*> figure;
    figure = prsr.parse("D:/Documents/programacao_avancada/sculptor_sc/pe.txt");

    s = new Sculptor(prsr.getx(), prsr.gety(), prsr.getz());

    for(int i = 0; i < int(figure.size()); i++) figure[i] -> draw(*s);

    s -> writeOFF("pe.off");

    for(int i = 0; i < int(figure.size()); i++) delete figure[i];
    delete s;

    return 0;
}


