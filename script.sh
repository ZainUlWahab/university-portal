#!/bin/bash
g++ -c person.cpp
g++ -c teacher.cpp
g++ -c student.cpp
g++ -c truefalse.cpp
g++ -c mcqs.cpp
g++ -c quiz.cpp
g++ -c subjective.cpp
g++ -c date.cpp
g++ person.o teacher.o student.o truefalse.o mcqs.o subjective.o quiz.o date.o main.cpp
./a.out
