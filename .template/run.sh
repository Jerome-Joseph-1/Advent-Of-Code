#!/bin/bash

GREEN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
YELLOW="\033[1;33m"
CYAN="\033[1;36m"
RESET="\033[0m"

BOLD="\033[1m"
UNDERLINE="\033[4m"


echo -e "${CYAN}${BOLD}Compiling your code...${RESET}"
g++ -o main main.cpp

if [ -f main ]; then
    echo -e "${GREEN}${BOLD}Compilation successful!${RESET}"
    
    START_TIME=$(date +%s%6N) 
    echo -e "${YELLOW}${BOLD}Running the program...${RESET}"
    echo -e "${BLUE}----------------------------${RESET}"
    ./main < input
    echo -e "${BLUE}----------------------------${RESET}"
    END_TIME=$(date +%s%6N) 

    EXECUTION_TIME=$((END_TIME - START_TIME)) 
    EXECUTION_TIME_MS=$(echo "scale=3; $EXECUTION_TIME / 1000" | bc) 

    echo -e "${GREEN}${BOLD}Execution Time: ${RESET}${CYAN}${EXECUTION_TIME_MS} milliseconds${RESET} ${GREEN}${RESET}"
    
    
    echo -e "${RED}${BOLD}Cleaning up...${RESET}"
    rm main
    echo -e "${GREEN}${BOLD}Done!${RESET}"
else
    echo -e "${RED}${BOLD}Compilation failed!${RESET} ❌"
fi
