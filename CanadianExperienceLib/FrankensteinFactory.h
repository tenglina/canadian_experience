/**
 * @file FrankensteinFactory.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_FRANKENSTEINFACTORY_H
#define CANADIANEXPERIENCE_FRANKENSTEINFACTORY_H


class Actor;

/**
 * the class that is responsible for creating an actor of this(Frankenstein) type
 */
class FrankensteinFactory {
private:

public:


    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_FRANKENSTEINFACTORY_H
