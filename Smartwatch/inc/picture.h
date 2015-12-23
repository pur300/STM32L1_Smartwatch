#ifndef PICTURE_H
#define PICTURE_H

#include "stm32l1xx.h"
#include "icons.h"

// picture width and height
#define WIDTH 128
#define HEIGHT 128

// Picture array size divider
#define WIDTH_DIV 8

typedef struct Frame{

    short locationX; // Location of a frame
    short locationY;
    Icon icon; // Icon structure

 } Frame;

typedef struct PictureFrames{

    uint8_t numOfFrames;
    Frame *frames;

} PictureFrames;

typedef struct Picture{

    short cols; // Number of bytes per row
    short rows;  // Number of rows
    const uint8_t* pixels;

}Picture;

void getPicture(Picture* picture);
void addLogoFrame(void);
void addBatteryFrame(uint8_t batPercentage);
void addCallFrame(void);
void removeCallFrame(void);
void addSmsFrame(void);
void removeSmsFrame(void);
void addMailFrame(void);
void removeMailFrame(void);
void addHumidityFrame(uint8_t humidity);
void addTemperatureFrame(uint8_t temp);
void addDateFrame(uint8_t day, uint8_t month, uint8_t year);
void addTimeFrame(uint8_t hours, uint8_t minutes);

#endif
