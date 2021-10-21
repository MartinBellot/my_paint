##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for day 12
##

NAME = mpaint

SRC = *.c

FLAGS = -lcsfml-graphics -lcsfml-window -lm

INCLUDES = include/

all:
	gcc -o ${NAME} ${SRC} ${FLAGS} -I ${INCLUDES}

build: all