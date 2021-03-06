/*
   Copyright (C) 2016 Ignacio Vina (@igvina)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#pragma once

#define A_B_BUTTONS_WIDTH  18
#define A_B_BUTTONS_HEIGHT 8

const unsigned char PROGMEM A_B_BUTTONS_BITMAP[] = //18,8
{
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c,
  0x00, 0x00, 0x3c, 0x66, 0xc3, 0x81, 0x81, 0xc3,
  0x66, 0x3c,
};


#define LOGO_WIDTH  68
#define LOGO_HEIGHT 26

const unsigned char PROGMEM LOGO_BITMAP[] = //68,26
{
  0x30, 0x70, 0xfc, 0xfe, 0x1c, 0x18, 0x18, 0x98,
  0xf8, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x0f,
  0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xf8, 0xfe, 0x3e, 0xfc, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x3f, 0x00,
  0x00, 0x00, 0x80, 0xe0, 0x70, 0x38, 0x1c, 0x0e,
  0x0e, 0x1e, 0x3c, 0x38, 0x10, 0x00, 0x00, 0x00,
  0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff,
  0xfc, 0x0e, 0x0e, 0x0f, 0x0d, 0x1c, 0x1c, 0xf8,
  0xe0, 0x80, 0x00, 0x00, 0x00, 0x60, 0xe0, 0xe0,
  0x7c, 0x6f, 0x60, 0x20, 0x21, 0x3f, 0x7e, 0xf0,
  0x30, 0x30, 0x30, 0x30, 0x00, 0x00, 0x00, 0xff,
  0xff, 0x00, 0x01, 0x07, 0x1f, 0x7c, 0xf0, 0xc0,
  0xff, 0xff, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x03,
  0x00, 0x00, 0x30, 0x30, 0x18, 0x18, 0x9c, 0xfc,
  0x7c, 0x08, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00,
  0x00, 0x00, 0x1c, 0x7f, 0x7f, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x0c, 0x0f, 0x07, 0x00, 0x00, 0x00,
  0x80, 0xe0, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x03, 0x1f, 0xfc, 0xf0, 0xc0,
  0x00, 0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x0f, 0x1f, 0x3f, 0x18, 0x00,
  0x00, 0x07, 0x1f, 0x3c, 0x78, 0x70, 0x70, 0x70,
  0x38, 0x1e, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


#define HEART_SIZE  7

const unsigned char PROGMEM HEART_BITMAP[] = //7,7
{
  0x0e, 0x1f, 0x3e, 0x7c, 0x3e, 0x1f, 0x0e,
};


#define RIGHT_ARROW_WIDTH 8
#define RIGHT_ARROW_HEIGHT 9

const unsigned char PROGMEM RIGHT_ARROW_BITMAP[] = //8,9
{
  0x7c, 0x7c, 0x7c, 0xff, 0xfe, 0x7c, 0x38, 0x10,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
};


#define DOWN_ARROW_WIDTH 9
#define DOWN_ARROW_HEIGHT 8

const unsigned char PROGMEM DOWN_ARROW_BITMAP[] = //9,8
{
  0x08, 0x18, 0x3f, 0x7f, 0xff, 0x7f, 0x3f, 0x18,
  0x08,
};


#define RAY_WIDTH 5
#define RAY_HEIGHT 64

const unsigned char PROGMEM RAY_BITMAP[] = //5,64
{
  0x04, 0x12, 0xaf, 0x42, 0x04, 0x00, 0x11, 0xaa,
  0x44, 0x00, 0x00, 0x11, 0xaa, 0x44, 0x00, 0x00,
  0x11, 0xaa, 0x44, 0x00, 0x00, 0x11, 0xaa, 0x44,
  0x00, 0x00, 0x11, 0xaa, 0x44, 0x00, 0x00, 0x11,
  0xaa, 0x44, 0x00, 0x00, 0x11, 0xaa, 0x44, 0x00,
};


#define BIG_BANNER_WIDTH 100
#define BIG_BANNER_HEIGHT 21


#define BANNER_HEAD_WIDTH 4
#define BANNER_HEAD_HEIGHT 21
const unsigned char PROGMEM BANNER_HEAD_BITMAP[]
{
0xf8, 0x0c, 0x06, 0x03, 0xff, 0x00, 0x00, 0x00,
0x03, 0x06, 0x0c, 0x18,
};

const unsigned char PROGMEM BANNER_HEAD_MASK_BITMAP[]
{
0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
0x03, 0x07, 0x0f, 0x1f,
};

#define BANNER_BODY_WIDTH 1
#define BANNER_BODY_HEIGHT 21
const unsigned char PROGMEM BANNER_BODY_BITMAP[]
{
0x01, 0x00, 0x10,
};

const unsigned char PROGMEM BANNER_BODY_MASK_BITMAP[]
{
0xff, 0xff, 0x1f,
};

/*
const unsigned char PROGMEM BIG_BANNER_BITMAP[]
{
  0xf8, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x03, 0x06, 0x0c, 0xf8, 0xff, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
  0x03, 0x06, 0x0c, 0x18, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x18, 0x0c, 0x06, 0x03,
};

const unsigned char PROGMEM BIG_BANNER_MASK_BITMAP[]
{
  0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xfe, 0xfc, 0xf8, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x0f, 0x07, 0x03,
};
*/

#define SMALL_BANNER_WIDTH 70
#define SMALL_BANNER_HEIGHT 21

/*
const unsigned char PROGMEM SMALL_BANNER_BITMAP[]
{
  0xf8, 0x0c, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x03, 0x06, 0x0c, 0xf8, 0xff, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0xff, 0x03, 0x06, 0x0c, 0x18,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0c,
  0x06, 0x03,
};

const unsigned char PROGMEM SMALL_BANNER_MASK_BITMAP[]
{
  0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0x03, 0x07, 0x0f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f,
  0x07, 0x03,
};
*/

#define DANGER_SIZE  48

const unsigned char PROGMEM DANGER_BITMAP[] = //48,48
{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0xc0, 0xe0, 0xf0, 0x70, 0x78, 0x3c, 0x1c, 0x1c,
  0x1e, 0x0e, 0x0e, 0x0f, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07, 0x0f, 0x0e, 0x0e, 0x1e,
  0x1c, 0x1c, 0x3c, 0x78, 0x70, 0xf0, 0xe0, 0xc0,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe0, 0xf0, 0xfc, 0x3e, 0x1f, 0x07,
  0x03, 0x81, 0xe0, 0xe0, 0xf0, 0xfc, 0xfc, 0xfc,
  0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8,
  0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x81, 0x03,
  0x07, 0x1f, 0x3e, 0xfc, 0xf0, 0xe0, 0x00, 0x00,
  0xf8, 0xff, 0xff, 0x0f, 0x01, 0x00, 0x00, 0xf8,
  0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x7f, 0x1e, 0x0c, 0xc0, 0xe0, 0xe0,
  0xe0, 0xe0, 0xc0, 0x0c, 0x1f, 0x7f, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
  0xf0, 0x00, 0x00, 0x01, 0x0f, 0xff, 0xff, 0xf8,
  0x1f, 0xff, 0xff, 0xf0, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0xc0, 0xe3, 0xe7, 0xe7,
  0xe7, 0xe7, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x80, 0xf0, 0xff, 0xff, 0x1f,
  0x00, 0x00, 0x07, 0x0f, 0x3f, 0x7c, 0xf8, 0xe0,
  0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x60, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0x70,
  0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
  0xe0, 0xf8, 0x7c, 0x3f, 0x0f, 0x07, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x03, 0x07, 0x0f, 0x0e, 0x1e, 0x3c, 0x38, 0x38,
  0x78, 0x78, 0x70, 0xf0, 0xe1, 0xe1, 0xe1, 0xe1,
  0xe1, 0xe1, 0xe1, 0xe1, 0xf0, 0x70, 0x70, 0x78,
  0x38, 0x38, 0x3c, 0x1e, 0x0e, 0x0f, 0x07, 0x03,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
