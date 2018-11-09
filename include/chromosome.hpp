#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <stdint.h>
#include <stdlib.h>

#define BUTTON_COUNT 3

uint8_t *generate_chromosome(uint8_t in_h, uint8_t in_w, uint8_t hlc, uint16_t npl);
uint8_t *locate_input_act(uint8_t *chrom);
float *locate_input_adj(uint8_t *chrom);
uint8_t *locate_hidden_act(uint8_t *chrom);
size_t get_chromosome_size(uint8_t in_h, uint8_t in_w, uint8_t hlc, uint16_t npl);
float *locate_hidden_adj(uint8_t *chrom, int num);
float *locate_out_adj(uint8_t *chrom);
void print_chromosome(uint8_t *chrom);

/*

All matrices in the chromosome will be flattened, 2D, row-major matrices with elements of type
uint8_t unless otherwise stated.

The parameters that define the size of a chromosome (notably nodes per hidden layer and hidden
layer count) will hopefully change so we will embed the size parameters in the beginning of a
chcromosome to allow some amount of portability. The first elements of a chromosome will be as
follows (byte indexed):

    0: IN_W (input width)
    1: IN_H (input height)
    2-3: NPL (nodes per hidden layer)
    4: HLC (hidden layer count)

INPUT ACTIVATION MATRIX
The next chunk of the chromosome will be a matrix of size (IN_H, IN_W) describing which
input tiles are active. The array is arranged from top to bottom, left to right w.r.t. the 
input (top left tile of input is first entry, bottom right tile is last entry). It currently 
makes sense to me that an inactive input tile should report that there is simply nothing there 
(empty tile). A 0 in this matrix at index i,j means that input tile i,j is inactive. A 1 means 
the input is active.

INPUT ADJACENCY MATRIX
The next chunk will be a matrix of size (NPL, IN_H * IN_W) and is an adjacency matrix
describing the weights connecting the input nodes to the first hidden layer. Each element will
be of type float. A row in this matrix represents a single node in the first hidden layer and 
the columns of that row represent a connection from a node in the input layer to said node. The
array is set up like this as it is cache friendly. The column is a flat index into the input
array, just like the indexing in the input activation matrix.

HIDDEN ACTIVATION MATRIX
The next chunk will be a matrix of size (HLC, NPL) describing which neurons are active in the
hidden layers. A 0 means active, and a 1 means inactive. This is transposed ((HLC, NPL) rather
than (NPL, HLC), which is the "logical view") to be cache friendly. Each row corresponds to an
entire layer.

HIDDEN ADJACENCY MATRIX
The next (HLC - 1) chunks will be adjacency matrices of size (NPL, NPL) describing weights
between the previous hidden layer and the current. Each element will be of type float. Once
again, this is logically transposed (at least logically to me) for cache-friendlyness. Each
row represents a node and the columns are connections to it.

OUTPUT ADJACENCY MATRIX
The final chunk will be an adjacency matrix of size (NPL, OUTPUT_SIZE) describing the weights
between the final hidden layer and the output layer. Each element will be of type float. Same
format as other adjacency matrices, each row represents a button and the columns are connections
to that button.

*/

#endif