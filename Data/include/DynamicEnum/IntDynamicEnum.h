//
// Created by 48782 on 09.12.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H
#define PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H

#include "Data/include/DynamicEnum/DynamicEnum.h"

template <typename keysType>
class IntDynamicEnum : public DynamicEnum<keysType, int> {
public:
    using DynamicEnum<keysType, int>::GetLen;
    using DynamicEnum<keysType, int>::Add;

    explicit IntDynamicEnum() = default;
    explicit IntDynamicEnum(std::vector<EnumValue<keysType, int>> &e) : DynamicEnum<keysType, int>(e) {}
    explicit IntDynamicEnum(std::vector<keysType> toConvert);

    void Add(keysType key);

    ~IntDynamicEnum() override = default;
};

template<typename keysType>
void IntDynamicEnum<keysType>::Add(keysType key) {
    Add(key, GetLen());
}

template<typename keysType>
IntDynamicEnum<keysType>::IntDynamicEnum(std::vector<keysType> toConvert) {
    for (keysType k : toConvert) {
        Add(k);
    }
}

#endif //PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H
