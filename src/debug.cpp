#include <stdio.h>
#include <stdint.h>
#include <chromosome.hpp>
#include <gamelogic.hpp>
#include <genetic.hpp>
#include <neural_network.hpp>
#include <levelgen.hpp>
#include <cuda_helper.hpp>
#include <defs.hpp>
#include <cuda_runtime.h>
#include <cuda.h>
#include <time.h>
#include <math.h>

int main()
{
    struct Game game;
    struct Player players;
    struct Chromosome chrom;
    struct Chromosome chromIN;
    unsigned int member, seed, level_seed;

    initialize_chromosome(&chrom, IN_W, IN_H, HLC, NPL);
    generate_chromosome(&chrom, 144);
    print_chromosome(&chrom);

    return 0;
}
