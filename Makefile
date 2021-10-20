##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile for day 12
##


NAME = graphical

SRC = *.c

FLAGS = -lcsfml-graphics -lcsfml-window

INCLUDES = include/

all:
	gcc -o ${NAME} ${SRC} ${FLAGS} -I ${INCLUDES}