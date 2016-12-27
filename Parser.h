

#if !defined(COCO_PARSER_H__)
#define COCO_PARSER_H__

#include "Global.h"



#include "Scanner.h"



class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(int line, int col, int n);
	void Error(int line, int col, const wchar_t *s);
	void Warning(int line, int col, const wchar_t *s);
	void Warning(const wchar_t *s);
	void Exception(const wchar_t *s);

}; // Errors

class Parser {
private:
	enum {
		_EOF=0,
		_Ident=1,
		_Number=2,
		_string=3
	};
	int maxT;

	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token



	Parser(Scanner *scanner);
	~Parser();
	void SemErr(const wchar_t* msg);

	void GRAPHPZDC();
	void StatL();
	void Op(Operations &op);
	void RelOp(Operations &op);
	void LogicOp(Operations &op);
	void Operator();
	void D_var(wchar_t* &name);
	void S_var(wchar_t* &name);
	void P_var(wchar_t* &name);
	void E_var(wchar_t* &name);
	void P_varId(bool set);
	void E_varP(bool set);
	void E_varW(bool set);
	void E_varD(bool set);
	void Point();
	void Any_Num();
	void Edge();
	void Boolean();
	void Any_Var();
	void Any_String();
	void Assign();
	void Compare();
	void Boolean_expression();
	void Delete();
	void Goto();
	void While();
	void If();
	void Bl_Operator();
	void Writeln();
	void Readln();

	void Parse();

}; // end Parser



#endif

