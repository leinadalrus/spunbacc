#ifndef SPUNBACC_H
#define SPUNBACC_H

#define sb_destroy(x) {delete x; x = nullptr;}

#include <cstdio>
#include <cstdlib>
#include <cmath>

// Additional include headers: here
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// My include headers/libraries

#include <tuple_t.h>

// My constants

const char *APP_TITLE = "o)))) ((spunbacc))";
const int VIRTUAL_VOLUME = 320;
const int WINDOW_HEIGHT = 440;
const int WINDOW_WIDTH = 532;

// My classes
enum class KeyPressedSurfaces {
    KEY_PRESSED_SURFACE_DEFAULT,
    KEY_PRESSED_SURFACE_UP,
    KEY_PRESSED_SURFACE_DOWN,
    KEY_PRESSED_SURFACE_LEFT,
    KEY_PRESSED_SURFACE_RIGHT,
};

class ColourKeyTexturee {
    SDL_Renderer *renderer;
    SDL_Texture *texturee;
    int width;
    int height;

  public:
    ColourKeyTexturee();
    ~ColourKeyTexturee();

    int load_file(const char* filepath);
    void dealloc_texture();
    void render_texture(int x, int y);
};

class VehicleActor {
    float x;
    float y;
    float z;

    int volume;
    int height;
    int width;

    float dx_velocity;
    float dy_velocity;
    float dz_velocity;

    SDL_Rect hitbox;

  public:
    VehicleActor() {}

    void handle_vehicle(SDL_Event &event);
    void move_vehicle(SDL_Rect &collision);
    int check_collision(SDL_Rect a, SDL_Rect b);
};

class EngineModule {
  public:
    EngineModule() {}

    int natural_aspiration = 0;
    int displacement = 0;

    int gears = 0;
    int max_rpm = 0;

    float power = 0.0f;
    float torque = 0.0f;
    int weight = 0;
};

class DrivetrainModule {
  public:
    DrivetrainModule() {}

    int layout = 0;
    int weight = 0;

    int max_speed = 0;
    int ground_clearance = 0;

    int wheel_base = 0;
    int wheel_size = 0;
};

class ChassisModule {
  public:
    ChassisModule() {}

    int downforce = 0;
    int weight = 0;
    float air_resistance = 0.0f;
};

class RacecarPrototype {
    EngineModule engine;
    DrivetrainModule drivetrain;
    ChassisModule chassis;

  public:
    RacecarPrototype() {}
};

#endif // SPUNBACC_H
