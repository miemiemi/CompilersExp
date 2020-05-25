#include "stdafx.h"
#include <iostream>
#include "TokenScanner.h"
#include "Parser.h"

static string 词法类型[100] = { "ENDFILE", "ERROR" ,
"PROGRAM", "PROCEDURE", "TYPE", "VAR", "IF",
"THEN", "ELSE"," FI", "WHILE", "DO",
"ENDWH", "BEGIN", "END", "READ", "WRITE",
"ARRAY", "OF", "RECORD", "RETURN",
"INTEGER", "CHAR",
/* 多字符单词符号 */
"ID", "INTC","CHARC",
/*特殊符号 */
"ASSIGN", "EQ", "LT", "PLUS", "MINUS",
"TIMES", "OVER"," LPAREN", "RPAREN", "DOT",
"COLON", "SEMI","COMMA"," LMIDPAREN", "RMIDPAREN",
"UNDERANGE"
};


int main()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\miemiemie\\Desktop\\实验报告\\SNL语言例子\\一般例子\\C4.txt", "r")) == NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}

	TokenScanner* TScanner = new TokenScanner();	// 词法分析部分的Scanner
	vector<Token> Tokenlist;						//存储Token序列
	Token* newtoken = NULL;
	while (!feof(fp))
	{
		newtoken = TScanner->Scan(fp);
		Tokenlist.push_back(*newtoken);
		if (TScanner->Error == true) {
			cout << "Error token  " << newtoken->content << endl;
			exit(1);
		}
		newtoken = NULL;
	}
	fclose(fp);
	if (Tokenlist.back().type == DOT) {
		Token* endfileTolen = new Token();
		endfileTolen->line = TScanner->Line;
		endfileTolen->content = "";
		endfileTolen->type = ENDFILE;
		Tokenlist.push_back(*endfileTolen);
	}
	for (Token t : Tokenlist) {
		if (t.type == ID)
			cout << "行数: " << t.line << "    " << t.type << "     " << t.content << endl;
		else
			cout << "行数: " << t.line << "    " << t.type << "     " << 词法类型[t.type] << endl;
	}

	Parser* parser = new Parser();
	parser->Parse(Tokenlist);
	parser->PrintTree(parser->root);
	return 0;
}
