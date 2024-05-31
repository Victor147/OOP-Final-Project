//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"
#include <iostream>
#include "Figure.h"
#include "Menu.h"

#include "FigureTest.h"

int main(int argc, char** argv)
{
    doctest::Context context;
    context.setOption("abort-after", 10);
    context.applyCommandLine(argc, argv);
    context.setOption("no-breaks", true);
    int res = context.run();
    if (context.shouldExit())
    {
        return res;
    }

    Menu menu;
    menu.handleInput();
    //menu.printInitialMenu();

    return 0;
}
