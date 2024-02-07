//
// Created by 48782 on 09.12.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_DYNAMICENUM_H
#define PATHFINDINGALGORITHMSCOMPARISON_DYNAMICENUM_H

#include <vector>
#include "EnumValue.h"

template <typename keysType, typename valuesType = int>
class DynamicEnum{
public:
    explicit DynamicEnum() = default;
    explicit DynamicEnum(std::vector<EnumValue<keysType, valuesType>> &e) : _enum(e){}

    virtual ~DynamicEnum() = default;

    valuesType& operator[](keysType key);

    valuesType virtual Find(keysType key) const;
    void Add(EnumValue<keysType, valuesType> enumValue);
    void Add(keysType key, valuesType value);
    void virtual Remove(EnumValue<keysType, valuesType> enumValue);
    void RemoveAt(int index);
    int GetLen() const;

protected:
    std::vector<EnumValue<keysType, valuesType>> GetEnum();

private:
    std::vector<EnumValue<keysType, valuesType>> _enum;
};

template<typename keysType, typename valuesType>
valuesType &DynamicEnum<keysType, valuesType>::operator[](keysType key) {
    auto i = std::find_if(_enum.begin(), _enum.end(),[key](const EnumValue<keysType, valuesType>& e)
    {
        return e.GetKey() == key;
    });

    if(i == _enum.end())
        throw std::invalid_argument("Invalid enum key");

    return (*i).GetValue();
}

template<typename keysType, typename valuesType>
int DynamicEnum<keysType, valuesType>::GetLen() const {
    return _enum.size();
}

template<typename keysType, typename valuesType>
void DynamicEnum<keysType, valuesType>::RemoveAt(int index) {
    if(index >= _enum.size())
        return;

    _enum.erase(_enum.begin() + index);
}

template<typename keysType, typename valuesType>
void DynamicEnum<keysType, valuesType>::Remove(EnumValue<keysType, valuesType> enumValue) {
    auto toRemove = std::find_if(_enum.begin(), _enum.end(),[enumValue](const EnumValue<keysType, valuesType>& e){
        return e == enumValue;
    });

    if(toRemove == _enum.end())
        return;

    _enum.erase(toRemove);
}

template<typename keysType, typename valuesType>
void DynamicEnum<keysType, valuesType>::Add(keysType key, valuesType value) {
    _enum.push_back(EnumValue<keysType, valuesType>(key, value));
}

template<typename keysType, typename valuesType>
void DynamicEnum<keysType, valuesType>::Add(EnumValue<keysType, valuesType> enumValue) {
    _enum.push_back(enumValue);
}

template<typename keysType, typename valuesType>
valuesType DynamicEnum<keysType, valuesType>::Find(keysType key) const{
    auto i = std::find_if(_enum.begin(), _enum.end(),[key](const EnumValue<keysType, valuesType>& e)
    {
        return e.GetKey() == key;
    });

    if(i == _enum.end())
        throw std::invalid_argument("Invalid enum key");

    return (*i).GetValue();
}

template<typename keysType, typename valuesType>
std::vector<EnumValue<keysType, valuesType>> DynamicEnum<keysType, valuesType>::GetEnum() {
    return _enum;
}

#endif //PATHFINDINGALGORITHMSCOMPARISON_DYNAMICENUM_H
