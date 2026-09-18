#pragma once

#include <Arduino.h>

void setBit(volatile uint8_t& reg, uint8_t bit){
    reg |= 1 << bit ;
}

void clearBit(volatile uint8_t& reg, uint8_t bit){
    reg &= ~(1 << bit);
}

void toggleBit(volatile uint8_t& reg, uint8_t bit){
    reg ^= (1 << bit);
}

bool getBit(volatile uint8_t& reg, uint8_t bit){
    return (reg & (1 << bit)) != 0;
}

unsigned int getBits(
    volatile uint8_t& reg,
    uint8_t start,
    uint8_t count
){
    reg >>= start;
    uint8_t mask = 0;
    for(uint8_t i = 0; i < count; ++i){
        mask |= 1 << i;   
    }
    return reg & mask;
}

void setBits(
    volatile uint8_t& reg,
    uint8_t start,
    uint8_t count
){
    uint8_t mask = 0;
    for(uint8_t i = 0; i < count; ++i){
        mask |= 1 << i;   
    }
    mask <<= start;
    reg |= mask;
}

void clearBits(
    volatile uint8_t& reg,
    uint8_t start,
    uint8_t count
){
    uint8_t mask = 0;
    for(uint8_t i = 0; i < count; ++i){
        mask |= 1 << (i + start);   
    }
    reg &= ~mask;
}

void writeBits(
    volatile uint8_t& reg,
    uint8_t start,
    uint8_t count,
    uint8_t newValue
){
    uint8_t mask = 0;
    for(uint8_t i = 0; i < count; ++i){
        mask |= 1 << (i + start);   
    }

    newValue &= (mask >> start);
    newValue <<= start;

    mask = ~mask;
    reg &= mask;

    reg |= newValue;

}