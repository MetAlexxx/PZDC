#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <map>

using namespace std;

extern int PK;


enum Operations {
	NL,
	PLS, MNS, MUL, DIV,
	LSS, GTR, EQU, NEQ,
	AND, OR,
	GOTO, ASG, DEL,
	WHILE_B, WHILE_E,
	IF_B, ELSE, IF_E,
	BOOL_B, BOOL_E,
	COMP_B, COMP_E,
	B_EXP_B, B_EXP_E,
	EDGE_B, EDGE_E, EDGE_PLS,
	PNT_B, PNT_E,
	WRITE, READ,
	BL_B, BL_E,
	GET_PID, GET_EP, GET_ED, GET_EW,
	CNCT, ANY_STR,
	SET_PID, SET_EP, SET_ED, SET_EW
};

struct StackEl {
	Operations op;
	wstring val;
};

extern map <wstring, int> labels;
extern map <wstring, wstring> variabels;
extern vector <StackEl> stackOp;

void Go();

int Operator();
int If_b();
int While_b();
int Asg();
int Goto();
int Del();
int Read();
int Write();
int Bool();

#endif