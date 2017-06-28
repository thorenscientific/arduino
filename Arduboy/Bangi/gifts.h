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
#define GIFT_SIZE  13

const unsigned char PROGMEM GIFT_LIFE_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x61, 0xf1, 0xf9, 0xf1, 0xe1, 0xf1,
  0xf9, 0xf1, 0x61, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x10, 0x11, 0x13, 0x17, 0x13, 0x11, 0x10, 0x10,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_DOUBLE_RAY_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x21, 0x11, 0xf9, 0x11, 0x21, 0x11,
  0xf9, 0x11, 0x21, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x10, 0x17, 0x10, 0x10, 0x10, 0x17, 0x10, 0x10,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_NO_GRAVITY_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x41, 0xc1, 0xc1, 0xe1, 0xf1, 0xf9,
  0x69, 0x39, 0x01, 0x03, 0xfe, 0x0f, 0x18, 0x12,
  0x14, 0x11, 0x13, 0x17, 0x10, 0x10, 0x10, 0x10,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_NEGATIVE_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x01, 0xf9, 0xf9, 0xf9, 0x79, 0x39,
  0x19, 0xf9, 0x01, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x13, 0x13, 0x12, 0x12, 0x12, 0x12, 0x13, 0x10,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_DEATH_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x01, 0xf1, 0x99, 0x9d, 0xfd, 0x9d,
  0x99, 0xf1, 0x01, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x11, 0x17, 0x13, 0x16, 0x13, 0x17, 0x11, 0x10,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_SLOW_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x41, 0xe1, 0xb1, 0x19, 0x49, 0xe1,
  0xb1, 0x19, 0x09, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x10, 0x11, 0x13, 0x12, 0x10, 0x11, 0x13, 0x12,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_MIRROR_BITMAP[] = //13,13
{
  0xfe, 0x03, 0x11, 0x39, 0x55, 0x11, 0x11, 0x11,
  0x51, 0x91, 0x01, 0x03, 0xfe, 0x0f, 0x18, 0x10,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0x13, 0x11,
  0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_SHIELD_BITMAP[] = //13,13
{
0xfe, 0x03, 0x01, 0x79, 0xf9, 0xf9, 0xf9, 0xf9,
0xf9, 0x79, 0x01, 0x03, 0xfe, 0x0f, 0x18, 0x10,
0x10, 0x11, 0x13, 0x17, 0x13, 0x11, 0x10, 0x10,
0x18, 0x0f,
};

const unsigned char PROGMEM GIFT_MASK_BITMAP[] = //13,13
{
  0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xfe, 0x0f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
  0x1f, 0x0f,
};
