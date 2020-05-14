#include "TokenScanner.h"


Token* TokenScanner::Scan(FILE* f)
{

	char c;
	string str = "";//初始为空串
	Token* tokenptr = NULL;
	tokenptr = new Token();
	tokenptr->content = "";
	StateType state = START;
	while (state != DONE) {
		c = fgetc(f);

		switch (state)
		{
			/* 当前DFA状态state为开始状态START,DFA处于当前单词开始位置 */
		case START:
			str += c;		//增加长度

			if (isdigit(c)) 
				state = INNUM;
			else if (isalpha(c)) 
				state = INID;
			else if (c == ':') 
				state = INASSIGN;
			else if (c == '.') 
				state = INRANGE;
			else if (c == '\'')
			{
				state = INCHAR;
				str = str.substr(0, str.length() - 1);
			}
			else if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r')) {
				str = str.substr(0, str.length() - 1);
				if ((c == '\n') || (c == '\r'))
					Line++;
			}
			else if (c == '{')
			{
				str = str.substr(0, str.length() - 1);
				state = INCOMMENT;
			}
			else
			{
				state = DONE;
				switch (c)
				{
					/* 当前字符c为EOF,字符存储标志save设置为FALSE,无需存储     *
					 * 当前识别单词返回值currentToken设置为文件结束单词ENDFILE */
				case EOF:
					str = str.substr(0, str.length() - 1);
					tokenptr->type = ENDFILE;
					break;

					/* 当前字符c为"=",当前识别单词返回值currentToken设置为等号单词EQ */
				case '=':
					tokenptr->type = EQ;
					break;

					/* 当前字符c为"<",当前识别单词返回值currentToken设置为小于单词LT */
				case '<':
					tokenptr->type = LT;
					break;

					/* 当前字符c为"+",当前识别单词返回值currentToken设置为加号单词PLUS */
				case '+':
					tokenptr->type = PLUS;
					break;

					/* 当前字符c为"-",当前识别单词返回值currentToken设置为减号单词MINUS */
				case '-':
					tokenptr->type = MINUS;
					break;

					/* 当前字符c为"*",当前识别单词返回值currentToken设置为乘号单词TIMES */
				case '*':
					tokenptr->type = TIMES;
					break;

					/* 当前字符c为"/",当前识别单词返回值currentToken设置为除号单词OVER */
				case '/':
					tokenptr->type = OVER;
					break;

					/* 当前字符c为"(",当前识别单词返回值currentToken设置为左括号单词LPAREN */
				case '(':
					tokenptr->type = LPAREN;
					break;

					/* 当前字符c为")",当前识别单词返回值currentToken设置为右括号单词RPAREN */
				case ')':
					tokenptr->type = RPAREN;
					break;

					/* 当前字符c为";",当前识别单词返回值currentToken设置为分号单词SEMI */
				case ';':
					tokenptr->type = SEMI;
					break;
					/* 当前字符c为",",当前识别单词返回值currentToken设置为逗号单词COMMA */
				case ',':
					tokenptr->type = COMMA;
					break;
					/* 当前字符c为"[",当前识别单词返回值currentToken设置为左中括号单词LMIDPAREN */
				case '[':
					tokenptr->type = LMIDPAREN;
					break;

					/* 当前字符c为"]",当前识别单词返回值currentToken设置为右中括号单词RMIDPAREN */
				case ']':
					tokenptr->type = RMIDPAREN;
					break;

					/* 当前字符c为其它字符,当前识别单词返回值currentToken设置为错误单词ERROR */
				default:
					tokenptr->type = ERROR;
					Error = true;
					break;
				}
			}
			break;
		/********** 当前状态为开始状态START的处理结束 **********/
		case INCOMMENT:
			if (c == EOF)
			{
				state = DONE;
				tokenptr->type = ENDFILE;

			}

			/* 当前字符c为"}",注释结束.当前DFA状态state设置为开始状态START */
			else if (c == '}')
				state = START;
			break;
		/********** 当前状态为注释状态INCOMMENT的处理结束 **********/
		case INASSIGN:
			str += c;
			state = DONE;

			/* 当前字符c为"=",当前识别单词返回值currentToken设置为赋值单词ASSIGN */
			if (c == '=')
				tokenptr->type = ASSIGN;

			/* 当前字符c为其它字符,即":"后不是"=",在输入行缓冲区中回退一个字符       *
			 * 字符存储状态save设置为FALSE,当前识别单词返回值currentToken设置为ERROR */
			else
			{
				fseek(f,-1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = ERROR;
				Error = true;
			}
			break;
		/********** 当前状态为赋值状态INASSIGN的处理结束 **********/
		case INRANGE:
			str += c;
			state = DONE;

			/* 当前字符c为".",当前识别单词返回值currentToken设置为下标界UNDERANGE */
			if (c == '.')
				tokenptr->type = UNDERANGE;

			/* 当前字符c为其它字符,即"."后不是".",在输入行缓冲区中回退一个字符       *
			 * 字符存储状态save设置为FALSE,当前识别单词返回值currentToken设置为ERROR */

			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = DOT;
			}
			break;
		case INNUM:

			/* 当前字符c不是数字,则在输入行缓冲区源中回退一个字符					*
			 * 字符存储标志设置为FALSE,当前DFA状态state设置为DONE,数字单词识别完成 *
			 * 当前识别单词返回值currentToken设置为数字单词NUM                     */
			str += c;
			if (!isdigit(c))
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = INTC;
			}
			break;

		case INCHAR:
			str += c;
			if (isalnum(c))
			{
				char c1 = fgetc(f);
				if (c1 == '\'')
				{
					state = DONE;
					tokenptr->type = CHARC;
				}
				else
				{
					fseek(f, -1, SEEK_CUR);
				}
			}
			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = ERROR;
				Error = true;
			}
			break;

		case INID:
			str += c;
			/* 当前字符c不是字母,则在输入行缓冲区源中回退一个字符		 			  *
			 * 字符存储标志设置为FALSE,当前DFA状态state设置为DONE,标识符单词识别完成 *
			 * 当前识别单词返回值currentToken设置为标识符单词ID                      */
			if (!isalnum(c))
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = ID;
			}
			break;
		case DONE:	
			break;
		default:
			//fprintf(listing, "Scanner Bug: state= %d\n", state);
			Error = true;
			state = DONE;
			tokenptr->type = ERROR;
			break;
		}
	}
	if (state == DONE)
	{

		/* 当前单词currentToken为标识符单词类型,查看其是否为保留字单词 */
		if (tokenptr->type == ID)
		{
			tokenptr->type = ReservedLookup(str);
			if (tokenptr->type == ID)
				tokenptr->content = str;
				//strcpy(tokenString, tokenString);
		}
		tokenptr->line = Line;
	}
	return tokenptr;
}

LexType TokenScanner::ReservedLookup(string str)
{
	for(int i = 0; i < 21; i++)
		if(str == reservedWords[i].str)
			return reservedWords[i].tok;
	return ID;
}
