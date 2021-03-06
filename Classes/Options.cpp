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

float const Options::EFFECT_WHITE_APPEAR_TIME = 0.3;
float const Options::EFFECT_BLACK_APPEAR_TIME = 3.0;
float const Options::EFFECT_SLIDE_VECTOR_X = 250.0;
float const Options::EFFECT_SLIDE_VECTOR_Y = 250.0;

float const Options::AWESOME_SCALE_APPEAR = 1.7;
float const Options::AWESOME_SCALE_APPEAR_TIME = 0.3;

float const Options::AWESOME_ROTATE_APPEAR = 10.0;
float const Options::AWESOME_ROTATE_APPEAR_TIME = 0.3;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFROM == CC_PLATFORM_MAC)

const char* Options::FONT = "Gang of Three";
const char* Options::GAME_MUSIC = "nature_bgm.mp3";
const char* Options::GAME_OVER = "game-over.mp3";
const char* Options::START_LEVEL = "game-start.mp3";

const char* Options::COMBO[10] = { "combo-0.mp3", "combo-1.mp3", "combo-2.mp3", "combo-3.mp3", "combo-4.mp3", "combo-5.mp3", "combo-6.mp3", "combo-7.mp3", "combo-8.mp3", "combo-9.mp3" };

const char* Options::COMBO_BLITZ_BACKING_LIGHT = "combo-blitz-backing-light.mp3";
const char* Options::COMBO_BLITZ_BACKING = "combo-blitz-backing.mp3";
const char* Options::NATURE_BGM = "nature_bgm.mp3";
const char* Options::COMBO_BLITZ_BACKING_END = "combo-blitz-backing-end.mp3";
const char* Options::TOSS_SIMULTANEOUS = "toss_simultaneous.mp3";
const char* Options::SWOOSH = "swoosh.mp3";
const char* Options::IMPACT_APPLE = "impact-apple.mp3";
const char* Options::IMPACT_BANANA = "impact-banana.mp3";
const char* Options::IMPACT_COCONUT = "impact-coconut.mp3";
const char* Options::IMPACT_WATERMELON = "impact-watermelon.mp3";
const char* Options::IMPACT_KIWIFRUIT = "impact-kiwifruit.mp3";
const char* Options::IMPACT_ORANGE = "impact-orange.mp3";
const char* Options::SQUASH = "squash.mp3";
const char* Options::EXPLOSION = "explosion.mp3";
const char* Options::CRITICAL = "critical.mp3";
const char* Options::LOSE_LIFE = "lose_life.mp3";
const char* Options::THROW_BOMB = "throw-bomb.mp3";
const char* Options::BOMB_FUSE = "bomb-fuse.mp3";
const char* Options::THROW_FRUIT = "throw-fruit.mp3";
const char* Options::BONUS_BLOW = "bonus-blow.mp3";

#else

const char* Options::FONT = "Fonts/go3v2.ttf";
const char* Options::GAME_MUSIC = "Music/nature_bgm.ogg";
const char* Options::GAME_OVER = "Sound/game-over.ogg";
const char* Options::START_LEVEL = "Sound/game-start.ogg";

const char* Options::COMBO[10] = { "Sound/combo-0.ogg", "Sound/combo-1.ogg", "Sound/combo-2.ogg", "Sound/combo-3.ogg", "Sound/combo-4.ogg", "Sound/combo-5.ogg", "Sound/combo-6.ogg", "Sound/combo-7.ogg", "Sound/combo-8.ogg", "Sound/combo-9.ogg" };

const char* Options::COMBO_BLITZ_BACKING_LIGHT = "Sound/combo-blitz-backing-light.ogg";
const char* Options::COMBO_BLITZ_BACKING = "Sound/combo-blitz-backing.ogg";
const char* Options::NATURE_BGM = "Music/nature_bgm.ogg";
const char* Options::COMBO_BLITZ_BACKING_END = "Sound/combo-blitz-backing-end.ogg";
const char* Options::TOSS_SIMULTANEOUS = "Sound/toss_simultaneous.ogg";
const char* Options::SWOOSH = "Sound/swoosh.mp3";
const char* Options::IMPACT_APPLE = "Sound/impact-apple.ogg";
const char* Options::IMPACT_BANANA = "Sound/impact-banana.ogg";
const char* Options::IMPACT_COCONUT = "Sound/impact-coconut.ogg";
const char* Options::IMPACT_WATERMELON = "Sound/impact-watermelon.ogg";
const char* Options::IMPACT_KIWIFRUIT = "Sound/impact-kiwifruit.ogg";
const char* Options::IMPACT_ORANGE = "Sound/impact-orange.ogg";
const char* Options::SQUASH = "Sound/squash.ogg";
const char* Options::EXPLOSION = "Sound/explosion.ogg";
const char* Options::CRITICAL = "Sound/critical.ogg";
const char* Options::LOSE_LIFE = "Sound/lose_life.ogg";
const char* Options::THROW_BOMB = "Sound/throw-bomb.ogg";
const char* Options::BOMB_FUSE = "Sound/bomb-fuse.ogg";
const char* Options::THROW_FRUIT = "Sound/throw-fruit.ogg";
const char* Options::BONUS_BLOW = "Sound/bonus-blow.ogg";

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