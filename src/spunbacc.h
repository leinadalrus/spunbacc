#ifndef SPUNBACC_H
#define SPUNBACC_H

<<<<<<< HEAD
#pragma once

#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>

// Additional include files here...

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Custom code here

typedef enum EquipmentSlots {
    ENGINE_SLOT,
    POWERTRAIN_SLOT,
    CHASSIS_SLOT,
    TIRE_SLOT
} EquipmentSlots;

typedef enum VehicleComponentTypes {
    NO_COMPONENT,
    ENGINE_COMPONENT,
    POWERTRAIN_COMPONENT,
    CHASSIS_COMPONENT,
    TIRE_COMPONENT,
    REPAIRKIT_COMPONENT,
    MEDIKIT_COMPONENT
} VehicleComponentTypes;

typedef struct VehicleComponent {
    VehicleComponentTypes vehicleComponent;
    const char *componentName;
    const char *componentValue;
} VehicleComponent;

typedef struct VehicleInventory {
    VehicleComponent inventory[32];
    VehicleComponent equipment[10];
} VehicleInventory;

void addVehicleComponent(VehicleInventory *inventory,
                         VehicleComponent component);
void unequipVehicleComponent(VehicleInventory *inventory,
                             EquipmentSlots slot);
int equipVehicleComponent(
    VehicleInventory *inventory,
    EquipmentSlots
        slot);  // int is preferable more than bool as a primitive type

typedef struct VehicleActor {
    float x;
    float y;  // angle
    float z;  // current height

    int volume;  // y-axis
    int height;  // z-axis
    int width;   // x-axis

    float dx_velocity;  // steer
    float dy_velocity;  // speed
    float dz_velocity;  // jump and drop speed and dictation
} VehicleActor;

#endif  // SPUNBACC_H
=======
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

const float ACCELERATION = 0.05f;
const float FRICTION = 0.02f;
const float MAX_SPEED = 1.0f;
const float STEER_SPEED = 1.0f;

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
    float y; // angle
    float z; // current height

    int volume;
    int height;
    int width;

    float dx_velocity; // steer
    float dy_velocity; // speed
    float dz_velocity; // jump and drop speed and dictation

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
>>>>>>> fad2eb094db5a6ac08384ed12207825e672a7674
