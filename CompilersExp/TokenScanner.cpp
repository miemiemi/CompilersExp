#include "TokenScanner.h"


Token* TokenScanner::Scan(FILE* f)
{

	char c;
	string str = "";//��ʼΪ�մ�
	Token* tokenptr = NULL;
	tokenptr = new Token();
	tokenptr->content = "";
	StateType state = START;
	while (state != DONE) {
		c = fgetc(f);

		switch (state)
		{
			/* ��ǰDFA״̬stateΪ��ʼ״̬START,DFA���ڵ�ǰ���ʿ�ʼλ�� */
		case START:
			str += c;		//���ӳ���

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
					/* ��ǰ�ַ�cΪEOF,�ַ��洢��־save����ΪFALSE,����洢     *
					 * ��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�ļ���������ENDFILE */
				case EOF:
					str = str.substr(0, str.length() - 1);
					tokenptr->type = ENDFILE;
					break;

					/* ��ǰ�ַ�cΪ"=",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�Ⱥŵ���EQ */
				case '=':
					tokenptr->type = EQ;
					break;

					/* ��ǰ�ַ�cΪ"<",��ǰʶ�𵥴ʷ���ֵcurrentToken����ΪС�ڵ���LT */
				case '<':
					tokenptr->type = LT;
					break;

					/* ��ǰ�ַ�cΪ"+",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�Ӻŵ���PLUS */
				case '+':
					tokenptr->type = PLUS;
					break;

					/* ��ǰ�ַ�cΪ"-",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ���ŵ���MINUS */
				case '-':
					tokenptr->type = MINUS;
					break;

					/* ��ǰ�ַ�cΪ"*",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�˺ŵ���TIMES */
				case '*':
					tokenptr->type = TIMES;
					break;

					/* ��ǰ�ַ�cΪ"/",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ���ŵ���OVER */
				case '/':
					tokenptr->type = OVER;
					break;

					/* ��ǰ�ַ�cΪ"(",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�����ŵ���LPAREN */
				case '(':
					tokenptr->type = LPAREN;
					break;

					/* ��ǰ�ַ�cΪ")",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�����ŵ���RPAREN */
				case ')':
					tokenptr->type = RPAREN;
					break;

					/* ��ǰ�ַ�cΪ";",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�ֺŵ���SEMI */
				case ';':
					tokenptr->type = SEMI;
					break;
					/* ��ǰ�ַ�cΪ",",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ���ŵ���COMMA */
				case ',':
					tokenptr->type = COMMA;
					break;
					/* ��ǰ�ַ�cΪ"[",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�������ŵ���LMIDPAREN */
				case '[':
					tokenptr->type = LMIDPAREN;
					break;

					/* ��ǰ�ַ�cΪ"]",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�������ŵ���RMIDPAREN */
				case ']':
					tokenptr->type = RMIDPAREN;
					break;

					/* ��ǰ�ַ�cΪ�����ַ�,��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ���󵥴�ERROR */
				default:
					tokenptr->type = ERROR;
					Error = true;
					break;
				}
			}
			break;
		/********** ��ǰ״̬Ϊ��ʼ״̬START�Ĵ������ **********/
		case INCOMMENT:
			if (c == EOF)
			{
				state = DONE;
				tokenptr->type = ENDFILE;

			}

			/* ��ǰ�ַ�cΪ"}",ע�ͽ���.��ǰDFA״̬state����Ϊ��ʼ״̬START */
			else if (c == '}')
				state = START;
			break;
		/********** ��ǰ״̬Ϊע��״̬INCOMMENT�Ĵ������ **********/
		case INASSIGN:
			str += c;
			state = DONE;

			/* ��ǰ�ַ�cΪ"=",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ��ֵ����ASSIGN */
			if (c == '=')
				tokenptr->type = ASSIGN;

			/* ��ǰ�ַ�cΪ�����ַ�,��":"����"=",�������л������л���һ���ַ�       *
			 * �ַ��洢״̬save����ΪFALSE,��ǰʶ�𵥴ʷ���ֵcurrentToken����ΪERROR */
			else
			{
				fseek(f,-1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = ERROR;
				Error = true;
			}
			break;
		/********** ��ǰ״̬Ϊ��ֵ״̬INASSIGN�Ĵ������ **********/
		case INRANGE:
			str += c;
			state = DONE;

			/* ��ǰ�ַ�cΪ".",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�±��UNDERANGE */
			if (c == '.')
				tokenptr->type = UNDERANGE;

			/* ��ǰ�ַ�cΪ�����ַ�,��"."����".",�������л������л���һ���ַ�       *
			 * �ַ��洢״̬save����ΪFALSE,��ǰʶ�𵥴ʷ���ֵcurrentToken����ΪERROR */

			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = DOT;
			}
			break;
		case INNUM:

			/* ��ǰ�ַ�c��������,���������л�����Դ�л���һ���ַ�					*
			 * �ַ��洢��־����ΪFALSE,��ǰDFA״̬state����ΪDONE,���ֵ���ʶ����� *
			 * ��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ���ֵ���NUM                     */
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
			/* ��ǰ�ַ�c������ĸ,���������л�����Դ�л���һ���ַ�		 			  *
			 * �ַ��洢��־����ΪFALSE,��ǰDFA״̬state����ΪDONE,��ʶ������ʶ����� *
			 * ��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ��ʶ������ID                      */
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

		/* ��ǰ����currentTokenΪ��ʶ����������,�鿴���Ƿ�Ϊ�����ֵ��� */
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
