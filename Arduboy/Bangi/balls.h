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

#include "config.h"

#define SMALL_BALL_SIZE 8
#define MEDIUM_BALL_SIZE 16
#define BIG_BALL_SIZE 24

const unsigned char BALL_SIZES[] =
{
  0,
  SMALL_BALL_SIZE,
  MEDIUM_BALL_SIZE,
  BIG_BALL_SIZE,
};

const unsigned char BALL_X_SPEEDS[] =
{
  0,
  BALL_SMALL_SPEED_X,
  BALL_MEDIUM_SPEED_X,
  BALL_BIG_SPEED_X,
};

const unsigned char BALL_Y_SPEEDS[] =
{
  0,
  BALL_SMALL_SPEED_Y,
  BALL_MEDIUM_SPEED_Y,
  BALL_BIG_SPEED_Y,
};


// Small balls (8,8)

const unsigned char PROGMEM SMALL_BALL_BITMAP[] = //8,8
{
  0x3c, 0x42, 0x8d, 0x85, 0xc1, 0xa1, 0x52, 0x3c,
};

const unsigned char PROGMEM SMALL_BALL_ROT_BITMAP[] = //8,8
{
  0x3c, 0x4a, 0x85, 0x83, 0xa1, 0xb1, 0x42, 0x3c,
};

const unsigned char PROGMEM SMALL_BALL_MASK_BITMAP[] = //8,8
{
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c,
};



// Medium balls (16,16)

const unsigned char PROGMEM MEDIUM_BALL_BITMAP[] = //16,16
{
  0xe0, 0x18, 0xe4, 0xf2, 0xfa, 0x39, 0x19, 0x01,
  0x01, 0x01, 0x01, 0x02, 0x02, 0x04, 0x98, 0xe0,
  0x07, 0x18, 0x20, 0x41, 0x41, 0x80, 0xa0, 0xd0,
  0xa8, 0xd4, 0xba, 0x54, 0x6a, 0x35, 0x1a, 0x07,
};

const unsigned char PROGMEM MEDIUM_BALL_ROT_BITMAP[] = //16,16
{
  0xe0, 0x58, 0xac, 0x56, 0x2a, 0x5d, 0x2b, 0x15,
  0x0b, 0x05, 0x01, 0x82, 0x82, 0x04, 0x18, 0xe0,
  0x07, 0x19, 0x20, 0x40, 0x40, 0x80, 0x80, 0x80,
  0x80, 0x98, 0x9c, 0x5f, 0x4f, 0x27, 0x18, 0x07,
};

const unsigned char PROGMEM MEDIUM_BALL_MASK_BITMAP[] = //16,16
{
  0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0,
  0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x07,
};



// Big balls (24,24)

const unsigned char PROGMEM BIG_BALL_BITMAP[] = //24,24
{
  0x00, 0xc0, 0x20, 0x90, 0xe8, 0xf4, 0xf2, 0xfa,
  0x7a, 0x39, 0x19, 0x01, 0x01, 0x01, 0x01, 0x02,
  0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0xc0, 0x00,
  0x7e, 0x81, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x0f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x80, 0x40, 0xa0, 0x50, 0xa9, 0x7e,
  0x00, 0x03, 0x04, 0x08, 0x10, 0x20, 0x40, 0x40,
  0x40, 0x80, 0x8a, 0x95, 0xaa, 0xd5, 0xba, 0x5d,
  0x7e, 0x5d, 0x2a, 0x15, 0x0a, 0x05, 0x03, 0x00,
};

const unsigned char PROGMEM BIG_BALL_ROT_BITMAP[] = //24,24
{
  0x00, 0xc0, 0xa0, 0x50, 0xa8, 0x54, 0xba, 0x7e,
  0xba, 0x5d, 0xab, 0x55, 0xa9, 0x51, 0x01, 0x02,
  0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0xc0, 0x00,
  0x7e, 0x95, 0x0a, 0x05, 0x02, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0xf8, 0xf8, 0xf8, 0xf0, 0x00, 0x81, 0x7e,
  0x00, 0x03, 0x04, 0x08, 0x10, 0x20, 0x40, 0x40,
  0x40, 0x80, 0x80, 0x80, 0x80, 0x98, 0x9c, 0x5e,
  0x5f, 0x4f, 0x2f, 0x17, 0x09, 0x04, 0x03, 0x00,
};

const unsigned char PROGMEM BIG_BALL_MASK_BITMAP[] = //24,24
{
  0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xfe,
  0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
  0xfe, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x00,
  0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e,
  0x00, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0x7f,
  0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f,
  0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00,
};


const unsigned char*  BALL_BITMAPS[] = {
  0,
  SMALL_BALL_BITMAP,
  MEDIUM_BALL_BITMAP,
  BIG_BALL_BITMAP,
};

const unsigned char*  BALL_ROT_BITMAPS[] = {
  0,
  SMALL_BALL_ROT_BITMAP,
  MEDIUM_BALL_ROT_BITMAP,
  BIG_BALL_ROT_BITMAP,
};

const unsigned char*  BALL_MASK_BITMAPS[] = {
  0,
  SMALL_BALL_MASK_BITMAP,
  MEDIUM_BALL_MASK_BITMAP,
  BIG_BALL_MASK_BITMAP,
};
