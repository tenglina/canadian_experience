/**
 * @file PictureObserverTest.cpp
 * @author Nandini Tengli
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>
#include <memory>
#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
    PictureObserverMock() : PictureObserver() {}


    bool mUpdated = false;

    virtual void UpdateObserver() override { mUpdated = true; }

};


TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}


TEST(PictureObserverTest, OneObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}

TEST(PictureObserverTest, GetPicture) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);


    auto testPic = observer.GetPicture();
    ASSERT_EQ(picture, testPic);
    ASSERT_EQ(picture->GetSize(),testPic->GetSize());
}


TEST(PictureObserverTest, Twobservers) {

    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create first mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    //second observer
    PictureObserverMock observer2;

    // And set it for the second observer:
    observer2.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer2.mUpdated);
    ASSERT_TRUE(observer.mUpdated);

}

TEST(PictureObserverTest, DestroyObservers) {

    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create first mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    //second observer
    PictureObserverMock observer2;

    // And set it for the second observer:
    observer2.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer2.mUpdated);
    ASSERT_TRUE(observer.mUpdated);



    //create another observer and destroy it
    {
        PictureObserverMock observer3;

        // And set it for the observer:
        observer3.SetPicture(picture);

        picture->UpdateObservers();


    }


    ASSERT_TRUE(observer2.mUpdated);
    ASSERT_TRUE(observer.mUpdated);

    auto testPic = observer.GetPicture();
    ASSERT_EQ(picture, testPic);


    testPic = observer2.GetPicture();
    ASSERT_EQ(picture, testPic);


}