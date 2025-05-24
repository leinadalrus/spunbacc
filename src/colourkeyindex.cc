#include <spunbacc.h>

ColourKeyTexturee::ColourKeyTexturee() {
    SDL_Texture *texturee = nullptr;
    int width = 0;
    int height = 0;
}

ColourKeyTexturee::~ColourKeyTexturee() {
    this->dealloc_texture();
}

int ColourKeyTexturee::load_file(const char *path) {
    this->dealloc_texture();

    SDL_Texture *next_texturee = nullptr;
    SDL_Surface *loaded_surface = IMG_Load(path);
    if (loaded_surface == NULL)
        std::printf("%s: %s\n\t", path, IMG_GetError());

    SDL_SetColorKey(loaded_surface, SDL_TRUE,
                    SDL_MapRGB(loaded_surface->format, 0, 0xff, 0xff));
    next_texturee = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if (next_texturee == NULL)
        std::printf("%s: %s\n\t", path, IMG_GetError());

    this->width = loaded_surface->w;
    this->height = loaded_surface->h;

    SDL_FreeSurface(loaded_surface);
    this->texturee = next_texturee;

    return this->texturee != NULL;
}

void ColourKeyTexturee::render_texture(int xn, int yn) {
    SDL_Rect render_quads = { xn, yn, this->width, this->height };
    SDL_RenderCopy(this->renderer, this->texturee, NULL, &render_quads);
}

void ColourKeyTexturee::dealloc_texture() {
    if (this->texturee != NULL) {
        this->width = 0;
        this->height = 0;

        SDL_DestroyTexture(this->texturee);
        sb_destroy(this->texturee)
    }
}
