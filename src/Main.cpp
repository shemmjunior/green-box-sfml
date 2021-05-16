#include <iostream>
#include "Logic.h"


int main()
{
    srand(time(0));
    // Construct Logic
    Logic logic;

   while(logic.running()) {
       logic.update();
       logic.render();
   }

    return 0;
}