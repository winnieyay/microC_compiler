/*	Definition section */
%{
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

%}

%union {
	TYPE type;
	OPERATOR op;
	bool b_val;
    int i_val;
	float f_val;
	char* lex;	
}

/* Token without return */
%token PRINT SEMICOLON
%token IF ELSE FOR WHILE
%token ADD SUB MUL DIV MOD INC DEC AND OR NOT
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token MT LT MTE LTE EQ NE LB RB LCB RCB LSB RSB COMMA
%token TRUE FALSE RET
%token I_CONST F_CONST STRING_CONST
%token VOID INT FLOAT BOOL STRING

/* Token with return */
%token <lex> ID

/* Nonterminal with return */
%type <type> constant expression or_expr and_expr type_term 
%type <type> comparison_expr addition_expr multiplication_expr parenthesis_clause func_invoke
%type <op> assign_op cmp_op add_op mul_op post_op 

/* Yacc start nonterminal */
%start program

/* Grammar section */
%%

program
	: declare_list
	;

declare_list
	: declare_list declare
	| declare
	| error { set_sy_flag(); }
	;

declare
	: func_declaration
	| global_variable_declaration
	| func_definition
	;

global_constant
	: I_CONST 
	| F_CONST 
	| sub_const
	| ans
	;
ans
	: TRUE
	| FALSE
	;
sub_const
	: SUB I_CONST { yylval.i_val *= -1; }
	| SUB F_CONST { yylval.f_val *= -1; }
	;
type_term
	: VOID { $$=VOID_TYPE; }
	| BOOL { $$=BOOLEAN_TYPE; }
	| INT { $$=INTEGER_TYPE; }
	| FLOAT { $$=FLOAT_TYPE; } 
	| STRING { $$=STRING_TYPE; }
	;

global_variable_declaration
	: type_term ID SEMICOLON 
		{ global_declaration($1, $2, 0);}
	| type_term ID ASGN global_constant SEMICOLON 
		{ global_declaration($1, $2, 1);}
	;

var_declare
	: type_term ID SEMICOLON { 	
		int t = lookup_symbol($2, 0);
		if(t == 0){
			insert_symbol(0, $2, $1, VARIABLE_TYPE, 0 );
			Entry* node = getEntry($2, 1);
			if($1 == INTEGER_TYPE){
				codeGen("\tldc 0\n");
				gen_store_load(node, 0);
			}
			else if($1 == FLOAT_TYPE){
				codeGen("\tldc 0.0\n");
				gen_store_load(node, 0);
			}
			else if($1 == BOOLEAN_TYPE){
				codeGen("\tldc 0\n");
				gen_store_load(node, 0);
			}
			else if($1 == STRING_TYPE){
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
	| type_term ID ASGN expression SEMICOLON {
        int tmp = lookup_symbol($2, 0);
		if(tmp == 0){
			insert_symbol(0, $2, $1, VARIABLE_TYPE, 0);
			Entry* ent = getEntry($2, 1);
			if($1 == INTEGER_TYPE && $4 == FLOAT_TYPE){
				codeGen("\tf2i\n");
			}
			else if($1 == FLOAT_TYPE && $4 == INTEGER_TYPE){
				codeGen("\ti2f\n");
			}
			gen_store_load(ent, 0);
		}
		else{
			error_hadle("Redeclared Variable");
		}
	}
	;



func_declaration
	: type_term ID LB parameters RB SEMICOLON {
		int tmp = lookup_symbol($2, 0);
		new_attr();
		if(tmp == 0){
			insert_symbol(0, $2, $1, FUNCTION_TYPE, 0);
		}
        else{
            Entry* node = getEntry($2, 0);
            if(node->entry_type == FUNCTION_TYPE){
				if(node != NIL){
					if(node->def == 0){
						error_hadle("ERROR : redeclared function");
					}
					if($1 != node->data_type){
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
	;
func_definition
	: type_term ID LB parameters RB { 
		int tmp = lookup_symbol($2, 0);
		new_attr();
		if(tmp == 0){
			insert_symbol(0, $2, $1, FUNCTION_TYPE, 1);
		}
        else{
            Entry* ent = getEntry($2, 0);
            if(ent->entry_type == FUNCTION_TYPE){
				if(ent != NIL){
					if(!check_assert(attr_tmp, ent->attribute)){
						error_hadle("error : parameter is not the same\n");
					}
					if(ent->def == 1){
						error_hadle("error : Redefined Function");
					}
					if($1 != ent->data_type){
						error_hadle("error : return type is not the same\n");
					}
				}
				
            }
        }
        codeGen(".method public static ");
		T_list* ptr = attr_tmp->par;
		codeGen($2);
		codeGen("(");
		if(!strcmp($2, "main")){
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
		if(!strcmp($2, "main")){
			codeGen("V");
			function_return_check = "V";
			if($1 != VOID_TYPE){
				error_hadle("Main(): type error\n");
			}
		}
		else{
			
			if($1 == INTEGER_TYPE){
				function_return_check = "I";
				codeGen("I");
			}
			else if($1 == BOOLEAN_TYPE){
				function_return_check = "Z";
				codeGen("Z");
			}
			else if($1 == FLOAT_TYPE){
				function_return_check = "F";
				codeGen("F");
			}
			else if($1 == STRING_TYPE){
				function_return_check = "S";
				codeGen("[Ljava/lang/String;");
			}
			else if($1 == VOID_TYPE){
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
		
	} function_compound_stat
	;
function_compound_stat
	: LCB content_list  RCB { 
		scope_count--;
        codeGen(".end method\n");
        dump_flag = true;
        display_flag = true;
        DUMP = HEAD;
        HEAD = HEAD->next;}
	;
compound_stat
	: LCB { create_symbol(); }content_list RCB { 
       	dump_flag = true;
        display_flag = true;

        DUMP = HEAD;
        HEAD = HEAD->next;
        scope_count--; }
	;
parameters
	: par_list 	
	;

par_list
	: par_list COMMA par
	| par
	| VOID
	;

par
	: type_term ID {
		T_list* new = malloc(sizeof(T_list));
		if(attr_tmp == NIL){
			attr_tmp = malloc(sizeof(F_list));
			attr_tmp->p_count = 1;
			new->type = $1;
			new->next = NIL;
			strcpy(new->name, $2);
			attr_tmp->par = new;
		}
		else{
			new->type = $1;
			new->next = NIL;
			strcpy(new->name, $2);
			T_list* ptr = attr_tmp->par;
			while(ptr->next != NIL){
				ptr = ptr->next;
			}
			ptr->next = new;
			attr_tmp->p_count ++;
		}
	}
	|
	;
content_list
	: content_list content
	|
	;
content
	: var_declare
	| stat
stat
	: assign_stat
	| if_stat
	| while_stat
	| return_stat
	| expression_stat
	| compound_stat
	| print_stat
	;
expression_stat
	: func_invoke SEMICOLON
	| postfix_expr SEMICOLON
	;

postfix_expr
 	: ID post_op {
		int check = lookup_symbol($1,1);
		
		if(check == 0){
			error_hadle("Undeclared variable");
		}
		Entry* tmp = getEntry($1,1); 
		gen_store_load(tmp, 1);
		if(tmp->data_type == INTEGER_TYPE){
			if($2 == INC_OP){
				codeGen("\tldc 1\n");
				codeGen("\tiadd\n");
				gen_store_load(tmp, 0);

			}
			else if($2 == DEC_OP){
				codeGen("\tldc 1\n");
				codeGen("\tisub\n");
				gen_store_load(tmp, 0);
			}
		}
		else if(tmp->data_type == FLOAT_TYPE){
			if($2 == INC_OP){
				codeGen("\tldc 1.0\n");
				codeGen("\tfadd\n");
				gen_store_load(tmp, 0);

			}
			else if($2 == DEC_OP){
				codeGen("\tldc 1.0\n");
				codeGen("\tfsub\n");
				gen_store_load(tmp, 0);
			}

		}
		else{
			printf("error in postfix expr");
		}
	}
	;

post_op
	: INC { $$=INC_OP; }
	| DEC { $$=DEC_OP; }
	;

assign_stat
	: ID assign_op expression SEMICOLON {
        int tmp = lookup_symbol($1, 1);
		Entry* ent = getEntry($1, 1);
		if(tmp == 0){
			error_hadle("Undeclared Variable");
		}
		AssignOP(ent, $2, $3);
	}

assign_op
	: ASGN { $$=ASGN_OP; }
	| ADDASGN { $$=ADD_ASGN_OP; }
	| SUBASGN { $$=SUB_ASGN_OP; }
	| MULASGN { $$=MUL_ASGN_OP; }
	| DIVASGN { $$=DIV_ASGN_OP; }
	| MODASGN { $$=MOD_ASGN_OP; }
	;

expression
	: or_expr { $$=$1; }
	;
or_expr
	: and_expr { $$=$1; }
	| or_expr OR and_expr { 
		$$=BOOLEAN_TYPE; 
		if( $1 == BOOLEAN_TYPE && $3 == BOOLEAN_TYPE ){
			codeGen("\tior\n");	
		}
		else{
			error_hadle("not bool \n");
		}
	}
	;
and_expr
	: comparison_expr { $$=$1; }
	| and_expr AND comparison_expr { 
		$$=BOOLEAN_TYPE; 
		if( $1 != BOOLEAN_TYPE && $3 != BOOLEAN_TYPE ){
			codeGen("\tiand\n");
		}
		else{	
			error_hadle("Cannot do AND with other type than bool");
		}
	}
	;

comparison_expr
	: addition_expr { $$=$1; } 
	| comparison_expr cmp_op addition_expr { 
		$$=BOOLEAN_TYPE; 
		compare_func($1, $2, $3);	
	}
	;

cmp_op
	: LT { $$=LT_OP; }
	| MT { $$=MT_OP; }
	| LTE { $$=LTE_OP; }
	| MTE { $$=MTE_OP; }
	| EQ { $$=EQ_OP; }
	| NE { $$=NE_OP; }
	;
return_stat
	: RET SEMICOLON {
		if(function_return_check == "V"){
			codeGen("\treturn\n");
		}
		else{
			error_hadle("return type error \n");
		}
	}
	| RET expression SEMICOLON{
		
		if(function_return_check == "I" && $2 == INTEGER_TYPE){
			codeGen("\tireturn\n");
		}
		else if(function_return_check == "F" && $2 == FLOAT_TYPE){
			codeGen("\tfreturn\n");
		}
		else if(function_return_check ==  "Z" && $2 == BOOLEAN_TYPE){
			codeGen("\tireturn\n");
		}
		else if(function_return_check == "I" && $2 == FLOAT_TYPE){
			codeGen("\tf2i\n\tireturn\n");
		}
		else if(function_return_check == "F" && $2 == INTEGER_TYPE){
			codeGen("\ti2f\n\tfreturn\n");
		}
	}
	;
addition_expr
	: multiplication_expr { $$=$1; }
	| addition_expr add_op multiplication_expr {
		if($2 == ADD_OP){
			if($1 == INTEGER_TYPE && $3 == INTEGER_TYPE){
				codeGen("\tiadd\n");
				$$ = INTEGER_TYPE;
			}
			else if($1 == INTEGER_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tswap\n\ti2f\n\tswap\n\tfadd\n");
				$$ = FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tfadd\n");
				$$ = FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == INTEGER_TYPE){
				codeGen("\ti2f\n\tfadd\n");
				$$ = FLOAT_TYPE;
			}
			else{
				error_hadle("ERROR type in ADD");
			}
		}
		else if($2 == SUB_OP){
			if($1== INTEGER_TYPE && $3 == INTEGER_TYPE){
				codeGen("\tisub\n");
				$$ = INTEGER_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tfsub\n");
				$$ =  FLOAT_TYPE;
			}
			else if($1 == INTEGER_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tswap\n\ti2f\n\tswap\n\tfsub\n");
				$$ =  FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == INTEGER_TYPE){
				codeGen("\ti2f\n\tfsub\n");
				$$ = FLOAT_TYPE;
			}
			else{
				error_hadle("ERROR in SUB");
			}
		}
		else{
			error_hadle("ERROR in addition expr\n");
		}
	}
	;

add_op
	: ADD { $$=ADD_OP; }
	| SUB { $$=SUB_OP; }
	;
multiplication_expr
	: parenthesis_clause { $$=$1; }
	| multiplication_expr mul_op parenthesis_clause { 
		if($2 == MUL_OP){
			if($1 == INTEGER_TYPE && $3 == INTEGER_TYPE){
				codeGen("\timul\n");
				$$ = INTEGER_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tfmul\n");
				$$ = FLOAT_TYPE;
			}
			else if($1 == INTEGER_TYPE && $3 == FLOAT_TYPE){	
				codeGen("\tswap\n");
				codeGen("\ti2f\n");	
				codeGen("\tswap\n");
				codeGen("\tfmul\n");
				$$ =  FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == INTEGER_TYPE){
				codeGen("\ti2f\n");
				codeGen("\tfmul\n");
				$$ =  FLOAT_TYPE;
			}
		}
		else if($2 == DIV_OP){
			if(check_zero_error == 0){
				error_hadle("ERROR : divide by zero!!!");
			}
			if($1 == INTEGER_TYPE && $3 == INTEGER_TYPE){
				codeGen("\tidiv\n");
				$$ = INTEGER_TYPE;
			}
			else if($1 == INTEGER_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tswap\n");
				codeGen("\ti2f\n");
				codeGen("\tswap\n");
				codeGen("\tfdiv\n");
				$$ = FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == FLOAT_TYPE){
				codeGen("\tfdiv\n");
				$$ = FLOAT_TYPE;
			}
			else if($1 == FLOAT_TYPE && $3 == INTEGER_TYPE){
				codeGen("\ti2f\n");
				codeGen("\tfdiv\n");
				$$ = FLOAT_TYPE;
			}
			else{
				error_hadle("type error in DIV");
			}
		}
		else if($3 == MOD_OP){		
			if($1== INTEGER_TYPE && $3 == INTEGER_TYPE){
				codeGen("\tirem\n");
				$$ = INTEGER_TYPE;
			}
			else{
				error_hadle("ERROR in MOD");
			}	
		}
		else{
			printf("error in multiplication expr\n");
		}
	}
	;
mul_op
	: MUL { $$=MUL_OP; }
	| MOD { $$=MOD_OP; }
	| DIV { $$=DIV_OP; }
	;
parenthesis_clause
	: constant { $$=$1; }
	| ID { 
        int tmp = lookup_symbol($1, 1);
		Entry* node = getEntry($1, 1);
		if(tmp == 0){
			error_hadle("Undeclared variable");
		}
		$$=node->data_type; 
		gen_store_load(node, 1);
		check_zero_error = 0;
	}
	| func_invoke { check_zero_error = 0; $$=$1; }
	| LB expression RB { $$=$2; }
	;

constant
	: I_CONST { 
		if(yylval.i_val == 0){
			check_zero_error = 1;
		}
		else{
			check_zero_error = 0;
		}
		$$=INTEGER_TYPE; 
		sprintf(code_buf, "\tldc %d\n", yylval.i_val); 
		codeGen(code_buf);
	}
	| F_CONST { 
		$$=FLOAT_TYPE; 
		sprintf(code_buf, "\tldc %f\n", yylval.f_val); 
		codeGen(code_buf);

		if(yylval.f_val == 0){
			check_zero_error = 1;
		}
		else{
			check_zero_error = 0;
		}
	}
	| TRUE { 
		$$=BOOLEAN_TYPE;
		sprintf(code_buf, "\tldc 1\n");
		codeGen(code_buf); 
	}
	| FALSE { 
		$$=BOOLEAN_TYPE; 
		sprintf(code_buf, "\tldc 0\n");
		codeGen(code_buf);	
	}
	| STRING_CONST { 
		$$=STRING_TYPE; 
		sprintf(code_buf, "\tldc \"%s\"\n", yylval.lex); 
		codeGen(code_buf);
	}
	| SUB I_CONST { 
		$$=INTEGER_TYPE; 
		sprintf(code_buf, "\tldc %d\n", -1*yylval.i_val); 
		codeGen(code_buf);
	}
	| SUB F_CONST { 
		$$=FLOAT_TYPE; 
		sprintf(code_buf, "\tldc %f\n", -1*yylval.f_val); 
		codeGen(code_buf);
	}
	;

	
while_stat
	: WHILE {
		codeGen("L_WHILE_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);	
	}
	LB expression RB {
		codeGen("\tifeq L_WHILE_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
	}
	compound_stat{
		codeGen("\tgoto L_WHILE_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_WHILE_EXIT_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_while, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_while++;
	}
	;
print_stat
	: PRINT LB ID RB SEMICOLON { 
        int tmp = lookup_symbol($3, 1);	
		Entry* node = getEntry($3, 1);
        if(tmp == 0){
            error_hadle("Undefined Variable in print()!");
        }
		else{
			gen_store_load(node, 1);
			gen_print(node->data_type);
		}
		
	}
    | PRINT LB constant RB SEMICOLON { gen_print($3); }
	;



if_stat
	: IF LB expression RB {	
		codeGen("\tifeq L_THEN0_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		HEAD->count_else_if = 0;
		codeGen(code_buf);
	}compound_stat {
		codeGen("\tgoto L_COND_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_THEN");
		sprintf(code_buf, "%d_%d_%d:\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_else_if++;
	} else_if_stat else_stat {
		codeGen("L_COND_EXIT_");
		sprintf(code_buf, "%d_%d:\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		HEAD->count_if++;
		HEAD->count_else_if = 0;
	}
	;

else_if_stat
	: else_if_stat ELSE IF LB expression RB {
		codeGen("\tifeq L_THEN");
		sprintf(code_buf, "%d_%d_%d\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
	}compound_stat {
		codeGen("\tgoto L_COND_EXIT_");
		sprintf(code_buf, "%d_%d\n", HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen("L_THEN");
		sprintf(code_buf, "%d_%d_%d:\n",HEAD->count_else_if, HEAD->count_if, HEAD->scope);
		codeGen(code_buf);
		codeGen(":\n");
		HEAD->count_else_if ++;
	}
	|
	;

else_stat
	: ELSE compound_stat
	|
	;


func_invoke
	: ID {
        int tmp = lookup_symbol($1, 1);
		Entry* node = getEntry($1, 1);
		if( node->scope != 0 || node->entry_type != FUNCTION_TYPE || tmp == 0){
			error_hadle("Undeclared Function");
		}
		else{
			attr_tmp = node->attribute;
			tmp_t_list = attr_tmp->par;
		}
	} LB arg RB {
		Entry* node = getEntry($1, 1);
		invoke_test(node);
		$$ = node->data_type;
		attr_tmp = NIL;
	}

arg
	: arg_list
	| {
		if(attr_tmp->p_count != 0){
			error_hadle("Ferror : function parameter change\n");
		}
	}
	;
	
arg_list
	: arg_list COMMA expression{
		if($3 != tmp_t_list->type){
			if ($3 == INTEGER_TYPE && tmp_t_list->type == FLOAT_TYPE){
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
	| expression {
		if($1 != tmp_t_list->type){
			if ($1 == INTEGER_TYPE && tmp_t_list->type == FLOAT_TYPE){
				codeGen("\ti2f\n");
			}
			else {
				error_hadle("ERROR");
			}
		}
		tmp_t_list = tmp_t_list -> next;
	}
	;



%% 
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