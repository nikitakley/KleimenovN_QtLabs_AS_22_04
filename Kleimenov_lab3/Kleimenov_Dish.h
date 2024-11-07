#pragma once
#include "boost.h"
#include <string>

using namespace std;

class Kleimenov_Dish
{
protected:
    static int maxId;
    int Id = 0;
    string dishName = "None";
    int dishPrice = 0;
    double dishWeight = 0.0;
    bool dishAvailability = 0;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& Id;
        ar& dishName;
        ar& dishPrice;
        ar& dishWeight;
        ar& dishAvailability;
    }

public:
};
