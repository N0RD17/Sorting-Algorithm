#include <SDL2/SDL.h>
#include "headers/LTimer.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

const int WIDTH = 800;
const int HEIGHT = 500;

const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;


SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

float *values = NULL;

void swap(float arr[], int a, int b);

void render();
void draw();

int main(int argc, char* argv[])
{
   (void)argc;
   (void)argv;

   srand((unsigned int)time(NULL));

   // Values will be same number of values as WIDTH
   values = (float *)calloc(WIDTH,sizeof(float));
   for(int i = 0; i < WIDTH; i++)
   {
      values[i] = rand() % 500;
   }

   // Create window and renderer
   SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &window, &renderer);

   SDL_SetWindowTitle(window, "Sorting Algorithm");


   render();
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(renderer);
   SDL_Quit();

   free(values);
   
   return 0;
}

void draw()
{
//   HEIGHT - values[i]

//   int index = 0;
   for(int i = 0; i < WIDTH; i++){
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderDrawLine(renderer, i, HEIGHT, i, HEIGHT - values[i]);
   }

   
}


void render() {
   SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
   SDL_RenderClear(renderer);
   for(int i  = 0; i < WIDTH; i++)
   {
      for(int j = 0; j < WIDTH - i; j++)
      {
         float a = values[j];
         float b = values[j + 1];
         if(a > b){
            swap(values, j, j+1);
         }
         SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
         SDL_RenderClear(renderer);
         draw();
         SDL_RenderPresent(renderer);
      }
   }
   
   SDL_RenderPresent(renderer);
}

void swap(float arr[], int a, int b)
{
   float temp = arr[a];
   arr[a] = arr[b];
   arr[b] = temp;
}
