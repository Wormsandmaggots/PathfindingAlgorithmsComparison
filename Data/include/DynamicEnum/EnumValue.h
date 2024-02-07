//
// Created by 48782 on 09.12.2023.
//

#ifndef PATHFINDINGALGORITHMSCOMPARISON_ENUMVALUE_H
#define PATHFINDINGALGORITHMSCOMPARISON_ENUMVALUE_H


#include <type_traits>

template<typename keyType, typename valueType>
class EnumValue {
public:
    EnumValue(keyType key, valueType value) : _key(key), _value(value) {}

    ~EnumValue() {
        if constexpr (std::is_pointer_v<keyType>)
            delete _key;

        if constexpr (std::is_pointer_v<valueType>)
            delete _value;
    }

    bool operator==(const EnumValue<keyType, valueType> other) const
    {
        return _key == other._key; //&& _value == other._value;
    }

    keyType GetKey() const {
        return _key;
    }

    valueType GetValue() const {
        return _value;
    }

private:
    keyType _key;
    valueType _value;
};


#endif //PATHFINDINGALGORITHMSCOMPARISON_ENUMVALUE_H
