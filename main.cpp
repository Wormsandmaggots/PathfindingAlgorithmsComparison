#include <iostream>
#include "include/Board.h"
#include "include/JsonReader.h"


int main() {
    Board* board = new Board(*new JsonReader("config.json"));

    std::cout << board->ToString() << std::endl;

    return 0;
}
