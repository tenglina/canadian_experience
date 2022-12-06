/**
 * @file FrankensteinFactory.cpp
 * @author Nandini Tengli
 */

#include "pch.h"
#include <memory>

#include "FrankensteinFactory.h"
#include "Actor.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;

/**
 * Creates Frankenstein character
 * @param imagesDir the directory that contains images of this character
 * @return actor the character that is created
 */
std::shared_ptr<Actor> FrankensteinFactory::Create(std::wstring imagesDir)
{
    auto actor = make_shared<Actor>(L"Frankenstein");

    auto shirt = make_shared<ImageDrawable>(L"Shirt", imagesDir + L"/black_coat.png");
    shirt->SetCenter(wxPoint(44, 138));
    shirt->SetPosition(wxPoint(0, -114));
    actor->SetRoot(shirt);

    auto lleg = make_shared<ImageDrawable>(L"Left Leg", imagesDir + L"/jeans_lleg.png");
    lleg->SetCenter(wxPoint(30, 9));
    lleg->SetPosition(wxPoint(30, 0));
    shirt->AddChild(lleg);

    auto rleg = make_shared<ImageDrawable>(L"Right Leg", imagesDir + L"/jeans_rleg.png");
    rleg->SetCenter(wxPoint(38, 9));
    rleg->SetPosition(wxPoint(-27, 0));
    shirt->AddChild(rleg);


    auto headb = make_shared<ImageDrawable>(L"Head Bottom", imagesDir + L"/headb3.png");
    headb->SetCenter(wxPoint(44, 31));
    headb->SetPosition(wxPoint(0, -130));
    shirt->AddChild(headb);


    auto headt = make_shared<HeadTop>(L"Head Top", imagesDir + L"/headt4.png");
    headt->SetCenter(wxPoint(80, 109));
    headt->SetPosition(wxPoint(0, -31));
    headb->AddChild(headt);
    headt->SetEyePos(wxPoint(65,65));


    auto larm = make_shared<PolyDrawable>(L"Left Arm");
    larm->SetColor(*wxBLACK);
    larm->SetPosition(wxPoint(45, -115));
    larm->AddPoint(wxPoint(-7, -7));
    larm->AddPoint(wxPoint(-7, 96));
    larm->AddPoint(wxPoint(8, 96));
    larm->AddPoint(wxPoint(8, -7));
    shirt->AddChild(larm);

    auto rarm = make_shared<PolyDrawable>(L"Right Arm");
    rarm->SetColor(*wxBLACK);
    rarm->SetPosition(wxPoint(-45, -110));
    rarm->AddPoint(wxPoint(-7, -7));
    rarm->AddPoint(wxPoint(-7, 96));
    rarm->AddPoint(wxPoint(8, 96));
    rarm->AddPoint(wxPoint(8, -7));
    shirt->AddChild(rarm);

    auto lhand = make_shared<PolyDrawable>(L"Left Hand");
    lhand->SetColor(wxColour(218, 160, 109));
    lhand->SetPosition(wxPoint(0, 96));
    lhand->AddPoint(wxPoint(-12, -2));
    lhand->AddPoint(wxPoint(-12, 17));
    lhand->AddPoint(wxPoint(11, 17));
    lhand->AddPoint(wxPoint(11, -2));
    larm->AddChild(lhand);

    auto rhand = make_shared<PolyDrawable>(L"Right Hand");
    rhand->SetColor(wxColour(218, 160, 109));
    rhand->SetPosition(wxPoint(0, 96));
    rhand->AddPoint(wxPoint(-12, -2));
    rhand->AddPoint(wxPoint(-12, 17));
    rhand->AddPoint(wxPoint(11, 17));
    rhand->AddPoint(wxPoint(11, -2));
    rarm->AddChild(rhand);


    actor->AddDrawable(rarm);
    actor->AddDrawable(larm);
    actor->AddDrawable(rhand);
    actor->AddDrawable(lhand);
    actor->AddDrawable(lleg);
    actor->AddDrawable(rleg);
    actor->AddDrawable(shirt);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);

    return actor;

}
