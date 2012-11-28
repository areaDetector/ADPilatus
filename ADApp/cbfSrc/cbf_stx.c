/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DATA = 258,
     DEFINE = 259,
     SAVE = 260,
     SAVEEND = 261,
     LOOP = 262,
     ITEM = 263,
     CATEGORY = 264,
     COLUMN = 265,
     STRING = 266,
     CBFWORD = 267,
     BINARY = 268,
     UNKNOWN = 269,
     COMMENT = 270,
     ERROR = 271
   };
#endif
/* Tokens.  */
#define DATA 258
#define DEFINE 259
#define SAVE 260
#define SAVEEND 261
#define LOOP 262
#define ITEM 263
#define CATEGORY 264
#define COLUMN 265
#define STRING 266
#define CBFWORD 267
#define BINARY 268
#define UNKNOWN 269
#define COMMENT 270
#define ERROR 271




/* Copy the first part of user declarations.  */



/**********************************************************************
 * cbf.stx -- cbf parser                                              *
 *                                                                    *
 * Version 0.7.7 19 February 2007                                     *
 *                                                                    *
 *                          Paul Ellis and                            *
 *         Herbert J. Bernstein (yaya@bernstein-plus-sons.com)        *
 *                                                                    *
 * (C) Copyright 2006, 2007 Herbert J. Bernstein                      *
 *                                                                    *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 * YOU MAY REDISTRIBUTE THE CBFLIB PACKAGE UNDER THE TERMS OF THE GPL *
 *                                                                    *
 * ALTERNATIVELY YOU MAY REDISTRIBUTE THE CBFLIB API UNDER THE TERMS  *
 * OF THE LGPL                                                        *
 *                                                                    *
 **********************************************************************/

/*************************** GPL NOTICES ******************************
 *                                                                    *
 * This program is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU General Public License as     *
 * published by the Free Software Foundation; either version 2 of     *
 * (the License, or (at your option) any later version.               *
 *                                                                    *
 * This program is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      *
 * GNU General Public License for more details.                       *
 *                                                                    *
 * You should have received a copy of the GNU General Public License  *
 * along with this program; if not, write to the Free Software        *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA           *
 * 02111-1307  USA                                                    *
 *                                                                    *
 **********************************************************************/

/************************* LGPL NOTICES *******************************
 *                                                                    *
 * This library is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU Lesser General Public         *
 * License as published by the Free Software Foundation; either       *
 * version 2.1 of the License, or (at your option) any later version. *
 *                                                                    *
 * This library is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *
 * Lesser General Public License for more details.                    *
 *                                                                    *
 * You should have received a copy of the GNU Lesser General Public   *
 * License along with this library; if not, write to the Free         *
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,    *
 * MA  02110-1301  USA                                                *
 *                                                                    *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 *                    Stanford University Notices                     *
 *  for the CBFlib software package that incorporates SLAC software   *
 *                 on which copyright is disclaimed                   *
 *                                                                    *
 * This software                                                      *
 * -------------                                                      *
 * The term �this software�, as used in these Notices, refers to      *
 * those portions of the software package CBFlib that were created by *
 * employees of the Stanford Linear Accelerator Center, Stanford      *
 * University.                                                        *
 *                                                                    *
 * Stanford disclaimer of copyright                                   *
 * --------------------------------                                   *
 * Stanford University, owner of the copyright, hereby disclaims its  *
 * copyright and all other rights in this software.  Hence, anyone    *
 * may freely use it for any purpose without restriction.             *
 *                                                                    *
 * Acknowledgement of sponsorship                                     *
 * ------------------------------                                     *
 * This software was produced by the Stanford Linear Accelerator      *
 * Center, Stanford University, under Contract DE-AC03-76SFO0515 with *
 * the Department of Energy.                                          *
 *                                                                    *
 * Government disclaimer of liability                                 *
 * ----------------------------------                                 *
 * Neither the United States nor the United States Department of      *
 * Energy, nor any of their employees, makes any warranty, express or *
 * implied, or assumes any legal liability or responsibility for the  *
 * accuracy, completeness, or usefulness of any data, apparatus,      *
 * product, or process disclosed, or represents that its use would    *
 * not infringe privately owned rights.                               *
 *                                                                    *
 * Stanford disclaimer of liability                                   *
 * --------------------------------                                   *
 * Stanford University makes no representations or warranties,        *
 * express or implied, nor assumes any liability for the use of this  *
 * software.                                                          *
 *                                                                    *
 * Maintenance of notices                                             *
 * ----------------------                                             *
 * In the interest of clarity regarding the origin and status of this *
 * software, this and all the preceding Stanford University notices   *
 * are to remain affixed to any copy or derivative of this software   *
 * made or distributed by the recipient and are to be affixed to any  *
 * copy of software made or distributed by the recipient that         *
 * contains a copy or derivative of this software.                    *
 *                                                                    *
 * Based on SLAC Software Notices, Set 4                              *
 * OTT.002a, 2004 FEB 03                                              *
 **********************************************************************/



/**********************************************************************
 *                               NOTICE                               *
 * Creative endeavors depend on the lively exchange of ideas. There   *
 * are laws and customs which establish rights and responsibilities   *
 * for authors and the users of what authors create.  This notice     *
 * is not intended to prevent you from using the software and         *
 * documents in this package, but to ensure that there are no         *
 * misunderstandings about terms and conditions of such use.          *
 *                                                                    *
 * Please read the following notice carefully.  If you do not         *
 * understand any portion of this notice, please seek appropriate     *
 * professional legal advice before making use of the software and    *
 * documents included in this software package.  In addition to       *
 * whatever other steps you may be obliged to take to respect the     *
 * intellectual property rights of the various parties involved, if   *
 * you do make use of the software and documents in this package,     *
 * please give credit where credit is due by citing this package,     *
 * its authors and the URL or other source from which you obtained    *
 * it, or equivalent primary references in the literature with the    *
 * same authors.                                                      *
 *                                                                    *
 * Some of the software and documents included within this software   *
 * package are the intellectual property of various parties, and      *
 * placement in this package does not in any way imply that any       *
 * such rights have in any way been waived or diminished.             *
 *                                                                    *
 * With respect to any software or documents for which a copyright    *
 * exists, ALL RIGHTS ARE RESERVED TO THE OWNERS OF SUCH COPYRIGHT.   *
 *                                                                    *
 * Even though the authors of the various documents and software      *
 * found here have made a good faith effort to ensure that the        *
 * documents are correct and that the software performs according     *
 * to its documentation, and we would greatly appreciate hearing of   *
 * any problems you may encounter, the programs and documents any     *
 * files created by the programs are provided **AS IS** without any   *
 * warranty as to correctness, merchantability or fitness for any     *
 * particular or general use.                                         *
 *                                                                    *
 * THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF    *
 * PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES CREATED BY USE OF THE   *
 * PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS   *
 * OR DOCUMENTS OR FILE OR FILES AND NOT WITH AUTHORS OF THE          *
 * PROGRAMS OR DOCUMENTS.                                             *
 **********************************************************************/

/**********************************************************************
 *                                                                    *
 *                           The IUCr Policy                          *
 *      for the Protection and the Promotion of the STAR File and     *
 *     CIF Standards for Exchanging and Archiving Electronic Data     *
 *                                                                    *
 * Overview                                                           *
 *                                                                    *
 * The Crystallographic Information File (CIF)[1] is a standard for   *
 * information interchange promulgated by the International Union of  *
 * Crystallography (IUCr). CIF (Hall, Allen & Brown, 1991) is the     *
 * recommended method for submitting publications to Acta             *
 * Crystallographica Section C and reports of crystal structure       *
 * determinations to other sections of Acta Crystallographica         *
 * and many other journals. The syntax of a CIF is a subset of the    *
 * more general STAR File[2] format. The CIF and STAR File approaches *
 * are used increasingly in the structural sciences for data exchange *
 * and archiving, and are having a significant influence on these     *
 * activities in other fields.                                        *
 *                                                                    *
 * Statement of intent                                                *
 *                                                                    *
 * The IUCr's interest in the STAR File is as a general data          *
 * interchange standard for science, and its interest in the CIF,     *
 * a conformant derivative of the STAR File, is as a concise data     *
 * exchange and archival standard for crystallography and structural  *
 * science.                                                           *
 *                                                                    *
 * Protection of the standards                                        *
 *                                                                    *
 * To protect the STAR File and the CIF as standards for              *
 * interchanging and archiving electronic data, the IUCr, on behalf   *
 * of the scientific community,                                       *
 *                                                                    *
 * * holds the copyrights on the standards themselves,                *
 *                                                                    *
 * * owns the associated trademarks and service marks, and            *
 *                                                                    *
 * * holds a patent on the STAR File.                                 *
 *                                                                    *
 * These intellectual property rights relate solely to the            *
 * interchange formats, not to the data contained therein, nor to     *
 * the software used in the generation, access or manipulation of     *
 * the data.                                                          *
 *                                                                    *
 * Promotion of the standards                                         *
 *                                                                    *
 * The sole requirement that the IUCr, in its protective role,        *
 * imposes on software purporting to process STAR File or CIF data    *
 * is that the following conditions be met prior to sale or           *
 * distribution.                                                      *
 *                                                                    *
 * * Software claiming to read files written to either the STAR       *
 * File or the CIF standard must be able to extract the pertinent     *
 * data from a file conformant to the STAR File syntax, or the CIF    *
 * syntax, respectively.                                              *
 *                                                                    *
 * * Software claiming to write files in either the STAR File, or     *
 * the CIF, standard must produce files that are conformant to the    *
 * STAR File syntax, or the CIF syntax, respectively.                 *
 *                                                                    *
 * * Software claiming to read definitions from a specific data       *
 * dictionary approved by the IUCr must be able to extract any        *
 * pertinent definition which is conformant to the dictionary         *
 * definition language (DDL)[3] associated with that dictionary.      *
 *                                                                    *
 * The IUCr, through its Committee on CIF Standards, will assist      *
 * any developer to verify that software meets these conformance      *
 * conditions.                                                        *
 *                                                                    *
 * Glossary of terms                                                  *
 *                                                                    *
 * [1] CIF:  is a data file conformant to the file syntax defined     *
 * at http://www.iucr.org/iucr-top/cif/spec/index.html                *
 *                                                                    *
 * [2] STAR File:  is a data file conformant to the file syntax       *
 * defined at http://www.iucr.org/iucr-top/cif/spec/star/index.html   *
 *                                                                    *
 * [3] DDL:  is a language used in a data dictionary to define data   *
 * items in terms of "attributes". Dictionaries currently approved    *
 * by the IUCr, and the DDL versions used to construct these          *
 * dictionaries, are listed at                                        *
 * http://www.iucr.org/iucr-top/cif/spec/ddl/index.html               *
 *                                                                    *
 * Last modified: 30 September 2000                                   *
 *                                                                    *
 * IUCr Policy Copyright (C) 2000 International Union of              *
 * Crystallography                                                    *
 **********************************************************************/

#ifdef __cplusplus

extern "C" {

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cbf_ad.h"
#include "cbf_tree_ad.h"
#include "cbf_alloc_ad.h"
#include "cbf_context_ad.h"
#include "cbf_ws_ad.h"

#define yyparse       cbf_parse
#define yylex         cbf_lex_wrapper
#define yyerror(x)    cbf_syntax_error(((cbf_handle)(((void **)context)[2])),(x))
#define YYLEX_PARAM   context
#define YYPARSE_PARAM context
typedef union
{
  int          errorcode;
  const char  *text;
  cbf_node    *node;
} YYSTYPE;
#define YYSTYPE_IS_DECLARED


#ifdef alloca
#undef alloca
#endif

#define alloca(x) (NULL)

#define YYINITDEPTH 200
#define YYMAXDEPTH  200

int cbf_lex (cbf_handle handle, YYSTYPE *val ); 
/*
  vcontext[0]  -- (void *)file
  vcontext[1]  -- (void *)handle->node
  vcontext[2]  -- (void *)handle
  vcontext[3]  -- (void *)node
*/


int cbf_lex_wrapper (void *val, void *vcontext)
{
  int token;
  
  cbf_handle cbfhandle;
  
  do {
  
    cbfhandle = (cbf_handle)((void **) vcontext) [2]; 

    token = cbf_lex (cbfhandle, (YYSTYPE *)val);
        
    if ( token == COMMENT && ((YYSTYPE *)val)->text ) {

      cbf_free_text(&(((YYSTYPE *)val)->text),NULL);

    }

  } while (token == COMMENT);

  return token;
}

int cbf_syntax_error (cbf_handle handle, const char *message)
{

  cbf_log( handle, message, CBF_LOGERROR|CBF_LOGSTARTLOC );
  return 0;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
  int          errorcode;
  const char  *text;
  cbf_node    *node;
}
/* Line 193 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   82

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  17
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNRULES -- Number of states.  */
#define YYNSTATES  85

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      15,    16
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     8,    11,    14,    16,    18,
      20,    22,    24,    26,    28,    31,    34,    37,    39,    41,
      43,    46,    49,    52,    55,    58,    61,    64,    67,    70,
      73,    76,    79,    82,    85,    88,    91,    94,    97,   100,
     103,   106,   109,   112,   115,   118,   121,   124,   127,   130,
     133,   136,   139,   142,   145,   148,   151,   154,   157,   160,
     163,   166,   169,   173,   175,   177,   179,   181,   183,   185,
     187,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      18,     0,    -1,    19,    -1,    22,    -1,    -1,    18,    43,
      -1,    23,    43,    -1,    19,    -1,    20,    -1,    27,    -1,
      32,    -1,    24,    -1,    41,    -1,    28,    -1,    22,    44,
      -1,    23,    44,    -1,    21,    44,    -1,    35,    -1,    40,
      -1,    36,    -1,    23,     6,    -1,    22,    45,    -1,    21,
      45,    -1,    25,    45,    -1,    26,    45,    -1,    25,    46,
      -1,    26,    47,    -1,    22,    47,    -1,    21,    47,    -1,
      26,    49,    -1,    27,    49,    -1,    28,    49,    -1,    29,
      49,    -1,    22,    42,    -1,    21,    42,    -1,    29,    42,
      -1,    29,    45,    -1,    31,    45,    -1,    29,    47,    -1,
      31,    47,    -1,    30,    46,    -1,    31,    49,    -1,    32,
      49,    -1,    23,    45,    -1,    33,    45,    -1,    34,    45,
      -1,    33,    46,    -1,    23,    47,    -1,    34,    47,    -1,
      34,    49,    -1,    35,    49,    -1,    36,    49,    -1,    37,
      49,    -1,    23,    42,    -1,    37,    42,    -1,    37,    45,
      -1,    39,    45,    -1,    37,    47,    -1,    39,    47,    -1,
      38,    46,    -1,    39,    49,    -1,    40,    49,    -1,    22,
      48,    49,    -1,     7,    -1,     3,    -1,     5,    -1,     9,
      -1,    10,    -1,     8,    -1,     4,    -1,    11,    -1,    12,
      -1,    13,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   397,   397,   400,   408,   413,   441,   475,   489,   492,
     504,   516,   527,   539,   553,   567,   591,   606,   614,   622,
     632,   647,   657,   669,   685,   703,   714,   734,   748,   766,
     779,   790,   801,   815,   820,   825,   836,   851,   867,   887,
     905,   925,   937,   952,   959,   973,   987,   995,  1008,  1030,
    1043,  1052,  1060,  1073,  1078,  1088,  1099,  1115,  1131,  1147,
    1164,  1174,  1186,  1204,  1207,  1212,  1217,  1222,  1227,  1232,
    1237,  1240,  1243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATA", "DEFINE", "SAVE", "SAVEEND",
  "LOOP", "ITEM", "CATEGORY", "COLUMN", "STRING", "CBFWORD", "BINARY",
  "UNKNOWN", "COMMENT", "ERROR", "$accept", "cbf", "cbfstart",
  "CbfThruDBName", "ErrorCbfWODBName", "CbfThruDBElement",
  "CbfThruSFElement", "CbfThruSaveFrame", "CbfThruCategory",
  "CbfThruColumn", "CbfThruAssignment", "ErrorCbfThruExtraValue",
  "CbfThruLoopStart", "CbfThruLoopCategory", "CbfThruLoopColumn",
  "CbfThruLoopAssignment", "CbfThruSFCategory", "CbfThruSFColumn",
  "CbfThruSFAssignment", "ErrorCbfThruExtraSFValue", "CbfThruSFLoopStart",
  "CbfThruSFLoopCategory", "CbfThruSFLoopColumn",
  "CbfThruSFLoopAssignment", "CbfThruFunction", "Loop", "DataBlockName",
  "SaveFrameName", "CategoryName", "ColumnName", "ItemName",
  "FunctionName", "Value", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    17,    18,    18,    19,    20,    20,    21,    22,    22,
      22,    22,    22,    22,    23,    23,    23,    23,    23,    23,
      24,    25,    25,    25,    25,    26,    26,    26,    26,    27,
      28,    28,    28,    29,    29,    29,    30,    30,    31,    31,
      31,    32,    32,    33,    33,    33,    34,    34,    34,    35,
      36,    36,    36,    37,    37,    38,    38,    39,    39,    39,
      40,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    49,    49
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     7,     8,     0,     3,     0,    11,     0,     0,
       9,    13,     0,     0,     0,    10,     0,     0,    17,    19,
       0,     0,     0,    18,    12,     1,    64,     5,    65,    63,
      68,    66,    34,    16,    22,    28,    69,    33,    14,    21,
      27,     0,    20,    53,     6,    15,    43,    47,    67,    23,
      25,    70,    71,    72,    24,    26,    29,    30,    31,    35,
      36,    38,    32,    40,    37,    39,    41,    42,    44,    46,
      45,    48,    49,    50,    51,    54,    55,    57,    52,    59,
      56,    58,    60,    61,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    32,    27,    33,    34,    50,
      35,    41,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -11
static const yytype_int8 yypact[] =
{
     -11,     3,    11,   -11,    70,    59,    46,   -11,    29,    61,
      69,    69,    49,    13,    61,    69,    29,    61,    69,    69,
      49,    13,    61,    69,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,    69,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,   -11,
     -11,   -11,   -11,   -11,   -11,    23,    15,    41,    10,     4,
      28,   -11,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int8 yytable[] =
{
      57,    58,    62,    25,    66,    67,    26,    72,    73,    74,
      78,    -2,    82,    83,    -2,    39,    46,    63,    49,    54,
      69,    44,    60,    48,    64,    79,    68,    70,    37,    43,
      76,    84,    80,    40,    47,    59,     0,    55,    31,    48,
      61,     0,    65,    75,     0,    71,    38,    45,    77,    26,
      81,    28,    42,    29,    30,    31,    29,    30,    31,     0,
      51,    52,    53,    36,    28,     0,    29,    30,    31,    30,
      31,     0,    51,    52,    53,    28,     0,    29,    30,    31,
      51,    52,    53
};

static const yytype_int8 yycheck[] =
{
      10,    11,    12,     0,    14,    15,     3,    17,    18,    19,
      20,     0,    22,    23,     3,     5,     6,    13,     8,     9,
      16,     6,    12,    10,    14,    21,    16,    17,     5,     6,
      20,    41,    22,     5,     6,    12,    -1,     9,     9,    10,
      12,    -1,    14,    20,    -1,    17,     5,     6,    20,     3,
      22,     5,     6,     7,     8,     9,     7,     8,     9,    -1,
      11,    12,    13,     4,     5,    -1,     7,     8,     9,     8,
       9,    -1,    11,    12,    13,     5,    -1,     7,     8,     9,
      11,    12,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     3,    43,     5,     7,
       8,     9,    42,    44,    45,    47,     4,    42,    44,    45,
      47,    48,     6,    42,    43,    44,    45,    47,    10,    45,
      46,    11,    12,    13,    45,    47,    49,    49,    49,    42,
      45,    47,    49,    46,    45,    47,    49,    49,    45,    46,
      45,    47,    49,    49,    49,    42,    45,    47,    49,    46,
      45,    47,    49,    49,    49
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
                                                  (yyval.node) = (yyvsp[(1) - (1)].node);  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 3:

    {
                
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))
                                                  
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_ROOT))
                                                ;}
    break;

  case 4:

    {
                                                  (yyval.node) = ((void **) context) [1];
                                                ;}
    break;

  case 5:

    {
                
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_DATABLOCK,
                                                                                                                  (cbf_node *) NULL))
             
                                                  if (strlen((yyvsp[(2) - (2)].text))==0) {
                                                  
                                                    cbf_log((cbf_handle)(((void **)context)[2]),"empty data block name",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                  
                                                  }

                                                  
                                                  if (!cbf_find_last_child(&((yyval.node)),(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].text)) ){
                                                  
                                                    cbf_log((cbf_handle)(((void **)context)[2]),"duplicate data block name",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                  
                                                  }

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_DATABLOCK, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
    
                                                ;}
    break;

  case 6:

    { 
                                                  cbf_log((cbf_handle)(((void **)context)[2]),"prior save frame not terminated",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                      
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_ROOT))
                
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_DATABLOCK,
                                                                                                                  (cbf_node *) NULL))
             
                                                  if (strlen((yyvsp[(2) - (2)].text))==0) {
                                                  
                                                    cbf_log((cbf_handle)(((void **)context)[2]),"empty data block name",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                  
                                                  }

                                                  
                                                  if (!cbf_find_last_child(&((yyval.node)),(yyval.node),(yyvsp[(2) - (2)].text)) ){
                                                  
                                                    cbf_log((cbf_handle)(((void **)context)[2]),"duplicate data block name",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                  
                                                  }

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_DATABLOCK, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
 
                                                  ;}
    break;

  case 7:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (1)].node), CBF_DATABLOCK, NULL))
                    
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  cbf_log((cbf_handle)(((void **)context)[2]),"no data block",
                                                    CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                 
                                                ;}
    break;

  case 8:

    {
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 9:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))
                                                                                                                   
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                   
                                                  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 10:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))
                                                  
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                   
                                                  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 11:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                   
                                                  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 12:

    {
						  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_FUNCTION,
                                                                                                                  NULL))
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                   
                                                  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 13:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                  NULL))
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                   
                                                  ((void **)context)[3] = NULL;
                                                ;}
    break;

  case 14:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_CATEGORY,
                                                                                                                   NULL))

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_SAVEFRAME, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                     
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                   
                                                  ((void **)context)[3] = NULL;
                                                  
                                                ;}
    break;

  case 15:

    { 
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_CATEGORY,
                                                                                                                   NULL))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_SAVEFRAME,
                                                                                                                   NULL))

                                                  cbf_log((cbf_handle)(((void **)context)[2]),"save frame not terminated",
                                                      CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                                      
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_SAVEFRAME, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                   
                                                  ((void **)context)[3] = NULL;
                                                  
                                                ;}
    break;

  case 16:

    {

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_CATEGORY,
                                                                                                                   NULL))

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_SAVEFRAME, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  ((void **)context)[3] = NULL;
                                                  
                                                ;}
    break;

  case 17:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))
                                                                                                                   
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                ;}
    break;

  case 18:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))
                                                  
                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                ;}
    break;

  case 19:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (1)].node), CBF_CATEGORY,
                                                                                                                   NULL))

                                                  (yyval.node) = (yyvsp[(1) - (1)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                ;}
    break;

  case 20:

    {
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_CATEGORY,
                                                                                                                   NULL))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(1) - (2)].node), CBF_SAVEFRAME,
                                                                                                                   NULL))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))


                                                ;}
    break;

  case 21:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                ;}
    break;

  case 22:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                 ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                ;}
    break;

  case 23:

    { cbf_log ((cbf_handle)(((void **)context)[2]),"data name with no value1",
                                                    CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                    
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                ;}
    break;

  case 24:

    { cbf_log ((cbf_handle)(((void **)context)[2]),"data name with no value",
                                                    CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                    
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                    
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                ;}
    break;

  case 25:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                  
                                                ;}
    break;

  case 26:

    { cbf_log ((cbf_handle)(((void **)context)[2]),"data name with no value",CBF_LOGERROR|CBF_LOGSTARTLOC);
                
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))

                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_DATABLOCK))
                                                  
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))                                                 
                                                   
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                    
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                  
                                                ;}
    break;

  case 27:

    {
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                                        
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                ;}
    break;

  case 28:

    {
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                    
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                ;}
    break;

  case 29:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_set_columnrow ((yyval.node), 0, (yyvsp[(2) - (2)].text), 1))
                      
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 30:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                     
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                     
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                  
                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)),NULL))

                                                ;}
    break;

  case 31:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);

                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)),NULL))

                                                ;}
    break;

  case 32:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"loop value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);

                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)),NULL))

                                                ;}
    break;

  case 33:

    {
                                                  cbf_failnez (cbf_make_node (&((yyval.node)), CBF_LINK, NULL, NULL))

                                                  cbf_failnez (cbf_set_link ((yyval.node), (yyvsp[(1) - (2)].node)))
                                                ;}
    break;

  case 34:

    {
                                                  cbf_failnez (cbf_make_node (&((yyval.node)), CBF_LINK, NULL, NULL))

                                                  cbf_failnez (cbf_set_link ((yyval.node), (yyvsp[(1) - (2)].node)))
                                                ;}
    break;

  case 35:

    {
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"redundant \"loop_\" ",CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                  
                                                  cbf_failnez (cbf_make_node (&((yyval.node)), CBF_LINK, NULL, NULL))

                                                  cbf_failnez (cbf_set_link ((yyval.node), (yyvsp[(1) - (2)].node)))
                                                ;}
    break;

  case 36:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                 ;}
    break;

  case 37:

    {
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_DATABLOCK))

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 38:

    {
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                                                                                                                      
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 39:

    {
                                                  (yyval.node) = ((void **)context)[3];

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 40:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                 
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 41:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_shift_link ((yyval.node)))

                                                  cbf_failnez (cbf_add_columnrow ((yyval.node), (yyvsp[(2) - (2)].text)))
                     
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 42:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_shift_link ((yyval.node)))

                                                  cbf_failnez (cbf_add_columnrow ((yyval.node), (yyvsp[(2) - (2)].text)))
                    
                                                  cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 43:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                ;}
    break;

  case 44:

    {  cbf_log((cbf_handle)(((void **)context)[2]), "data name with no value", CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))
                                                  
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                  
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                ;}
    break;

  case 45:

    {  cbf_log((cbf_handle)(((void **)context)[2]), "data name with no value", CBF_LOGERROR|CBF_LOGSTARTLOC);
                
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))
                                                  
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                  
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);
                                                ;}
    break;

  case 46:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                ;}
    break;

  case 47:

    {
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                                                                    
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                ;}
    break;

  case 48:

    {
                                                  cbf_log((cbf_handle)(((void **)context)[2]), "data name with no value", CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                  
                                                  (yyval.node) = (yyvsp[(1) - (2)].node); cbf_failnez (cbf_undo_links (&((yyval.node))))
                                                  
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyval.node), CBF_SAVEFRAME))
                                                   
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                                                                    
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))
                                                ;}
    break;

  case 49:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_set_columnrow ((yyval.node), 0, (yyvsp[(2) - (2)].text), 1))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 50:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                  
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);

                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)), NULL))

                                                ;}
    break;

  case 51:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                  
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);

                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)), NULL))
                                                ;}
    break;

  case 52:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                  
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"loop value without tag",CBF_LOGERROR|CBF_LOGSTARTLOC);

                                                  cbf_failnez(cbf_free_text(&((yyvsp[(2) - (2)].text)), NULL))

                                                ;}
    break;

  case 53:

    {
                                                  cbf_failnez (cbf_make_node (&((yyval.node)), CBF_LINK, NULL, NULL))

                                                  cbf_failnez (cbf_set_link ((yyval.node), (yyvsp[(1) - (2)].node)))
                                                ;}
    break;

  case 54:

    {
                                                  cbf_log ((cbf_handle)(((void **)context)[2]),"redundant \"loop_\" ",CBF_LOGERROR|CBF_LOGSTARTLOC);
                                                  
                                                  cbf_failnez (cbf_make_node (&((yyval.node)), CBF_LINK, NULL, NULL))

                                                  cbf_failnez (cbf_set_link ((yyval.node), (yyvsp[(1) - (2)].node)))
                                                ;}
    break;

  case 55:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))
                                                  
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 56:

    {
                                                  cbf_failnez (cbf_find_parent (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_SAVEFRAME))

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))
                                                 
                                                  ((void **)context)[3] = (void *)(yyval.node);

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 57:

    {
                                                  cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_CATEGORY, (yyvsp[(2) - (2)].text)))
                                                  
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, cbf_copy_string(NULL,(yyvsp[(2) - (2)].text),0)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 58:

    {
                                                  (yyval.node) = ((void **)context)[3];

                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyval.node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 59:

    {
                                                  cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (2)].node), CBF_COLUMN, (yyvsp[(2) - (2)].text)))
                                                  
                                                  ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
                                                  
                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyval.node), CBF_COLUMN,
                                                                                                                  (cbf_node *)(((void **)context)[3])))

                                                  cbf_failnez (cbf_set_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  cbf_failnez (cbf_add_link ((yyvsp[(1) - (2)].node), (yyval.node)))

                                                  (yyval.node) = (yyvsp[(1) - (2)].node);
                                                ;}
    break;

  case 60:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_shift_link ((yyval.node)))

                                                  cbf_failnez (cbf_add_columnrow ((yyval.node), (yyvsp[(2) - (2)].text)))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 61:

    {
                                                  (yyval.node) = (yyvsp[(1) - (2)].node);

                                                  cbf_failnez (cbf_shift_link ((yyval.node)))

                                                  cbf_failnez (cbf_add_columnrow ((yyval.node), (yyvsp[(2) - (2)].text)))

                                                  cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(2) - (2)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
                                                ;}
    break;

  case 62:

    {								
		
					        	cbf_failnez (cbf_make_new_child (&((yyval.node)), (yyvsp[(1) - (3)].node), CBF_FUNCTION, (yyvsp[(2) - (3)].text)))
                                                  
                                                        ((cbf_handle)(((void **)context)[2]))->node=(cbf_node *)(yyval.node);
													
							cbf_failnez(cbf_apply_ws((cbf_handle)(((void **)context)[2])))
													
							((void **)context)[3] = (void *)(yyval.node);
						
							cbf_failnez (cbf_make_child (&((yyval.node)), (yyvsp[(1) - (3)].node), CBF_COLUMN, (yyvsp[(2) - (3)].text)))
							
							cbf_failnez (cbf_set_columnrow ((yyval.node), 0, (yyvsp[(3) - (3)].text), 1))	
                                                  	
							cbf_failnez (cbf_validate ((cbf_handle)(((void **)context)[2]), (cbf_node *) (yyvsp[(3) - (3)].text), CBF_VALUE,
                                                                                                                  (cbf_node *) (yyval.node)))
							;}
    break;

  case 64:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 65:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 66:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 67:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 68:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 69:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 70:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 71:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;

  case 72:

    {
                                                  (yyval.text) = (yyvsp[(1) - (1)].text);
                                                ;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





#ifdef __cplusplus

}

#endif

