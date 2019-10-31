/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    SEMICOLON = 259,
    IF = 260,
    ELSE = 261,
    FOR = 262,
    WHILE = 263,
    ADD = 264,
    SUB = 265,
    MUL = 266,
    DIV = 267,
    MOD = 268,
    INC = 269,
    DEC = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    ASGN = 274,
    ADDASGN = 275,
    SUBASGN = 276,
    MULASGN = 277,
    DIVASGN = 278,
    MODASGN = 279,
    MT = 280,
    LT = 281,
    MTE = 282,
    LTE = 283,
    EQ = 284,
    NE = 285,
    LB = 286,
    RB = 287,
    LCB = 288,
    RCB = 289,
    LSB = 290,
    RSB = 291,
    COMMA = 292,
    TRUE = 293,
    FALSE = 294,
    RET = 295,
    I_CONST = 296,
    F_CONST = 297,
    STRING_CONST = 298,
    VOID = 299,
    INT = 300,
    FLOAT = 301,
    BOOL = 302,
    STRING = 303,
    ID = 304
  };
#endif
/* Tokens.  */
#define PRINT 258
#define SEMICOLON 259
#define IF 260
#define ELSE 261
#define FOR 262
#define WHILE 263
#define ADD 264
#define SUB 265
#define MUL 266
#define DIV 267
#define MOD 268
#define INC 269
#define DEC 270
#define AND 271
#define OR 272
#define NOT 273
#define ASGN 274
#define ADDASGN 275
#define SUBASGN 276
#define MULASGN 277
#define DIVASGN 278
#define MODASGN 279
#define MT 280
#define LT 281
#define MTE 282
#define LTE 283
#define EQ 284
#define NE 285
#define LB 286
#define RB 287
#define LCB 288
#define RCB 289
#define LSB 290
#define RSB 291
#define COMMA 292
#define TRUE 293
#define FALSE 294
#define RET 295
#define I_CONST 296
#define F_CONST 297
#define STRING_CONST 298
#define VOID 299
#define INT 300
#define FLOAT 301
#define BOOL 302
#define STRING 303
#define ID 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "compiler_hw3.y" /* yacc.c:1909  */

	TYPE type;
	OPERATOR op;
	bool b_val;
    int i_val;
	float f_val;
	char* lex;	

#line 161 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
