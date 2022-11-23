#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "interpreter.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

interpreter::interpreter(){
} //method constructor
interpreter::~interpreter(){
} //method destructor

// method to interpret an input file

std::vector<FiguraGeometrica*> interpreter::parse(std::string filename){

    std::vector <FiguraGeometrica*> figure; //vector to walk line by line
    std::fstream fileIn; //input file
    std::string aux; //aux string

    fileIn.open(filename); //open the file

    //wether file is opened
    if(fileIn.is_open() == false){
        std::cout << "Try open the file again!" << std::endl;
        exit(EXIT_FAILURE);
    }

    //verify if the flux input is ready to read
    while(fileIn.good()){
        //read all lines and break if not
        fileIn >> aux;
        if(!fileIn.good()) break;

        //first line
        if(aux.compare("dim") == 0){
            fileIn >> x >> y >> z;
        }

        //putVoxel method compare strings to init the input flux
        else if(aux.compare("putVoxel") == 0){
            int x, y, z;
            fileIn >> x >> y >> z >> r >> g >> b >> a;
            figure.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }

        //cutVoxel method compare strings to init the input flux
        else if(aux.compare("cutVoxel") == 0){
            int x, y, z;
            fileIn >> x >> y >> z;
            figure.push_back(new CutVoxel(x, y, z));
        }

        //putBox method compare strings to init the input flux
        else if(aux.compare("putBox") == 0){
            int x0, x1, y0, y1, z0, z1;
            fileIn >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figure.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        //cutBox method compare strings to init the input flux
        else if(aux.compare("cutBox") == 0){
            int x0, x1, y0, y1, z0, z1;
            fileIn >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figure.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
        }

        //putSphere method compare strings to init the input flux
        else if(aux.compare("putSphere") == 0){
            int x, y, z, radius;
            fileIn >> x >> y >> z >> radius >> r >> g >> b >> a;
            figure.push_back(new putSphere(x, y, z, radius, r, g, b, a));
        }

        //cutSphere method compare strings to init the input flux
        else if(aux.compare("cutSphere") == 0){
            int x, y, z, radius;
            fileIn >> x >> y >> z >> radius;
            figure.push_back(new cutSphere(x, y, z, radius));
        }

        //putEllipsoid method compare strings to init the input flux
        else if(aux.compare("putEllipsoid") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fileIn >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figure.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
        }

        //cutEllipsoid method compare strings to init the input flux
        else if(aux.compare("cutEllipsoid") == 0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fileIn >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figure.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
    }

    //show feedback, exit file and return vector figure
    if(fileIn.is_open()) std::cout << ".txt has been interpreted." << std::endl;
    fileIn.close();
    return figure;
}

//dimensional methods
int interpreter::getx(){return x;}
int interpreter::gety(){return y;}
int interpreter::getz(){return z;}
