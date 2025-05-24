#include <spunbacc.h>

class GamePrototypeMgr {
    // Core
    SDL_Window *window = nullptr;
    SDL_Surface *main_surface = nullptr;
    SDL_Surface *key_pressed_surfaces[[]];
    SDL_Surface *current_surface = nullptr;

    // Accessory
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *texturer = nullptr;
  public:
    int window_init(
        SDL_Window *window
    ) {
        SDL_Surface *input_surface = nullptr;
        SDL_Surface *output_surface = nullptr;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("%s", SDL_GetError());
            return 1;
        }

        window = SDL_CreateWindow(APP_TITLE,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);
        input_surface = SDL_GetWindowSurface(window);

        SDL_FillRect(input_surface,
                     NULL,
                     SDL_MapRGB(input_surface->format,
                                0xff,
                                0xff,
                                0xff));

        SDL_BlitSurface(output_surface, NULL, input_surface, NULL);
        SDL_UpdateWindowSurface(window);

        return 0;
    }

    SDL_Texture *load_texture(const char *filepath) {
        SDL_Surface *loaded_surface = IMG_Load(filepath);
        if (loaded_surface == NULL) {
            std::printf("%s", IMG_GetError());
        }

        SDL_Texture *next_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if (next_texture = NULL) {
            std::printf("%s", SDL_GetError());
        }

        SDL_FreeSurface(loaded_surface);

        return next_texture;
    }

    SDL_Surface *load_surface(const char *filepath, SDL_Surface *screen_surface) {
        SDL_Surface *loaded_surface = SDL_LoadBMP(filepath);
        if (loaded_surface == NULL) {
            std::printf("%s", SDL_GetError());
        }

        SDL_Surface formatted_surface =
            SDL_ConvertSurface(loaded_surface, screen_surface->format, 0);
        SDL_FreeSurface(loaded_surface);

        return &formatted_surface;
    }

    int load_surface_mediums(
        SDL_Window window,
        SDL_Surface surface
    ) {
        int is_quitting = 0;
        SDL_Event event_code;

        current_surface =
            key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_DEFAULT];

        while (!is_quitting) {
            while (SDL_PollEvent(&event_code) != 0) {
                if (event_code == SDL_QUIT) {
                    is_quitting = 1;
                }

                switch (event_code.key.keysym.sym) {
                case SDLK_UP:
                    current_surface = key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_UP];
                    key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_UP] =
                        load_surface("data/imgs/up.bmp", current_surface);

                case SDLK_DOWN:
                    current_surface = key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_DOWN];
                    key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_DOWN] =
                        load_surface("data/imgs/down.bmp", current_surface);

                case SDLK_LEFT:
                    current_surface = key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_LEFT];
                    key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_LEFT] =
                        load_surface("data/imgs/left.bmp", current_surface);

                case SDLK_RIGHT:
                    current_surface = key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_RIGHT];
                    key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_RIGHT] =
                        load_surface("data/imgs/right.bmp", current_surface);

                default:
                    current_surface =
                        key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_DEFAULT];
                    key_pressed_surfaces[KeyPressedSurfaces::KEY_PRESSED_SURFACE_DEFAULT] = load_surface("data/imgs/default.bmp");
                }

                this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                if (renderer = NULL) {
                    std::printf("%s", SDL_GetError());
                }

                SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
                //Initialize PNG loading
                int img_flags = IMG_INIT_PNG;
                if( !( IMG_Init( img_flags ) & img_flags ) ) {
                    std::printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                }

                SDL_BlitScaled(current_surface, NULL, surface, NULL);
                SDL_UpdateWindowSurface(window);

                //Clear screen
                SDL_RenderClear(renderer);
                //Render texture to screen
                SDL_RenderCopy(renderer, texturer, NULL, NULL);
                //Update screen
                SDL_RenderPresent(renderer);
            }
        }

        close_window(window, surface);
        return is_quitting;
    }

    int init_viewport() {
        SDL_Rect viewport;
        viewport.x = 0;
        viewport.y = 0;
        viewport.w = SCREEN_WIDTH;
        viewport.h = SCREEN_HEIGHT;

        SDL_RenderSetViewport(this->renderer, &viewport);
        SDL_RenderCopy(this->renderer, this->texturer, NULL, NULL);
        SDL_RenderPresent(this->renderer);
    }

    int close_window(
        SDL_Window window,
        SDL_Surface surface
    ) {
        int is_quitting = 0;
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                is_quitting = 1;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texturer, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_FreeSurface(surface);
        surface = nullptr;

        SDL_DestroyRenderer(renderer);
        renderer = nullptr;

        SDL_DestroyWindow(window);
        window = nullptr;

        IMG_Quit();
        SDL_Quit();
        return is_quitting;
    }
};

int main() {
    SDL_Window *window = nullptr;
    SDL_Surface *surface = nullptr;

    GamePrototypeMgr game_mgr = new GamePrototypeMgr();
    game_mgr.window_init(window, surface);
    game_mgr.load_surface_mediums(window, surface);
    game_mgr.close_window(window, surface);
}

