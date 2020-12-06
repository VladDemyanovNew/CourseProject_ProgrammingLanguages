#pragma once
#define LEXEMA_FIXSIZE				1				// ���� ������ �������
#define LT_MAXSIZE					4096			// ���� ���-�� ����� � ������� ������
#define LT_TI_NULLIDX				0xffffffff		// ��� �������� ������� ���������������

#define LEX_MAIN					'g'				// go
#define LEX_FUNCTION				'f'				// func
#define LEX_RETURN					'r'				// ret
#define LEX_PRINT					'p'				// puts
#define LEX_IF						'q'				// if
#define LEX_UNTIL					'u'				// until
#define LEX_LOOP					'l'				// loop
#define LEX_ELSE					'e'				// else
#define LEX_END						'd'				// end

#define LEX_TYPE					't'				// ���
#define LEX_ID						'i'				// �������������
#define LEX_SYMBOL_LITERAL			'c'				// symbol
#define LEX_STRING_LITERAL			's'				// ��������� �������
#define LEX_NUMERICAL_LITERAL		'n'				// �������� �������

#define LEX_DECLARE					'$'				// $
#define LEX_SEMICOLON				';'				// ;
#define LEX_COMMA					','				// ,
#define LEX_LEFTBRACE				'{'				// {
#define LEX_BRACELET				'}'				// }
#define LEX_LEFTHESIS				'('				// (
#define LEX_RIGHTHESIS				')'				// )
#define LEX_PLUS					'v'				// +
#define LEX_MINUS					'v'				// -
#define LEX_STAR					'v'				// *
#define LEX_DIRSLASH				'v'				// /
#define LEX_EQUAL					'='				// =
#define LEX_MORE					'v'				// >
#define LEX_LESS					'v'				// <
#define LEX_COMPARE_EQUAL			'v'				// ==
#define LEX_COMPARE_LESS			'v'				// <=
#define LEX_COMPARE_MORE			'v'				// >=

namespace LT									// ������� ������
{
	struct Entry								// ������ ������� ������
	{
		char lexema;							// �������
		int lineSource;							// ����� ������ � �������� ����
		int indexIdTable;						// ������ � ������� ��������������� ��� LT_TI_NULLIDX
		const char* sign;
		Entry();
		Entry(char l, int n);
		Entry(char l, int ls, int i, const char* s);
	};

	struct LexTable								// ��������� ������� ������
	{
		int maxsize;							// ������� ������� ������ < LT_MAXSIZE
		int size;								// ������� ������ ������� ������ < maxsize
		Entry* table;							// ������ ����� ������� ������
	};

	LexTable Create(int size);					// ������� ������� ������, ������� ������� ������ < LT_MAXSIZE
	void Add(LexTable& lextable, Entry entry);	// �������� ������ � ������� ������ 
	Entry GetEntry(LexTable& lextable, int n);	// �������� ������ ������� ������, n - ����� ���������� ������
	void Delete(LexTable& lextable);			// ������� ������� ������ (���������� ������)
	
}