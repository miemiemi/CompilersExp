#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Global.h"
using namespace std;

class Token
{
public:
	Token();
	~Token() {};
	int line;
	LexType type;
	string content;
};