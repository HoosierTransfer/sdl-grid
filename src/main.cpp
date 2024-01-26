#include <SDL2/SDL.h>
#include "grid.hpp"
#include <vector>

const int GRID_WIDTH = 50;
const int GRID_HEIGHT = 50;

const int CELL_WIDTH = 16;

Grid grid;

std::vector<SDL_Color> colors = {
    { 0, 0, 0, 255 },
    { 255, 255, 255, 255 }
};

void drawGrid(SDL_Renderer* renderer, int x, int y) {
    std::vector<std::vector<int>> slice = grid.gridSlice(x, y, GRID_WIDTH, GRID_HEIGHT);

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            SDL_Rect rect = { i * CELL_WIDTH, (GRID_HEIGHT - j - 1) * CELL_WIDTH, CELL_WIDTH, CELL_WIDTH };
            SDL_SetRenderDrawColor(renderer, colors[slice[i][j]].r, colors[slice[i][j]].g, colors[slice[i][j]].b, colors[slice[i][j]].a);
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

int main() {
    grid = Grid();

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GRID_WIDTH * CELL_WIDTH, GRID_HEIGHT * CELL_WIDTH, 0);

    SDL_SetWindowResizable(window, SDL_FALSE);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        drawGrid(renderer, 0, 0);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}