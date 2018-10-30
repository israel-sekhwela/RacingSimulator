/**
*  @author Israel Sekhwela
*  @file StandardFormulaOne.h
*  @class StandardFormulaOne
*  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
*/

#ifndef STANDARDFORMULAONE_H
#define STANDARDFORMULAONE_H

#include "StandardCar.h"

class StandardFormulaOne : public StandardCar{
public:
    /**
     * Constructor for StandardFormulaOne, calls Constructor of StandardCar
     */
    StandardFormulaOne() : StandardCar("FormulaOne"){
        setHandling(120);
        setSpeed(150);
        setAcceleration(120);

        cout << "Constructing a Standard FormulaOne ...\n" << toString() << endl;
    };
    /**
     * Copy constructor used for cloning
     * @param car_  car object for copying
     * @param flag_ to determine if must be full clone or basic clone
     */
    StandardFormulaOne(const Car& car_, bool flag_) : StandardCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(120);
            setSpeed(150);
            setHandling(120);
        }

        string out = "Cloning ";
        if (flag_ == false){
            out += "Original Car ...\n";
        }
        else{
            out += "Customized Car ...\n";
        }
        cout << out;
        cout << toString() << endl;
    };

    /**
     * implementation of clone function
     * @param flag_ determines if must be full clone or basic clone
     * @return a copied car object
     */
    virtual Car* clone(bool flag_ = false){
        return new StandardFormulaOne(*this, flag_);
    };
};

#endif
