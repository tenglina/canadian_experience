/**
 * @file PictureFactory.h
 * @author Nandini Tengli
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;
class HaroldFactory;

/**
 * A factory class that builds our picture.
 */


class PictureFactory {
private:

public:







    std::shared_ptr<Picture> Create(std::wstring imagesDir);



};

#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
