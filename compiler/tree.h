#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "tokenizer.h"

enum {		/* head_type */
	BLOCK = 0,
	ADD,
	SUB,
	MULT,
	DIV,
	ASGN,
	IF,
	WHILE,
	NUMBER,
	VARIABLE,
	GT,
	LT,
	GTE,
	LTE,
	EQL,
	NEQL,
	INT_DECL,
	BPF_INSTR,
	NEGATIVE,
	INC,
	DEC,
	POST_INC,
	POST_DEC,
	LABEL,
	GOTO,
	ARRAY,
	ARRAY_DECL,
	ARG_LIST,
	PROC,
	RET,
	PROC_CALL,
	ADDR,
	DEREF,
	STR_CONST,
	MOD,
	CC_OR,
	CC_AND,
	CC_NOT,
	ARRAY_DIM,
	DECL_CHILD,
	DECL_STAR,
	CAST,
	BASE_TYPE,
	CAST_TYPE,
	CHAR_DECL,
	TO_DECL_STMT,
	TO_UNK,
	TO_BLOCK,
	BREAK,
	ARG,
	ARRAY_ADR,
	STRUCT_DECL,
	STRUCT_MEMB,
	DEREF_STRUCT_MEMB,
	NAMED_STRUCT_DECL,
	SIZEOF,
	LONG_DECL,
	TERNARY,
	COMPLICATED_INITIALIZER,
	COMPLICATED_INITIALIZATION,
	SEQ,
	VOID_DECL,
	BOR,
	BXOR,
	BAND,
	BSL,
	BSR,
	CONTLAB,
	CONTINUE,
	MINGW_IOBUF,
	PROTOTYPE,
	PROTO_ARG,
	SWITCH,
	SWITCH_CASE,
	SWITCH_DEFAULT,
	SWITCH_BREAK,
	ENUM_DECL,
	PROC_CALL_MEMCPY,
	EXTERN_DECL,
	DOWHILE,
	SUB_MASKED,
	/* special */
	NULL_TREE
};

extern char** tree_nam;

typedef struct exp_tree {
	char head_type;
	token_t* tok;
	/*unsigned*/ int child_count;
	/*unsigned*/ int child_alloc;
	struct exp_tree **child;
} exp_tree_t;

extern exp_tree_t null_tree;

void add_child(exp_tree_t *dest, exp_tree_t* src);
exp_tree_t new_exp_tree(/*unsigned*/ int type, token_t* tok);
int valid_tree(exp_tree_t et);
exp_tree_t *alloc_exptree(exp_tree_t et);
void printout_tree(exp_tree_t et);
void init_tree(void);
exp_tree_t copy_tree(exp_tree_t src_a);

#endif
