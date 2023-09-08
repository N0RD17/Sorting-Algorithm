// Includes
#include <SDL2/SDL.h>
#include "headers/LTimer.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Width and Height values
const int WIDTH = 800;
const int HEIGHT = 500;

// The window and renderer
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

// What will store the numbers that are being sorted
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
      // Assign each element array of values the remainder of rand() and 500
      values[i] = rand() % 500;
   }

   // Create window and renderer
   SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, &window, &renderer);

   // Sets the title of the Window
   SDL_SetWindowTitle(window, "Sorting Algorithm");


   // Calls render
   render();

   // After render is done call these values
   SDL_DestroyWindow(window);
   SDL_DestroyRenderer(renderer);
   SDL_Quit();

   // Frees the dynamically allocated array
   free(values);
   
   return 0;
}

void draw()
{
   // What will draw the Sorting Algorithm
   for(int i = 0; i < WIDTH; i++){
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderDrawLine(renderer, i, HEIGHT, i, HEIGHT - values[i]);
   }
}

void render() {
   // Background color
   SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
   // Clear the renderer
   SDL_RenderClear(renderer);

   // Calculate the sort
   for(int i  = 0; i < WIDTH; i++)
   {
      for(int j = 0; j < WIDTH - i; j++)
      {
         // Swap values
         float a = values[j];
         float b = values[j + 1];
         if(a > b){
            swap(values, j, j+1);
         }

         // After the values check each other and potentially swap, clear render then draw and display
         SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
         SDL_RenderClear(renderer);
         draw();
         SDL_RenderPresent(renderer);
      }
   }

   // Display
   SDL_RenderPresent(renderer);
}

// Swap array values
void swap(float arr[], int a, int b)
{
   float temp = arr[a];
   arr[a] = arr[b];
   arr[b] = temp;
}
