//
// Created by 48782 on 09.12.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H
#define PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H

#include "Data/include/DynamicEnum/DynamicEnum.h"

template <typename valueType>
class IntDynamicEnum : public DynamicEnum<int, valueType> {
public:
    using DynamicEnum<int, valueType>::GetLen;
    using DynamicEnum<int, valueType>::Add;
    using DynamicEnum<int, valueType>::GetEnum;

    explicit IntDynamicEnum() = default;
    explicit IntDynamicEnum(std::vector<EnumValue<int, valueType>> &e) : DynamicEnum<int, valueType>(e) {}
    explicit IntDynamicEnum(std::vector<valueType> toConvert);

    void Add(valueType value);
    int IndexOf(valueType value);

    ~IntDynamicEnum() override = default;
};

template<typename valueType>
int IntDynamicEnum<valueType>::IndexOf(valueType value) {
    int index = 0;
    for(auto v : GetEnum())
    {
        if(v.GetValue() == value)
        {
            return index;
        }

        index++;
    }

    return -1;
}

template<typename valueType>
void IntDynamicEnum<valueType>::Add(valueType value) {
    Add(GetLen(), value);
}

template<typename valueType>
IntDynamicEnum<valueType>::IntDynamicEnum(std::vector<valueType> toConvert) {
    for (valueType v : toConvert) {
        Add(v);
    }
}

#endif //PATHFINDINGALGORITHMSCOMPARISON_INTDYNAMICENUM_H
