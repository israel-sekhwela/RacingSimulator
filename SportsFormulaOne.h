/**
 *  @author Israel Sekhwela
 *  @file SportsFormulaOne.h
 *  @class SportsFormulaOne
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */

#ifndef SPORTSFORMULAONE_H
#define SPORTSFORMULAONE_H

#include "SportsCar.h"

class SportsFormulaOne : public SportsCar{
public:
    /**
     * Constructor for SportsFormulaOne, calls Constructor of SportsCar
     */
    SportsFormulaOne() : SportsCar("FormulaOne"){
        setHandling(120);
        setSpeed(200);
        setAcceleration(150);

        cout << "Constructing a Sports FormulaOne ...\n" << toString() << endl;
    };
    /**
     * Copy constructor used for cloning
     * @param car_  car object for copying
     * @param flag_ to determine if must be full clone or basic clone
     */
    SportsFormulaOne(const Car& car_, bool flag_) : SportsCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(120);
            setSpeed(200);
            setHandling(150);
        }

        string out = "Cloning ";
        if (flag_ == false){
            out += "Original car ...\n";
        }
        else{
            out += "Customized car ...\n";
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
        return new SportsFormulaOne(*this, flag_);
    };
};

#endif