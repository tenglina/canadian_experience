/**
 * @file DrawableTest.cpp
 * @author Nandini Tengli
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Drawable.h>



class DrawableMock: public Drawable
{
public:

    DrawableMock(const std::wstring &name) :Drawable(name) {}

    bool HitTest(wxPoint pos) override { return true; }
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}

};

TEST(Drawable, Constructor)
{
    DrawableMock drawableMock(L"Theo");

    //testing the name getter
    ASSERT_EQ(L"Theo", drawableMock.GetName());
}

TEST(Drawable, Position)
{
    DrawableMock drawableMock(L"Theo");
    wxPoint defaultPos = wxPoint(0,0);

    //testing the getter with the default value of position
    ASSERT_EQ(defaultPos, drawableMock.GetPosition());


    drawableMock.SetPosition(wxPoint(25, 71));
    ASSERT_EQ(wxPoint(25, 71), drawableMock.GetPosition());

}

TEST(Drawable, Rotation)
{
    DrawableMock drawableMock(L"Theo");


    //testing the getter with the default value of rotation
    ASSERT_EQ(0, drawableMock.GetRotation());


    drawableMock.SetRotation(3.14157);
    ASSERT_NEAR(3.14157, drawableMock.GetRotation(), 0.0001);


}

TEST(DrawableTest, Association)
{
    DrawableMock body(L"Body");
    auto arm = std::make_shared<DrawableMock>(L"Arm");
    auto leg = std::make_shared<DrawableMock>(L"Leg");

    ASSERT_EQ(nullptr, arm->GetParent());
    ASSERT_EQ(nullptr, leg->GetParent());

    body.AddChild(arm);
    body.AddChild(leg);

    ASSERT_EQ(&body, arm->GetParent());
    ASSERT_EQ(&body, leg->GetParent());
}