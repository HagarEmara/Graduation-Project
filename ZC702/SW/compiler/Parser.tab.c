/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
extern int yyerror(char *s);
extern int yylex(void);
extern char *yytext;
extern cAstNode *root;

#line 81 "Parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 25,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 26,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 27,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 28,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 29,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 30,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUM_CONSTANT = 31,             /* ENUM_CONSTANT  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_INLINE = 37,                    /* INLINE  */
  YYSYMBOL_KERNEL = 38,                    /* KERNEL  */
  YYSYMBOL_CLASS = 39,                     /* CLASS  */
  YYSYMBOL_NT1 = 40,                       /* NT1  */
  YYSYMBOL_NT2 = 41,                       /* NT2  */
  YYSYMBOL_NT4 = 42,                       /* NT4  */
  YYSYMBOL_NT8 = 43,                       /* NT8  */
  YYSYMBOL_NT16 = 44,                      /* NT16  */
  YYSYMBOL_CONST = 45,                     /* CONST  */
  YYSYMBOL_RESTRICT = 46,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 47,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 48,                      /* BOOL  */
  YYSYMBOL_CHAR = 49,                      /* CHAR  */
  YYSYMBOL_SHORT = 50,                     /* SHORT  */
  YYSYMBOL_INT = 51,                       /* INT  */
  YYSYMBOL_LONG = 52,                      /* LONG  */
  YYSYMBOL_SIGNED = 53,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 54,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 55,                     /* FLOAT  */
  YYSYMBOL_FLOAT2 = 56,                    /* FLOAT2  */
  YYSYMBOL_FLOAT4 = 57,                    /* FLOAT4  */
  YYSYMBOL_FLOAT8 = 58,                    /* FLOAT8  */
  YYSYMBOL_FLOAT16 = 59,                   /* FLOAT16  */
  YYSYMBOL_DOUBLE = 60,                    /* DOUBLE  */
  YYSYMBOL_VOID = 61,                      /* VOID  */
  YYSYMBOL_RESULT = 62,                    /* RESULT  */
  YYSYMBOL_POINTER_SCOPE = 63,             /* POINTER_SCOPE  */
  YYSYMBOL_COMPLEX = 64,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 65,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 66,                    /* STRUCT  */
  YYSYMBOL_UNION = 67,                     /* UNION  */
  YYSYMBOL_ENUM = 68,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 69,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 70,                      /* CASE  */
  YYSYMBOL_DEFAULT = 71,                   /* DEFAULT  */
  YYSYMBOL_IF = 72,                        /* IF  */
  YYSYMBOL_ELSE = 73,                      /* ELSE  */
  YYSYMBOL_SWITCH = 74,                    /* SWITCH  */
  YYSYMBOL_WHILE = 75,                     /* WHILE  */
  YYSYMBOL_DO = 76,                        /* DO  */
  YYSYMBOL_FOR = 77,                       /* FOR  */
  YYSYMBOL_GOTO = 78,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 79,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 80,                     /* BREAK  */
  YYSYMBOL_RETURN = 81,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 82,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 83,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 84,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 85,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 86,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 87,             /* STATIC_ASSERT  */
  YYSYMBOL_SHARE = 88,                     /* SHARE  */
  YYSYMBOL_GLOBAL = 89,                    /* GLOBAL  */
  YYSYMBOL_90_ = 90,                       /* '('  */
  YYSYMBOL_91_ = 91,                       /* ')'  */
  YYSYMBOL_92_ = 92,                       /* ','  */
  YYSYMBOL_93_ = 93,                       /* ':'  */
  YYSYMBOL_94_ = 94,                       /* '['  */
  YYSYMBOL_95_ = 95,                       /* ']'  */
  YYSYMBOL_96_ = 96,                       /* '.'  */
  YYSYMBOL_97_ = 97,                       /* '{'  */
  YYSYMBOL_98_ = 98,                       /* '}'  */
  YYSYMBOL_99_ = 99,                       /* '&'  */
  YYSYMBOL_100_ = 100,                     /* '*'  */
  YYSYMBOL_101_ = 101,                     /* '+'  */
  YYSYMBOL_102_ = 102,                     /* '-'  */
  YYSYMBOL_103_ = 103,                     /* '~'  */
  YYSYMBOL_104_ = 104,                     /* '!'  */
  YYSYMBOL_105_ = 105,                     /* '/'  */
  YYSYMBOL_106_ = 106,                     /* '%'  */
  YYSYMBOL_107_ = 107,                     /* '<'  */
  YYSYMBOL_108_ = 108,                     /* '>'  */
  YYSYMBOL_109_ = 109,                     /* '^'  */
  YYSYMBOL_110_ = 110,                     /* '|'  */
  YYSYMBOL_111_ = 111,                     /* '?'  */
  YYSYMBOL_112_ = 112,                     /* '='  */
  YYSYMBOL_113_ = 113,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 114,                 /* $accept  */
  YYSYMBOL_identifier = 115,               /* identifier  */
  YYSYMBOL_i_constant = 116,               /* i_constant  */
  YYSYMBOL_f_constant = 117,               /* f_constant  */
  YYSYMBOL_string_literal = 118,           /* string_literal  */
  YYSYMBOL_func_name = 119,                /* func_name  */
  YYSYMBOL_sizeof = 120,                   /* sizeof  */
  YYSYMBOL_ptr_op = 121,                   /* ptr_op  */
  YYSYMBOL_inc_op = 122,                   /* inc_op  */
  YYSYMBOL_dec_op = 123,                   /* dec_op  */
  YYSYMBOL_left_op = 124,                  /* left_op  */
  YYSYMBOL_right_op = 125,                 /* right_op  */
  YYSYMBOL_le_op = 126,                    /* le_op  */
  YYSYMBOL_ge_op = 127,                    /* ge_op  */
  YYSYMBOL_eq_op = 128,                    /* eq_op  */
  YYSYMBOL_ne_op = 129,                    /* ne_op  */
  YYSYMBOL_and_op = 130,                   /* and_op  */
  YYSYMBOL_or_op = 131,                    /* or_op  */
  YYSYMBOL_mul_assign = 132,               /* mul_assign  */
  YYSYMBOL_div_assign = 133,               /* div_assign  */
  YYSYMBOL_mod_assign = 134,               /* mod_assign  */
  YYSYMBOL_add_assign = 135,               /* add_assign  */
  YYSYMBOL_sub_assign = 136,               /* sub_assign  */
  YYSYMBOL_left_assign = 137,              /* left_assign  */
  YYSYMBOL_right_assign = 138,             /* right_assign  */
  YYSYMBOL_and_assign = 139,               /* and_assign  */
  YYSYMBOL_xor_assign = 140,               /* xor_assign  */
  YYSYMBOL_or_assign = 141,                /* or_assign  */
  YYSYMBOL_typedef_name = 142,             /* typedef_name  */
  YYSYMBOL_enum_constant = 143,            /* enum_constant  */
  YYSYMBOL_typedef = 144,                  /* typedef  */
  YYSYMBOL_extern = 145,                   /* extern  */
  YYSYMBOL_static = 146,                   /* static  */
  YYSYMBOL_auto = 147,                     /* auto  */
  YYSYMBOL_register = 148,                 /* register  */
  YYSYMBOL_inline = 149,                   /* inline  */
  YYSYMBOL_kernel = 150,                   /* kernel  */
  YYSYMBOL_class = 151,                    /* class  */
  YYSYMBOL_nt1 = 152,                      /* nt1  */
  YYSYMBOL_nt2 = 153,                      /* nt2  */
  YYSYMBOL_nt4 = 154,                      /* nt4  */
  YYSYMBOL_nt8 = 155,                      /* nt8  */
  YYSYMBOL_nt16 = 156,                     /* nt16  */
  YYSYMBOL_const = 157,                    /* const  */
  YYSYMBOL_restrict = 158,                 /* restrict  */
  YYSYMBOL_volatile = 159,                 /* volatile  */
  YYSYMBOL_bool = 160,                     /* bool  */
  YYSYMBOL_char = 161,                     /* char  */
  YYSYMBOL_short = 162,                    /* short  */
  YYSYMBOL_int = 163,                      /* int  */
  YYSYMBOL_long = 164,                     /* long  */
  YYSYMBOL_signed = 165,                   /* signed  */
  YYSYMBOL_unsigned = 166,                 /* unsigned  */
  YYSYMBOL_float = 167,                    /* float  */
  YYSYMBOL_float2 = 168,                   /* float2  */
  YYSYMBOL_float4 = 169,                   /* float4  */
  YYSYMBOL_float8 = 170,                   /* float8  */
  YYSYMBOL_float16 = 171,                  /* float16  */
  YYSYMBOL_double = 172,                   /* double  */
  YYSYMBOL_void = 173,                     /* void  */
  YYSYMBOL_result = 174,                   /* result  */
  YYSYMBOL_complex = 175,                  /* complex  */
  YYSYMBOL_imaginary = 176,                /* imaginary  */
  YYSYMBOL_struct = 177,                   /* struct  */
  YYSYMBOL_union = 178,                    /* union  */
  YYSYMBOL_enum = 179,                     /* enum  */
  YYSYMBOL_ellipsis = 180,                 /* ellipsis  */
  YYSYMBOL_case = 181,                     /* case  */
  YYSYMBOL_default = 182,                  /* default  */
  YYSYMBOL_if = 183,                       /* if  */
  YYSYMBOL_else = 184,                     /* else  */
  YYSYMBOL_switch = 185,                   /* switch  */
  YYSYMBOL_while = 186,                    /* while  */
  YYSYMBOL_do = 187,                       /* do  */
  YYSYMBOL_for = 188,                      /* for  */
  YYSYMBOL_goto = 189,                     /* goto  */
  YYSYMBOL_continue = 190,                 /* continue  */
  YYSYMBOL_break = 191,                    /* break  */
  YYSYMBOL_return = 192,                   /* return  */
  YYSYMBOL_alignas = 193,                  /* alignas  */
  YYSYMBOL_alignof = 194,                  /* alignof  */
  YYSYMBOL_atomic = 195,                   /* atomic  */
  YYSYMBOL_generic = 196,                  /* generic  */
  YYSYMBOL_noreturn = 197,                 /* noreturn  */
  YYSYMBOL_static_assert = 198,            /* static_assert  */
  YYSYMBOL_share = 199,                    /* share  */
  YYSYMBOL_global = 200,                   /* global  */
  YYSYMBOL_primary_expression = 201,       /* primary_expression  */
  YYSYMBOL_constant = 202,                 /* constant  */
  YYSYMBOL_enumeration_constant = 203,     /* enumeration_constant  */
  YYSYMBOL_string = 204,                   /* string  */
  YYSYMBOL_generic_selection = 205,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 206,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 207,      /* generic_association  */
  YYSYMBOL_postfix_expression = 208,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 209, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 210,         /* unary_expression  */
  YYSYMBOL_unary_operator = 211,           /* unary_operator  */
  YYSYMBOL_cast_expression = 212,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 213, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 214,      /* additive_expression  */
  YYSYMBOL_shift_expression = 215,         /* shift_expression  */
  YYSYMBOL_relational_expression = 216,    /* relational_expression  */
  YYSYMBOL_equality_expression = 217,      /* equality_expression  */
  YYSYMBOL_and_expression = 218,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 219,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 220,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 221,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 222,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 223,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 224,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 225,      /* assignment_operator  */
  YYSYMBOL_expression = 226,               /* expression  */
  YYSYMBOL_constant_expression = 227,      /* constant_expression  */
  YYSYMBOL_declaration = 228,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 229,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 230,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 231,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 232,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 233,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 234, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 235,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 236,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 237,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 238, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 239,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 240,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 241,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 242,          /* enumerator_list  */
  YYSYMBOL_enumerator = 243,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 244,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 245,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 246,       /* function_specifier  */
  YYSYMBOL_class_specifier = 247,          /* class_specifier  */
  YYSYMBOL_alignment_specifier = 248,      /* alignment_specifier  */
  YYSYMBOL_declarator = 249,               /* declarator  */
  YYSYMBOL_direct_declarator = 250,        /* direct_declarator  */
  YYSYMBOL_pointer = 251,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 252,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 253,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 254,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 255,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 256,          /* identifier_list  */
  YYSYMBOL_type_name = 257,                /* type_name  */
  YYSYMBOL_abstract_declarator = 258,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 259, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 260,              /* initializer  */
  YYSYMBOL_initializer_list = 261,         /* initializer_list  */
  YYSYMBOL_designation = 262,              /* designation  */
  YYSYMBOL_designator_list = 263,          /* designator_list  */
  YYSYMBOL_designator = 264,               /* designator  */
  YYSYMBOL_static_assert_declaration = 265, /* static_assert_declaration  */
  YYSYMBOL_statement = 266,                /* statement  */
  YYSYMBOL_labeled_statement = 267,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 268,       /* compound_statement  */
  YYSYMBOL_block_item_list = 269,          /* block_item_list  */
  YYSYMBOL_block_item = 270,               /* block_item  */
  YYSYMBOL_expression_statement = 271,     /* expression_statement  */
  YYSYMBOL_selection_statement = 272,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 273,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 274,           /* jump_statement  */
  YYSYMBOL_translation_unit = 275,         /* translation_unit  */
  YYSYMBOL_external_declaration = 276,     /* external_declaration  */
  YYSYMBOL_class_name = 277,               /* class_name  */
  YYSYMBOL_class_declaration_list = 278,   /* class_declaration_list  */
  YYSYMBOL_class_declaration = 279,        /* class_declaration  */
  YYSYMBOL_function_definition = 280,      /* function_definition  */
  YYSYMBOL_declaration_list = 281,         /* declaration_list  */
  YYSYMBOL_pointer_scope = 282,            /* pointer_scope  */
  YYSYMBOL_pointer_scope_list = 283        /* pointer_scope_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  129
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2883

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  170
/* YYNRULES -- Number of rules.  */
#define YYNRULES  383
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  595

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   344


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   104,     2,     2,     2,   106,    99,     2,
      90,    91,   100,   101,    92,   102,    96,   105,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,   113,
     107,   112,   108,   111,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,   109,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,   110,    98,   103,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   153,   154,
     155,   156,   157,   161,   162,   163,   167,   171,   172,   176,
     180,   181,   185,   186,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   203,   204,   208,   209,   210,   211,
     212,   213,   214,   218,   219,   220,   221,   222,   223,   227,
     228,   232,   233,   234,   235,   239,   240,   241,   245,   246,
     247,   251,   252,   253,   254,   255,   259,   260,   261,   265,
     266,   270,   271,   275,   276,   280,   281,   285,   286,   290,
     291,   295,   296,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   315,   319,   323,   324,   325,
     326,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   343,   344,   348,   349,   353,   354,   355,   356,   357,
     358,   359,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   388,   389,   390,   394,   395,   399,
     400,   404,   405,   406,   410,   411,   412,   413,   417,   418,
     422,   423,   424,   428,   429,   430,   431,   432,   436,   437,
     441,   442,   446,   450,   451,   452,   453,   457,   458,   459,
     463,   464,   465,   466,   467,   471,   472,   476,   477,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   498,   499,   500,   501,   505,   506,   511,
     512,   516,   517,   521,   522,   523,   527,   528,   532,   533,
     537,   538,   539,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   567,   568,   569,   573,   574,   575,
     576,   580,   584,   585,   589,   590,   594,   598,   599,   600,
     601,   602,   603,   607,   608,   609,   613,   614,   618,   619,
     623,   624,   628,   629,   633,   634,   635,   639,   640,   641,
     642,   643,   644,   648,   649,   650,   651,   652,   656,   657,
     661,   662,   666,   670,   671,   675,   679,   680,   683,   684,
     687,   688,   692,   693
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME", "ENUM_CONSTANT",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE", "KERNEL",
  "CLASS", "NT1", "NT2", "NT4", "NT8", "NT16", "CONST", "RESTRICT",
  "VOLATILE", "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "FLOAT2", "FLOAT4", "FLOAT8", "FLOAT16", "DOUBLE", "VOID",
  "RESULT", "POINTER_SCOPE", "COMPLEX", "IMAGINARY", "STRUCT", "UNION",
  "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "SHARE", "GLOBAL",
  "'('", "')'", "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'?'", "'='", "';'", "$accept", "identifier", "i_constant",
  "f_constant", "string_literal", "func_name", "sizeof", "ptr_op",
  "inc_op", "dec_op", "left_op", "right_op", "le_op", "ge_op", "eq_op",
  "ne_op", "and_op", "or_op", "mul_assign", "div_assign", "mod_assign",
  "add_assign", "sub_assign", "left_assign", "right_assign", "and_assign",
  "xor_assign", "or_assign", "typedef_name", "enum_constant", "typedef",
  "extern", "static", "auto", "register", "inline", "kernel", "class",
  "nt1", "nt2", "nt4", "nt8", "nt16", "const", "restrict", "volatile",
  "bool", "char", "short", "int", "long", "signed", "unsigned", "float",
  "float2", "float4", "float8", "float16", "double", "void", "result",
  "complex", "imaginary", "struct", "union", "enum", "ellipsis", "case",
  "default", "if", "else", "switch", "while", "do", "for", "goto",
  "continue", "break", "return", "alignas", "alignof", "atomic", "generic",
  "noreturn", "static_assert", "share", "global", "primary_expression",
  "constant", "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "class_specifier", "alignment_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "class_name", "class_declaration_list", "class_declaration",
  "function_definition", "declaration_list", "pointer_scope",
  "pointer_scope_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-489)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2551,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,   -60,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,    38,
     -35,   -26,  -489,   -24,  -489,  -489,  -489,    49,  2671,  2671,
    -489,    51,  -489,  -489,  2671,  2671,    -3,  2671,  -489,  2060,
    -489,  -489,  -489,  -489,    72,  -489,    72,    -9,  1071,  2799,
    1866,    60,   174,  -489,  -489,   -71,  -489,  2186,   112,    65,
    -489,  -489,  2716,    -7,  -489,  -489,  -489,    72,  -489,  -489,
    -489,  -489,   -62,  -489,   -17,   -27,  -489,    72,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  1071,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    1888,  1910,  1910,  -489,   -13,    92,  -489,  -489,  -489,  -489,
     250,  -489,  1866,  -489,   -20,   102,   221,   157,   225,   115,
      83,   101,   199,    32,  -489,   133,  2799,    99,  2799,   137,
     140,   143,   156,  -489,  -489,  -489,   174,    60,  -489,   693,
     400,  -489,    49,  -489,  2425,  2126,  1173,   112,  2311,  -489,
      64,  -489,  2716,  -489,  -489,   -63,    72,  -489,  1866,    31,
    -489,    86,   512,  -489,  -489,   153,   159,  1071,  -489,  1071,
    -489,  -489,  2799,  1866,  -489,  1005,  1866,    72,    72,  -489,
    -489,  -489,  1866,  1866,  1866,  1866,  1866,  -489,  -489,  1866,
    1866,  -489,  -489,  1866,  1866,  1866,  1866,  -489,  -489,  1866,
    1866,  1866,  1866,  1866,  -489,  1866,  -489,  1866,  1866,  -489,
    -489,  2254,  1195,   119,  -489,   122,  -489,  -489,  -489,   246,
    -489,  -489,  -489,  -489,   145,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,   162,  1866,
     179,   185,   187,   197,   578,   210,    72,   194,   196,   513,
     -57,  -489,  -489,  -489,  -489,   797,  -489,  -489,  -489,  -489,
    -489,  1698,  -489,  -489,  -489,  -489,  -489,  -489,    79,   223,
     227,  -489,   202,  -489,   230,  1545,   244,  1297,  -489,  -489,
    1866,  -489,   -54,  -489,   249,  2366,    72,  -489,  -489,  -489,
    -489,  -489,    34,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  1866,  -489,  1866,  1720,   254,
     256,   260,   273,  -489,   211,  -489,    88,  -489,  -489,  -489,
    -489,  -489,   -20,   -20,   102,   102,   221,   221,   221,   221,
     157,   157,   225,   115,    83,   101,   213,   199,  -489,   278,
     291,  -489,   288,  1545,   295,  1319,   122,  2491,  1421,   300,
     578,   301,   578,  1866,  1866,  1866,   321,   901,   284,  -489,
    -489,  -489,   -39,  -489,  -489,  -489,  1866,    72,  -489,    93,
     400,   -34,  -489,  1991,  -489,   172,  -489,  -489,  2611,  -489,
      72,  -489,   303,  1545,  -489,  -489,   304,  1866,   306,  -489,
      21,  -489,  1866,  -489,  -489,  -489,  -489,  -489,  1698,  -489,
     305,   305,  -489,  2759,  -489,  1866,  -489,  1866,  -489,  -489,
    -489,   314,  1545,  -489,  -489,  1866,   317,  -489,   322,  -489,
     320,  1545,   323,  1443,   307,  -489,   578,  -489,   220,   232,
     237,   326,   967,   967,  -489,  -489,   324,  -489,  1567,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,   328,  -489,
     329,  -489,  -489,  -489,   109,   332,   239,  -489,   334,  -489,
    -489,  -489,   333,   335,  -489,  -489,  -489,   337,  1545,  -489,
    -489,  1866,   339,  -489,  -489,   578,   578,   578,  1866,  1742,
    1844,  -489,  -489,  -489,   400,  -489,  -489,  1596,  -489,  1866,
    -489,  2759,  1866,  -489,  -489,  -489,   340,   341,  -489,   348,
    -489,  -489,   245,   578,   258,   578,   265,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,   578,   316,  -489,   578,  -489,
     578,  -489,  -489,  -489,  -489
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    29,    31,    32,    33,    34,    35,    36,    37,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   381,    62,    63,    64,    65,    66,    80,    82,
      84,    85,    86,    87,   221,   195,   196,   197,   200,   201,
     257,   258,   260,   261,   262,   263,   264,   253,   254,   255,
     215,   203,   204,   205,   206,   213,   214,   207,   208,   209,
     210,   211,   212,   202,   222,   216,   217,   227,   228,     0,
       0,   256,   259,     0,   198,   199,   371,     0,   182,   184,
     219,     0,   220,   218,   186,   188,     0,   190,   179,     0,
     368,   180,   370,   223,     0,     2,     0,   247,     0,     0,
       0,     0,   286,   177,   269,     0,   191,   194,   268,     0,
     181,   183,     0,   226,   185,   187,    38,     0,   189,     1,
     369,   382,     0,    96,   251,     0,   248,     0,     3,     4,
       5,     6,     7,     9,    10,    30,    81,    83,     0,   123,
     124,   125,   126,   127,   128,    88,    93,    94,    97,    98,
       0,     0,     0,    95,     0,     0,   104,    89,    90,    92,
     116,   129,     0,   131,   135,   138,   141,   146,   149,   151,
     153,   155,   157,   159,   176,     0,   235,   299,   237,     0,
       0,     0,     0,   256,   287,   285,   284,     0,   178,     0,
       0,   378,     0,   377,     0,     0,     0,   267,     0,   229,
       0,   233,     0,   372,   373,     0,     0,   380,     0,     0,
     243,     0,   129,   161,   174,     0,     0,     0,   120,     0,
     117,   118,     0,     0,     8,     0,     0,     0,     0,   110,
     111,   119,     0,     0,     0,     0,     0,    11,    12,     0,
       0,    13,    14,     0,     0,     0,     0,    15,    16,     0,
       0,     0,     0,     0,    17,     0,    18,     0,     0,   266,
     234,     0,     0,   301,   298,   302,   236,   265,   252,     0,
     270,   288,   283,   192,   194,    68,    69,    70,    72,    73,
      74,    75,    76,    77,    78,    79,   346,   352,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   350,   351,   337,   338,     0,   348,   339,   340,   341,
     342,     0,   326,   193,   379,   376,   281,   296,   295,     0,
     290,   291,     0,   271,   124,     0,     0,     0,   224,   230,
       0,   231,     0,   238,   242,     0,     0,   375,   383,   250,
     244,   249,     0,   245,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,    91,     0,     0,     0,
       0,     0,     0,   106,     0,   114,     0,   108,   109,   132,
     133,   134,   136,   137,   139,   140,   142,   143,   144,   145,
     147,   148,   150,   152,   154,   156,     0,   158,   320,     0,
       0,   304,   124,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   364,
     365,   366,     0,   353,   347,   349,     0,     0,   328,     0,
       0,     0,   332,     0,   293,   301,   294,   280,     0,   282,
       0,   272,     0,     0,   279,   278,   124,     0,     0,   240,
       0,   232,     0,   225,   374,   246,   162,   175,     0,   130,
     121,     0,   122,     0,   107,     0,   105,     0,   321,   303,
     305,     0,     0,   311,   310,     0,     0,   322,     0,   312,
     124,     0,     0,     0,     0,   343,     0,   345,     0,     0,
       0,     0,     0,     0,   363,   367,     0,   335,     0,   324,
     327,   331,   333,    67,   289,   292,   297,   274,     0,   275,
       0,   277,   239,   241,     0,     0,     0,   100,     0,   115,
     160,   307,     0,     0,   309,   323,   313,     0,     0,   319,
     318,     0,     0,   336,   344,     0,     0,     0,     0,     0,
       0,   334,   325,   330,     0,   273,   276,     0,   112,     0,
      99,     0,     0,   306,   308,   315,     0,     0,   316,   355,
     356,   357,     0,     0,     0,     0,     0,   329,   113,   103,
     101,   102,   314,   317,    71,     0,     0,   361,     0,   359,
       0,   354,   358,   362,   360
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -489,   -79,  -489,  -489,   158,  -489,  -489,  -489,   268,   269,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -167,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -400,  -489,
    -489,  -489,    18,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,   -98,  -489,  -489,  -489,  -489,  -489,  -489,  -489,  -489,
    -489,  -489,  -489,  -115,  -489,  -489,    36,  -489,   -56,   117,
     123,    15,   120,   184,   188,   186,   182,   183,  -489,   -77,
     154,  -489,   -91,   -84,   -89,     5,  -489,   255,  -489,   -99,
    -489,  -489,   242,  -192,  -116,  -489,    -5,  -489,   327,  -200,
    -489,  -105,  -489,  -489,  -489,   -85,  -118,   -90,  -130,  -194,
    -489,    12,  -489,   -64,  -172,  -255,  -187,     2,  -488,  -489,
      20,   -61,  -104,  -489,   -38,  -489,   148,  -308,  -489,  -489,
    -489,  -489,   366,   127,  -489,  -489,  -489,  -489,  -489,  -489
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   155,   156,   157,   158,   159,   160,   238,   161,   162,
     249,   250,   255,   256,   259,   260,   265,   268,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,    44,   163,
      45,    46,    47,    48,    49,    50,    51,   127,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   514,   299,   300,   301,
     585,   302,   303,   304,   305,   306,   307,   308,   309,    80,
     164,    81,   165,    82,    83,    84,    85,   166,   167,   134,
     168,   169,   526,   527,   170,   384,   222,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   223,
     224,   375,   310,   185,    86,   202,   115,   116,    88,    89,
      90,    91,   208,   209,   187,   342,   343,    92,   135,   136,
      93,    94,    95,    96,    97,   192,   118,   119,   196,   409,
     330,   331,   332,   528,   410,   275,   438,   439,   440,   441,
     442,    98,   312,   313,   314,   315,   316,   317,   318,   319,
     320,    99,   100,   214,   215,   101,   102,   204,   103,   132
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   207,   117,   188,   188,    87,   210,   194,   114,   186,
     186,   329,   123,   323,   193,   274,   339,   188,   416,   351,
     554,   197,   195,   186,   105,   131,   191,   133,   201,   346,
     216,   184,   114,   184,   105,   377,   126,   105,   460,   335,
     114,   105,   198,   188,   189,   190,   217,   104,   213,   186,
     347,   266,   105,   377,   105,   108,   433,   225,   133,   461,
     436,   211,   437,   105,   109,   219,   110,   105,   105,   554,
     270,   220,   276,   525,   505,   105,   337,   232,   511,   203,
     242,   188,   105,   188,   226,   243,   244,   186,   137,   186,
     212,   281,   210,   120,   121,   218,   210,   273,   193,   124,
     125,   194,   128,   188,    87,   413,   282,   188,   193,   186,
     311,   111,   284,   186,   340,   324,   241,   284,   114,   503,
     298,   112,   188,   114,   188,   344,   327,   188,   186,   350,
     186,   114,   465,   186,   349,   106,   225,   348,   225,   111,
     133,   184,   415,   267,   171,   386,   171,   211,   122,   112,
     111,   211,   351,   339,   111,   111,   446,   340,   387,   388,
     112,   525,   113,   379,   112,   380,   325,   194,   381,   443,
     457,   251,   252,   272,   193,   105,   406,   341,   352,   112,
     377,   273,   233,   476,   353,   508,   389,   390,   391,   271,
     416,   509,   262,   272,   549,   550,   228,   230,   231,   112,
     426,   557,   205,   245,   246,   453,   206,   558,   171,   271,
     328,   263,   417,   272,   261,   421,   418,   264,   432,    14,
      15,    16,   184,   488,   269,   298,   311,   428,   277,   210,
     194,   278,   281,   247,   248,   279,   298,   193,   445,   193,
     188,   257,   258,   444,   376,   377,   186,   280,   485,   114,
     378,   491,   140,   510,   171,   420,   459,   200,    39,   234,
     143,   144,   443,   184,   253,   254,   272,   213,   396,   397,
     398,   399,   422,   133,   112,   423,   328,   424,   171,   171,
     171,   171,   171,   482,   211,   171,   171,   425,   493,   171,
     171,   171,   171,   449,   450,   171,   171,   171,   171,   171,
     427,   171,   474,   475,   171,   377,   477,   429,   194,   430,
     281,   545,   377,   194,   447,   193,   495,   193,   497,   448,
     193,   553,   469,   546,   377,   451,   541,   207,   547,   377,
     560,   561,   498,   499,   500,   171,   586,   377,   502,   454,
     235,   298,   462,   298,   236,   470,   237,   471,   281,   588,
     377,   472,   506,   445,   322,   193,   590,   377,   507,   184,
     336,   538,   392,   393,   114,   473,   114,   577,   188,   478,
     553,   516,   394,   395,   186,   344,   171,   281,   523,   400,
     401,   114,   479,   480,   193,   184,   194,   382,   281,   385,
     483,   494,   544,   193,   496,   193,   289,   504,   517,   519,
     530,   521,   468,   105,   138,   139,   140,   141,   142,   531,
     143,   144,   534,   535,   171,   536,   548,   298,   539,   551,
     543,   584,   328,   555,   556,   559,   414,   562,   563,   592,
     564,   145,   565,   281,   568,   582,   583,   419,   239,   240,
     193,   569,   570,   571,   501,   402,   580,   405,   328,   404,
     403,   407,   283,   328,   345,   522,   188,   572,   574,   576,
     515,   512,   186,   435,   221,   130,   298,   298,   298,   587,
     524,   589,   171,   464,     0,   322,     0,     0,     0,     0,
       0,   591,     0,   146,   593,   147,   594,     0,     0,   452,
     148,   458,     0,     0,   298,     0,   298,   321,   171,   149,
     150,   151,   152,   153,   154,     0,   298,     0,     0,   298,
       0,   298,     0,   171,     0,     0,   105,   138,   139,   140,
     141,   142,     0,   143,   144,     0,     0,     0,     0,   466,
       0,   467,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,     0,     0,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,     0,   486,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   138,   139,   140,   141,   142,     0,   143,   144,
       0,     0,     0,     0,   322,     0,   146,     0,   147,     0,
       0,     0,     0,   148,     0,     0,     0,   518,     0,   145,
       0,   520,   149,   150,   151,   152,   153,   154,     0,     0,
       0,     0,   322,     0,   364,     0,   431,     0,     0,   529,
       0,     0,     0,     0,     0,     0,   532,     0,     0,   533,
       0,     0,     0,     0,     0,   537,     0,   542,   285,   286,
     287,     0,   288,   289,   290,   291,   292,   293,   294,   295,
       0,   146,   322,   147,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   199,     0,   149,   150,   151,
     152,   153,   154,     0,     0,     0,     0,     0,     0,     0,
       0,   297,   566,     0,     0,   567,   105,   138,   139,   140,
     141,   142,     0,   143,   144,     0,     0,     0,   322,     0,
       0,   322,     0,   579,     0,     0,   581,     0,     0,     0,
       0,     0,     0,     1,   145,     2,     3,     4,     5,     6,
       7,     8,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     0,   285,   286,   287,     0,   288,   289,   290,
     291,   292,   293,   294,   295,    38,   146,    39,   147,    40,
      41,    42,    43,   148,     0,     0,     0,     0,     0,     0,
     199,   296,   149,   150,   151,   152,   153,   154,     0,     0,
     105,   138,   139,   140,   141,   142,   297,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,   145,     2,
       3,     4,     5,     6,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     0,   285,   286,   287,
       0,   288,   289,   290,   291,   292,   293,   294,   295,    38,
     146,    39,   147,    40,    41,    42,    43,   148,     0,     0,
       0,     0,     0,     0,   199,   434,   149,   150,   151,   152,
     153,   154,     0,     0,   105,   138,   139,   140,   141,   142,
     297,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   145,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     105,   138,   139,   140,   141,   142,     0,   143,   144,     0,
       0,     0,     0,    38,   146,    39,   147,    40,    41,    42,
      43,   148,     0,     0,     0,     0,     0,     0,   145,     0,
     149,   150,   151,   152,   153,   154,     0,     0,   105,   138,
     139,   140,   141,   142,   297,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,   147,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   151,   152,
     153,   154,     0,     0,   105,   138,   139,   140,   141,   142,
     297,   143,   144,     0,     0,     0,     0,     0,   146,     0,
     147,     0,     0,     0,     0,   148,   383,     0,     0,     0,
       0,     1,   145,     0,   149,   150,   151,   152,   153,   154,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,    39,   147,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   150,   151,   152,   153,   154,   105,   138,   139,   140,
     141,   142,     0,   143,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   105,   138,
     139,   140,   141,   142,   145,   143,   144,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
      16,     0,     0,     0,     0,     0,   145,     0,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,    39,   147,     0,
       0,     0,     0,   148,     0,     0,     0,     0,   333,     0,
       0,     0,   149,   334,   151,   152,   153,   154,   146,    39,
     147,     0,     0,     0,     0,   148,     0,     0,     0,     0,
     411,     0,     0,     0,   149,   412,   151,   152,   153,   154,
     105,   138,   139,   140,   141,   142,     0,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,   138,   139,   140,   141,   142,   145,   143,
     144,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,    16,     0,     0,     0,     0,     0,
     145,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,    39,   147,     0,     0,     0,     0,   148,     0,     0,
       0,     0,   455,     0,     0,     0,   149,   456,   151,   152,
     153,   154,   146,    39,   147,     0,     0,     0,     0,   148,
       0,     0,     0,     0,   484,     0,     0,     0,   149,   150,
     151,   152,   153,   154,   105,   138,   139,   140,   141,   142,
       0,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   138,   139,   140,
     141,   142,   145,   143,   144,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,   145,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,    39,   147,     0,     0,     0,
       0,   148,     0,     0,     0,     0,   489,     0,     0,     0,
     149,   490,   151,   152,   153,   154,   146,    39,   147,     0,
       0,     0,     0,   148,     0,     0,     0,     0,   540,     0,
       0,     0,   149,   150,   151,   152,   153,   154,   105,   138,
     139,   140,   141,   142,     0,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   138,   139,   140,   141,   142,   145,   143,   144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,     0,     0,     0,     0,     0,   145,   105,
     138,   139,   140,   141,   142,     0,   143,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,   146,    39,
     147,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   149,   150,   151,   152,   153,   154,
     146,     0,   147,     0,     0,     0,     0,   148,     0,     0,
       0,   436,     0,   437,   321,   552,   149,   150,   151,   152,
     153,   154,     0,     0,     0,     0,     0,     0,     0,   146,
       0,   147,     0,     0,     0,     0,   148,     0,     0,     0,
     436,     0,   437,   321,   578,   149,   150,   151,   152,   153,
     154,   105,   138,   139,   140,   141,   142,     0,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   138,   139,   140,   141,   142,   145,
     143,   144,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,   138,   139,   140,   141,
     142,   145,   143,   144,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,     0,     0,     0,
       0,   146,     0,   147,     0,     0,     0,     0,   148,     0,
       0,     0,   436,     0,   437,   321,     0,   149,   150,   151,
     152,   153,   154,   146,     0,   147,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   468,     0,   149,
     150,   151,   152,   153,   154,   146,     0,   147,     0,     0,
       0,     0,   148,   573,     0,     0,     0,     0,     0,     0,
       0,   149,   150,   151,   152,   153,   154,   105,   138,   139,
     140,   141,   142,     0,   143,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
     138,   139,   140,   141,   142,   145,   143,   144,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,   138,   139,   140,   141,   142,   145,   143,   144,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,   138,   139,   140,   141,   142,   145,
     143,   144,     0,     0,     0,     0,     0,   146,     0,   147,
       0,     0,     0,     0,   148,   575,     0,     0,     0,     0,
       0,   145,     0,   149,   150,   151,   152,   153,   154,   146,
       0,   147,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,   152,   153,
     154,   146,     0,   147,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   146,   105,   147,     0,     0,     0,     0,
     229,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,   151,   152,   153,   154,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,    42,
      43,   443,   408,     0,     0,   272,     0,     0,     0,     0,
       1,   112,     2,     3,     4,     5,     6,     7,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    39,     0,    40,    41,    42,    43,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
      39,     0,    40,     0,    42,    43,     1,   326,     2,     3,
       4,     5,     6,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
      39,     0,    40,    41,    42,    43,     0,     0,     0,     0,
       0,     0,     0,   199,     1,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     0,   200,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    39,     0,
      40,     1,    42,    43,   271,   408,     0,     0,   272,     0,
       0,     0,     0,     0,   112,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     1,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   338,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    41,     0,     1,     0,     2,     3,     4,
       5,     6,     7,     8,   463,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    39,
       0,    40,    41,    42,    43,     0,     0,     0,     0,     0,
       0,     1,   199,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,    42,
      43,     1,   487,     2,     3,     4,     5,     6,     7,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,    41,    42,
      43,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
     513,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,    42,
      43,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     0,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,    38,     0,    39,     0,    40,     0,    42,
      43,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,    41,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,     1,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39
};

static const yytype_int16 yycheck[] =
{
      79,   119,    87,   108,   109,     0,   122,   112,    87,   108,
     109,   205,    91,   200,   112,   187,   208,   122,   273,   219,
     508,    92,   112,   122,     3,   104,   110,   106,   117,    92,
      92,   108,   111,   110,     3,    92,    39,     3,    92,   206,
     119,     3,   113,   148,   108,   109,   108,   107,   127,   148,
     113,    19,     3,    92,     3,    90,   113,   148,   137,   113,
      94,   122,    96,     3,    90,    92,    90,     3,     3,   557,
     186,    98,   188,   473,   113,     3,   206,    90,   112,   117,
     100,   186,     3,   188,   148,   105,   106,   186,    97,   188,
      97,   196,   208,    88,    89,   112,   212,   187,   196,    94,
      95,   206,    97,   208,    99,   272,   196,   212,   206,   208,
     199,    90,   197,   212,    93,   204,   172,   202,   197,   427,
     199,   100,   227,   202,   229,   210,   205,   232,   227,    98,
     229,   210,    98,   232,   218,    97,   227,   216,   229,    90,
     219,   218,   272,   111,   108,   236,   110,   208,    97,   100,
      90,   212,   352,   345,    90,    90,   328,    93,   237,   238,
     100,   561,   113,   227,   100,   229,   204,   272,   232,    90,
     337,    14,    15,    94,   272,     3,   267,   113,    92,   100,
      92,   271,    90,    95,    98,    92,   242,   243,   244,    90,
     445,    98,   109,    94,   502,   503,   160,   161,   162,   100,
     304,    92,    90,   101,   102,   335,    94,    98,   172,    90,
     205,   110,    90,    94,    99,   299,    94,    18,   309,    45,
      46,    47,   299,   417,    91,   304,   315,   306,    91,   345,
     335,    91,   337,    12,    13,    92,   315,   335,   328,   337,
     345,    16,    17,   328,    91,    92,   345,    91,   415,   328,
      91,   418,     6,   440,   218,    93,   340,   112,    84,     9,
      10,    11,    90,   340,   107,   108,    94,   346,   253,   254,
     255,   256,    93,   352,   100,    90,   271,    90,   242,   243,
     244,   245,   246,   413,   345,   249,   250,    90,   418,   253,
     254,   255,   256,    91,    92,   259,   260,   261,   262,   263,
      90,   265,    91,    92,   268,    92,    93,   113,   413,   113,
     415,    91,    92,   418,    91,   413,   420,   415,   422,    92,
     418,   508,   378,    91,    92,    95,   493,   445,    91,    92,
      91,    92,   423,   424,   425,   299,    91,    92,   427,    95,
      90,   420,    93,   422,    94,    91,    96,    91,   453,    91,
      92,    91,   436,   443,   200,   453,    91,    92,   437,   436,
     206,   491,   245,   246,   443,    92,   445,   554,   473,    91,
     557,   450,   249,   250,   473,   460,   340,   482,   462,   259,
     260,   460,    91,    95,   482,   462,   491,   233,   493,   235,
      95,    91,   496,   491,    93,   493,    75,   113,    95,    95,
     477,    95,    97,     3,     4,     5,     6,     7,     8,    95,
      10,    11,    95,    91,   378,    95,    90,   496,    95,    95,
     113,    73,   417,    95,    95,    93,   272,    93,    95,   113,
      95,    31,    95,   538,    95,    95,    95,   279,   170,   170,
     538,   545,   546,   547,   426,   261,   561,   265,   443,   263,
     262,   268,   197,   448,   212,   460,   561,   548,   549,   550,
     448,   441,   561,   315,   137,    99,   545,   546,   547,   573,
     468,   575,   436,   346,    -1,   321,    -1,    -1,    -1,    -1,
      -1,   585,    -1,    83,   588,    85,   590,    -1,    -1,   335,
      90,   337,    -1,    -1,   573,    -1,   575,    97,   462,    99,
     100,   101,   102,   103,   104,    -1,   585,    -1,    -1,   588,
      -1,   590,    -1,   477,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,   375,
      -1,   377,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,   415,
      -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,   440,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,   453,    -1,    31,
      -1,   457,    99,   100,   101,   102,   103,   104,    -1,    -1,
      -1,    -1,   468,    -1,   112,    -1,   113,    -1,    -1,   475,
      -1,    -1,    -1,    -1,    -1,    -1,   482,    -1,    -1,   485,
      -1,    -1,    -1,    -1,    -1,   491,    -1,   493,    70,    71,
      72,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,   508,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    -1,    99,   100,   101,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   538,    -1,    -1,   541,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,   554,    -1,
      -1,   557,    -1,   559,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
       3,     4,     5,     6,     7,     8,   113,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,    72,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,     3,     4,     5,     6,     7,     8,
     113,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      99,   100,   101,   102,   103,   104,    -1,    -1,     3,     4,
       5,     6,     7,     8,   113,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,    -1,    -1,     3,     4,     5,     6,     7,     8,
     113,    10,    11,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    30,    31,    -1,    99,   100,   101,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    99,   100,   101,   102,   103,   104,    83,    84,
      85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,    83,    84,    85,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    99,   100,
     101,   102,   103,   104,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      99,   100,   101,   102,   103,   104,    83,    84,    85,    -1,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    99,   100,   101,   102,   103,   104,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    31,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    83,    84,
      85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,   104,
      83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    96,    97,    -1,    99,   100,   101,
     102,   103,   104,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    99,
     100,   101,   102,   103,   104,    83,    -1,    85,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,   103,   104,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    99,   100,   101,   102,   103,   104,    83,
      -1,    85,    -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,
     104,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,    83,     3,    85,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
     100,   101,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    90,    91,    -1,    -1,    94,    -1,    -1,    -1,    -1,
      30,   100,    32,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    -1,    86,    -1,    88,    89,    30,    91,    32,    33,
      34,    35,    36,    37,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,   112,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,    -1,
      86,    30,    88,    89,    90,    91,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    30,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    98,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    97,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    30,    91,    32,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    -1,    86,    87,    88,
      89,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    84,    -1,    86,    -1,    88,
      89,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    87,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    30,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    82,    84,
      86,    87,    88,    89,   142,   144,   145,   146,   147,   148,
     149,   150,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     193,   195,   197,   198,   199,   200,   228,   229,   232,   233,
     234,   235,   241,   244,   245,   246,   247,   248,   265,   275,
     276,   279,   280,   282,   107,     3,    97,   115,    90,    90,
      90,    90,   100,   113,   115,   230,   231,   249,   250,   251,
     229,   229,    97,   115,   229,   229,    39,   151,   229,     0,
     276,   115,   283,   115,   203,   242,   243,    97,     4,     5,
       6,     7,     8,    10,    11,    31,    83,    85,    90,    99,
     100,   101,   102,   103,   104,   115,   116,   117,   118,   119,
     120,   122,   123,   143,   194,   196,   201,   202,   204,   205,
     208,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   227,   233,   238,   245,   257,
     257,   227,   249,   195,   245,   251,   252,    92,   113,    97,
     112,   228,   229,   268,   281,    90,    94,   250,   236,   237,
     238,   265,    97,   115,   277,   278,    92,   108,   112,    92,
      98,   242,   210,   223,   224,   226,   257,    90,   210,    90,
     210,   210,    90,    90,     9,    90,    94,    96,   121,   122,
     123,   212,   100,   105,   106,   101,   102,    12,    13,   124,
     125,    14,    15,   107,   108,   126,   127,    16,    17,   128,
     129,    99,   109,   110,    18,   130,    19,   111,   131,    91,
     238,    90,    94,   251,   258,   259,   238,    91,    91,    92,
      91,   245,   251,   231,   249,    70,    71,    72,    74,    75,
      76,    77,    78,    79,    80,    81,    98,   113,   115,   181,
     182,   183,   185,   186,   187,   188,   189,   190,   191,   192,
     226,   228,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    97,   224,   260,   228,   268,    91,   115,   229,   253,
     254,   255,   256,    95,   100,   146,   224,   252,    98,   237,
      93,   113,   239,   240,   249,   236,    92,   113,   115,   227,
      98,   243,    92,    98,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   112,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   225,    91,    92,    91,   257,
     257,   257,   224,    91,   209,   224,   226,   115,   115,   212,
     212,   212,   213,   213,   214,   214,   215,   215,   215,   215,
     216,   216,   217,   218,   219,   220,   226,   221,    91,   253,
     258,    95,   100,   146,   224,   252,   259,    90,    94,   118,
      93,   227,    93,    90,    90,    90,   266,    90,   115,   113,
     113,   113,   226,   113,    98,   270,    94,    96,   260,   261,
     262,   263,   264,    90,   249,   251,   258,    91,    92,    91,
      92,    95,   224,   252,    95,    95,   100,   146,   224,   227,
      92,   113,    93,    98,   277,    98,   224,   224,    97,   212,
      91,    91,    91,    92,    91,    92,    95,    93,    91,    91,
      95,   224,   252,    95,    95,   146,   224,    91,   253,    95,
     100,   146,   224,   252,    91,   266,    93,   266,   226,   226,
     226,   186,   228,   271,   113,   113,   227,   115,    92,    98,
     260,   112,   264,    69,   180,   255,   115,    95,   224,    95,
     224,    95,   240,   227,   261,   182,   206,   207,   257,   224,
     223,    95,   224,   224,    95,    91,    95,   224,   252,    95,
      95,   146,   224,   113,   266,    91,    91,    91,    90,   271,
     271,    95,    98,   260,   262,    95,    95,    92,    98,    93,
      91,    92,    93,    95,    95,    95,   224,   224,    95,   266,
     266,   266,   226,    91,   226,    91,   226,   260,    98,   224,
     207,   224,    95,    95,    73,   184,    91,   266,    91,   266,
      91,   266,   113,   266,   266
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   201,
     201,   201,   201,   202,   202,   202,   203,   204,   204,   205,
     206,   206,   207,   207,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   211,   211,   212,
     212,   213,   213,   213,   213,   214,   214,   214,   215,   215,
     215,   216,   216,   216,   216,   216,   217,   217,   217,   218,
     218,   219,   219,   220,   220,   221,   221,   222,   222,   223,
     223,   224,   224,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   226,   226,   227,   228,   228,   228,
     228,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   230,   230,   231,   231,   232,   232,   232,   232,   232,
     232,   232,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   234,   234,   234,   235,   235,   236,
     236,   237,   237,   237,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   244,   245,   245,   245,   245,   246,   246,   246,
     247,   247,   247,   247,   247,   248,   248,   249,   249,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   251,   251,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   255,   256,   256,   257,   257,
     258,   258,   258,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   260,   260,   260,   261,   261,   261,
     261,   262,   263,   263,   264,   264,   265,   266,   266,   266,
     266,   266,   266,   267,   267,   267,   268,   268,   269,   269,
     270,   270,   271,   271,   272,   272,   272,   273,   273,   273,
     273,   273,   273,   274,   274,   274,   274,   274,   275,   275,
     276,   276,   277,   278,   278,   279,   280,   280,   281,   281,
     282,   282,   283,   283
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     6,
       1,     3,     3,     3,     1,     4,     3,     4,     3,     3,
       2,     2,     6,     7,     1,     3,     1,     2,     2,     2,
       2,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     1,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     2,     1,     1,     1,
       2,     2,     3,     1,     2,     1,     2,     1,     1,     3,
       2,     3,     1,     4,     5,     5,     6,     2,     1,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     4,
       3,     2,     1,     2,     3,     2,     7,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       1,     1,     1,     2,     7,     5,     5,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     1,     1,     3,     4,     4,     3,     1,     2,
       4,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* identifier: IDENTIFIER  */
#line 65 "Parser.y"
                        {(yyval.a)=ast_newidentifier(eTOKEN_IDENTIFIER,yytext);}
#line 2301 "Parser.tab.c"
    break;

  case 3: /* i_constant: I_CONSTANT  */
#line 66 "Parser.y"
                        {(yyval.a)=ast_newint(eTOKEN_I_CONSTANT,yytext);}
#line 2307 "Parser.tab.c"
    break;

  case 4: /* f_constant: F_CONSTANT  */
#line 67 "Parser.y"
                        {(yyval.a)=ast_newfloat(eTOKEN_F_CONSTANT,yytext);}
#line 2313 "Parser.tab.c"
    break;

  case 5: /* string_literal: STRING_LITERAL  */
#line 68 "Parser.y"
                                {(yyval.a)=ast_newstring(eTOKEN_STRING_LITERAL,yytext);}
#line 2319 "Parser.tab.c"
    break;

  case 6: /* func_name: FUNC_NAME  */
#line 69 "Parser.y"
                       {(yyval.a)=ast_newtoken(eTOKEN_FUNC_NAME,0);}
#line 2325 "Parser.tab.c"
    break;

  case 7: /* sizeof: SIZEOF  */
#line 70 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_SIZEOF,0);}
#line 2331 "Parser.tab.c"
    break;

  case 8: /* ptr_op: PTR_OP  */
#line 71 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_PTR_OP,0);}
#line 2337 "Parser.tab.c"
    break;

  case 9: /* inc_op: INC_OP  */
#line 72 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_INC_OP,0);}
#line 2343 "Parser.tab.c"
    break;

  case 10: /* dec_op: DEC_OP  */
#line 73 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_DEC_OP,0);}
#line 2349 "Parser.tab.c"
    break;

  case 11: /* left_op: LEFT_OP  */
#line 74 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_LEFT_OP,0);}
#line 2355 "Parser.tab.c"
    break;

  case 12: /* right_op: RIGHT_OP  */
#line 75 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_RIGHT_OP,0);}
#line 2361 "Parser.tab.c"
    break;

  case 13: /* le_op: LE_OP  */
#line 76 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_LE_OP,0);}
#line 2367 "Parser.tab.c"
    break;

  case 14: /* ge_op: GE_OP  */
#line 77 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_GE_OP,0);}
#line 2373 "Parser.tab.c"
    break;

  case 15: /* eq_op: EQ_OP  */
#line 78 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_EQ_OP,0);}
#line 2379 "Parser.tab.c"
    break;

  case 16: /* ne_op: NE_OP  */
#line 79 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_NE_OP,0);}
#line 2385 "Parser.tab.c"
    break;

  case 17: /* and_op: AND_OP  */
#line 80 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_AND_OP,0);}
#line 2391 "Parser.tab.c"
    break;

  case 18: /* or_op: OR_OP  */
#line 81 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_OR_OP,0);}
#line 2397 "Parser.tab.c"
    break;

  case 19: /* mul_assign: MUL_ASSIGN  */
#line 82 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_MUL_ASSIGN,0);}
#line 2403 "Parser.tab.c"
    break;

  case 20: /* div_assign: DIV_ASSIGN  */
#line 83 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_DIV_ASSIGN,0);}
#line 2409 "Parser.tab.c"
    break;

  case 21: /* mod_assign: MOD_ASSIGN  */
#line 84 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_MOD_ASSIGN,0);}
#line 2415 "Parser.tab.c"
    break;

  case 22: /* add_assign: ADD_ASSIGN  */
#line 85 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_ADD_ASSIGN,0);}
#line 2421 "Parser.tab.c"
    break;

  case 23: /* sub_assign: SUB_ASSIGN  */
#line 86 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_SUB_ASSIGN,0);}
#line 2427 "Parser.tab.c"
    break;

  case 24: /* left_assign: LEFT_ASSIGN  */
#line 87 "Parser.y"
                          {(yyval.a)=ast_newtoken(eTOKEN_LEFT_ASSIGN,0);}
#line 2433 "Parser.tab.c"
    break;

  case 25: /* right_assign: RIGHT_ASSIGN  */
#line 88 "Parser.y"
                            {(yyval.a)=ast_newtoken(eTOKEN_RIGHT_ASSIGN,0);}
#line 2439 "Parser.tab.c"
    break;

  case 26: /* and_assign: AND_ASSIGN  */
#line 89 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_AND_ASSIGN,0);}
#line 2445 "Parser.tab.c"
    break;

  case 27: /* xor_assign: XOR_ASSIGN  */
#line 90 "Parser.y"
                        {(yyval.a)=ast_newtoken(eTOKEN_XOR_ASSIGN,0);}
#line 2451 "Parser.tab.c"
    break;

  case 28: /* or_assign: OR_ASSIGN  */
#line 91 "Parser.y"
                      {(yyval.a)=ast_newtoken(eTOKEN_OR_ASSIGN,0);}
#line 2457 "Parser.tab.c"
    break;

  case 29: /* typedef_name: TYPEDEF_NAME  */
#line 92 "Parser.y"
                            {(yyval.a)=ast_newstring(eTOKEN_TYPEDEF_NAME,yytext);}
#line 2463 "Parser.tab.c"
    break;

  case 30: /* enum_constant: ENUM_CONSTANT  */
#line 93 "Parser.y"
                              {(yyval.a)=ast_newstring(eTOKEN_ENUMERATION_CONSTANT,yytext);}
#line 2469 "Parser.tab.c"
    break;

  case 31: /* typedef: TYPEDEF  */
#line 94 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_TYPEDEF,0);}
#line 2475 "Parser.tab.c"
    break;

  case 32: /* extern: EXTERN  */
#line 95 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_EXTERN,0);}
#line 2481 "Parser.tab.c"
    break;

  case 33: /* static: STATIC  */
#line 96 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_STATIC,0);}
#line 2487 "Parser.tab.c"
    break;

  case 34: /* auto: AUTO  */
#line 97 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_AUTO,0);}
#line 2493 "Parser.tab.c"
    break;

  case 35: /* register: REGISTER  */
#line 98 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_REGISTER,0);}
#line 2499 "Parser.tab.c"
    break;

  case 36: /* inline: INLINE  */
#line 99 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_INLINE,0);}
#line 2505 "Parser.tab.c"
    break;

  case 37: /* kernel: KERNEL  */
#line 100 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_KERNEL,0);}
#line 2511 "Parser.tab.c"
    break;

  case 38: /* class: CLASS  */
#line 101 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_CLASS,0);}
#line 2517 "Parser.tab.c"
    break;

  case 39: /* nt1: NT1  */
#line 102 "Parser.y"
          {(yyval.a)=ast_newtoken(eTOKEN_NT1,0);}
#line 2523 "Parser.tab.c"
    break;

  case 40: /* nt2: NT2  */
#line 103 "Parser.y"
          {(yyval.a)=ast_newtoken(eTOKEN_NT2,0);}
#line 2529 "Parser.tab.c"
    break;

  case 41: /* nt4: NT4  */
#line 104 "Parser.y"
          {(yyval.a)=ast_newtoken(eTOKEN_NT4,0);}
#line 2535 "Parser.tab.c"
    break;

  case 42: /* nt8: NT8  */
#line 105 "Parser.y"
          {(yyval.a)=ast_newtoken(eTOKEN_NT8,0);}
#line 2541 "Parser.tab.c"
    break;

  case 43: /* nt16: NT16  */
#line 106 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_NT16,0);}
#line 2547 "Parser.tab.c"
    break;

  case 44: /* const: CONST  */
#line 107 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_CONST,0);}
#line 2553 "Parser.tab.c"
    break;

  case 45: /* restrict: RESTRICT  */
#line 108 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_RESTRICT,0);}
#line 2559 "Parser.tab.c"
    break;

  case 46: /* volatile: VOLATILE  */
#line 109 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_VOLATILE,0);}
#line 2565 "Parser.tab.c"
    break;

  case 47: /* bool: BOOL  */
#line 110 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_BOOL,0);}
#line 2571 "Parser.tab.c"
    break;

  case 48: /* char: CHAR  */
#line 111 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_CHAR,0);}
#line 2577 "Parser.tab.c"
    break;

  case 49: /* short: SHORT  */
#line 112 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_SHORT,0);}
#line 2583 "Parser.tab.c"
    break;

  case 50: /* int: INT  */
#line 113 "Parser.y"
          {(yyval.a)=ast_newtoken(eTOKEN_INT,0);}
#line 2589 "Parser.tab.c"
    break;

  case 51: /* long: LONG  */
#line 114 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_LONG,0);}
#line 2595 "Parser.tab.c"
    break;

  case 52: /* signed: SIGNED  */
#line 115 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_SIGNED,0);}
#line 2601 "Parser.tab.c"
    break;

  case 53: /* unsigned: UNSIGNED  */
#line 116 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_UNSIGNED,0);}
#line 2607 "Parser.tab.c"
    break;

  case 54: /* float: FLOAT  */
#line 117 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_FLOAT,0);}
#line 2613 "Parser.tab.c"
    break;

  case 55: /* float2: FLOAT2  */
#line 118 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_FLOAT,1);}
#line 2619 "Parser.tab.c"
    break;

  case 56: /* float4: FLOAT4  */
#line 119 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_FLOAT,2);}
#line 2625 "Parser.tab.c"
    break;

  case 57: /* float8: FLOAT8  */
#line 120 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_FLOAT,3);}
#line 2631 "Parser.tab.c"
    break;

  case 58: /* float16: FLOAT16  */
#line 121 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_FLOAT,4);}
#line 2637 "Parser.tab.c"
    break;

  case 59: /* double: DOUBLE  */
#line 122 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_DOUBLE,0);}
#line 2643 "Parser.tab.c"
    break;

  case 60: /* void: VOID  */
#line 123 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_VOID,0);}
#line 2649 "Parser.tab.c"
    break;

  case 61: /* result: RESULT  */
#line 124 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_RESULT,0);}
#line 2655 "Parser.tab.c"
    break;

  case 62: /* complex: COMPLEX  */
#line 125 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_COMPLEX,0);}
#line 2661 "Parser.tab.c"
    break;

  case 63: /* imaginary: IMAGINARY  */
#line 126 "Parser.y"
                      {(yyval.a)=ast_newtoken(eTOKEN_IMAGINARY,0);}
#line 2667 "Parser.tab.c"
    break;

  case 64: /* struct: STRUCT  */
#line 127 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_STRUCT,0);}
#line 2673 "Parser.tab.c"
    break;

  case 65: /* union: UNION  */
#line 128 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_UNION,0);}
#line 2679 "Parser.tab.c"
    break;

  case 66: /* enum: ENUM  */
#line 129 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_ENUM,0);}
#line 2685 "Parser.tab.c"
    break;

  case 67: /* ellipsis: ELLIPSIS  */
#line 130 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_ELLIPSIS,0);}
#line 2691 "Parser.tab.c"
    break;

  case 68: /* case: CASE  */
#line 131 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_CASE,0);}
#line 2697 "Parser.tab.c"
    break;

  case 69: /* default: DEFAULT  */
#line 132 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_DEFAULT,0);}
#line 2703 "Parser.tab.c"
    break;

  case 70: /* if: IF  */
#line 133 "Parser.y"
        {(yyval.a)=ast_newtoken(eTOKEN_IF,0);}
#line 2709 "Parser.tab.c"
    break;

  case 71: /* else: ELSE  */
#line 134 "Parser.y"
            {(yyval.a)=ast_newtoken(eTOKEN_ELSE,0);}
#line 2715 "Parser.tab.c"
    break;

  case 72: /* switch: SWITCH  */
#line 135 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_SWITCH,0);}
#line 2721 "Parser.tab.c"
    break;

  case 73: /* while: WHILE  */
#line 136 "Parser.y"
               {(yyval.a)=ast_newtoken(eTOKEN_WHILE,0);}
#line 2727 "Parser.tab.c"
    break;

  case 74: /* do: DO  */
#line 137 "Parser.y"
         {(yyval.a)=ast_newtoken(eTOKEN_DO,0);}
#line 2733 "Parser.tab.c"
    break;

  case 75: /* for: FOR  */
#line 138 "Parser.y"
           {(yyval.a)=ast_newtoken(eTOKEN_FOR,0);}
#line 2739 "Parser.tab.c"
    break;

  case 76: /* goto: GOTO  */
#line 139 "Parser.y"
             {(yyval.a)=ast_newtoken(eTOKEN_GOTO,0);}
#line 2745 "Parser.tab.c"
    break;

  case 77: /* continue: CONTINUE  */
#line 140 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_CONTINUE,0);}
#line 2751 "Parser.tab.c"
    break;

  case 78: /* break: BREAK  */
#line 141 "Parser.y"
               {(yyval.a)=ast_newtoken(eTOKEN_BREAK,0);}
#line 2757 "Parser.tab.c"
    break;

  case 79: /* return: RETURN  */
#line 142 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_RETURN,0);}
#line 2763 "Parser.tab.c"
    break;

  case 80: /* alignas: ALIGNAS  */
#line 143 "Parser.y"
                   {(yyval.a)=ast_newtoken(eTOKEN_ALIGNAS,0);}
#line 2769 "Parser.tab.c"
    break;

  case 81: /* alignof: ALIGNOF  */
#line 144 "Parser.y"
                  {(yyval.a)=ast_newtoken(eTOKEN_ALIGNOF,0);}
#line 2775 "Parser.tab.c"
    break;

  case 82: /* atomic: ATOMIC  */
#line 145 "Parser.y"
                 {(yyval.a)=ast_newtoken(eTOKEN_ATOMIC,0);}
#line 2781 "Parser.tab.c"
    break;

  case 83: /* generic: GENERIC  */
#line 146 "Parser.y"
                   {(yyval.a)=ast_newtoken(eTOKEN_GENERIC,0);}
#line 2787 "Parser.tab.c"
    break;

  case 84: /* noreturn: NORETURN  */
#line 147 "Parser.y"
                     {(yyval.a)=ast_newtoken(eTOKEN_NORETURN,0);}
#line 2793 "Parser.tab.c"
    break;

  case 85: /* static_assert: STATIC_ASSERT  */
#line 148 "Parser.y"
                              {(yyval.a)=ast_newtoken(eTOKEN_STATIC_ASSERT,0);}
#line 2799 "Parser.tab.c"
    break;

  case 86: /* share: SHARE  */
#line 149 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_SHARE,0);}
#line 2805 "Parser.tab.c"
    break;

  case 87: /* global: GLOBAL  */
#line 150 "Parser.y"
                {(yyval.a)=ast_newtoken(eTOKEN_GLOBAL,0);}
#line 2811 "Parser.tab.c"
    break;

  case 88: /* primary_expression: identifier  */
#line 153 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_primary_expression,1,(yyvsp[0].a));}
#line 2817 "Parser.tab.c"
    break;

  case 89: /* primary_expression: constant  */
#line 154 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_primary_expression,1,(yyvsp[0].a));}
#line 2823 "Parser.tab.c"
    break;

  case 90: /* primary_expression: string  */
#line 155 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_primary_expression,1,(yyvsp[0].a));}
#line 2829 "Parser.tab.c"
    break;

  case 91: /* primary_expression: '(' expression ')'  */
#line 156 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_primary_expression,1,(yyvsp[-1].a));}
#line 2835 "Parser.tab.c"
    break;

  case 92: /* primary_expression: generic_selection  */
#line 157 "Parser.y"
                            {(yyval.a)=ast_newnode(eTOKEN_primary_expression,1,(yyvsp[0].a));}
#line 2841 "Parser.tab.c"
    break;

  case 93: /* constant: i_constant  */
#line 161 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_constant,1,(yyvsp[0].a));}
#line 2847 "Parser.tab.c"
    break;

  case 94: /* constant: f_constant  */
#line 162 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_constant,1,(yyvsp[0].a));}
#line 2853 "Parser.tab.c"
    break;

  case 95: /* constant: enum_constant  */
#line 163 "Parser.y"
                        {(yyval.a)=ast_newnode(eTOKEN_constant,1,(yyvsp[0].a));}
#line 2859 "Parser.tab.c"
    break;

  case 96: /* enumeration_constant: identifier  */
#line 167 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_enumeration_constant,1,(yyvsp[0].a));}
#line 2865 "Parser.tab.c"
    break;

  case 97: /* string: string_literal  */
#line 171 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_string,1,(yyvsp[0].a));}
#line 2871 "Parser.tab.c"
    break;

  case 98: /* string: func_name  */
#line 172 "Parser.y"
                    {(yyval.a)=ast_newnode(eTOKEN_string,1,(yyvsp[0].a));}
#line 2877 "Parser.tab.c"
    break;

  case 99: /* generic_selection: generic '(' assignment_expression ',' generic_assoc_list ')'  */
#line 176 "Parser.y"
                                                                       {(yyval.a)=ast_newnode(eTOKEN_generic_selection,3,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-1].a));}
#line 2883 "Parser.tab.c"
    break;

  case 100: /* generic_assoc_list: generic_association  */
#line 180 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_generic_assoc_list,1,(yyvsp[0].a));}
#line 2889 "Parser.tab.c"
    break;

  case 101: /* generic_assoc_list: generic_assoc_list ',' generic_association  */
#line 181 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_generic_assoc_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2895 "Parser.tab.c"
    break;

  case 102: /* generic_association: type_name ':' assignment_expression  */
#line 185 "Parser.y"
                                              {(yyval.a)=ast_newnode(eTOKEN_generic_association,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2901 "Parser.tab.c"
    break;

  case 103: /* generic_association: default ':' assignment_expression  */
#line 186 "Parser.y"
                                            {(yyval.a)=ast_newnode(eTOKEN_generic_association,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2907 "Parser.tab.c"
    break;

  case 104: /* postfix_expression: primary_expression  */
#line 190 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_postfix_expression1,1,(yyvsp[0].a));}
#line 2913 "Parser.tab.c"
    break;

  case 105: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 191 "Parser.y"
                                                {(yyval.a)=ast_newnode(eTOKEN_postfix_expression2,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 2919 "Parser.tab.c"
    break;

  case 106: /* postfix_expression: postfix_expression '(' ')'  */
#line 192 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_postfix_expression3,1,(yyvsp[-2].a));}
#line 2925 "Parser.tab.c"
    break;

  case 107: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 193 "Parser.y"
                                                              {(yyval.a)=ast_newnode(eTOKEN_postfix_expression4,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 2931 "Parser.tab.c"
    break;

  case 108: /* postfix_expression: postfix_expression '.' identifier  */
#line 194 "Parser.y"
                                            {(yyval.a)=ast_newnode(eTOKEN_postfix_expression5,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2937 "Parser.tab.c"
    break;

  case 109: /* postfix_expression: postfix_expression ptr_op identifier  */
#line 195 "Parser.y"
                                               {(yyval.a)=ast_newnode(eTOKEN_postfix_expression6,3,(yyvsp[-2].a),(yyvsp[-1].a),(yyvsp[0].a));}
#line 2943 "Parser.tab.c"
    break;

  case 110: /* postfix_expression: postfix_expression inc_op  */
#line 196 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_postfix_expression7,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 2949 "Parser.tab.c"
    break;

  case 111: /* postfix_expression: postfix_expression dec_op  */
#line 197 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_postfix_expression8,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 2955 "Parser.tab.c"
    break;

  case 112: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 198 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_postfix_expression9,2,(yyvsp[-4].a),(yyvsp[-1].a));}
#line 2961 "Parser.tab.c"
    break;

  case 113: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 199 "Parser.y"
                                                         {(yyval.a)=ast_newnode(eTOKEN_postfix_expression10,2,(yyvsp[-5].a),(yyvsp[-2].a));}
#line 2967 "Parser.tab.c"
    break;

  case 114: /* argument_expression_list: assignment_expression  */
#line 203 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_argument_expression_list,1,(yyvsp[0].a));}
#line 2973 "Parser.tab.c"
    break;

  case 115: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 204 "Parser.y"
                                                             {(yyval.a)=ast_newnode(eTOKEN_argument_expression_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 2979 "Parser.tab.c"
    break;

  case 116: /* unary_expression: postfix_expression  */
#line 208 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_unary_expression,1,(yyvsp[0].a));}
#line 2985 "Parser.tab.c"
    break;

  case 117: /* unary_expression: inc_op unary_expression  */
#line 209 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 2991 "Parser.tab.c"
    break;

  case 118: /* unary_expression: dec_op unary_expression  */
#line 210 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 2997 "Parser.tab.c"
    break;

  case 119: /* unary_expression: unary_operator cast_expression  */
#line 211 "Parser.y"
                                         {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3003 "Parser.tab.c"
    break;

  case 120: /* unary_expression: sizeof unary_expression  */
#line 212 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3009 "Parser.tab.c"
    break;

  case 121: /* unary_expression: sizeof '(' type_name ')'  */
#line 213 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3015 "Parser.tab.c"
    break;

  case 122: /* unary_expression: alignof '(' type_name ')'  */
#line 214 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_unary_expression,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3021 "Parser.tab.c"
    break;

  case 123: /* unary_operator: '&'  */
#line 218 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"&");}
#line 3027 "Parser.tab.c"
    break;

  case 124: /* unary_operator: '*'  */
#line 219 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"*");}
#line 3033 "Parser.tab.c"
    break;

  case 125: /* unary_operator: '+'  */
#line 220 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"+");}
#line 3039 "Parser.tab.c"
    break;

  case 126: /* unary_operator: '-'  */
#line 221 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"-");}
#line 3045 "Parser.tab.c"
    break;

  case 127: /* unary_operator: '~'  */
#line 222 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"~");}
#line 3051 "Parser.tab.c"
    break;

  case 128: /* unary_operator: '!'  */
#line 223 "Parser.y"
              {(yyval.a)=ast_newstring(eTOKEN_unary_operator,"!");}
#line 3057 "Parser.tab.c"
    break;

  case 129: /* cast_expression: unary_expression  */
#line 227 "Parser.y"
                           {(yyval.a)=ast_newnode(eTOKEN_cast_expression,1,(yyvsp[0].a));}
#line 3063 "Parser.tab.c"
    break;

  case 130: /* cast_expression: '(' type_name ')' cast_expression  */
#line 228 "Parser.y"
                                            {(yyval.a)=ast_newnode(eTOKEN_cast_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3069 "Parser.tab.c"
    break;

  case 131: /* multiplicative_expression: cast_expression  */
#line 232 "Parser.y"
                          {(yyval.a)=ast_newnode(eTOKEN_multiplicative_expression,1,(yyvsp[0].a));}
#line 3075 "Parser.tab.c"
    break;

  case 132: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 233 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_multiplicative_expression_mul,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3081 "Parser.tab.c"
    break;

  case 133: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 234 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_multiplicative_expression_div,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3087 "Parser.tab.c"
    break;

  case 134: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 235 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_multiplicative_expression_mod,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3093 "Parser.tab.c"
    break;

  case 135: /* additive_expression: multiplicative_expression  */
#line 239 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_additive_expression,1,(yyvsp[0].a));}
#line 3099 "Parser.tab.c"
    break;

  case 136: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 240 "Parser.y"
                                                            {(yyval.a)=ast_newnode(eTOKEN_additive_expression_add,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3105 "Parser.tab.c"
    break;

  case 137: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 241 "Parser.y"
                                                            {(yyval.a)=ast_newnode(eTOKEN_additive_expression_sub,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3111 "Parser.tab.c"
    break;

  case 138: /* shift_expression: additive_expression  */
#line 245 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_shift_expression,1,(yyvsp[0].a));}
#line 3117 "Parser.tab.c"
    break;

  case 139: /* shift_expression: shift_expression left_op additive_expression  */
#line 246 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_shift_expression_shl,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3123 "Parser.tab.c"
    break;

  case 140: /* shift_expression: shift_expression right_op additive_expression  */
#line 247 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_shift_expression_shr,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3129 "Parser.tab.c"
    break;

  case 141: /* relational_expression: shift_expression  */
#line 251 "Parser.y"
                           {(yyval.a)=ast_newnode(eTOKEN_relational_expression,1,(yyvsp[0].a));}
#line 3135 "Parser.tab.c"
    break;

  case 142: /* relational_expression: relational_expression '<' shift_expression  */
#line 252 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_relational_expression_lt,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3141 "Parser.tab.c"
    break;

  case 143: /* relational_expression: relational_expression '>' shift_expression  */
#line 253 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_relational_expression_gt,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3147 "Parser.tab.c"
    break;

  case 144: /* relational_expression: relational_expression le_op shift_expression  */
#line 254 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_relational_expression_le,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3153 "Parser.tab.c"
    break;

  case 145: /* relational_expression: relational_expression ge_op shift_expression  */
#line 255 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_relational_expression_ge,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3159 "Parser.tab.c"
    break;

  case 146: /* equality_expression: relational_expression  */
#line 259 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_equality_expression,1,(yyvsp[0].a));}
#line 3165 "Parser.tab.c"
    break;

  case 147: /* equality_expression: equality_expression eq_op relational_expression  */
#line 260 "Parser.y"
                                                          {(yyval.a)=ast_newnode(eTOKEN_equality_expression_eq,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3171 "Parser.tab.c"
    break;

  case 148: /* equality_expression: equality_expression ne_op relational_expression  */
#line 261 "Parser.y"
                                                          {(yyval.a)=ast_newnode(eTOKEN_equality_expression_ne,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3177 "Parser.tab.c"
    break;

  case 149: /* and_expression: equality_expression  */
#line 265 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_and_expression,1,(yyvsp[0].a));}
#line 3183 "Parser.tab.c"
    break;

  case 150: /* and_expression: and_expression '&' equality_expression  */
#line 266 "Parser.y"
                                                 {(yyval.a)=ast_newnode(eTOKEN_and_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3189 "Parser.tab.c"
    break;

  case 151: /* exclusive_or_expression: and_expression  */
#line 270 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_exclusive_or_expression,1,(yyvsp[0].a));}
#line 3195 "Parser.tab.c"
    break;

  case 152: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 271 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_exclusive_or_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3201 "Parser.tab.c"
    break;

  case 153: /* inclusive_or_expression: exclusive_or_expression  */
#line 275 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_inclusive_or_expression,1,(yyvsp[0].a));}
#line 3207 "Parser.tab.c"
    break;

  case 154: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 276 "Parser.y"
                                                              {(yyval.a)=ast_newnode(eTOKEN_inclusive_or_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3213 "Parser.tab.c"
    break;

  case 155: /* logical_and_expression: inclusive_or_expression  */
#line 280 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_logical_and_expression,1,(yyvsp[0].a));}
#line 3219 "Parser.tab.c"
    break;

  case 156: /* logical_and_expression: logical_and_expression and_op inclusive_or_expression  */
#line 281 "Parser.y"
                                                                {(yyval.a)=ast_newnode(eTOKEN_logical_and_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3225 "Parser.tab.c"
    break;

  case 157: /* logical_or_expression: logical_and_expression  */
#line 285 "Parser.y"
                                 {(yyval.a)=ast_newnode(eTOKEN_logical_or_expression,1,(yyvsp[0].a));}
#line 3231 "Parser.tab.c"
    break;

  case 158: /* logical_or_expression: logical_or_expression or_op logical_and_expression  */
#line 286 "Parser.y"
                                                             {(yyval.a)=ast_newnode(eTOKEN_logical_or_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3237 "Parser.tab.c"
    break;

  case 159: /* conditional_expression: logical_or_expression  */
#line 290 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_conditional_expression,1,(yyvsp[0].a));}
#line 3243 "Parser.tab.c"
    break;

  case 160: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 291 "Parser.y"
                                                                          {(yyval.a)=ast_newnode(eTOKEN_conditional_expression,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 3249 "Parser.tab.c"
    break;

  case 161: /* assignment_expression: conditional_expression  */
#line 295 "Parser.y"
                                 {(yyval.a)=ast_newnode(eTOKEN_assignment_expression,1,(yyvsp[0].a));}
#line 3255 "Parser.tab.c"
    break;

  case 162: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 296 "Parser.y"
                                                                     {(yyval.a)=ast_newnode(eTOKEN_assignment_expression,3,(yyvsp[-2].a),(yyvsp[-1].a),(yyvsp[0].a));}
#line 3261 "Parser.tab.c"
    break;

  case 163: /* assignment_operator: '='  */
#line 300 "Parser.y"
              {(yyval.a)=ast_newtoken(eTOKEN_assignment_operator,0);}
#line 3267 "Parser.tab.c"
    break;

  case 164: /* assignment_operator: mul_assign  */
#line 301 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_mul,1,(yyvsp[0].a));}
#line 3273 "Parser.tab.c"
    break;

  case 165: /* assignment_operator: div_assign  */
#line 302 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_div,1,(yyvsp[0].a));}
#line 3279 "Parser.tab.c"
    break;

  case 166: /* assignment_operator: mod_assign  */
#line 303 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_mod,1,(yyvsp[0].a));}
#line 3285 "Parser.tab.c"
    break;

  case 167: /* assignment_operator: add_assign  */
#line 304 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_add,1,(yyvsp[0].a));}
#line 3291 "Parser.tab.c"
    break;

  case 168: /* assignment_operator: sub_assign  */
#line 305 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_sub,1,(yyvsp[0].a));}
#line 3297 "Parser.tab.c"
    break;

  case 169: /* assignment_operator: left_assign  */
#line 306 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_left,1,(yyvsp[0].a));}
#line 3303 "Parser.tab.c"
    break;

  case 170: /* assignment_operator: right_assign  */
#line 307 "Parser.y"
                       {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_right,1,(yyvsp[0].a));}
#line 3309 "Parser.tab.c"
    break;

  case 171: /* assignment_operator: and_assign  */
#line 308 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_and,1,(yyvsp[0].a));}
#line 3315 "Parser.tab.c"
    break;

  case 172: /* assignment_operator: xor_assign  */
#line 309 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_xor,1,(yyvsp[0].a));}
#line 3321 "Parser.tab.c"
    break;

  case 173: /* assignment_operator: or_assign  */
#line 310 "Parser.y"
                    {(yyval.a)=ast_newnode(eTOKEN_assignment_operator_or,1,(yyvsp[0].a));}
#line 3327 "Parser.tab.c"
    break;

  case 174: /* expression: assignment_expression  */
#line 314 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_expression,1,(yyvsp[0].a));}
#line 3333 "Parser.tab.c"
    break;

  case 175: /* expression: expression ',' assignment_expression  */
#line 315 "Parser.y"
                                               {(yyval.a)=ast_newnode(eTOKEN_expression,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3339 "Parser.tab.c"
    break;

  case 176: /* constant_expression: conditional_expression  */
#line 319 "Parser.y"
                                 {(yyval.a)=ast_newnode(eTOKEN_constant_expression,1,(yyvsp[0].a));}
#line 3345 "Parser.tab.c"
    break;

  case 177: /* declaration: declaration_specifiers ';'  */
#line 323 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_declaration,1,(yyvsp[-1].a));}
#line 3351 "Parser.tab.c"
    break;

  case 178: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 324 "Parser.y"
                                                          {(yyval.a)=ast_newnode(eTOKEN_declaration,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3357 "Parser.tab.c"
    break;

  case 179: /* declaration: static_assert_declaration  */
#line 325 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_declaration,1,(yyvsp[0].a));}
#line 3363 "Parser.tab.c"
    break;

  case 180: /* declaration: class_declaration  */
#line 326 "Parser.y"
                            {(yyval.a)=ast_newnode(eTOKEN_declaration,1,(yyvsp[0].a));}
#line 3369 "Parser.tab.c"
    break;

  case 181: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 330 "Parser.y"
                                                         {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3375 "Parser.tab.c"
    break;

  case 182: /* declaration_specifiers: storage_class_specifier  */
#line 331 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,1,(yyvsp[0].a));}
#line 3381 "Parser.tab.c"
    break;

  case 183: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 332 "Parser.y"
                                                {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3387 "Parser.tab.c"
    break;

  case 184: /* declaration_specifiers: type_specifier  */
#line 333 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,1,(yyvsp[0].a));}
#line 3393 "Parser.tab.c"
    break;

  case 185: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 334 "Parser.y"
                                                {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3399 "Parser.tab.c"
    break;

  case 186: /* declaration_specifiers: type_qualifier  */
#line 335 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,1,(yyvsp[0].a));}
#line 3405 "Parser.tab.c"
    break;

  case 187: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 336 "Parser.y"
                                                    {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3411 "Parser.tab.c"
    break;

  case 188: /* declaration_specifiers: function_specifier  */
#line 337 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,1,(yyvsp[0].a));}
#line 3417 "Parser.tab.c"
    break;

  case 189: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 338 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3423 "Parser.tab.c"
    break;

  case 190: /* declaration_specifiers: alignment_specifier  */
#line 339 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_declaration_specifiers,1,(yyvsp[0].a));}
#line 3429 "Parser.tab.c"
    break;

  case 191: /* init_declarator_list: init_declarator  */
#line 343 "Parser.y"
                          {(yyval.a)=ast_newnode(eTOKEN_init_declarator_list,1,(yyvsp[0].a));}
#line 3435 "Parser.tab.c"
    break;

  case 192: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 344 "Parser.y"
                                                   {(yyval.a)=ast_newnode(eTOKEN_init_declarator_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3441 "Parser.tab.c"
    break;

  case 193: /* init_declarator: declarator '=' initializer  */
#line 348 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_init_declarator,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3447 "Parser.tab.c"
    break;

  case 194: /* init_declarator: declarator  */
#line 349 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_init_declarator,1,(yyvsp[0].a));}
#line 3453 "Parser.tab.c"
    break;

  case 195: /* storage_class_specifier: typedef  */
#line 353 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3459 "Parser.tab.c"
    break;

  case 196: /* storage_class_specifier: extern  */
#line 354 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3465 "Parser.tab.c"
    break;

  case 197: /* storage_class_specifier: static  */
#line 355 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3471 "Parser.tab.c"
    break;

  case 198: /* storage_class_specifier: share  */
#line 356 "Parser.y"
                {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3477 "Parser.tab.c"
    break;

  case 199: /* storage_class_specifier: global  */
#line 357 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3483 "Parser.tab.c"
    break;

  case 200: /* storage_class_specifier: auto  */
#line 358 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3489 "Parser.tab.c"
    break;

  case 201: /* storage_class_specifier: register  */
#line 359 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_storage_class_specifier,1,(yyvsp[0].a));}
#line 3495 "Parser.tab.c"
    break;

  case 202: /* type_specifier: void  */
#line 363 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3501 "Parser.tab.c"
    break;

  case 203: /* type_specifier: char  */
#line 364 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3507 "Parser.tab.c"
    break;

  case 204: /* type_specifier: short  */
#line 365 "Parser.y"
                {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3513 "Parser.tab.c"
    break;

  case 205: /* type_specifier: int  */
#line 366 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3519 "Parser.tab.c"
    break;

  case 206: /* type_specifier: long  */
#line 367 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3525 "Parser.tab.c"
    break;

  case 207: /* type_specifier: float  */
#line 368 "Parser.y"
                {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3531 "Parser.tab.c"
    break;

  case 208: /* type_specifier: float2  */
#line 369 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3537 "Parser.tab.c"
    break;

  case 209: /* type_specifier: float4  */
#line 370 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3543 "Parser.tab.c"
    break;

  case 210: /* type_specifier: float8  */
#line 371 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3549 "Parser.tab.c"
    break;

  case 211: /* type_specifier: float16  */
#line 372 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3555 "Parser.tab.c"
    break;

  case 212: /* type_specifier: double  */
#line 373 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3561 "Parser.tab.c"
    break;

  case 213: /* type_specifier: signed  */
#line 374 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3567 "Parser.tab.c"
    break;

  case 214: /* type_specifier: unsigned  */
#line 375 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3573 "Parser.tab.c"
    break;

  case 215: /* type_specifier: bool  */
#line 376 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3579 "Parser.tab.c"
    break;

  case 216: /* type_specifier: complex  */
#line 377 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3585 "Parser.tab.c"
    break;

  case 217: /* type_specifier: imaginary  */
#line 378 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3591 "Parser.tab.c"
    break;

  case 218: /* type_specifier: atomic_type_specifier  */
#line 379 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3597 "Parser.tab.c"
    break;

  case 219: /* type_specifier: struct_or_union_specifier  */
#line 380 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3603 "Parser.tab.c"
    break;

  case 220: /* type_specifier: enum_specifier  */
#line 381 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3609 "Parser.tab.c"
    break;

  case 221: /* type_specifier: typedef_name  */
#line 382 "Parser.y"
                       {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3615 "Parser.tab.c"
    break;

  case 222: /* type_specifier: result  */
#line 383 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3621 "Parser.tab.c"
    break;

  case 223: /* type_specifier: pointer_scope  */
#line 384 "Parser.y"
                        {(yyval.a)=ast_newnode(eTOKEN_type_specifier,1,(yyvsp[0].a));}
#line 3627 "Parser.tab.c"
    break;

  case 224: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 388 "Parser.y"
                                                          {(yyval.a)=ast_newnode(eTOKEN_struct_or_union_specifier,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3633 "Parser.tab.c"
    break;

  case 225: /* struct_or_union_specifier: struct_or_union identifier '{' struct_declaration_list '}'  */
#line 389 "Parser.y"
                                                                     {(yyval.a)=ast_newnode(eTOKEN_struct_or_union_specifier,3,(yyvsp[-4].a),(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3639 "Parser.tab.c"
    break;

  case 226: /* struct_or_union_specifier: struct_or_union identifier  */
#line 390 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_struct_or_union_specifier,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3645 "Parser.tab.c"
    break;

  case 227: /* struct_or_union: struct  */
#line 394 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_struct_or_union,1,(yyvsp[0].a));}
#line 3651 "Parser.tab.c"
    break;

  case 228: /* struct_or_union: union  */
#line 395 "Parser.y"
                {(yyval.a)=ast_newnode(eTOKEN_struct_or_union,1,(yyvsp[0].a));}
#line 3657 "Parser.tab.c"
    break;

  case 229: /* struct_declaration_list: struct_declaration  */
#line 399 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_struct_declaration_list,1,(yyvsp[0].a));}
#line 3663 "Parser.tab.c"
    break;

  case 230: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 400 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_struct_declaration_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3669 "Parser.tab.c"
    break;

  case 231: /* struct_declaration: specifier_qualifier_list ';'  */
#line 404 "Parser.y"
                                       {(yyval.a)=ast_newnode(eTOKEN_struct_declaration,1,(yyvsp[-1].a));}
#line 3675 "Parser.tab.c"
    break;

  case 232: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 405 "Parser.y"
                                                              {(yyval.a)=ast_newnode(eTOKEN_struct_declaration,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3681 "Parser.tab.c"
    break;

  case 233: /* struct_declaration: static_assert_declaration  */
#line 406 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_struct_declaration,1,(yyvsp[0].a));}
#line 3687 "Parser.tab.c"
    break;

  case 234: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 410 "Parser.y"
                                                  {(yyval.a)=ast_newnode(eTOKEN_specifier_qualifier_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3693 "Parser.tab.c"
    break;

  case 235: /* specifier_qualifier_list: type_specifier  */
#line 411 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_specifier_qualifier_list,1,(yyvsp[0].a));}
#line 3699 "Parser.tab.c"
    break;

  case 236: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 412 "Parser.y"
                                                  {(yyval.a)=ast_newnode(eTOKEN_specifier_qualifier_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3705 "Parser.tab.c"
    break;

  case 237: /* specifier_qualifier_list: type_qualifier  */
#line 413 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_specifier_qualifier_list,1,(yyvsp[0].a));}
#line 3711 "Parser.tab.c"
    break;

  case 238: /* struct_declarator_list: struct_declarator  */
#line 417 "Parser.y"
                            {(yyval.a)=ast_newnode(eTOKEN_struct_declarator_list,1,(yyvsp[0].a));}
#line 3717 "Parser.tab.c"
    break;

  case 239: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 418 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_struct_declarator_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3723 "Parser.tab.c"
    break;

  case 240: /* struct_declarator: ':' constant_expression  */
#line 422 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_struct_declarator,1,(yyvsp[0].a));}
#line 3729 "Parser.tab.c"
    break;

  case 241: /* struct_declarator: declarator ':' constant_expression  */
#line 423 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_struct_declarator,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3735 "Parser.tab.c"
    break;

  case 242: /* struct_declarator: declarator  */
#line 424 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_struct_declarator,1,(yyvsp[0].a));}
#line 3741 "Parser.tab.c"
    break;

  case 243: /* enum_specifier: enum '{' enumerator_list '}'  */
#line 428 "Parser.y"
                                       {(yyval.a)=ast_newnode(eTOKEN_enum_specifier,1,(yyvsp[-1].a));}
#line 3747 "Parser.tab.c"
    break;

  case 244: /* enum_specifier: enum '{' enumerator_list ',' '}'  */
#line 429 "Parser.y"
                                           {(yyval.a)=ast_newnode(eTOKEN_enum_specifier,1,(yyvsp[-2].a));}
#line 3753 "Parser.tab.c"
    break;

  case 245: /* enum_specifier: enum identifier '{' enumerator_list '}'  */
#line 430 "Parser.y"
                                                  {(yyval.a)=ast_newnode(eTOKEN_enum_specifier,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3759 "Parser.tab.c"
    break;

  case 246: /* enum_specifier: enum identifier '{' enumerator_list ',' '}'  */
#line 431 "Parser.y"
                                                      {(yyval.a)=ast_newnode(eTOKEN_enum_specifier,2,(yyvsp[-4].a),(yyvsp[-2].a));}
#line 3765 "Parser.tab.c"
    break;

  case 247: /* enum_specifier: enum identifier  */
#line 432 "Parser.y"
                          {(yyval.a)=ast_newnode(eTOKEN_enum_specifier,1,(yyvsp[0].a));}
#line 3771 "Parser.tab.c"
    break;

  case 248: /* enumerator_list: enumerator  */
#line 436 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_enumerator_list,1,(yyvsp[0].a));}
#line 3777 "Parser.tab.c"
    break;

  case 249: /* enumerator_list: enumerator_list ',' enumerator  */
#line 437 "Parser.y"
                                         {(yyval.a)=ast_newnode(eTOKEN_enumerator_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3783 "Parser.tab.c"
    break;

  case 250: /* enumerator: enumeration_constant '=' constant_expression  */
#line 441 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_enumerator,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 3789 "Parser.tab.c"
    break;

  case 251: /* enumerator: enumeration_constant  */
#line 442 "Parser.y"
                               {(yyval.a)=ast_newnode(eTOKEN_enumerator,1,(yyvsp[0].a));}
#line 3795 "Parser.tab.c"
    break;

  case 252: /* atomic_type_specifier: atomic '(' type_name ')'  */
#line 446 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_atomic_type_specifier,1,(yyvsp[-1].a));}
#line 3801 "Parser.tab.c"
    break;

  case 253: /* type_qualifier: const  */
#line 450 "Parser.y"
                {(yyval.a)=ast_newnode(eTOKEN_type_qualifier,1,(yyvsp[0].a));}
#line 3807 "Parser.tab.c"
    break;

  case 254: /* type_qualifier: restrict  */
#line 451 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_type_qualifier,1,(yyvsp[0].a));}
#line 3813 "Parser.tab.c"
    break;

  case 255: /* type_qualifier: volatile  */
#line 452 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_type_qualifier,1,(yyvsp[0].a));}
#line 3819 "Parser.tab.c"
    break;

  case 256: /* type_qualifier: atomic  */
#line 453 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_type_qualifier,1,(yyvsp[0].a));}
#line 3825 "Parser.tab.c"
    break;

  case 257: /* function_specifier: inline  */
#line 457 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_function_specifier,1,(yyvsp[0].a));}
#line 3831 "Parser.tab.c"
    break;

  case 258: /* function_specifier: kernel  */
#line 458 "Parser.y"
                 {(yyval.a)=ast_newnode(eTOKEN_function_specifier,1,(yyvsp[0].a));}
#line 3837 "Parser.tab.c"
    break;

  case 259: /* function_specifier: noreturn  */
#line 459 "Parser.y"
                   {(yyval.a)=ast_newnode(eTOKEN_function_specifier,1,(yyvsp[0].a));}
#line 3843 "Parser.tab.c"
    break;

  case 260: /* class_specifier: nt1  */
#line 463 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_class_specifier,1,(yyvsp[0].a));}
#line 3849 "Parser.tab.c"
    break;

  case 261: /* class_specifier: nt2  */
#line 464 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_class_specifier,1,(yyvsp[0].a));}
#line 3855 "Parser.tab.c"
    break;

  case 262: /* class_specifier: nt4  */
#line 465 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_class_specifier,1,(yyvsp[0].a));}
#line 3861 "Parser.tab.c"
    break;

  case 263: /* class_specifier: nt8  */
#line 466 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_class_specifier,1,(yyvsp[0].a));}
#line 3867 "Parser.tab.c"
    break;

  case 264: /* class_specifier: nt16  */
#line 467 "Parser.y"
               {(yyval.a)=ast_newnode(eTOKEN_class_specifier,1,(yyvsp[0].a));}
#line 3873 "Parser.tab.c"
    break;

  case 265: /* alignment_specifier: alignas '(' type_name ')'  */
#line 471 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_alignment_specifier,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3879 "Parser.tab.c"
    break;

  case 266: /* alignment_specifier: alignas '(' constant_expression ')'  */
#line 472 "Parser.y"
                                              {(yyval.a)=ast_newnode(eTOKEN_alignment_specifier,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3885 "Parser.tab.c"
    break;

  case 267: /* declarator: pointer direct_declarator  */
#line 476 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_declarator,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3891 "Parser.tab.c"
    break;

  case 268: /* declarator: direct_declarator  */
#line 477 "Parser.y"
                            {(yyval.a)=ast_newnode(eTOKEN_declarator,1,(yyvsp[0].a));}
#line 3897 "Parser.tab.c"
    break;

  case 269: /* direct_declarator: identifier  */
#line 481 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_direct_declarator1,1,(yyvsp[0].a));}
#line 3903 "Parser.tab.c"
    break;

  case 270: /* direct_declarator: '(' declarator ')'  */
#line 482 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_direct_declarator2,1,(yyvsp[-1].a));}
#line 3909 "Parser.tab.c"
    break;

  case 271: /* direct_declarator: direct_declarator '[' ']'  */
#line 483 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_direct_declarator3,1,(yyvsp[-2].a));}
#line 3915 "Parser.tab.c"
    break;

  case 272: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 484 "Parser.y"
                                        {(yyval.a)=ast_newnode(eTOKEN_direct_declarator4,1,(yyvsp[-3].a));}
#line 3921 "Parser.tab.c"
    break;

  case 273: /* direct_declarator: direct_declarator '[' static type_qualifier_list assignment_expression ']'  */
#line 485 "Parser.y"
                                                                                     {(yyval.a)=ast_newnode(eTOKEN_direct_declarator5,4,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3927 "Parser.tab.c"
    break;

  case 274: /* direct_declarator: direct_declarator '[' static assignment_expression ']'  */
#line 486 "Parser.y"
                                                                 {(yyval.a)=ast_newnode(eTOKEN_direct_declarator6,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3933 "Parser.tab.c"
    break;

  case 275: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 487 "Parser.y"
                                                            {(yyval.a)=ast_newnode(eTOKEN_direct_declarator7,2,(yyvsp[-4].a),(yyvsp[-2].a));}
#line 3939 "Parser.tab.c"
    break;

  case 276: /* direct_declarator: direct_declarator '[' type_qualifier_list static assignment_expression ']'  */
#line 488 "Parser.y"
                                                                                     {(yyval.a)=ast_newnode(eTOKEN_direct_declarator8,4,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3945 "Parser.tab.c"
    break;

  case 277: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 489 "Parser.y"
                                                                              {(yyval.a)=ast_newnode(eTOKEN_direct_declarator9,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 3951 "Parser.tab.c"
    break;

  case 278: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 490 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_direct_declarator10,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3957 "Parser.tab.c"
    break;

  case 279: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 491 "Parser.y"
                                                          {(yyval.a)=ast_newnode(eTOKEN_direct_declarator11,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3963 "Parser.tab.c"
    break;

  case 280: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 492 "Parser.y"
                                                        {(yyval.a)=ast_newnode(eTOKEN_direct_declarator12,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3969 "Parser.tab.c"
    break;

  case 281: /* direct_declarator: direct_declarator '(' ')'  */
#line 493 "Parser.y"
                                    {(yyval.a)=ast_newnode(eTOKEN_direct_declarator13,1,(yyvsp[-2].a));}
#line 3975 "Parser.tab.c"
    break;

  case 282: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 494 "Parser.y"
                                                    {(yyval.a)=ast_newnode(eTOKEN_direct_declarator14,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 3981 "Parser.tab.c"
    break;

  case 283: /* pointer: '*' type_qualifier_list pointer  */
#line 498 "Parser.y"
                                          {(yyval.a)=ast_newnode(eTOKEN_pointer,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 3987 "Parser.tab.c"
    break;

  case 284: /* pointer: '*' type_qualifier_list  */
#line 499 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_pointer,1,(yyvsp[0].a));}
#line 3993 "Parser.tab.c"
    break;

  case 285: /* pointer: '*' pointer  */
#line 500 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_pointer,1,(yyvsp[0].a));}
#line 3999 "Parser.tab.c"
    break;

  case 286: /* pointer: '*'  */
#line 501 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_pointer,0);}
#line 4005 "Parser.tab.c"
    break;

  case 287: /* type_qualifier_list: type_qualifier  */
#line 505 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_type_qualifier_list,1,(yyvsp[0].a));}
#line 4011 "Parser.tab.c"
    break;

  case 288: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 506 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_type_qualifier_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4017 "Parser.tab.c"
    break;

  case 289: /* parameter_type_list: parameter_list ',' ellipsis  */
#line 511 "Parser.y"
                                      {(yyval.a)=ast_newnode(eTOKEN_type_qualifier_list,1,(yyvsp[-2].a));}
#line 4023 "Parser.tab.c"
    break;

  case 290: /* parameter_type_list: parameter_list  */
#line 512 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_type_qualifier_list,1,(yyvsp[0].a));}
#line 4029 "Parser.tab.c"
    break;

  case 291: /* parameter_list: parameter_declaration  */
#line 516 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_parameter_list,1,(yyvsp[0].a));}
#line 4035 "Parser.tab.c"
    break;

  case 292: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 517 "Parser.y"
                                                   {(yyval.a)=ast_newnode(eTOKEN_parameter_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4041 "Parser.tab.c"
    break;

  case 293: /* parameter_declaration: declaration_specifiers declarator  */
#line 521 "Parser.y"
                                            {(yyval.a)=ast_newnode(eTOKEN_parameter_declaration,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4047 "Parser.tab.c"
    break;

  case 294: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 522 "Parser.y"
                                                     {(yyval.a)=ast_newnode(eTOKEN_parameter_declaration,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4053 "Parser.tab.c"
    break;

  case 295: /* parameter_declaration: declaration_specifiers  */
#line 523 "Parser.y"
                                 {(yyval.a)=ast_newnode(eTOKEN_parameter_declaration,1,(yyvsp[0].a));}
#line 4059 "Parser.tab.c"
    break;

  case 296: /* identifier_list: identifier  */
#line 527 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_identifier_list,1,(yyvsp[0].a));}
#line 4065 "Parser.tab.c"
    break;

  case 297: /* identifier_list: identifier_list ',' identifier  */
#line 528 "Parser.y"
                                         {(yyval.a)=ast_newnode(eTOKEN_identifier_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4071 "Parser.tab.c"
    break;

  case 298: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 532 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_type_name,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4077 "Parser.tab.c"
    break;

  case 299: /* type_name: specifier_qualifier_list  */
#line 533 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_type_name,1,(yyvsp[0].a));}
#line 4083 "Parser.tab.c"
    break;

  case 300: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 537 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_abstract_declarator,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4089 "Parser.tab.c"
    break;

  case 301: /* abstract_declarator: pointer  */
#line 538 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_abstract_declarator,1,(yyvsp[0].a));}
#line 4095 "Parser.tab.c"
    break;

  case 302: /* abstract_declarator: direct_abstract_declarator  */
#line 539 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_abstract_declarator,1,(yyvsp[0].a));}
#line 4101 "Parser.tab.c"
    break;

  case 303: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 543 "Parser.y"
                                      {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-1].a));}
#line 4107 "Parser.tab.c"
    break;

  case 304: /* direct_abstract_declarator: '[' ']'  */
#line 544 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,0);}
#line 4113 "Parser.tab.c"
    break;

  case 305: /* direct_abstract_declarator: '[' '*' ']'  */
#line 545 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,0);}
#line 4119 "Parser.tab.c"
    break;

  case 306: /* direct_abstract_declarator: '[' static type_qualifier_list assignment_expression ']'  */
#line 546 "Parser.y"
                                                                   {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,3,(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4125 "Parser.tab.c"
    break;

  case 307: /* direct_abstract_declarator: '[' static assignment_expression ']'  */
#line 547 "Parser.y"
                                               {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4131 "Parser.tab.c"
    break;

  case 308: /* direct_abstract_declarator: '[' type_qualifier_list static assignment_expression ']'  */
#line 548 "Parser.y"
                                                                   {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,3,(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4137 "Parser.tab.c"
    break;

  case 309: /* direct_abstract_declarator: '[' type_qualifier_list assignment_expression ']'  */
#line 549 "Parser.y"
                                                            {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4143 "Parser.tab.c"
    break;

  case 310: /* direct_abstract_declarator: '[' type_qualifier_list ']'  */
#line 550 "Parser.y"
                                      {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-1].a));}
#line 4149 "Parser.tab.c"
    break;

  case 311: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 551 "Parser.y"
                                        {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-1].a));}
#line 4155 "Parser.tab.c"
    break;

  case 312: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 552 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-2].a));}
#line 4161 "Parser.tab.c"
    break;

  case 313: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 553 "Parser.y"
                                                 {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-3].a));}
#line 4167 "Parser.tab.c"
    break;

  case 314: /* direct_abstract_declarator: direct_abstract_declarator '[' static type_qualifier_list assignment_expression ']'  */
#line 554 "Parser.y"
                                                                                              {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,3,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a));}
#line 4173 "Parser.tab.c"
    break;

  case 315: /* direct_abstract_declarator: direct_abstract_declarator '[' static assignment_expression ']'  */
#line 555 "Parser.y"
                                                                          {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4179 "Parser.tab.c"
    break;

  case 316: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 556 "Parser.y"
                                                                                       {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4185 "Parser.tab.c"
    break;

  case 317: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list static assignment_expression ']'  */
#line 557 "Parser.y"
                                                                                              {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,4,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4191 "Parser.tab.c"
    break;

  case 318: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list ']'  */
#line 558 "Parser.y"
                                                                 {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 4197 "Parser.tab.c"
    break;

  case 319: /* direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'  */
#line 559 "Parser.y"
                                                                   {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 4203 "Parser.tab.c"
    break;

  case 320: /* direct_abstract_declarator: '(' ')'  */
#line 560 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,0);}
#line 4209 "Parser.tab.c"
    break;

  case 321: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 561 "Parser.y"
                                      {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-1].a));}
#line 4215 "Parser.tab.c"
    break;

  case 322: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 562 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,1,(yyvsp[-2].a));}
#line 4221 "Parser.tab.c"
    break;

  case 323: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 563 "Parser.y"
                                                                 {(yyval.a)=ast_newnode(eTOKEN_direct_abstract_declarator,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 4227 "Parser.tab.c"
    break;

  case 324: /* initializer: '{' initializer_list '}'  */
#line 567 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_initializer,1,(yyvsp[-1].a));}
#line 4233 "Parser.tab.c"
    break;

  case 325: /* initializer: '{' initializer_list ',' '}'  */
#line 568 "Parser.y"
                                       {(yyval.a)=ast_newnode(eTOKEN_initializer,1,(yyvsp[-2].a));}
#line 4239 "Parser.tab.c"
    break;

  case 326: /* initializer: assignment_expression  */
#line 569 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_initializer,1,(yyvsp[0].a));}
#line 4245 "Parser.tab.c"
    break;

  case 327: /* initializer_list: designation initializer  */
#line 573 "Parser.y"
                                  {(yyval.a)=ast_newnode(eTOKEN_initializer_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4251 "Parser.tab.c"
    break;

  case 328: /* initializer_list: initializer  */
#line 574 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_initializer_list,1,(yyvsp[0].a));}
#line 4257 "Parser.tab.c"
    break;

  case 329: /* initializer_list: initializer_list ',' designation initializer  */
#line 575 "Parser.y"
                                                       {(yyval.a)=ast_newnode(eTOKEN_initializer_list,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 4263 "Parser.tab.c"
    break;

  case 330: /* initializer_list: initializer_list ',' initializer  */
#line 576 "Parser.y"
                                           {(yyval.a)=ast_newnode(eTOKEN_initializer_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4269 "Parser.tab.c"
    break;

  case 331: /* designation: designator_list '='  */
#line 580 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_designation,1,(yyvsp[-1].a));}
#line 4275 "Parser.tab.c"
    break;

  case 332: /* designator_list: designator  */
#line 584 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_designator_list,1,(yyvsp[0].a));}
#line 4281 "Parser.tab.c"
    break;

  case 333: /* designator_list: designator_list designator  */
#line 585 "Parser.y"
                                     {(yyval.a)=ast_newnode(eTOKEN_designator_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4287 "Parser.tab.c"
    break;

  case 334: /* designator: '[' constant_expression ']'  */
#line 589 "Parser.y"
                                      {(yyval.a)=ast_newnode(eTOKEN_designator,1,(yyvsp[-1].a));}
#line 4293 "Parser.tab.c"
    break;

  case 335: /* designator: '.' identifier  */
#line 590 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_designator,1,(yyvsp[0].a));}
#line 4299 "Parser.tab.c"
    break;

  case 336: /* static_assert_declaration: static_assert '(' constant_expression ',' string_literal ')' ';'  */
#line 594 "Parser.y"
                                                                           {(yyval.a)=ast_newnode(eTOKEN_static_assert_declaration,3,(yyvsp[-6].a),(yyvsp[-4].a),(yyvsp[-2].a));}
#line 4305 "Parser.tab.c"
    break;

  case 337: /* statement: labeled_statement  */
#line 598 "Parser.y"
                            {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4311 "Parser.tab.c"
    break;

  case 338: /* statement: compound_statement  */
#line 599 "Parser.y"
                             {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4317 "Parser.tab.c"
    break;

  case 339: /* statement: expression_statement  */
#line 600 "Parser.y"
                               {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4323 "Parser.tab.c"
    break;

  case 340: /* statement: selection_statement  */
#line 601 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4329 "Parser.tab.c"
    break;

  case 341: /* statement: iteration_statement  */
#line 602 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4335 "Parser.tab.c"
    break;

  case 342: /* statement: jump_statement  */
#line 603 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_statement,1,(yyvsp[0].a));}
#line 4341 "Parser.tab.c"
    break;

  case 343: /* labeled_statement: identifier ':' statement  */
#line 607 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_labeled_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4347 "Parser.tab.c"
    break;

  case 344: /* labeled_statement: case constant_expression ':' statement  */
#line 608 "Parser.y"
                                                 {(yyval.a)=ast_newnode(eTOKEN_labeled_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4353 "Parser.tab.c"
    break;

  case 345: /* labeled_statement: default ':' statement  */
#line 609 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_labeled_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4359 "Parser.tab.c"
    break;

  case 346: /* compound_statement: '{' '}'  */
#line 613 "Parser.y"
                  {(yyval.a)=ast_newnode(eTOKEN_compound_statement,0);}
#line 4365 "Parser.tab.c"
    break;

  case 347: /* compound_statement: '{' block_item_list '}'  */
#line 614 "Parser.y"
                                   {(yyval.a)=ast_newnode(eTOKEN_compound_statement,1,(yyvsp[-1].a));}
#line 4371 "Parser.tab.c"
    break;

  case 348: /* block_item_list: block_item  */
#line 618 "Parser.y"
                     {(yyval.a)=ast_newcodeblock(eTOKEN_block_item_list,1,(yyvsp[0].a));}
#line 4377 "Parser.tab.c"
    break;

  case 349: /* block_item_list: block_item_list block_item  */
#line 619 "Parser.y"
                                     {(yyval.a)=ast_newcodeblock(eTOKEN_block_item_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4383 "Parser.tab.c"
    break;

  case 350: /* block_item: declaration  */
#line 623 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_block_item,1,(yyvsp[0].a));}
#line 4389 "Parser.tab.c"
    break;

  case 351: /* block_item: statement  */
#line 624 "Parser.y"
                    {(yyval.a)=ast_newnode(eTOKEN_block_item,1,(yyvsp[0].a));}
#line 4395 "Parser.tab.c"
    break;

  case 352: /* expression_statement: ';'  */
#line 628 "Parser.y"
              {(yyval.a)=ast_newnode(eTOKEN_expression_statement,0);}
#line 4401 "Parser.tab.c"
    break;

  case 353: /* expression_statement: expression ';'  */
#line 629 "Parser.y"
                         {(yyval.a)=ast_newnode(eTOKEN_expression_statement,1,(yyvsp[-1].a));}
#line 4407 "Parser.tab.c"
    break;

  case 354: /* selection_statement: if '(' expression ')' statement else statement  */
#line 633 "Parser.y"
                                                         {(yyval.a)=ast_newnode(eTOKEN_selection_statement,3,(yyvsp[-4].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 4413 "Parser.tab.c"
    break;

  case 355: /* selection_statement: if '(' expression ')' statement  */
#line 634 "Parser.y"
                                          {(yyval.a)=ast_newnode(eTOKEN_selection_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4419 "Parser.tab.c"
    break;

  case 356: /* selection_statement: switch '(' expression ')' statement  */
#line 635 "Parser.y"
                                              {(yyval.a)=ast_newnode(eTOKEN_switch_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4425 "Parser.tab.c"
    break;

  case 357: /* iteration_statement: while '(' expression ')' statement  */
#line 639 "Parser.y"
                                             {(yyval.a)=ast_newnode(eTOKEN_iteration_while_statement,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4431 "Parser.tab.c"
    break;

  case 358: /* iteration_statement: do statement while '(' expression ')' ';'  */
#line 640 "Parser.y"
                                                    {(yyval.a)=ast_newnode(eTOKEN_iteration_do_while_statement,2,(yyvsp[-5].a),(yyvsp[-2].a));}
#line 4437 "Parser.tab.c"
    break;

  case 359: /* iteration_statement: for '(' expression_statement expression_statement ')' statement  */
#line 641 "Parser.y"
                                                                          {(yyval.a)=ast_newnode(eTOKEN_iteration_for_statement,4,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 4443 "Parser.tab.c"
    break;

  case 360: /* iteration_statement: for '(' expression_statement expression_statement expression ')' statement  */
#line 642 "Parser.y"
                                                                                     {(yyval.a)=ast_newnode(eTOKEN_iteration_for_statement,5,(yyvsp[-6].a),(yyvsp[-4].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 4449 "Parser.tab.c"
    break;

  case 361: /* iteration_statement: for '(' declaration expression_statement ')' statement  */
#line 643 "Parser.y"
                                                                 {(yyval.a)=ast_newnode(eTOKEN_iteration_for_statement,4,(yyvsp[-5].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 4455 "Parser.tab.c"
    break;

  case 362: /* iteration_statement: for '(' declaration expression_statement expression ')' statement  */
#line 644 "Parser.y"
                                                                            {(yyval.a)=ast_newnode(eTOKEN_iteration_for_statement,5,(yyvsp[-6].a),(yyvsp[-4].a),(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[0].a));}
#line 4461 "Parser.tab.c"
    break;

  case 363: /* jump_statement: goto identifier ';'  */
#line 648 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_jump_statement,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4467 "Parser.tab.c"
    break;

  case 364: /* jump_statement: continue ';'  */
#line 649 "Parser.y"
                       {(yyval.a)=ast_newnode(eTOKEN_jump_statement,1,(yyvsp[-1].a));}
#line 4473 "Parser.tab.c"
    break;

  case 365: /* jump_statement: break ';'  */
#line 650 "Parser.y"
                    {(yyval.a)=ast_newnode(eTOKEN_jump_statement,1,(yyvsp[-1].a));}
#line 4479 "Parser.tab.c"
    break;

  case 366: /* jump_statement: return ';'  */
#line 651 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_jump_statement,1,(yyvsp[-1].a));}
#line 4485 "Parser.tab.c"
    break;

  case 367: /* jump_statement: return expression ';'  */
#line 652 "Parser.y"
                                {(yyval.a)=ast_newnode(eTOKEN_jump_statement,2,(yyvsp[-2].a),(yyvsp[-1].a));}
#line 4491 "Parser.tab.c"
    break;

  case 368: /* translation_unit: external_declaration  */
#line 656 "Parser.y"
                               {(yyval.a)=ast_newcodeblock(eTOKEN_translation_unit,1,(yyvsp[0].a));root=(yyval.a);}
#line 4497 "Parser.tab.c"
    break;

  case 369: /* translation_unit: translation_unit external_declaration  */
#line 657 "Parser.y"
                                                 {(yyval.a)=ast_newcodeblock(eTOKEN_translation_unit,2,(yyvsp[-1].a),(yyvsp[0].a));root=(yyval.a);}
#line 4503 "Parser.tab.c"
    break;

  case 370: /* external_declaration: function_definition  */
#line 661 "Parser.y"
                              {(yyval.a)=ast_newnode(eTOKEN_external_declaration,1,(yyvsp[0].a));}
#line 4509 "Parser.tab.c"
    break;

  case 371: /* external_declaration: declaration  */
#line 662 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_external_declaration,1,(yyvsp[0].a));}
#line 4515 "Parser.tab.c"
    break;

  case 372: /* class_name: identifier  */
#line 666 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_class_name,1,(yyvsp[0].a));}
#line 4521 "Parser.tab.c"
    break;

  case 373: /* class_declaration_list: class_name  */
#line 670 "Parser.y"
                     {(yyval.a)=ast_newcodeblock(eTOKEN_class_declaration_list,1,(yyvsp[0].a));}
#line 4527 "Parser.tab.c"
    break;

  case 374: /* class_declaration_list: class_declaration_list ',' class_name  */
#line 671 "Parser.y"
                                                {(yyval.a)=ast_newcodeblock(eTOKEN_class_declaration_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4533 "Parser.tab.c"
    break;

  case 375: /* class_declaration: class_specifier class class_declaration_list ';'  */
#line 675 "Parser.y"
                                                           {(yyval.a)=ast_newnode(eTOKEN_class_declaration,2,(yyvsp[-3].a),(yyvsp[-1].a));}
#line 4539 "Parser.tab.c"
    break;

  case 376: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 679 "Parser.y"
                                                                                {(yyval.a)=ast_newnode(eTOKEN_function_definition1,4,(yyvsp[-3].a),(yyvsp[-2].a),(yyvsp[-1].a),(yyvsp[0].a));}
#line 4545 "Parser.tab.c"
    break;

  case 377: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 680 "Parser.y"
                                                               {(yyval.a)=ast_newnode(eTOKEN_function_definition2,3,(yyvsp[-2].a),(yyvsp[-1].a),(yyvsp[0].a));}
#line 4551 "Parser.tab.c"
    break;

  case 378: /* declaration_list: declaration  */
#line 683 "Parser.y"
                      {(yyval.a)=ast_newnode(eTOKEN_declaration_list,1,(yyvsp[0].a));}
#line 4557 "Parser.tab.c"
    break;

  case 379: /* declaration_list: declaration_list declaration  */
#line 684 "Parser.y"
                                       {(yyval.a)=ast_newnode(eTOKEN_declaration_list,2,(yyvsp[-1].a),(yyvsp[0].a));}
#line 4563 "Parser.tab.c"
    break;

  case 380: /* pointer_scope: POINTER_SCOPE '<' pointer_scope_list '>'  */
#line 687 "Parser.y"
                                                         {(yyval.a)=ast_newnode(eTOKEN_POINTER_SCOPE,1,(yyvsp[-1].a));}
#line 4569 "Parser.tab.c"
    break;

  case 381: /* pointer_scope: POINTER_SCOPE  */
#line 688 "Parser.y"
                    {(yyval.a)=ast_newtoken(eTOKEN_POINTER_SCOPE,0);}
#line 4575 "Parser.tab.c"
    break;

  case 382: /* pointer_scope_list: identifier  */
#line 692 "Parser.y"
                     {(yyval.a)=ast_newnode(eTOKEN_pointer_scope_list,1,(yyvsp[0].a));}
#line 4581 "Parser.tab.c"
    break;

  case 383: /* pointer_scope_list: pointer_scope_list ',' identifier  */
#line 693 "Parser.y"
                                            {(yyval.a)=ast_newnode(eTOKEN_pointer_scope_list,2,(yyvsp[-2].a),(yyvsp[0].a));}
#line 4587 "Parser.tab.c"
    break;


#line 4591 "Parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 697 "Parser.y"

#include <stdio.h>
