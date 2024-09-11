//
// Created by Malik T on 11/09/2024.
//
#include "Random.h"

uint64_t random_seed = 144641901;
uint64_t RandomU64(void)
{
    random_seed ^= random_seed >> 12, random_seed ^= random_seed << 25, random_seed ^= random_seed >> 27;
    return (uint64_t)(random_seed * 2685821657736338717LL);
}
