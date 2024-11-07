#pragma once
#include "Kleimenov_Dish.h"

class Kleimenov_Special_Dish : public Kleimenov_Dish
{
private:
    string seasonDish = "None";
    bool isChef = false;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& boost::serialization::base_object<Kleimenov_Dish>(*this);
        ar& seasonDish;
        ar& isChef;
    }

public:
};
