#ifndef UTMODEL_H_INCLUDED
#define UTMODEL_H_INCLUDED

#include "Model.h"

TEST (Model, createCircle) {
    Model m;
    m.createCircle();
    LONGS_EQUAL(1, m.getGraphics()->size());

    DescriptionVisitor dv;
    Graphics *g = m.getGraphics()->at(0);
    g->accept(dv);
    CHECK(std::string("C(50,0,50)\n")==dv.getDescription());
}

TEST (Model, createRectangle) {
    Model m;
    m.createRectangle();
    LONGS_EQUAL(1, m.getGraphics()->size());

    DescriptionVisitor dv;
    Graphics *g = m.getGraphics()->at(0);
    g->accept(dv);
    CHECK(std::string("R(0,0,100,50)\n")==dv.getDescription());
}

TEST (Model, createSquare) {
    Model m;
    m.createSquare();
    LONGS_EQUAL(1, m.getGraphics()->size());

    DescriptionVisitor dv;
    Graphics *g = m.getGraphics()->at(0);
    g->accept(dv);
    CHECK(std::string("S(50,0,50)\n")==dv.getDescription());
}

#endif // UTMODEL_H_INCLUDED
