#ifndef SPUNBACC_H
#define SPUNBACC_H

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
