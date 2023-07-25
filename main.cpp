#include "include/DataManager.h"
#include "include/JsonReader.h"

int main() {
    DataManager* dm = new DataManager(*new JsonReader("config.json"));

    std::cout << dm->GetBoard().ToString() << std::endl;
    std::cout << dm->GetPlayer().ToString() << std::endl;
    return 0;
}
