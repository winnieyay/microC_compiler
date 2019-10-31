/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include <string.h>
#define BUF_SIZE 256
#define NIL (void*)-1
extern char buf[BUF_SIZE]; 
extern int yylineno;
extern int yylex();
extern char *yytext; 
//FIX///////////////////////////////////
extern int flag_se;
extern int flag_sy;
/////////////////////////////////////////////////////////
char err_msg[BUF_SIZE];
char code_buf[BUF_SIZE];
int label_count=0;

// To generate .j file for Jasmin
FILE *file; 

void yyerror(char *s);
void error_hadle(char *err);
char* function_return_check = "V";

Table* HEAD = NIL;
Table* DUMP = NIL;
Table* Current = NIL;


int var_count = 0;
int scope_count = 0;

bool err_flag = false;
bool dump_flag = false;
bool display_flag = false;

void set_sy_flag();
Table create_symbol();
int lookup_symbol(char* name, int flag);
void dump_symbol();
void insert_symbol(int check_scope, const char* name, TYPE data_type, TYPE entry_type, int check_def);
Entry* getEntry(char* name, int check);


void gen_print(TYPE type);
void codeGen(char const *s);
void gen_store_load(Entry* node, int action);

F_list * attr_tmp = NIL;
T_list * tmp_t_list = NIL;

int check_assert(F_list * M, F_list* N);

//FIX///////////////////////////////////////////////////////

void invoke_test(Entry* node);
void AssignOP(Entry* node,OPERATOR op, TYPE right);
void global_declaration(TYPE type, char* name, int value_flag);
void compare_func(TYPE first,OPERATOR op,TYPE second);
int check_zero_error = 0;
void new_attr();


#line 132 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 68 "compiler_hw3.y" /* yacc.c:355  */

	TYPE type;
	OPERATOR op;
	bool b_val;
    int i_val;
	float f_val;
	char* lex;	

#line 279 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   106,   107,   108,   112,   113,   114,   118,
     119,   120,   121,   124,   125,   128,   129,   132,   133,   134,
     135,   136,   140,   142,   147,   176,   198,   224,   224,   331,
     340,   340,   349,   353,   354,   355,   359,   381,   384,   385,
     388,   389,   391,   392,   393,   394,   395,   396,   397,   400,
     401,   405,   447,   448,   452,   462,   463,   464,   465,   466,
     467,   471,   474,   475,   486,   487,   499,   500,   507,   508,
     509,   510,   511,   512,   515,   523,   543,   544,   594,   595,
     598,   599,   665,   666,   667,   670,   671,   681,   682,   686,
     697,   709,   714,   719,   724,   729,   738,   743,   738,   759,
     771,   777,   782,   777,   800,   800,   814,   818,   819,   824,
     824,   842,   843,   851,   865
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "SEMICOLON", "IF", "ELSE",
  "FOR", "WHILE", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC", "AND",
  "OR", "NOT", "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN",
  "MODASGN", "MT", "LT", "MTE", "LTE", "EQ", "NE", "LB", "RB", "LCB",
  "RCB", "LSB", "RSB", "COMMA", "TRUE", "FALSE", "RET", "I_CONST",
  "F_CONST", "STRING_CONST", "VOID", "INT", "FLOAT", "BOOL", "STRING",
  "ID", "$accept", "program", "declare_list", "declare", "global_constant",
  "ans", "sub_const", "type_term", "global_variable_declaration",
  "var_declare", "func_declaration", "func_definition", "$@1",
  "function_compound_stat", "compound_stat", "$@2", "parameters",
  "par_list", "par", "content_list", "content", "stat", "expression_stat",
  "postfix_expr", "post_op", "assign_stat", "assign_op", "expression",
  "or_expr", "and_expr", "comparison_expr", "cmp_op", "return_stat",
  "addition_expr", "add_op", "multiplication_expr", "mul_op",
  "parenthesis_clause", "constant", "while_stat", "$@3", "$@4",
  "print_stat", "if_stat", "$@5", "$@6", "else_if_stat", "$@7",
  "else_stat", "func_invoke", "$@8", "arg", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -138

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define YYTABLE_NINF -110

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,  -138,  -138,  -138,  -138,  -138,  -138,     7,   102,  -138,
     -37,  -138,  -138,  -138,  -138,  -138,     2,  -138,    85,   107,
     -32,  -138,  -138,  -138,  -138,    12,  -138,  -138,   -35,   -30,
       9,    -6,  -138,  -138,  -138,  -138,  -138,    30,   102,  -138,
       3,  -138,  -138,  -138,    10,     8,    11,  -138,  -138,  -138,
      63,   114,    13,  -138,  -138,  -138,  -138,  -138,    64,  -138,
    -138,  -138,  -138,  -138,    65,    50,    72,    39,  -138,  -138,
     -17,    72,  -138,  -138,  -138,  -138,  -138,    43,    67,    58,
      68,   115,    18,    40,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,    72,    52,     4,  -138,
    -138,    54,    66,    75,    72,    32,  -138,  -138,    76,  -138,
      72,    72,  -138,  -138,  -138,  -138,  -138,  -138,    72,  -138,
    -138,    72,  -138,  -138,  -138,    72,    86,    72,  -138,    72,
      92,    96,  -138,    77,  -138,  -138,    68,   115,    18,    40,
    -138,  -138,  -138,    84,    80,   116,  -138,  -138,    89,  -138,
    -138,    72,  -138,  -138,    89,  -138,  -138,  -138,   112,    -1,
    -138,    88,  -138,    72,    93,  -138,    89,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,    17,    19,    20,    18,    21,     0,     2,     4,
       0,     7,     6,     8,     1,     3,     0,    22,     0,    37,
       0,    13,    14,     9,    10,     0,    12,    11,    35,     0,
       0,    32,    34,    15,    16,    23,    36,    27,    37,    26,
       0,    33,    39,    28,     0,     0,     0,    96,    30,    29,
       0,   109,     0,    40,    47,    38,    41,    46,     0,    42,
      45,    44,    48,    43,     0,     0,     0,     0,    39,    74,
       0,     0,    91,    92,    89,    90,    93,    86,     0,    61,
      62,    64,    66,    76,    80,    85,    87,    52,    53,    55,
      56,    57,    58,    59,    60,    51,     0,     0,     0,    50,
      49,     0,     0,     0,     0,     0,    94,    95,     0,    75,
       0,     0,    69,    68,    71,    70,    72,    73,     0,    78,
      79,     0,    82,    84,    83,     0,     0,   112,    24,     0,
       0,     0,   101,     0,    31,    88,    63,    65,    67,    77,
      81,    54,   114,     0,   111,     0,    99,   100,     0,    97,
     110,     0,    25,   102,     0,   113,   106,    98,   108,     0,
     103,     0,   107,     0,     0,   104,     0,   105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,   122,  -138,  -138,  -138,   -18,  -138,  -138,
    -138,  -138,  -138,  -138,  -137,  -138,  -138,  -138,    94,    71,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   -66,  -138,    21,
      45,  -138,  -138,    41,  -138,    36,  -138,    33,    95,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   -41,
    -138,  -138,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    25,    26,    27,    10,    11,    53,
      12,    13,    40,    43,    54,    68,    30,    31,    32,    44,
      55,    56,    57,    58,    95,    59,    96,    78,    79,    80,
      81,   118,    60,    82,   121,    83,   125,    84,    85,    61,
      67,   154,    62,    63,   148,   156,   158,   166,   160,    86,
      97,   143,   144
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,    29,     1,    64,   161,   108,    17,    14,   128,    33,
      34,   153,    16,    45,   -17,    46,    35,   157,    47,    36,
      29,    18,   162,   129,   106,   107,    52,   119,   120,   167,
     126,    38,    48,    19,    39,    45,    42,    46,   133,    65,
      47,    37,    66,    48,    49,     2,     3,     4,     5,     6,
      50,   122,   123,   124,     2,     3,     4,     5,     6,    51,
      70,   142,    98,   145,    64,    48,   134,    69,    99,   100,
     104,   109,    50,    70,  -109,   110,     2,     3,     4,     5,
       6,    51,    70,   127,   111,   155,   130,    52,    72,    73,
     141,    74,    75,    76,    71,    20,   146,   164,   131,   101,
     147,    72,    73,    71,    74,    75,    76,   132,   135,   149,
      72,    73,    77,    74,    75,    76,   150,   151,   159,   163,
     152,    77,    48,    21,    22,   165,    23,    24,    87,    88,
      15,   136,    41,    89,    90,    91,    92,    93,    94,   105,
     112,   113,   114,   115,   116,   117,     2,     3,     4,     5,
       6,    28,     3,     4,     5,     6,   137,   139,   140,   138,
     102
};

static const yytype_uint8 yycheck[] =
{
      66,    19,     1,    44,     5,    71,     4,     0,     4,    41,
      42,   148,    49,     3,    49,     5,     4,   154,     8,    49,
      38,    19,   159,    19,    41,    42,    44,     9,    10,   166,
      96,    37,    33,    31,     4,     3,    33,     5,   104,    31,
       8,    32,    31,    33,    34,    44,    45,    46,    47,    48,
      40,    11,    12,    13,    44,    45,    46,    47,    48,    49,
      10,   127,    49,   129,   105,    33,    34,     4,     4,     4,
      31,     4,    40,    10,    31,    17,    44,    45,    46,    47,
      48,    49,    10,    31,    16,   151,    32,   105,    38,    39,
       4,    41,    42,    43,    31,    10,     4,   163,    32,    49,
       4,    38,    39,    31,    41,    42,    43,    32,    32,    32,
      38,    39,    49,    41,    42,    43,    32,    37,     6,    31,
       4,    49,    33,    38,    39,    32,    41,    42,    14,    15,
       8,   110,    38,    19,    20,    21,    22,    23,    24,    68,
      25,    26,    27,    28,    29,    30,    44,    45,    46,    47,
      48,    44,    45,    46,    47,    48,   111,   121,   125,   118,
      65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    44,    45,    46,    47,    48,    51,    52,    53,
      57,    58,    60,    61,     0,    53,    49,     4,    19,    31,
      10,    38,    39,    41,    42,    54,    55,    56,    44,    57,
      66,    67,    68,    41,    42,     4,    49,    32,    37,     4,
      62,    68,    33,    63,    69,     3,     5,     8,    33,    34,
      40,    49,    57,    59,    64,    70,    71,    72,    73,    75,
      82,    89,    92,    93,    99,    31,    31,    90,    65,     4,
      10,    31,    38,    39,    41,    42,    43,    49,    77,    78,
      79,    80,    83,    85,    87,    88,    99,    14,    15,    19,
      20,    21,    22,    23,    24,    74,    76,   100,    49,     4,
       4,    49,    88,    77,    31,    69,    41,    42,    77,     4,
      17,    16,    25,    26,    27,    28,    29,    30,    81,     9,
      10,    84,    11,    12,    13,    86,    77,    31,     4,    19,
      32,    32,    32,    77,    34,    32,    79,    80,    83,    85,
      87,     4,    77,   101,   102,    77,     4,     4,    94,    32,
      32,    37,     4,    64,    91,    77,    95,    64,    96,     6,
      98,     5,    64,    31,    77,    32,    97,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    59,    59,    60,    62,    61,    63,
      65,    64,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    76,    76,    76,    76,
      76,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      81,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    88,    90,    91,    89,    92,
      92,    94,    95,    93,    97,    96,    96,    98,    98,   100,
      99,   101,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     3,     5,     3,     5,     6,     0,     7,     3,
       0,     4,     1,     3,     1,     1,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     0,     0,     7,     5,
       5,     0,     0,     9,     0,     8,     0,     2,     0,     0,
       5,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 108 "compiler_hw3.y" /* yacc.c:1646  */
    { set_sy_flag(); }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "compiler_hw3.y" /* yacc.c:1646  */
    { yylval.i_val *= -1; }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "compiler_hw3.y" /* yacc.c:1646  */
    { yylval.f_val *= -1; }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=VOID_TYPE; }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=BOOLEAN_TYPE; }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=INTEGER_TYPE; }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=FLOAT_TYPE; }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=STRING_TYPE; }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 141 "compiler_hw3.y" /* yacc.c:1646  */
    { global_declaration((yyvsp[-2].type), (yyvsp[-1].lex), 0);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    { global_declaration((yyvsp[-4].type), (yyvsp[-3].lex), 1);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "compiler_hw3.y" /* yacc.c:1646  */
    { 	
		int t = lookup_symbol((yyvsp[-1].lex), 0);
		if(t == 0){
			insert_symbol(0, (yyvsp[-1].lex), (yyvsp[-2].type), VARIABLE_TYPE, 0 );
			Entry* node = getEntry((yyvsp[-1].lex), 1);
			if((yyvsp[-2].type) == INTEGER_TYPE){
				codeGen("\tldc 0\n");
				gen_store_load(node, 0);
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE){
				codeGen("\tldc 0.0\n");
				gen_store_load(node, 0);
			}
			else if((yyvsp[-2].type) == BOOLEAN_TYPE){
				codeGen("\tldc 0\n");
				gen_store_load(node, 0);
			}
			else if((yyvsp[-2].type) == STRING_TYPE){
				codeGen("\tldc \"\"\n");
				gen_store_load(node, 0);
			}
			else{
				error_hadle("variable declaration error\n");
			}
		}
		else{
			error_hadle("ERROR : redeclared variable\n");
		}
	}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 176 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int tmp = lookup_symbol((yyvsp[-3].lex), 0);
		if(tmp == 0){
			insert_symbol(0, (yyvsp[-3].lex), (yyvsp[-4].type), VARIABLE_TYPE, 0);
			Entry* ent = getEntry((yyvsp[-3].lex), 1);
			if((yyvsp[-4].type) == INTEGER_TYPE && (yyvsp[-1].type) == FLOAT_TYPE){
				codeGen("\tf2i\n");
			}
			else if((yyvsp[-4].type) == FLOAT_TYPE && (yyvsp[-1].type) == INTEGER_TYPE){
				codeGen("\ti2f\n");
			}
			gen_store_load(ent, 0);
		}
		else{
			error_hadle("Redeclared Variable");
		}
	}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 198 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int tmp = lookup_symbol((yyvsp[-4].lex), 0);
		new_attr();
		if(tmp == 0){
			insert_symbol(0, (yyvsp[-4].lex), (yyvsp[-5].type), FUNCTION_TYPE, 0);
		}
        else{
            Entry* node = getEntry((yyvsp[-4].lex), 0);
            if(node->entry_type == FUNCTION_TYPE){
				if(node != NIL){
					if(node->def == 0){
						error_hadle("ERROR : redeclared function");
					}
					if((yyvsp[-5].type) != node->data_type){
						error_hadle("return ERROR");
					}
					if(!check_assert(attr_tmp, node->attribute)){
						error_hadle("parameter ERROR");
					}
				} 
            }
        }
		attr_tmp = NIL;
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		int tmp = lookup_symbol((yyvsp[-3].lex), 0);
		new_attr();
		if(tmp == 0){
			insert_symbol(0, (yyvsp[-3].lex), (yyvsp[-4].type), FUNCTION_TYPE, 1);
		}
        else{
            Entry* ent = getEntry((yyvsp[-3].lex), 0);
            if(ent->entry_type == FUNCTION_TYPE){
				if(ent != NIL){
					if(!check_assert(attr_tmp, ent->attribute)){
						error_hadle("error : parameter is not the same\n");
					}
					if(ent->def == 1){
						error_hadle("error : Redefined Function");
					}
					if((yyvsp[-4].type) != ent->data_type){
						error_hadle("error : return type is not the same\n");
					}
				}
				
            }
        }
        codeGen(".method public static ");
		T_list* ptr = attr_tmp->par;
		codeGen((yyvsp[-3].lex));
		codeGen("(");
		if(!strcmp((yyvsp[-3].lex), "main")){
			if(attr_tmp->p_count != 0){
				error_hadle("error : main function have parameter\n");
			}
			codeGen("[Ljava/lang/String;");
		}
		else{
			while(ptr != NIL){
				if(ptr->type != VOID_TYPE){
					if(ptr->type == INTEGER_TYPE){
						codeGen("I");
					}
					else if(ptr->type == BOOLEAN_TYPE){
						codeGen("Z");
					}
					else if(ptr->type == FLOAT_TYPE){
						codeGen("F");	
					}
					else if(ptr->type == STRING_TYPE){
						codeGen("[Ljava/lang/String;");
					}
				}
				ptr = ptr->next;
			}
		}
		
		codeGen(")");
		//Return
		if(!strcmp((yyvsp[-3].lex), "main")){
			codeGen("V");
			function_return_check = "V";
			if((yyvsp[-4].type) != VOID_TYPE){
				error_hadle("Main(): type error\n");
			}
		}
		else{
			
			if((yyvsp[-4].type) == INTEGER_TYPE){
				function_return_check = "I";
				codeGen("I");
			}
			else if((yyvsp[-4].type) == BOOLEAN_TYPE){
				function_return_check = "Z";
				codeGen("Z");
			}
			else if((yyvsp[-4].type) == FLOAT_TYPE){
				function_return_check = "F";
				codeGen("F");
			}
			else if((yyvsp[-4].type) == STRING_TYPE){
				function_return_check = "S";
				codeGen("[Ljava/lang/String;");
			}
			else if((yyvsp[-4].type) == VOID_TYPE){
				function_return_check = "V";
				codeGen("V");
			}
		}
		var_count = 0; 
		codeGen("\n.limit stack 50\n.limit locals 50\n");
		
		/////////////////////////FIX////////////////////////////////////////////

		
		create_symbol(); 	
		ptr = attr_tmp->par;
		while(ptr != NIL && attr_tmp->p_count != 0){
			insert_symbol(0, ptr->name, ptr->type, PARAMETER_TYPE, 0);
			ptr = ptr->next;
		}	
		Entry* ent = HEAD->head;
		attr_tmp = NIL;	
		while(ent != NIL){
			gen_store_load(ent, 1);
			ent = ent->next;
		}
		
	}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 331 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		scope_count--;
        codeGen(".end method\n");
        dump_flag = true;
        display_flag = true;
        DUMP = HEAD;
        HEAD = HEAD->next;}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 340 "compiler_hw3.y" /* yacc.c:1646  */
    { create_symbol(); }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 340 "compiler_hw3.y" /* yacc.c:1646  */
    { 
       	dump_flag = true;
        display_flag = true;

        DUMP = HEAD;
        HEAD = HEAD->next;
        scope_count--; }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    {
		T_list* new = malloc(sizeof(T_list));
		if(attr_tmp == NIL){
			attr_tmp = malloc(sizeof(F_list));
			attr_tmp->p_count = 1;
			new->type = (yyvsp[-1].type);
			new->next = NIL;
			strcpy(new->name, (yyvsp[0].lex));
			attr_tmp->par = new;
		}
		else{
			new->type = (yyvsp[-1].type);
			new->next = NIL;
			strcpy(new->name, (yyvsp[0].lex));
			T_list* ptr = attr_tmp->par;
			while(ptr->next != NIL){
				ptr = ptr->next;
			}
			ptr->next = new;
			attr_tmp->p_count ++;
		}
	}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 405 "compiler_hw3.y" /* yacc.c:1646  */
    {
		int check = lookup_symbol((yyvsp[-1].lex),1);
		
		if(check == 0){
			error_hadle("Undeclared variable");
		}
		Entry* tmp = getEntry((yyvsp[-1].lex),1); 
		gen_store_load(tmp, 1);
		if(tmp->data_type == INTEGER_TYPE){
			if((yyvsp[0].op) == INC_OP){
				codeGen("\tldc 1\n");
				codeGen("\tiadd\n");
				gen_store_load(tmp, 0);

			}
			else if((yyvsp[0].op) == DEC_OP){
				codeGen("\tldc 1\n");
				codeGen("\tisub\n");
				gen_store_load(tmp, 0);
			}
		}
		else if(tmp->data_type == FLOAT_TYPE){
			if((yyvsp[0].op) == INC_OP){
				codeGen("\tldc 1.0\n");
				codeGen("\tfadd\n");
				gen_store_load(tmp, 0);

			}
			else if((yyvsp[0].op) == DEC_OP){
				codeGen("\tldc 1.0\n");
				codeGen("\tfsub\n");
				gen_store_load(tmp, 0);
			}

		}
		else{
			printf("error in postfix expr");
		}
	}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 447 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=INC_OP; }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 448 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=DEC_OP; }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 452 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int tmp = lookup_symbol((yyvsp[-3].lex), 1);
		Entry* ent = getEntry((yyvsp[-3].lex), 1);
		if(tmp == 0){
			error_hadle("Undeclared Variable");
		}
		AssignOP(ent, (yyvsp[-2].op), (yyvsp[-1].type));
	}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 462 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=ASGN_OP; }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 463 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=ADD_ASGN_OP; }
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 464 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=SUB_ASGN_OP; }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 465 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MUL_ASGN_OP; }
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 466 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=DIV_ASGN_OP; }
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 467 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MOD_ASGN_OP; }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 471 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 474 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 475 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=BOOLEAN_TYPE; 
		if( (yyvsp[-2].type) == BOOLEAN_TYPE && (yyvsp[0].type) == BOOLEAN_TYPE ){
			codeGen("\tior\n");	
		}
		else{
			error_hadle("not bool \n");
		}
	}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 486 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 487 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=BOOLEAN_TYPE; 
		if( (yyvsp[-2].type) != BOOLEAN_TYPE && (yyvsp[0].type) != BOOLEAN_TYPE ){
			codeGen("\tiand\n");
		}
		else{	
			error_hadle("Cannot do AND with other type than bool");
		}
	}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 499 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 500 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=BOOLEAN_TYPE; 
		compare_func((yyvsp[-2].type), (yyvsp[-1].op), (yyvsp[0].type));	
	}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 507 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=LT_OP; }
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 508 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MT_OP; }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 509 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=LTE_OP; }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 510 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MTE_OP; }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 511 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=EQ_OP; }
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 512 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=NE_OP; }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 515 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(function_return_check == "V"){
			codeGen("\treturn\n");
		}
		else{
			error_hadle("return type error \n");
		}
	}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 523 "compiler_hw3.y" /* yacc.c:1646  */
    {
		
		if(function_return_check == "I" && (yyvsp[-1].type) == INTEGER_TYPE){
			codeGen("\tireturn\n");
		}
		else if(function_return_check == "F" && (yyvsp[-1].type) == FLOAT_TYPE){
			codeGen("\tfreturn\n");
		}
		else if(function_return_check ==  "Z" && (yyvsp[-1].type) == BOOLEAN_TYPE){
			codeGen("\tireturn\n");
		}
		else if(function_return_check == "I" && (yyvsp[-1].type) == FLOAT_TYPE){
			codeGen("\tf2i\n\tireturn\n");
		}
		else if(function_return_check == "F" && (yyvsp[-1].type) == INTEGER_TYPE){
			codeGen("\ti2f\n\tfreturn\n");
		}
	}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 543 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 544 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[-1].op) == ADD_OP){
			if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\tiadd\n");
				(yyval.type) = INTEGER_TYPE;
			}
			else if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tswap\n\ti2f\n\tswap\n\tfadd\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tfadd\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\ti2f\n\tfadd\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else{
				error_hadle("ERROR type in ADD");
			}
		}
		else if((yyvsp[-1].op) == SUB_OP){
			if((yyvsp[-2].type)== INTEGER_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\tisub\n");
				(yyval.type) = INTEGER_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tfsub\n");
				(yyval.type) =  FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tswap\n\ti2f\n\tswap\n\tfsub\n");
				(yyval.type) =  FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\ti2f\n\tfsub\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else{
				error_hadle("ERROR in SUB");
			}
		}
		else{
			error_hadle("ERROR in addition expr\n");
		}
	}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 594 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=ADD_OP; }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 595 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=SUB_OP; }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 598 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 599 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if((yyvsp[-1].op) == MUL_OP){
			if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\timul\n");
				(yyval.type) = INTEGER_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tfmul\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == FLOAT_TYPE){	
				codeGen("\tswap\n");
				codeGen("\ti2f\n");	
				codeGen("\tswap\n");
				codeGen("\tfmul\n");
				(yyval.type) =  FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\ti2f\n");
				codeGen("\tfmul\n");
				(yyval.type) =  FLOAT_TYPE;
			}
		}
		else if((yyvsp[-1].op) == DIV_OP){
			if(check_zero_error == 0){
				error_hadle("ERROR : divide by zero!!!");
			}
			if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\tidiv\n");
				(yyval.type) = INTEGER_TYPE;
			}
			else if((yyvsp[-2].type) == INTEGER_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tswap\n");
				codeGen("\ti2f\n");
				codeGen("\tswap\n");
				codeGen("\tfdiv\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == FLOAT_TYPE){
				codeGen("\tfdiv\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else if((yyvsp[-2].type) == FLOAT_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\ti2f\n");
				codeGen("\tfdiv\n");
				(yyval.type) = FLOAT_TYPE;
			}
			else{
				error_hadle("type error in DIV");
			}
		}
		else if((yyvsp[0].type) == MOD_OP){		
			if((yyvsp[-2].type)== INTEGER_TYPE && (yyvsp[0].type) == INTEGER_TYPE){
				codeGen("\tirem\n");
				(yyval.type) = INTEGER_TYPE;
			}
			else{
				error_hadle("ERROR in MOD");
			}	
		}
		else{
			printf("error in multiplication expr\n");
		}
	}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 665 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MUL_OP; }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 666 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=MOD_OP; }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 667 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.op)=DIV_OP; }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[0].type); }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 671 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        int tmp = lookup_symbol((yyvsp[0].lex), 1);
		Entry* node = getEntry((yyvsp[0].lex), 1);
		if(tmp == 0){
			error_hadle("Undeclared variable");
		}
		(yyval.type)=node->data_type; 
		gen_store_load(node, 1);
		check_zero_error = 0;
	}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 681 "compiler_hw3.y" /* yacc.c:1646  */
    { check_zero_error = 0; (yyval.type)=(yyvsp[0].type); }
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 682 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.type)=(yyvsp[-1].type); }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 686 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		if(yylval.i_val == 0){
			check_zero_error = 1;
		}
		else{
			check_zero_error = 0;
		}
		(yyval.type)=INTEGER_TYPE; 
		sprintf(code_buf, "\tldc %d\n", yylval.i_val); 
		codeGen(code_buf);
	}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 697 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=FLOAT_TYPE; 
		sprintf(code_buf, "\tldc %f\n", yylval.f_val); 
		codeGen(code_buf);

		if(yylval.f_val == 0){
			check_zero_error = 1;
		}
		else{
			check_zero_error = 0;
		}
	}
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 709 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=BOOLEAN_TYPE;
		sprintf(code_buf, "\tldc 1\n");
		codeGen(code_buf); 
	}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 714 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=BOOLEAN_TYPE; 
		sprintf(code_buf, "\tldc 0\n");
		codeGen(code_buf);	
	}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 719 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=STRING_TYPE; 
		sprintf(code_buf, "\tldc \"%s\"\n", yylval.lex); 
		codeGen(code_buf);
	}
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 724 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=INTEGER_TYPE; 
		sprintf(code_buf, "\tldc %d\n", -1*yylval.i_val); 
		codeGen(code_buf);
	}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 729 "compiler_hw3.y" /* yacc.c:1646  */
    { 
		(yyval.type)=FLOAT_TYPE; 
		sprintf(code_buf, "\tldc %f\n", -1*yylval.f_val); 
		codeGen(code_buf);
	}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 738 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("L_WHILE_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);	
	}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 743 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("\tifeq L_WHILE_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
	}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 748 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("\tgoto L_WHILE_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_WHILE_EXIT_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_while++;
	}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 759 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        int tmp = lookup_symbol((yyvsp[-2].lex), 1);	
		Entry* node = getEntry((yyvsp[-2].lex), 1);
        if(tmp == 0){
            error_hadle("Undefined Variable in print()!");
        }
		else{
			gen_store_load(node, 1);
			gen_print(node->data_type);
		}
		
	}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 771 "compiler_hw3.y" /* yacc.c:1646  */
    { gen_print((yyvsp[-2].type)); }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 777 "compiler_hw3.y" /* yacc.c:1646  */
    {	
		codeGen("\tifeq L_THEN0_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		HEAD->count_else_if = 0;
		codeGen(code_buf);
	}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 782 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("\tgoto L_COND_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_THEN");
		sprintf(code_buf, "%d_%d_%d:\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_else_if++;
	}
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 790 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("L_COND_EXIT_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_if++;
		HEAD->count_else_if = 0;
	}
#line 2425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 800 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("\tifeq L_THEN");
		sprintf(code_buf, "%d_%d_%d\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
	}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 804 "compiler_hw3.y" /* yacc.c:1646  */
    {
		codeGen("\tgoto L_COND_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_THEN");
		sprintf(code_buf, "%d_%d_%d:\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen(":\n");
		HEAD->count_else_if ++;
	}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 824 "compiler_hw3.y" /* yacc.c:1646  */
    {
        int tmp = lookup_symbol((yyvsp[0].lex), 1);
		Entry* node = getEntry((yyvsp[0].lex), 1);
		if( node->scope != 0 || node->entry_type != FUNCTION_TYPE || tmp == 0){
			error_hadle("Undeclared Function");
		}
		else{
			attr_tmp = node->attribute;
			tmp_t_list = attr_tmp->par;
		}
	}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 834 "compiler_hw3.y" /* yacc.c:1646  */
    {
		Entry* node = getEntry((yyvsp[-4].lex), 1);
		invoke_test(node);
		(yyval.type) = node->data_type;
		attr_tmp = NIL;
	}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 843 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if(attr_tmp->p_count != 0){
			error_hadle("Ferror : function parameter change\n");
		}
	}
#line 2487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 851 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].type) != tmp_t_list->type){
			if ((yyvsp[0].type) == INTEGER_TYPE && tmp_t_list->type == FLOAT_TYPE){
				codeGen("\ti2f\n");
			}
			else {
				error_hadle("ERROR");
			}
		}
		tmp_t_list = tmp_t_list -> next;
		if(tmp_t_list != NIL){
			error_hadle("error : function parameter change\n");
		}
	}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 865 "compiler_hw3.y" /* yacc.c:1646  */
    {
		if((yyvsp[0].type) != tmp_t_list->type){
			if ((yyvsp[0].type) == INTEGER_TYPE && tmp_t_list->type == FLOAT_TYPE){
				codeGen("\ti2f\n");
			}
			else {
				error_hadle("ERROR");
			}
		}
		tmp_t_list = tmp_t_list -> next;
	}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2526 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 880 "compiler_hw3.y" /* yacc.c:1906  */
 
/* C code section */
int main(int argc, char** argv)
{
    
    file = fopen("compiler_hw3.j","w");

    fprintf(file, ".class public compiler_hw3\n");
	fprintf(file, ".super java/lang/Object\n" );	

	yylineno = 0;			
	create_symbol();
    yyparse();

	dump_flag = true;
    display_flag = true;
    
    DUMP = HEAD;
    HEAD = HEAD->next;
    scope_count--;

	dump_symbol();
    printf("\nTotal lines: %d \n",yylineno);


    fclose(file);	
    return 0;
}

void yyerror(char *s)
{
	if(flag_se == 1){
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| %s", err_msg);
        printf("\n|-----------------------------------------------|\n\n");
        memset(err_msg, '\0', BUF_SIZE);
    }
    else if(flag_sy == 0){
        printf("\n|-----------------------------------------------|\n");
        printf("| Error found in line %d: %s\n", yylineno, buf);
        printf("| syntax error");
        printf("\n|-----------------------------------------------|\n\n");
        memset(err_msg, '\0', BUF_SIZE);
    }   
}
void error_hadle(char *err){

    err_flag = true;
    if(strcmp(err, "syntax error")){
		flag_se = 1;
		strncpy(err_msg, err, strlen(err));
	}
	else{
		flag_sy= 1;
	}
}


Table create_symbol(){

    Table* new = malloc(sizeof(Table));
    new->head = NIL;
	if(HEAD == NIL){
        new->next = NIL;
        HEAD = new;
    }
    else{
        new->next = HEAD;
        HEAD = new;
    }

    new->entry_num = 0;
	new->count_while = 0;
	new->count_if = 0;
	new->count_else_if = 0;
    new->scope = scope_count;
    Current = new;
    scope_count++;  
}

void dump_symbol(void){
	
    if(DUMP->head != NIL){
        if(display_flag){
            printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n", "Index", "Name", "Kind", "Type", "Scope", "Attribute");
        }
        Entry* ptr = DUMP->head;
        Entry* del_ptr = NIL;
		char* tmp;
        while(ptr != NIL){
            if(display_flag){
                printf("%-10d%-10s", ptr->index,ptr->name);
                //printf("%-10s", ptr->name);
				if(ptr->entry_type == INTEGER_TYPE){
					tmp = "int";
					printf("%-12s", tmp);
				}
				else if(ptr->entry_type == FLOAT_TYPE){
					tmp = "float";
					printf("%-12s", tmp);

				}
				else if(ptr->entry_type == FUNCTION_TYPE){
					tmp = "function";
					printf("%-12s", tmp);	
				}
				else if(ptr->entry_type == PARAMETER_TYPE){
					tmp = "parameter";
					printf("%-12s", tmp);	
				}
				else if(ptr->entry_type == STRING_TYPE){
					tmp = "string";
					printf("%-12s", tmp);	
				}
				else if(ptr->entry_type == VOID_TYPE){
					tmp = "void";
					printf("%-12s", tmp);	
				}
				else if(ptr->entry_type == VARIABLE_TYPE){
					tmp = "variable";
					printf("%-12s", tmp);
				}
				else if(ptr->entry_type == BOOLEAN_TYPE){
					tmp = "boolean";
					printf("%-12s", tmp);	
				}
				else{
					printf("ERROR IN DUMP TABLE!");
				}
                if(ptr->data_type == INTEGER_TYPE){
					tmp = "int";
					printf("%-10s", tmp);
				}
				else if(ptr->data_type == FLOAT_TYPE){
					tmp = "float";
					printf("%-10s", tmp);
				}
				else if(ptr->data_type == FUNCTION_TYPE){
					tmp = "function";
					printf("%-10s", tmp);
				}
				else if(ptr->data_type == VARIABLE_TYPE){
					tmp = "variable";
					printf("%-10s", tmp);
				}
				else if(ptr->data_type == PARAMETER_TYPE){
					tmp = "parameter";
					printf("%-10s", tmp);
				}
				else if(ptr->data_type == STRING_TYPE){
					tmp = "string";
					printf("%-10s", tmp);
					
				}
				else if(ptr->data_type == VOID_TYPE){
					tmp = "void";
					printf("%-10s", tmp);	
				}
				else if(ptr->data_type == BOOLEAN_TYPE){
					tmp = "boolean";
					printf("%-10s", tmp);	
				}
				else{
					printf("ERROR IN DUMP TABLE!");
				}
                printf("%-10d", ptr->scope);
            }
            if(ptr->entry_type == FUNCTION_TYPE){
                int num = ptr->attribute->p_count;
                T_list* param_ptr = ptr->attribute->par;
                T_list* del_tmp = NIL;
                if (num == 0){
					printf("\n");
				}
				else{
					while(num > 0){
						num--;
						if(display_flag){
							if(num == 0){
								if(param_ptr->type == INTEGER_TYPE){
									tmp = "int";
									printf("%s\n", tmp);
								}
								else if(param_ptr->type == FLOAT_TYPE){
									tmp = "float";
									printf("%s\n", tmp);
								}
								else if(param_ptr->type == FUNCTION_TYPE){
									tmp = "function";
									printf("%s\n", tmp);
									
								}
								else if(param_ptr->type == PARAMETER_TYPE){
									tmp = "parameter";
									printf("%s\n", tmp);
								}
								else if(param_ptr->type == VARIABLE_TYPE){
									tmp = "variable";
									printf("%s\n", tmp);
								}
								else if(param_ptr->type == STRING_TYPE){
									tmp = "string";
									printf("%s\n", tmp);	
								}
								else if(param_ptr->type == VOID_TYPE){
									tmp = "void";
									printf("%s\n", tmp);
								}
								else if(param_ptr->type == BOOLEAN_TYPE){
									tmp = "boolean";
									printf("%s\n", tmp);
								}
							}
							else{
								if(param_ptr->type == INTEGER_TYPE){
									tmp = "int";
									printf("%s, ", tmp);
								}
								else if(param_ptr->type == FLOAT_TYPE){
									tmp = "float";
									printf("%s, ", tmp);
								}
								else if(param_ptr->type == STRING_TYPE){
									tmp = "string";
									printf("%s, ", tmp);	
								}
								else if(param_ptr->type == VOID_TYPE){
									tmp = "void";
									printf("%s, ", tmp);
									
								}
								else if(param_ptr->type == BOOLEAN_TYPE){
									tmp = "boolean";
									printf("%s, ", tmp);
								}
							}
						}
						del_tmp = param_ptr;
						param_ptr = param_ptr->next;
						free(del_tmp);
					}
				}
                free(ptr->attribute);
				
            }
			else{
				if(display_flag){
					printf("\n");
				}
			}
            del_ptr = ptr;
            ptr = ptr->next;
            free(del_ptr);
        }
		if(display_flag){
			printf("\n");
		}
    }
    free(DUMP);
    DUMP = NIL;
    dump_flag = false;
}


void insert_symbol( int check_scope, const char* name, TYPE data_type, TYPE entry_type, int check_def){
    
    Entry* new_node = malloc(sizeof(struct Entry));
    strcpy(new_node->name, name);
	
    new_node->entry_type = entry_type;
    new_node->data_type = data_type;

    new_node->next = NIL;
    new_node->def = check_def;

    // Attribute
	if(entry_type == FUNCTION_TYPE){
		if(attr_tmp == NIL){
			error_hadle("ERROR in insert_symbol");
		}
		else{
			new_node->attribute = attr_tmp;
		}
	}

	// Insert to sym table
	if(check_scope == 1){
		new_node->scope = HEAD->next->scope;
		new_node->index = var_count;
		
		HEAD->next->entry_num++;
		var_count ++;
		Entry* ptr = HEAD->next->head;

		if (ptr == NIL){
			HEAD->next->head = new_node;
		} else {
			while(ptr->next != NIL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
		}
	}
	else{

		new_node->index =  var_count;
		var_count ++ ;
    	HEAD->entry_num++;
		new_node->scope = HEAD->scope;

		Entry* ptr = HEAD->head;
		
		if (ptr == NIL){
			HEAD->head = new_node;
		} else {
			while(ptr->next != NIL){
				ptr = ptr->next;
			}
			ptr->next = new_node;
		}
	}
}
Entry* getEntry(char* name, int check){

    Table* tmp_table = HEAD;
	Entry* ent = tmp_table->head;

	if(check == 1){
		int test;
		test = 0;
		ent = tmp_table->head;
		while(tmp_table != NIL){
			ent = tmp_table->head;
			while(ent != NIL){
				if(!strcmp(ent->name, name)){
					return ent;
				}	
				ent = ent->next;
			}
			tmp_table = tmp_table->next;
		}
		return NIL;
	}
	else{
		while(ent != NIL){
			if(!strcmp(ent->name, name)){
				return ent;
			}	
			ent = ent->next;
		}
		return NIL;
	}

}
int lookup_symbol(char* name, int flag){
	
	Table* tmp_table = HEAD;
	Entry* ent = tmp_table->head;

	if(flag == 1){
		int test;
		test = 0;
		while(tmp_table != NIL){
			ent = tmp_table->head;
			while(ent != NIL){
				if(!strcmp(ent->name, name)){
					return 1;
				}	
				ent = ent->next;
			}
			tmp_table = tmp_table->next;
		}
		return 0;
	}
	else{
		while(ent != NIL){
			if(!strcmp(ent->name, name)){
				return 1;
			}	
			ent = ent->next;
		}
		return 0;
	}
}

int check_assert(F_list* M, F_list* N){
	int count;
	T_list* M_p = M->par;
	T_list* N_p = N->par;
	if(M->p_count != N->p_count){
		return 0;
	}
	else{
		count = M->p_count;	
		while(count > 0){
			if(M_p->type != N_p->type){
				return 0;
			}
			M_p = M_p->next;
			N_p = N_p->next;
			count -- ;
		}
		return 1;
	}
}


void gen_print(TYPE type){
	switch (type)
	{
	case INTEGER_TYPE:
		sprintf(code_buf, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n");
		codeGen(code_buf);
		break;
	case FLOAT_TYPE:
		sprintf(code_buf, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(F)V\n");
		codeGen(code_buf);
		break;
	case STRING_TYPE:
		sprintf(code_buf, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		codeGen(code_buf);
		break;
	case BOOLEAN_TYPE:
		sprintf(code_buf, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n\tinvokevirtual java/io/PrintStream/println(I)V\n");
		codeGen(code_buf);
		break;
	default:
		error_hadle("print():type error");
	}
}
void new_attr(){
	if(attr_tmp == NIL){
		attr_tmp = malloc(sizeof(F_list));
		attr_tmp->par = malloc(sizeof(T_list));
		attr_tmp->p_count = 0;
		attr_tmp->par->type = VOID_TYPE;
		attr_tmp->par->next = NIL;
	}
}


void gen_store_load(Entry* node,int action){
	//action = 0 store
	//action = 1 load
	int static_check = 0;
	if(node->scope == 0){
		static_check = 1;
	}
	
	switch (node->data_type){
		case INTEGER_TYPE:
			if(action == 0){
				if(static_check == 1){
					sprintf(code_buf, "\tputstatic compiler_hw3/%s I\n", node->name);
				}
				else{
					sprintf(code_buf, "\tistore %d\n", node->index);
				}
				codeGen(code_buf);
				
			}
			else{
				if(static_check == 1){
					sprintf(code_buf, "\tgetstatic compiler_hw3/%s I\n", node->name);
				}
				else{
					sprintf(code_buf, "\tiload %d\n", node->index);
				}
				codeGen(code_buf);
			}
			break;

		case FLOAT_TYPE:
			if(action == 0){
				if(static_check == 1){
					sprintf(code_buf, "\tputstatic compiler_hw3/%s F\n", node->name);
				}
				else{
					sprintf(code_buf, "\tistore %d\n", node->index);
				}
				codeGen(code_buf);
				
			}
			else{
				if(static_check == 1){
					sprintf(code_buf, "\tgetstatic compiler_hw3/%s F\n", node->name);
				}
				else{
					sprintf(code_buf, "\tiload %d\n", node->index);
				}
				codeGen(code_buf);
			}
			break;

		case STRING_TYPE:
			if(action == 0){
				if(static_check == 1){
					sprintf(code_buf, "\tputstatic compiler_hw3/%s [Ljava/lang/String;\n", node->name);
				}
				else{
					sprintf(code_buf, "\tistore %d\n", node->index);
				}
				codeGen(code_buf);
				
			}
			else{
				if(static_check == 1){
					sprintf(code_buf, "\tgetstatic compiler_hw3/%s [Ljava/lang/String;\n", node->name);
				}
				else{
					sprintf(code_buf, "\tiload %d\n", node->index);
				}
				codeGen(code_buf);
			}
			break;

		case BOOLEAN_TYPE:
			if(action == 0){
				if(static_check == 1){
					sprintf(code_buf, "\tputstatic compiler_hw3/%s Z\n", node->name);
				}
				else{
					sprintf(code_buf, "\tistore %d\n", node->index);
				}
				codeGen(code_buf);
				
			}
			else{
				if(static_check == 1){
					sprintf(code_buf, "\tgetstatic compiler_hw3/%s Z\n", node->name);
				}
				else{
					sprintf(code_buf, "\tiload %d\n", node->index);
				}
				codeGen(code_buf);
			}
			break;
		
		default:
			error_hadle("EROOR in genStore\n");
			break;
	}
}

void codeGen(char const *s)
{
    if (!err_flag)
        fprintf(file, "%s", s);
}

void compare_func(TYPE first,OPERATOR op,TYPE second){

	
	if(first == INTEGER_TYPE && second == FLOAT_TYPE){
		codeGen("\tswap\n");
		codeGen("\ti2f\n");
		codeGen("\tswap\n");
	}
	else if(first == FLOAT_TYPE && second == INTEGER_TYPE){
		codeGen("\ti2f\n");
	}
	else if(first == INTEGER_TYPE && second == INTEGER_TYPE){
		codeGen("\ti2f\n");
		codeGen("\tswap\n");
		codeGen("\ti2f\n");
		codeGen("\tswap\n");
	}
	else{
		error_hadle("compare type error\n");
	}

	if(op == LT_OP){
		sprintf(code_buf, "\tfcmpl\n\tiflt L_LT_TRUE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "\ticonst_0\n\tgoto L_LT_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_LT_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_LT_FALSE_%d:\n", label_count);
		codeGen(code_buf);
		
	}
	else if(op == MT_OP){
		sprintf(code_buf, "\tfcmpl\n\tifgt L_MT_TRUE_%d\n", label_count);
		codeGen(code_buf);
		codeGen("");
		sprintf(code_buf, "\ticonst_0\n\tgoto L_MT_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_MT_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_MT_FALSE_%d:\n", label_count);
		codeGen(code_buf);
	}
	else if(op == LTE_OP){
		sprintf(code_buf, "\tfcmpl\n\tifle L_LTE_TRUE_%d\n", label_count);
		codeGen(code_buf);
		codeGen("");
		sprintf(code_buf, "\ticonst_0\n\tgoto L_LTE_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_LTE_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_LTE_FALSE_%d:\n", label_count);
		codeGen(code_buf);
	}
	else if( op == MTE_OP){
		sprintf(code_buf, "\tfcmpl\n\tifge L_MTE_TRUE_%d\n", label_count);
		codeGen(code_buf);
		codeGen("");
		sprintf(code_buf, "\ticonst_0\n\tgoto L_MTE_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_MTE_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_MTE_FALSE_%d:\n", label_count);
		codeGen(code_buf);
	}
	else if( op == EQ_OP){
		sprintf(code_buf, "\tfcmpl\n\tifeq L_EQ_TRUE_%d\n", label_count);
		codeGen(code_buf);
		codeGen("");
		sprintf(code_buf, "\ticonst_0\n\tgoto L_EQ_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_EQ_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_EQ_FALSE_%d:\n", label_count);
		codeGen(code_buf);

	}
	else if( op == NE_OP){
		sprintf(code_buf, "\tfcmpl\n\tifne L_NE_TRUE_%d\n", label_count);
		codeGen(code_buf);
		codeGen("");
		sprintf(code_buf, "\ticonst_0\n\tgoto L_NE_FALSE_%d\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf, "L_NE_TRUE_%d:\n", label_count);
		codeGen(code_buf);
		sprintf(code_buf,"\ticonst_1\nL_NE_FALSE_%d:\n", label_count);
		codeGen(code_buf);
	}
	label_count++;
}


void AssignOP(Entry* entry, OPERATOR op, TYPE give){
	
	TYPE assgn = entry->data_type;
	if(op == ASGN_OP){
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			gen_store_load(entry, 0);
		}
		else if(assgn == FLOAT_TYPE && give == FLOAT_TYPE){
			gen_store_load(entry, 0);
		}
		else if(assgn == STRING_TYPE && give == STRING_TYPE){
			gen_store_load(entry, 0);
		}
		else if(assgn == BOOLEAN_TYPE && give == BOOLEAN_TYPE){
			gen_store_load(entry, 0);
		}
		//chang type
		else if(assgn == INTEGER_TYPE && give == FLOAT_TYPE){
			codeGen("\tf2i\n");
			gen_store_load(entry, 0);
		}	
		else if(assgn == FLOAT_TYPE && give == INTEGER_TYPE){
			codeGen("\ti2f\n");
			gen_store_load(entry, 0);
		}
		else{
			error_hadle("assgin error wrong type!");
		}
	}
	else if(op == ADD_ASGN_OP){
		gen_store_load(entry, 1);
		codeGen("\tswap\n");
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			codeGen("\tiadd\n");
		}
		else if(assgn == INTEGER_TYPE && give == FLOAT_TYPE){
			codeGen("\tswap\n\ti2f\n\tswap\n\tfadd\n");
		}
		else if(assgn == FLOAT_TYPE && give == FLOAT_TYPE){
			codeGen("\tfadd\n");
		}
		else if(assgn == FLOAT_TYPE && give == INTEGER_TYPE){
			codeGen("\ti2f\n\tfadd\n");
		}
		else{
			error_hadle("Only int and float can do addition");
		}
		gen_store_load(entry, 0);
	}
	else if(op == SUB_ASGN_OP){
		gen_store_load(entry, 1);
		codeGen("\tswap\n");
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			codeGen("\tisub\n");
		}
		else if(assgn == INTEGER_TYPE && give == FLOAT_TYPE){
			codeGen("\tswap\n\ti2f\n\tswap\n\tfsub\n");
		}
		else if(assgn == FLOAT_TYPE && give == FLOAT_TYPE){
			codeGen("\tfsub\n");
		}
		else if(assgn == FLOAT_TYPE && give == INTEGER_TYPE){
			codeGen("\ti2f\n\tfsub\n");
		}
		else{
			error_hadle("ERROR IN SUB ASGN");
		}
		gen_store_load(entry, 0);
	}
	else if(op == MOD_ASGN_OP){
		gen_store_load(entry, 1);
		codeGen("\tswap\n");
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			codeGen("\tirem\n");
		}
		else{
			error_hadle("ERROR IN MOD ASSGN\n");
		}
		gen_store_load(entry, 0);
	}
	else if(op == MUL_ASGN_OP){
		gen_store_load(entry, 1);
		codeGen("\tswap\n");
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			codeGen("\timul\n");
		}
		else if(assgn == FLOAT_TYPE && give == FLOAT_TYPE){
			codeGen("\tfmul\n");
		}
		else if(assgn == INTEGER_TYPE && give == FLOAT_TYPE){
			codeGen("\tswap\n");
			codeGen("\ti2f\n");
			codeGen("\tswap\n");
			codeGen("\tfmul\n");
		}
		else if(assgn == FLOAT_TYPE && give == INTEGER_TYPE){

			codeGen("\ti2f\n");
			codeGen("\tfmul\n");
		}
		else{
			error_hadle("MUL ASSGN ERROR");
		}
		gen_store_load(entry, 0);
	}
	else if(op == DIV_ASGN_OP){
		gen_store_load(entry, 1);
		codeGen("\tswap\n");
		if(check_zero_error == 0){
			error_hadle("ERROR : divide by zero!!!");
		}
		if(assgn == INTEGER_TYPE && give == INTEGER_TYPE){
			codeGen("\tidiv\n");
		}
		else if(assgn == INTEGER_TYPE && give == FLOAT_TYPE){
			codeGen("\tswap\n");
			codeGen("\ti2f\n");
			codeGen("\tswap\n");
			codeGen("\tfdiv\n");
		}
		else if(assgn == FLOAT_TYPE && give == FLOAT_TYPE){
			codeGen("\tfdiv\n");
		}
		else if(assgn == FLOAT_TYPE && give == INTEGER_TYPE){
			// change to float
			codeGen("\ti2f\n");
			codeGen("\tfdiv\n");
		}
		else{
			error_hadle("Only int and float can do division");
		}
		gen_store_load(entry, 0);
	}
	return;
}

void global_declaration(TYPE type, char* name, int value_flag){

	if(lookup_symbol(name, 0) != 0){
		error_hadle("Redeclared Variable");
	}
	else{
		insert_symbol(0, name, type, VARIABLE_TYPE, 0);
		
		if(type == INTEGER_TYPE){
			if(value_flag == 0){
				sprintf(code_buf, ".field public static %s I\n", name);
			}
			else if(yylval.i_val == 0){
				sprintf(code_buf, ".field public static %s I\n", name);
			}
			else{
				sprintf(code_buf, ".field public static %s I = %d\n", name, yylval.i_val);
			}
			codeGen(code_buf);
		}
		else if(type == FLOAT_TYPE){
			if(value_flag == 0){
				sprintf(code_buf, ".field public static %s F\n", name);
			}
			else if(yylval.f_val == 0){
				sprintf(code_buf, ".field public static %s F\n", name);
			}
			else{
				sprintf(code_buf, ".field public static %s F = %f\n", name, yylval.f_val);	
			}
			codeGen(code_buf);
		}
		else if(type == BOOLEAN_TYPE){
			if(value_flag == 0){
					sprintf(code_buf, ".field public static %s Z\n", name);
									
				}
				else{
					sprintf(code_buf, ".field public static %s Z = %d\n", name, yylval.i_val);	
				}
				codeGen(code_buf);
		}
		else{
			error_hadle("type error in global declaration");
		}
	}
}
void invoke_test(Entry* ent){
	T_list* t = ent->attribute->par;
	codeGen("\tinvokestatic compiler_hw3/");
	codeGen(ent->name);
	codeGen("(");	
	while(t != NIL){
		if(t->type != VOID_TYPE){
			if(t->type == INTEGER_TYPE){
				codeGen("I");
			}
			else if(t->type == BOOLEAN_TYPE){
				codeGen("Z");

			}
			else if(t->type == FLOAT_TYPE){
				codeGen("F");
				
			}
			else if(t->type == STRING_TYPE){
				codeGen("[Ljava/lang/String;");
			}
		}
		t = t->next;
	}
	codeGen(")");
	//Return
	if(ent->data_type == INTEGER_TYPE){
		codeGen("I\n");
	}
	else if(ent->data_type == BOOLEAN_TYPE){
		codeGen("Z\n");

	}
	else if(ent->data_type == FLOAT_TYPE){
		codeGen("F\n");
		
	}
	else if(ent->data_type == STRING_TYPE){
		codeGen("[Ljava/lang/String;\n");
	}
	else if(ent->data_type = VOID_TYPE){
		codeGen("V\n");
	}
}
void set_sy_flag(){
	flag_sy = 1;
}
