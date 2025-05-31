#include <spunbacc.h>

VehicleActor::VehicleActor() {
    z = 0.0f;
    y = 0.0f;
    x = 0.0f;

    volume = 0;
    height = 0;
    width = 0;

    dz_velocity = 0.0f;
    dy_velocity = 0.0f;
    dx_velocity = 0.0f;

    hitbox.h = height;
    hitbox.w = width;
}

void VehicleActor::handle_vehicle(SDL_Event &event) {
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.keys.keysym.sym) {
        case SDLK_UP:
            dy_velocity += 100.0f;
            break;
        case SDLK_DOWN:
            dy_velocity -= 100.0f;
            break;
        case SDLK_LEFT:
            dx_velocity += 100.0f;
            break;
        case SDLK_RIGHT:
            dx_velocity -= 100.0f;
            break;
        }
    }
}

void VehicleActor::move_vehicle(SDL_Rect &collision) {
    x += dx_velocity;
    y += dy_velocity;
    z += dz_velocity;

    if( (x < 0) || (x + width > WINDOW_WIDTH) || check_collision(hitbox, collision)) {
        // return back into windowed dimensions
        x -= dx_velocity;
    }

    if( (y < 0) || (y + height > WINDOW_HEIGHT) || check_collision(hitbox, collision)) {
        // return back into windowed dimensions
        y -= dy_velocity;
    }

    if( (z < 0) || (z + volume > VIRTUAL_VOLUME) || check_collision(hitbox, collision)) {
        // return back into windowed dimensions
        z -= dz_velocity;
    }
}

int VehicleActor::check_collision(SDL_Rect a, SDL_Rect b) {
    auto ra = a.x + a.w;
    auto ba = a.y + a.h;
    auto rb = b.x + b.w;
    auto bb = b.y + b.h;

    int ret_val = 0;

    if (ba <= b.y) ret_val = 1;
    if (a.y >= bb) ret_val = 1;
    if (ra <= b.x) ret_val = 1;
    if (a.x >= rb) ret_val = 1;

    return ret_val;
}

auto main() -> int {
}
