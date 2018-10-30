/**
 *  @author Israel Sekhwela
 *  @file Decider.h
 *  @class Decider
 *  @brief visitor class in visitor pattern
 */

#ifndef Decider_H
#define Decider_H


class LeftEighth;
class RightEighth;
class LeftPeelOff;
class RightPeelOff;
class LeftPeelOn;
class RightPeelOn;
class Straight;

class Decider
{
public:
    /**
     * virtual visit that visits Left Eighth object
     * @param leftEighth
     */
    virtual void visit(LeftEighth* leftEighth)=0;
    /**
     * virtual visit that visits rightEighth object
     * @param rightEighth
     */
    virtual void visit(RightEighth* rightEighth)=0;
    /**
     * virtual visit that visits leftPeelOff object
     * @param leftPeelOff
     */
    virtual void visit(LeftPeelOff* leftPeelOff)=0;
    /**
     * virtual visit that visits rightPeelOff object
     * @param rightPeelOff
     */
    virtual void visit(RightPeelOff* rightPeelOff)=0;
    /**
     * virtual visit that visits leftPeelOn object
     * @param leftPeelOn
     */
    virtual void visit(LeftPeelOn* leftPeelOn)=0;
    /**
     * virtual visit that visits rightPeelOn object
     * @param rightPeelOn
     */
    virtual void visit(RightPeelOn* rightPeelOn)=0;
    /**
     * virtual visit that visits straight object
     * @param straight
     */
    virtual void visit(Straight* straight)=0;
};

#endif
