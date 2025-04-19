cmake_minimum_required(VERSION 3.28)
project(bank_system C)

set(CMAKE_C_STANDARD 11)

add_executable(bank_system src/main.c
        src/main.c
        include/accounts.h
        src/accounts.c)
