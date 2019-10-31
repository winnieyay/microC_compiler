#ifndef DEFINE_H
#define DEIFNE_H



#include <stdbool.h>


typedef enum { BOOLEAN_TYPE, VOID_TYPE, INTEGER_TYPE, FLOAT_TYPE, STRING_TYPE, \
               VARIABLE_TYPE, FUNCTION_TYPE, PARAMETER_TYPE } TYPE;
typedef struct T_list T_list;
struct T_list { 
    int count;
    TYPE type;
    struct T_list* next;
    char name[20];
};
typedef struct F_list F_list;
struct F_list {
    int p_count;    
    int count;
    struct T_list* par; 
    char* share;  
};


typedef struct Entry Entry;
struct Entry {
    char name[10];
    int scope;
    TYPE entry_type;
    int index;
    Entry* next;
    TYPE data_type;
    int def;
    int check;
    struct F_list *attribute;
};

typedef struct Table Table;
struct Table {
    Table* next;
    Entry* head;
    int entry_num;
    int scope;
    int count_total;
    int count_while;
    int count_if;
    int count_else_if;
    int count_garbage;
};

typedef enum {
    ADD_OP, SUB_OP, MUL_OP, DIV_OP, MOD_OP, INC_OP, DEC_OP,
    LTE_OP, MTE_OP, LT_OP, MT_OP, EQ_OP, NE_OP,
    ASGN_OP, ADD_ASGN_OP, SUB_ASGN_OP, MUL_ASGN_OP, DIV_ASGN_OP, MOD_ASGN_OP,
} OPERATOR;
#endif

