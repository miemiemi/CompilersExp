#pragma once
#include "Scanner.h"
#include "token.h"

static struct
{
	string str;
	LexType tok;
} reservedWords[21]
= { {"program",PROGRAM},{"type",TYPE},{"var",VAR},{"procedure",PROCEDURE}
   ,{"begin",BEGIN},{"end",END},{"array",ARRAY},{"of",OF},{"record",RECORD}
   ,{"if",IF},{"then",THEN},{"else",ELSE},{"fi",FI},{"while",WHILE}
   ,{"do",DO},{"endwh",ENDWH},{"read",READ},{"write",WRITE},{"return",RETURN}
   ,{"integer",INTEGER},{"char",CHAR} };


typedef enum
{
	START, INASSIGN, INRANGE, INCOMMENT, INNUM, INID, INCHAR, DONE
}
StateType;


class TokenScanner :
	public Scanner
{
public:
	Token* Scan(FILE* f);
	LexType ReservedLookup(string str);			//判断是是否为保留字
	//void AddIdentifier(string str);//查表，若没有将该标识符加入表中
	//void AddConstant(string str);
	//bool Isother(char a);//判断是否为字母和数字以外其他的
	//bool Isletter(char a);
	//bool Isnumber(char a);

	int Line = 1;
	//标识符表和常量表，用于保存一个程序的所有标识符和常量
	vector<string> identifier;
	vector<string> constant;
	bool Error = false;
};

