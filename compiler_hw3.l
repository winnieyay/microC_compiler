/* Definition section */
%{
#include "define.h" 
#include "y.tab.h"	/* header file generated by bison */
#include "string.h"
#define BUF_SIZE 256


extern char err_msg[BUF_SIZE];
extern YYSTYPE yylval; //YYSTYPE
extern bool dump_flag;
extern bool display_flag;
extern void dump_symbol();
extern void yyerror(char *s);
extern void error_hadle(char *err);
int flag_se=0;
int flag_sy=0;
char buf[BUF_SIZE];
char buf_s[BUF_SIZE];

/* This macro is used to record code line */
#define CONCAT { strncat(buf, yytext, BUF_SIZE - strlen(buf) - 1); }
%}

/* Define regular expression label */
newline		[\n]
digit		[0-9]
letter		[a-zA-Z]
integer     {digit}+
float      {digit}+"."{digit}+
id			{letter}+({letter}|{digit})*

%option yylineno

%x COMMENT STRING_STATE

/* Rules section */
%%

 /* Arithmetic */
"+"     { CONCAT return(ADD); }
"-" 	{ CONCAT return(SUB); }
"*" 	{ CONCAT return(MUL); }
"/" 	{ CONCAT return(DIV); }
"%"     { CONCAT return(MOD); }
"++"    { CONCAT return(INC); }
"--"    { CONCAT return(DEC); }

 /* Relational */
">"		{ CONCAT return(MT); }
"<"		{ CONCAT return(LT); }
">="	{ CONCAT return(MTE); }
"<="	{ CONCAT return(LTE); }
"=="	{ CONCAT return(EQ); }
"!="	{ CONCAT return(NE); }

 /* Assignment */
"="		{ CONCAT return(ASGN); }
"+="	{ CONCAT return(ADDASGN); }
"-="	{ CONCAT return(SUBASGN); }
"*="	{ CONCAT return(MULASGN); }
"/="	{ CONCAT return(DIVASGN); }
"%="	{ CONCAT return(MODASGN); }

 /* Logical */
"&&"	{ CONCAT return(AND); }
"||"	{ CONCAT return(OR); }
"!"		{ CONCAT return(NOT); }

 /* Delimiters */
"("		{ CONCAT return(LB); }
")"		{ CONCAT return(RB); }
"{"		{ CONCAT return(LCB); }
"}"		{ CONCAT return(RCB); }
"["		{ CONCAT return(LSB); }
"]"		{ CONCAT return(RSB); }
","		{ CONCAT return(COMMA); }

 /* Print Keywords */	
"print"		{ CONCAT return(PRINT); }

 /* Condition and Loop Keywords */
"if"		{ CONCAT return(IF); }
"else"		{ CONCAT return(ELSE); }
"for"		{ CONCAT return(FOR); }
"while"		{ CONCAT return(WHILE); }

 /* Declaration Keywords */
"void"		{ CONCAT return(VOID); }
"int"		{ CONCAT return(INT); }
"float"  	{ CONCAT return(FLOAT); }
"string"  	{ CONCAT return(STRING); }
"bool"  	{ CONCAT return(BOOL); }

 /* boolean Keywords */
"true"      { CONCAT yylval.i_val = 1; return(TRUE); }
"false"     { CONCAT yylval.i_val = 0; return(FALSE); }

"return"    { CONCAT return(RET); }

 /* String Constant */
\"				        { CONCAT BEGIN STRING_STATE; 
                          memset(buf_s, 0, BUF_SIZE);
                        }
<STRING_STATE>\"		{ CONCAT 
                          BEGIN INITIAL;
                          yylval.lex = strdup(buf_s);
                          return(STRING_CONST); }
<STRING_STATE>[^"]*		{ CONCAT 
                          strncat(buf_s, yytext, BUF_SIZE - strlen(buf_s) - 1);
                        }

 /* Number Constant */
{integer}	{ 
                CONCAT
                yylval.i_val = atoi(yytext);
                return(I_CONST);
 }
{float}	    { 
                CONCAT
                yylval.f_val = atof(yytext);
                return(F_CONST);
 }

 /* C type Comment */
"/*"				{ BEGIN COMMENT; CONCAT }
<COMMENT>[^*\n]+	{ CONCAT }
<COMMENT>\n			{ printf("%d: %s\n", yylineno, buf); memset(buf, 0, BUF_SIZE); }
<COMMENT>"*"		{ CONCAT }
<COMMENT>"*/"		{  BEGIN INITIAL; CONCAT}

 /* C++ type Comment */
\/\/.*	{ CONCAT }

 /* Variable ID */
 {id}       { 
                CONCAT
                yylval.lex = strdup(yytext);
                return(ID);
  }

 /* others */

[;]         { CONCAT return(SEMICOLON); }
[\n]        { 
              if(buf[0] == '\0'){
                  printf("%d:\n", yylineno);
              }
              else{
                  printf("%d: %s\n",yylineno, buf);
              }

              if(dump_flag){
                dump_symbol();
              }

              if(flag_se == 1) {
                  yyerror(err_msg);
                  flag_se = 0;
                  memset(err_msg, '\0', BUF_SIZE);
              }

              if(flag_sy == 1){
                  yyerror(err_msg);
                  flag_sy = 0;
                  memset(err_msg, '\0', BUF_SIZE);
                  exit(1);
              }

              memset(buf, '\0', BUF_SIZE);
            }
[ \t]		{ CONCAT }
[^ \t\n] 	{ CONCAT } /* Other charactor sets */


%%
int yywrap()
{
    return 1;
}