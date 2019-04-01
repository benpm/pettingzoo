#ifndef DEFS_H
#define DEFS_H

// Default NN parameters
#define IN_H                  12
#define IN_W                  12
#define HLC                   2
#define NPL                   128
#define GEN_SIZE              100
#define GENERATIONS           1
#define MUTATE_RATE           0.001f

struct Params {
    int in_h;
    int in_w;
    int hlc;
    int npl;
    int gen_size;
    int generations;
    float mutate_rate;
};

// Time in seconds until NN is considered timedout
// based on fitness change
#define AGENT_FITNESS_TIMEOUT (UPDATES_PS * 6)

// Enemies
#define ENABLE_ENEMIES  false
#define JUMPING_ENEMIES false
#define MAX_ENEMIES 0

// Button parameters
#define BUTTON_COUNT 3
#define LEFT  0
#define RIGHT 1
#define JUMP  2

// Level parameters
#define LEVEL_HEIGHT 32
#define LEVEL_WIDTH  256
#define TILE_SIZE    32
#define LEVEL_PIXEL_WIDTH (LEVEL_WIDTH * TILE_SIZE)
#define LEVEL_PIXEL_HEIGHT (LEVEL_HEIGHT * TILE_SIZE)
#define LEVEL_SIZE (LEVEL_HEIGHT * LEVEL_WIDTH)

#define BG            0
#define GRID          1
#define LAMP          2

#define INPUT_SIZE    16

#endif
