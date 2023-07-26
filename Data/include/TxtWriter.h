//
// Created by 48782 on 26.07.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_TXTWRITER_H
#define PATHFINDINGALGORITHMSCOMPARISON_TXTWRITER_H

#include "Data/include/Writer.h"

class TxtWriter : public Writer {
public:
    explicit TxtWriter(std::string);
    ~TxtWriter() override = default;

    void ToQueue(std::string) override;
    void ToFile() override;

};


#endif //PATHFINDINGALGORITHMSCOMPARISON_TXTWRITER_H
