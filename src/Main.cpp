#include <iostream>
#include "Logic.h"


int main()
{
    // Construct Logic
    Logic logic;

   while(logic.running()) {
       logic.update();
       logic.render();
   }

    return 0;
}