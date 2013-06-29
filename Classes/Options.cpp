#ifndef CONST_OPTIONS
#define CONST_OPTIONS

#include "Options.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Options::CENTER_X = 0;
int Options::CENTER_Y = 0;

int Options::SCREEN_WIDTH = 0;
int Options::SCREEN_HEIGHT = 0;

int Options::SCREEN_CENTER_X = 0;
int Options::SCREEN_CENTER_Y = 0;

int Options::CAMERA_WIDTH = 0;
int Options::CAMERA_HEIGHT = 0;

int Options::CAMERA_CENTER_X = 0;
int Options::CAMERA_CENTER_Y = 0;

bool Options::MUSIC_ENABLE = true;
bool Options::SOUND_ENABLE = true;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFROM == CC_PLATFORM_MAC)
const char* Options::FONT = "Gang of Three";
const char* Options::GAME_MUSIC = "nature_bgm.mp3";
const char* Options::GAME_OVER = "game-over.mp3";
const char* Options::START_LEVEL = "game-start.mp3";
#else
const char* Options::FONT = "Fonts/go3v2.ttf";
const char* Options::GAME_MUSIC = "Sound/nature_bgm.mp3";
const char* Options::GAME_OVER = "Sound/game-over.ogg";
const char* Options::START_LEVEL = "Sound/game-start.ogg";
#endif

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif