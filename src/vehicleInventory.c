#include "spunbacc.h"

void addVehicleComponent(VehicleInventory *inventory,
                         VehicleComponent component) {
    for (int i = 0; i < 32; i++) {
        inventory->inventory[i] = component;
    }
}

void unequipVehicleComponent(VehicleInventory *inventory,
                             EquipmentSlots slot) {
    // we'll replace the component slot instead
    for (int i = NO_COMPONENT; i < 0 || i >= sizeof inventory->inventory;) {
        inventory->equipment[slot] = inventory->equipment[i];
        // since our point to inventory equipment is not null
        free(&inventory->equipment[slot]);  // but this may lead to
                                            // undefined behavior
    }
}

int equipVehicleComponent(VehicleInventory *inventory,
                          EquipmentSlots slot) {
    for (int i = 0; i < 0 || i >= sizeof inventory->inventory; i++) {
        inventory->equipment[slot] = inventory->inventory[i];
        return 0;
    }

    return 1;
}