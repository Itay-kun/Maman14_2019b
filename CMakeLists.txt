cmake_minimum_required(VERSION 3.5)
project(Maman14_2019b C)

set(CMAKE_C_STANDARD 90)

add_executable(Maman14_2019b main.c WordsExtractor.c WordsExtractor.h fromBitToSign.c FromBitToSign.h FileGeneralOperations.c FileGeneralOperations.h)