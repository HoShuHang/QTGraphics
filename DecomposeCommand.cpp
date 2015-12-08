#include "DecomposeCommand.h"

DecomposeCommand::DecomposeCommand(vector<Graphics *> *g, Graphics *comp)
{
    graphics = g;
    compositeGraphic = comp;
}

void DecomposeCommand::Excute()
{
    graphics->erase((remove(graphics->begin(), graphics->end(), compositeGraphic)), graphics->end());
    for(int i = 0; i < compositeGraphic->getGraphics().size(); i++)
    {
        Graphics *g = compositeGraphic->getGraphics().at(i);
        graphics->push_back(g);
    }
}

void DecomposeCommand::UnExcute()
{
    for(int i = 0; i < compositeGraphic->getGraphics().size(); i++)
    {
        Graphics *g = compositeGraphic->getGraphics().at(i);
        graphics->erase((remove(graphics->begin(), graphics->end(), g)), graphics->end());
    }
    graphics->push_back(compositeGraphic);
}
