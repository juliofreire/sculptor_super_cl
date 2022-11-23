#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "sculptor.h"
#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica
{
public:
    int x, y, z;
    float r, g, b, a;
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    ~PutVoxel();
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
