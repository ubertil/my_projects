#include <iostream>
#include "Game/Core.hpp"

int     main(void)
{
    try
    {
        Sprint::Game::Core core(false);

        core.splashScreen();
        core.run();
    }
    catch (const Sprint::Error::Error &err)
    {
        std::cerr << err.what() << std::endl;
    }
    return (0);
}