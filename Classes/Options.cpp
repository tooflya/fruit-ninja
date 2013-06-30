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

const char* Options::COMBO[10] = { "combo-0.mp3", "combo-1.mp3", "combo-2.mp3", "combo-3.mp3", "combo-4.mp3", "combo-5.mp3", "combo-6.mp3", "combo-7.mp3", "combo-8.mp3", "combo-9.mp3" };

const char* Options::COMBO_BLITZ_BACKING_LIGHT = "combo-blitz-backing-light.ogg";
const char* Options::COMBO_BLITZ_BACKING = "combo-blitz-backing.ogg";
const char* Options::NATURE_BGM = "nature_bgm.mp3";
const char* Options::COMBO_BLITZ_BACKING_END = "combo-blitz-backing-end.ogg";
const char* Options::TOSS_SIMULTANEOUS = "toss_simultaneous.mp3";
const char* Options::SWOOSH = "swoosh.mp3";
const char* Options::IMPACT_APPLE = "impact-apple.ogg";
const char* Options::IMPACT_BANANA = "impact-banana.ogg";
const char* Options::IMPACT_COCONUT = "impact-coconut.ogg";
const char* Options::IMPACT_WATERMELON = "impact-watermelon.ogg";
const char* Options::IMPACT_KIWIFRUIT = "impact-kiwifruit.ogg";
const char* Options::IMPACT_ORANGE = "impact-orange.ogg";
const char* Options::SQUASH = "squash.mp3";
const char* Options::EXPLOSION = "explosion.mp3";
const char* Options::CRITICAL = "critical.ogg";
const char* Options::LOSE_LIFE = "lose_life.mp3";
const char* Options::THROW_BOMB = "throw-bomb.ogg";
const char* Options::BOMB_FUSE = "bomb-fuse.ogg";
const char* Options::THROW_FRUIT = "throw-fruit.ogg";

#else
const char* Options::FONT = "Fonts/go3v2.ttf";
const char* Options::GAME_MUSIC = "Music/nature_bgm.mp3";
const char* Options::GAME_OVER = "Sound/game-over.mp3";
const char* Options::START_LEVEL = "Sound/game-start.mp3";

const char* Options::COMBO[10] = { "Sound/combo-0.mp3", "Sound/combo-1.mp3", "Sound/combo-2.mp3", "Sound/combo-3.mp3", "Sound/combo-4.mp3", "Sound/combo-5.mp3", "Sound/combo-6.mp3", "Sound/combo-7.mp3", "Sound/combo-8.mp3", "Sound/combo-9.mp3" };

const char* Options::COMBO_BLITZ_BACKING_LIGHT = "combo-blitz-backing-light.ogg";
const char* Options::COMBO_BLITZ_BACKING = "Sound/combo-blitz-backing.ogg";
const char* Options::NATURE_BGM = "Music/nature_bgm.mp3";
const char* Options::COMBO_BLITZ_BACKING_END = "Sound/combo-blitz-backing-end.ogg";
const char* Options::TOSS_SIMULTANEOUS = "Sound/toss_simultaneous.mp3";
const char* Options::SWOOSH = "Sound/swoosh.mp3";
const char* Options::IMPACT_APPLE = "Sound/impact-apple.ogg";
const char* Options::IMPACT_BANANA = "Sound/impact-banana.ogg";
const char* Options::IMPACT_COCONUT = "Sound/impact-coconut.ogg";
const char* Options::IMPACT_WATERMELON = "Sound/impact-watermelon.ogg";
const char* Options::IMPACT_KIWIFRUIT = "Sound/impact-kiwifruit.ogg";
const char* Options::IMPACT_ORANGE = "Sound/impact-orange.ogg";
const char* Options::SQUASH = "Sound/squash.mp3";
const char* Options::EXPLOSION = "Sound/explosion.mp3";
const char* Options::CRITICAL = "Sound/critical.ogg";
const char* Options::LOSE_LIFE = "Sound/lose_life.mp3";
const char* Options::THROW_BOMB = "Sound/throw-bomb.ogg";
const char* Options::BOMB_FUSE = "Sound/bomb-fuse.ogg";
const char* Options::THROW_FRUIT = "Sound/throw-fruit.ogg";
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