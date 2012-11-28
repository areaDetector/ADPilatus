/**********************************************************************
 * cbf_lex -- lexical scanner for CBF tokens                          *
 *                                                                    *
 * Version 0.9.0 18 October 2009                                      *
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

#include "cbf_ad.h"
#include "cbf_compress_ad.h"
#include "cbf_lex_ad.h"
#include "cbf_codes_ad.h"
#include "cbf_file_ad.h"
#include "cbf_string_ad.h"
#include "cbf_read_binary_ad.h"
#include "cbf_read_mime_ad.h"
#include "cbf_alloc_ad.h"
#include "cbf_ws_ad.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>


  /* Return an error code */

#define cbf_errornez(f,v) { if (((v)->errorcode = (f)) != 0) return ERROR; }

#define cbf_onerrornez(f,v,c) { if (((v)->errorcode = (f)) != 0) { { c; } return ERROR; } }


  /* Return a copy of the text */

int cbf_return_text (int code, YYSTYPE *val, const char *text, char type)
{

  val->text = cbf_copy_string (NULL, text, type);

  if (!val->text)
  {
    val->errorcode = CBF_ALLOC;

    return ERROR;
  }

  return code;
}

  /* Back up one character in the file */
  
int cbf_lex_unget (cbf_file *file, YYSTYPE *val, int c[5]) {

    if ( file->temporary || file->characters )  {
    
      if (file->characters > file->characters_base)  {
     
        file->characters--;
      
        file->characters_used++;
      
        file->characters_size++;
      
      } else  {
      
        if (file->characters_used >= file->characters_size)  {
        
          cbf_errornez(cbf_set_io_buffersize(file,file->characters_size+1),val)
        	
        }
        
        if (file->characters_used) memmove(file->characters_base,file->characters_base+1,file->characters_used);
        
        file->characters_used++;
        
        *(file->characters) = c[0];
      	
      }
    	
    } else  {

      ungetc(c[0],file->stream);
      	
    }
    
    c[0] = c[1];
    
    c[1] = c[2];
    
    c[2] = c[3];
    
    c[3] = c[4];
    
    c[4] = ' ';
  
    file->column--;
  
    file->last_read='\0';
    
    return 0;
}


  /* Get the next token */

int cbf_lex (cbf_handle handle, YYSTYPE *val )
{
  int data, define, save, loop, item, column, comment, string, ascii,
      cqueue[5],
      reprocess, errorcode, mime, encoding, 
      bits, sign, checked_digest, real, depth, q3;

  long id, position;

  unsigned int file_column, compression;

  size_t size, length=0, code_size, dimover, dimfast, dimmid, dimslow, padding, ii;

  const char *line;
  
  cbf_file *file;

  char out_line [(((sizeof (void *) +
                    sizeof (long int) * 2 +
                    sizeof (int) * 3) * CHAR_BIT) >> 2) + 57
                    +15+((5*sizeof (size_t)*3*CHAR_BIT)>>2)];

  char digest [25], new_digest [25];
  
  const char * byteorder;
  
  file = handle->file;

  cbf_errornez (cbf_reset_buffer (file), val)
  
  if (file->read_headers & CBF_PARSE_WS) {
  
    if (handle->commentfile == NULL){
    	
      cbf_errornez(cbf_make_file(&(handle->commentfile),NULL), val)

    }
    
    
    /* 
       The commentfile buffer will contain a copy of the whitespace and
       comments constructed as raw material for components of a bracketed
       construct.  Each component begins with the ascii-encoded 1-based
       column number followed by a colon.  White space may follow, then
       an optional comment, which is always followed by a newline.
       
       see cbf_apply_ws for the code that processes this buffer
       
     */
  	
      if (handle->commentfile->buffer_used > 0 ) {
          
          cbf_errornez (cbf_save_character (handle->commentfile, ','), val)
          
      }
      
      cbf_errornez (cbf_set_ws_column  (handle->commentfile, file->column+1), val)
      

  }

  cqueue[0] = file->last_read;

  cqueue[4] = cqueue[3] = cqueue[2] = cqueue[1] = ' ';
  
  if (file->column == 0) cqueue[0] = '\n';

  column = cqueue[0] == '.';

  comment = cqueue[0] == '#';

  reprocess = (column || comment);

  data = define = save = loop = item = string = !reprocess;

  comment = !column;

  do
  {
    cbf_errornez (cbf_get_buffer (file, &line, &length), val)

    if (reprocess) {

      reprocess = 0;

    } else {
    
      cqueue[4] = cqueue[3];

      cqueue[3] = cqueue[2];

      cqueue[2] = cqueue[1];
      
      cqueue[1] = cqueue[0];

      cqueue[0] = cbf_read_character (file);

      if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;
      
      if (file->column == file->columnlimit+1) {
      
        cbf_log(handle, "over line size limit", CBF_LOGWARNING|CBF_LOGCURRENTLOC);

      }

      if (isspace (cqueue[0])) {
      
        if (cqueue[0]== '\013' || cqueue[0] == '\014') 
          cbf_log(handle,"invalid space character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
      
      }  else {

        if (!(file->read_headers & CBF_PARSE_UTF8)) {

            if ( cqueue[0] != EOF && ((unsigned char)cqueue[0] > 126 || (unsigned char )cqueue[0] < 32 ) ) {
                cbf_log(handle,"invalid character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            }
          
        } else {

            if ( cqueue[0] != EOF &&
                ( ((unsigned char)cqueue[0] < 32)
                || ((unsigned char)cqueue[0] == 127) ) ){
                    cbf_log(handle,"invalid character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            } 
        }
    

      }


    }

      /* Discard spaces ([[:space:]]+)  and mark starting point */


    if (length == 0) {

      if (isspace (cqueue[0])) {
      
      if (cqueue[0]== '\013' || cqueue[0] == '\014') cbf_log(handle,"invalid space character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
      
      if (file->read_headers & CBF_PARSE_WS) {
       
          cbf_errornez (cbf_save_character_trim (handle->commentfile, (cqueue[0]&0xFF)), val)
                 
      }

      continue;
      
      }

      handle->startline = file->line;

      handle->startcolumn = file->column;

    }


       /* DATA ([Dd][Aa][Tt][Aa][_][^[:space:]]*) */

    if (data) {

      if (length < 5) {

         data = toupper (cqueue[0]) == "DATA_" [length];

      } else {
      
        if ( length == 81 ) cbf_log(handle, "data block name exceeds 75 characters",
          CBF_LOGERROR|CBF_LOGSTARTLOC);
        
        if ((file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
            	
            	return cbf_return_text (DATA, val, &line [5], 0);
            }

        if (isspace (cqueue[0]) || cqueue[0] == EOF)

          return cbf_return_text (DATA, val, &line [5], 0);

      }

    }

       /* DEFINE ([Dd][Ee][Ff][Ii][Nn][Ee]_[^[:space:]]*) */

    if (define && (file->read_headers & CBF_PARSE_DEFINES)) {

      if (length < 8) {

         define = toupper (cqueue[0]) == "DEFINE_" [length];

      } else {
      
        if ( length == 84 ) cbf_log(handle, "function name exceeds 75 characters",
          CBF_LOGERROR|CBF_LOGSTARTLOC);

		if (cqueue[0] == EOF) cbf_log(handle, "function has no definition", 
			CBF_LOGERROR|CBF_LOGSTARTLOC);
		
		if ((file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	   cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	   
            	};
            	
            	return cbf_return_text (DEFINE, val, &line [8], 0);
        }

        if (isspace (cqueue[0]) || cqueue[0] == EOF)

		
        if (isspace (cqueue[0]))

          return cbf_return_text (DEFINE, val, &line [8], 0);

      }

    }

       /* SAVE ([Ss][Aa][Vv][Ee][_][^[:space:]]*) */

    if (save) {

      if (length < 5) {

         save = toupper (cqueue[0]) == "SAVE_" [length];

      } else {

        if ( length == 81 ) cbf_log(handle, "save frame name exceeds 75 characters",
          CBF_LOGERROR|CBF_LOGSTARTLOC);
        
		if ((file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
            	
            	if (length==5) return SAVEEND;
            	
            	return cbf_return_text (SAVE, val, &line [5], 0);
        }

        if (isspace (cqueue[0]) || cqueue[0] == EOF) {

          if (length==5) return SAVEEND;

          return cbf_return_text (SAVE, val, &line [5], 0);

        }

      }

    }

       /* LOOP ([Ll][Oo][Oo][Pp][_]) */

    if (loop)
    {
    
      loop = 0;

      if (length < 5) loop = (toupper (cqueue[0]) == "LOOP_" [length]);

      if ((!loop) && (length == 5)) {
      
        if ((file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
            	
            	return LOOP;
        }
      	
        if (isspace(cqueue[0]) || cqueue[0] == EOF) return LOOP;
      
        cbf_log(handle, "\"loop_\" must be followed by white space", 
          CBF_LOGERROR|CBF_LOGSTARTLOC );
            
        cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            
        return LOOP;

      }

    }


       /* ITEM ([_][^[:space:]\.]+) */

    if (item) {

      if (length == 0) {

        item = cqueue[0] == '_';

      } else {

        item = !isspace (cqueue[0]) && cqueue[0] != '.' && cqueue[0] != EOF;
        
        if (item && (file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
            	
            	item = 0;
        }


        if (length >= 2 && !item) {

          if (cqueue[0] == '.') {

            if ( length > 74 ) cbf_log(handle, "category name exceeds 73 characters",
              CBF_LOGERROR|CBF_LOGSTARTLOC);
            
            return cbf_return_text (CATEGORY, val, &line [1], 0);
            
          }

          else {
          
            /* if ( length > 75 ) cbf_log(handle, "data item name exceeds 75 characters",
              CBF_LOGERROR|CBF_LOGSTARTLOC); */
           	
            return cbf_return_text (ITEM, val, &line [0], 0);
          }

        }

      }

    }


      /* COLUMN (\.[^[:space:]]+) */

    if (column)

    {

      column = (!isspace(cqueue[0]) && cqueue[0] != EOF);
      
      if (column && (file->read_headers & CBF_PARSE_CIF2_DELIMS) 
            && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
            
            	cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
            	
            	if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
            	
            	column = 0;
      }


      if (!column)

        return cbf_return_text (COLUMN, val, &line [1], 0);

    }


      /* STRING ([\'][^'\n]*[\':space:]) |
                ([\"][^"\n]*[\":space:]) |
                or any of the bracketed constructs 
        The parse is controlled by the variables
        depth and index.
        
        depth 0 top level
        depth 1, 2, ... within a bracketed construct
          state 0 looking for the next item
          state 1 found the first item, looking for 
            then end of the item 
            
        on entry, the commentfile buffer has all the leading
        whitespace.  This can be left as is to be picked up
        by the parser, except for the bracketed constructs.
        For the bracketed constructs, we need to bracket
        the possible internal comments and whitespace.    
                
                */

    if (string && length==0 && 
      (cqueue[0] == '\'' || cqueue[0] == '"' 
      || ((file->read_headers & CBF_PARSE_BRC) && cqueue[0]=='{')
      || ((file->read_headers & CBF_PARSE_PRN) && cqueue[0]=='(')
      || ((file->read_headers & CBF_PARSE_BKT) && cqueue[0]=='[')
      ) ) {
      
      int *tokentype;
      
      int **vtokentype;
      
      size_t tokentype_size;

      int *state;
      
      int **vstate;
      
      size_t state_size;

      int *index;
      
      int **vindex;
      
      size_t index_size;
      
      tokentype_size = state_size = index_size = 0;
      
      vtokentype = &tokentype;
      
      vstate = &state;
      
      vindex = &index;
      

      
      /* Add the boundary character to the text */

      cbf_errornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val);
      
      /* initialize depth */
      
      depth =  0;
      
      /* for the bracketed constructs, set up the stacks */
      
      if (((file->read_headers & CBF_PARSE_BRC) && cqueue[0]=='{')
          || ((file->read_headers & CBF_PARSE_PRN) && cqueue[0]=='(')
          || ((file->read_headers & CBF_PARSE_BKT) && cqueue[0]=='[')) {              	
        depth = 1;
            
        tokentype_size = state_size = index_size = 100;
            
        cbf_errornez(cbf_alloc((void **)vtokentype, NULL, sizeof(int), tokentype_size), val)
            
        cbf_onerrornez(cbf_alloc((void **)vstate, NULL, sizeof(int), state_size), 
          val, cbf_free((void **)vtokentype, NULL))

        cbf_onerrornez(cbf_alloc((void **)vindex, NULL, sizeof(int), index_size), 
          val, {cbf_free((void **)vtokentype, NULL); cbf_free((void **)vstate, NULL);})
          
        state[depth-1] = index[depth-1] = 0;

        switch(cqueue[0]) {
            
          case ('[') : tokentype[depth-1]=CBF_TOKEN_BKTSTRING; break;
          case ('{') : tokentype[depth-1]=CBF_TOKEN_BRCSTRING; break;
          case ('(') : tokentype[depth-1]=CBF_TOKEN_PRNSTRING; break;
            	
        }
          
      }  
      
      /* now loop though the characters until the terminator */

      do {
      
        int savechar=1;  /* flag to save the character */
         
        int breakout=0;  /* flag to break out of the loop */
      
        /* refresh the line array in case the buffer expanded */
      
        cbf_errornez (cbf_get_buffer (file, &line, &length), val)
          
        cqueue[4] = cqueue[3];
        
        cqueue[3] = cqueue[2];
          
        cqueue[2] = cqueue[1];
      
        cqueue[1] = cqueue[0];

        cqueue[0] = cbf_read_character (file);
          
        if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;
        
        /* check for a triple quote */
      
        q3 = (((file->read_headers & CBF_PARSE_TQ ) != 0)
                         && length > 3
                         && (line[0]=='\'' || line[0]=='"')
                         && line[1] ==  line[0] && line[2] == line[1]);

        if (file->column == file->columnlimit+1) {
      
          cbf_log(handle, "over line size limit", CBF_LOGWARNING|CBF_LOGCURRENTLOC);

        }
        
        /* report invalid characters */
      	
        if (isspace (cqueue[0])) {
      
          if (cqueue[0]== '\013' || cqueue[0] == '\014') 
            cbf_log(handle,"invalid space character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
          
          if ((file->read_headers & CBF_PARSE_WS) && depth > 0) {
       
            cbf_errornez (cbf_save_character_trim (handle->commentfile, (cqueue[0]&0xFF)), val)
                 
          }

      
        }  else {

          if ( cqueue[0] != EOF && ((unsigned char)cqueue[0] > 126 || (unsigned char )cqueue[0] < 32 ) )
            cbf_log(handle,"invalid character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);

        }
        
        if (depth == 0)  {
        
          /* handle the non-bracketed case */ 
          
          if ((file->read_headers & CBF_PARSE_CIF2_DELIMS)) {
 
            string = !(!q3 && cqueue[0] == line[0] 
              && cqueue[1]!='\\' && length > 1)
              && !( q3 && length > 5
                   && cqueue[0] == line[0]
                   && cqueue[1] == line[1] 
                   && cqueue[2] == line[2]
                   && (cqueue[3] != '\\' ));
              
              if (!string) {
              
                cbf_errornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val)

                cqueue[4] = cqueue[3];
              
                cqueue[3] = cqueue[2];
              
                cqueue[2] = cqueue[1];
              
                cqueue[1] = cqueue[0];
              
                cqueue[0] = cbf_read_character (file);
                  
                if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;
              
                if (!isspace(cqueue[0])) {
              
                  cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
              
                }
             }
              
          } else {
        
          string = !(!q3 && cqueue[1] == line[0] && length > 1 && isspace(cqueue[0]))
                   && !( q3 && length > 5
                         && cqueue[1] == line[0] 
                         && cqueue[2] == line[1] 
                         && cqueue[3] == line[2]
                         && isspace(cqueue[0]));
          }

          if ( string && ( (cqueue[0] == '\n' && !q3) || cqueue[0] == EOF ) )  {
            
            if (line[0] == '\'' && !q3) 

              cbf_log(handle,"premature end of single-quoted string", 
                CBF_LOGWARNING|CBF_LOGSTARTLOC);
            
            else { if (line[0] == '"' && !q3)

              cbf_log(handle,"premature end of double-quoted string", 
                CBF_LOGWARNING|CBF_LOGSTARTLOC);
                
              else if (q3)
              
                cbf_log(handle,"premature end of triple-quoted string", 
                  CBF_LOGWARNING|CBF_LOGSTARTLOC);
                
                
            }
                
            string = 0;
            
              
          }

          if ( !string ) {

            if ( cqueue[1] == line[0] && file->buffer_used > 0 ) {

              file->buffer_used--;

              file->buffer [file->buffer_used] = '\0';
              
              if (q3 && cqueue[2] == line[0] && file->buffer_used > 0 ) {
              	
                file->buffer_used--;

                file->buffer [file->buffer_used] = '\0';
               
                if (q3 && cqueue[3] == line[0] && file->buffer_used > 0 ) {

                  file->buffer_used--;

                  file->buffer [file->buffer_used] = '\0';

                }

              }
            
            }

            if (line [0] == '\'')

              return cbf_return_text (STRING, val, &line [1],
                                                  CBF_TOKEN_SQSTRING);

            else

              return cbf_return_text (STRING, val, &line [1],
                                                  CBF_TOKEN_DQSTRING);
          }
          
          cbf_errornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val);
                    
          continue;

        	
        } else {
        
          /* handle the bracketed cases */
          
          savechar = 0;
          
          breakout = 0;
           
            switch (state[depth-1]) {
                    
                    /* 
                     In state 1 we have started an item and are looking for
                     the end of the item.
                     
                     The possibilities are that the item we are parsing is
                     1.  A single-quoted string
                     2.  A double-quoted string
                     3.  A triple-single-quoted string (only if CBF_PARSE_TQ is set) 
                     4.  A triple-double-quoted string (only if CBF_PARSE_TQ is set)
                     5.  A parenthesis-bracketed string
                     6.  A brace-bracketed string
                     7.  A bracket-bracketed string
                     8.  A blank-bracketed string (requires a warning)
                     9.  A bracket-bracketed item (requires a warning)
                     
                     In all cases, the depth will have been increased by 1 and the
                     appropriate token type stored in tokentype[depth-1], and
                     index[depth-1] will accumulate the number of characters
                     
                     It is important that this code come before the code
                     for state 2 so that we can fall through.
                     
                     */
                    
                case (1):
                    
                    /* See if we are looking for a terminal quote mark */
                    
                    if (cbf_token_term(tokentype[depth-1])=='\'' 
                        || cbf_token_term(tokentype[depth-1])=='"' ) {
                        
                        string = ( cqueue[1] != cbf_token_term(tokentype[depth-1])
                                  || index[depth-1] < 1 
                                  || !(isspace(cqueue[0])||cqueue[0]==','||cqueue[0]==cbf_token_term(tokentype[depth-2]) ) );
                        
                        if (index[depth-1] == 2  && cqueue[0]==cqueue[1] && cqueue[1]==cqueue[2] && (cqueue[3] != '\\')
                            && (file->read_headers & CBF_PARSE_TQ ) != 0) {
                            tokentype[depth-1] = 
                            tokentype[depth-1]==CBF_TOKEN_SQSTRING?CBF_TOKEN_TSQSTRING:CBF_TOKEN_TDQSTRING;
                        }
                        
                        if (tokentype[depth-1]==CBF_TOKEN_TSQSTRING 
                            || tokentype[depth-1]==CBF_TOKEN_TDQSTRING) {
                            string = !(cqueue[1] == cbf_token_term(tokentype[depth-1])
                                       && cqueue[2] == cqueue[1] 
                                       && cqueue[3]==cqueue[2]
                                       && index[depth-1] > 5
                                       && (isspace(cqueue[0])||cqueue[0]==','||cqueue[0]==cbf_token_term(tokentype[depth-2])
                                           ));
                            
                            if (string && cqueue[0] == EOF) {
                                
                                if (cbf_token_term(tokentype[depth-1]) == '\'') {
                                    
                                    cbf_log(handle,"ended before end of triple single-quoted string", 
                                            CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                    
                                } else {
                                    
                                    cbf_log(handle,"ended before end of triple double-quoted string", 
                                            CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                    
                                }
                                
                                string = 0;
                                
                            }
                            
                        } else {  /* not treble-quoted, just ' or " single quoted */
                            
                            if ( string && ( cqueue[0] == '\n' || cqueue[0] == EOF ) )  {
                                
                                if (cbf_token_term(tokentype[depth-1]) == '\'') {
                                    
                                    cbf_log(handle,"ended before end of single-quoted string", 
                                            CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                    
                                } else {
                                    
                                    cbf_log(handle,"ended before end of double-quoted string", 
                                            CBF_LOGWARNING|CBF_LOGSTARTLOC);
                                    
                                }
                                
                                string = 0;
                                
                            }
                            
                            
                        }
                        
                        if ( !string ) {
                            depth--;  /* drop down from this level */
                            state[depth-1]++;
                            
                            if (depth==1 && cqueue[0]==cbf_token_term(tokentype[0])) {
                                
                                int ttype=tokentype[0];
                                int ii;
                                
                                cbf_free((void **)vtokentype, NULL);
                                cbf_free((void **)vstate, NULL);
                                cbf_free((void **)vindex, NULL);
                                
                                /* trim all trailing whitespace in bracketed constructs */
                                
                                for (ii=length-1; ii >=0 && isspace(line[ii]); ii--);
                                
                                file->buffer[ii+1] = '\0';
                                
                                return cbf_return_text (STRING, val, (line[1]=='\\'&&line[2]=='\n')?(&line[3]):(&line [1]), ttype);
                                
                                
                            }

                            savechar = 0;
                            if (cqueue[0] == EOF || cqueue[0] == '\n') {
                                
                                if (cqueue[0] == EOF) breakout = 1;
                                break;
                                
                            }
                            
                            if (!isspace(cqueue[0])) savechar = 1;
                            /* intentionally fail to do a break */
                            
                        } else {
                            
                            savechar = 1;
                            breakout = 0;
                            index[depth-1]++;
                            break;
                            
                        }
                        
                    } else {
                        
                        /* We are not looking for a terminal quote mark */
                        
                        /* on a blank-delimited item we may end on a blank,
                         comma or the next level terminator, or to handle
                         such constructs as [*[5]] on the starting delimiter
                         of an embedded bracketed structure*/
                        
                        if (cbf_token_term(tokentype[depth-1])==' ') {
                            
                            
                            /* we are still in a blank-delimited item if the
                             character is not a space, not a comma and not an
                             opening bracket and not a closing bracket
                             bracket from the next level.  The string also ends
                             at eol or eof */
                            
                            string = ( !isspace(cqueue[0])) 
                            && !(cqueue[0]==','||
                                 cqueue[0]=='('||
                                 cqueue[0]=='['||
                                 cqueue[0]=='{'||
                                 cqueue[0]==cbf_token_term(tokentype[depth-2]) );
                            
                            if ( string && ( cqueue[0] == '\n' || cqueue[0] == EOF ) )  {
                                
                                string = 0;
                                
                            }
                            
                            if ( !string ) {
                                if (file->read_headers & CBF_PARSE_WS) {
                                    if(cqueue[0]==')' || cqueue[0]=='}' || cqueue[0]==']'){
                                        
                                        cbf_onerrornez (cbf_save_character_trim (handle->commentfile, ')'), val, 
                                                        { cbf_free((void **)vtokentype, NULL);
                                                        cbf_free((void **)vstate, NULL);
                                                        cbf_free((void **)vindex, NULL);})
                                        
                                    }
                                    if(cqueue[0]=='[' || cqueue[0]=='{' || cqueue[0]=='['){
                                        
                                        cbf_onerrornez (cbf_save_character_trim (handle->commentfile, ','), val, 
                                                        { cbf_free((void **)vtokentype, NULL);
                                                        cbf_free((void **)vstate, NULL);
                                                        cbf_free((void **)vindex, NULL);})
                                        
                                        cbf_onerrornez (cbf_save_character_trim (handle->commentfile, '('), val, 
                                                        { cbf_free((void **)vtokentype, NULL);
                                                        cbf_free((void **)vstate, NULL);
                                                        cbf_free((void **)vindex, NULL);})
                                        
                                        cbf_errornez (cbf_set_ws_column  (handle->commentfile, file->column+1), val)
                                        
                                    }
                                }

                                if(cqueue[0]=='(' || cqueue[0]=='{' || cqueue[0]=='['){
                                    
                                    savechar = 0;
                                    
                                    index[depth-2]++;
                                                                        
                                    index[depth-1] = state[depth-1] = 0;
                                    
                                    switch(cqueue[0]) {
                                            
                                        case ('[')  : tokentype[depth-1]=CBF_TOKEN_BKTSTRING; break;
                                        case ('{')  : tokentype[depth-1]=CBF_TOKEN_BRCSTRING; break;
                                        case ('(')  : tokentype[depth-1]=CBF_TOKEN_PRNSTRING; break;
                                            
                                    }
                                    cbf_onerrornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val,
                                                    {cbf_free((void **)vtokentype, NULL);
                                                    cbf_free((void **)vstate, NULL);
                                                    cbf_free((void **)vindex, NULL);})
                                    
                                    breakout = 0;
                                    break;
                                    
                                    
                                }
                                
                                if (!isspace(cqueue[0])&&depth>1&&cqueue[0]!=',') depth--;
                                depth--;
                                state[depth-1]++;
                                savechar = 1;
                                breakout = 0;
                                
                                
                                if (depth==0 && cqueue[0]==cbf_token_term(tokentype[0])) {
                                    
                                    int ttype=tokentype[0];
                                    int ii;
                                    
                                    cbf_free((void **)vtokentype, NULL);
                                    cbf_free((void **)vstate, NULL);
                                    cbf_free((void **)vindex, NULL);
                                    
                                    /* trim all trailing whitespace in bracketed constructs */
                                    
                                    for (ii=length-1; ii >=0 && isspace(line[ii]); ii--);
                                    
                                    file->buffer[ii+1] = '\0';
                                    
                                    return cbf_return_text (STRING, val, (line[1]=='\\'&&line[2]=='\n')?(&line[3]):(&line [1]), ttype);
                                    
                                    
                                }
                                
                                if (cqueue[0] == EOF) breakout = 1;
                                break;
                                
                            } else {
                                savechar = 1;
                                breakout = 0;
                                index[depth-1]++;
                                break;
                            }
                            
                        } else {
                            
                            if (cbf_token_term(tokentype[depth-1])==';') {
                                
                                string = ( cqueue[2] != '\n'
                                          || cqueue[1] != cbf_token_term(tokentype[depth-1]) 
                                          || index[depth-1] < 3 
                                          || !(isspace(cqueue[0]) || cqueue[0]==','||cqueue[0]==cbf_token_term(tokentype[depth-2])||(file->read_headers & CBF_PARSE_CIF2_DELIMS) ) );
                                
                                if ( cqueue[0] == EOF )   {
                                    
                                    string = 0;
                                    
                                }
                                
                                if ( !string ) {
                                    
                                    if (file->read_headers & CBF_PARSE_WS) {
                                        
                                        cbf_onerrornez (cbf_save_character_trim (handle->commentfile, ')'), val, 
                                                        { cbf_free((void **)vtokentype, NULL);
                                                        cbf_free((void **)vstate, NULL);
                                                        cbf_free((void **)vindex, NULL);})
                                        
                                    }
                                    
                                    depth--;
                                    state[depth-1]++;
                                    savechar = 0;
                                    breakout = 0;
                                    
                                    if (depth==1 && cqueue[0]==cbf_token_term(tokentype[0])) {
                                        
                                        int ttype=tokentype[0];
                                        int ii;
                                        
                                        cbf_free((void **)vtokentype, NULL);
                                        cbf_free((void **)vstate, NULL);
                                        cbf_free((void **)vindex, NULL);
                                        
                                        /* trim all trailing whitespace in bracketed constructs */
                                        
                                        for (ii=length-1; ii >=0 && isspace(line[ii]); ii--);
                                        
                                        file->buffer[ii+1] = '\0';
                                        
                                        return cbf_return_text (STRING, val, (line[1]=='\\'&&line[2]=='\n')?(&line[3]):(&line [1]), ttype);
                                        
                                        
                                    }
                                    
                                    if (cqueue[0] == EOF) breakout = 1;
                                    break;
                                } else {
                                    savechar = 1;
                                    breakout = 0;
                                    index[depth-1]++;
                                    break;
                                }
                                
                            } else {
                                
                                cbf_log(handle,"unrecognized bracketed construct item", 
                                        CBF_LOGWARNING|CBF_LOGSTARTLOC);
                            }
                            
                        }
                        
                    }
                    
                    /* 
                     In state 2 we have completed an item and need to scan for
                     a comma or a terminator.  Since we are not breaking out the
                     items, we merge this case with state 0.
                     
                     */
                    
                case (2):
                    
                    /* In state 0 we are looking for an item for the construct
                     We may encounter a comment, a space, a comma, a terminator 
                     for the construct or the beginning of an item
                     
                     If we are parsing whitespace, comments and space simply get
                     appended to the whitespace.  
                     
                     */
                    
                case (0):
                    
                    if (cqueue[0]=='#') {
                        
                        /* if we are parsing whitespace and encounter a comment
                         the entire comment including the '\n' gets appended to
                         the whitespace, converting an EOF to a '\n'
                         
                         */
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_onerrornez (cbf_save_character_trim (handle->commentfile, (cqueue[0]&0xFF)), val, 
                                            { cbf_free((void **)vtokentype, NULL);
                                            cbf_free((void **)vstate, NULL);
                                            cbf_free((void **)vindex, NULL);})
                            
                        }
                        
                        
                        do {
                            cqueue[4] = cqueue[3];
                            
                            cqueue[3] = cqueue[2];
                            
                            cqueue[2] = cqueue[1];
                            
                            cqueue[1] = cqueue[0];
                            
                            cqueue[0] = cbf_read_character (file);
                            
                            if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;
                            
                            if (file->column == file->columnlimit+1) {
                                
                                cbf_log(handle, "over line size limit", CBF_LOGWARNING|CBF_LOGCURRENTLOC);
                                
                            }
                            
                            if (file->read_headers & CBF_PARSE_WS) {
                                
                                if (cqueue[0] == EOF) {
                                    
                                    cbf_onerrornez (cbf_save_character_trim (handle->commentfile, '\n'), val, 
                                                    { cbf_free((void **)vtokentype, NULL);
                                                    cbf_free((void **)vstate, NULL);
                                                    cbf_free((void **)vindex, NULL);})
                                    
                                } else {
                                    
                                    cbf_onerrornez (cbf_save_character_trim (handle->commentfile, (cqueue[0]&0xFF)), val, 
                                                    { cbf_free((void **)vtokentype, NULL);
                                                    cbf_free((void **)vstate, NULL);
                                                    cbf_free((void **)vindex, NULL);})
                                    
                                }
                                
                            }
                            
                            
                            if (isspace (cqueue[0])) {
                                
                                if (cqueue[0]== '\013' || cqueue[0] == '\014') 
                                    cbf_log(handle,"invalid space character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
                                
                            } 
                            
                            if ( cqueue[0] != EOF && ((unsigned char)cqueue[0] > 126 || (unsigned char )cqueue[0] < 32 ) )
                                cbf_log(handle,"invalid character",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
                            
                            
                        } while (cqueue[0] != '\n' && cqueue[0] != EOF);
                        
                    }
                    
                    if (cqueue[0]==EOF) {
                        
                        int ttype=tokentype[0];
                        
                        cbf_log(handle,"file ended before end of bracketed construct", 
                                CBF_LOGWARNING|CBF_LOGSTARTLOC);
                        
                        cbf_free((void **)vtokentype, NULL);
                        cbf_free((void **)vstate, NULL);
                        cbf_free((void **)vindex, NULL);
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_errornez (cbf_save_character_trim (handle->commentfile, '\n'), val)
                            
                            
                        }
                        
                        return cbf_return_text (STRING, val, (line[1]=='\\'&&line[2]=='\n')?(&line[3]):(&line [1]), ttype);
                        
                        
                    }
                    
                    if (isspace(cqueue[0])) {
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_errornez (cbf_save_character_trim (handle->commentfile, (cqueue[0]&0xFF)), val)
                            
                        }
                        savechar = 0;
                        breakout = 0;
                        break;
                        
                    }
                    
                    
                    if (cqueue[0]==',' ) {
                        
                        savechar = 1;           /* Keep the comma */
                        breakout = 0;
                        /* depth--; */          /* Stay at this level */
                        index[depth-1]++;
                        state[depth-1] = 0;     /* Search for a non-blank */
                        
                        /* If we encounter a comma, it is time to break up the whitespace as well */
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_errornez (cbf_save_character_trim (handle->commentfile, ','), val)
                            
                            cbf_errornez (cbf_set_ws_column  (handle->commentfile, file->column+1), val)
                            
                        }
                        
                        break;
                        
                    }
                    
                    if (cqueue[0]==cbf_token_term(tokentype[depth-1]) 
                        && (cbf_token_term(tokentype[depth-1])==';'?'\n':cqueue[1])==cqueue[1]) {
                        
                        savechar = 1;
                        breakout = 0;
                        if (depth > 0)depth--; /* end the bracket */
                        
                        if (depth==0) {
                            
                            int ttype=tokentype[0];
                            int ii;
                            
                            cbf_free((void **)vtokentype, NULL);
                            cbf_free((void **)vstate, NULL);
                            cbf_free((void **)vindex, NULL);
                            
                            /* trim all trailing whitespace in bracketed constructs */
                            
                            for (ii=length-1; ii >=0 && isspace(line[ii]); ii--);
                            
                            file->buffer[ii+1] = '\0';
                            
                            return cbf_return_text (STRING, val, (line[1]=='\\'&&line[2]=='\n')?(&line[3]):(&line [1]), ttype);
                            
                            
                        }
                        
                        /* If we encounter the closing bracket, it is time to break up the whitespace as well */
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_errornez (cbf_save_character_trim (handle->commentfile, ')'), val)
                            
                        }
                        
                        
                        state[depth-1]++;
                        break;
                        
                        
                    }
                    
                    if ( !isspace(cqueue[0])) {
                        
                        if (file->read_headers & CBF_PARSE_WS) {
                            
                            cbf_onerrornez (cbf_save_character_trim (handle->commentfile, ','), val, 
                                            { cbf_free((void **)vtokentype, NULL);
                                            cbf_free((void **)vstate, NULL);
                                            cbf_free((void **)vindex, NULL);})
                            
                            if (cqueue[0] == '[' || cqueue[0] == '(' || cqueue[0] == '{') {
                                
                                cbf_onerrornez (cbf_save_character_trim (handle->commentfile, '('), val, 
                                                { cbf_free((void **)vtokentype, NULL);
                                                cbf_free((void **)vstate, NULL);
                                                cbf_free((void **)vindex, NULL);})
                                
                                
                            }
                            
                            cbf_onerrornez (cbf_set_ws_column  (handle->commentfile, file->column+1), val, 
                                            { cbf_free((void **)vtokentype, NULL);
                                            cbf_free((void **)vstate, NULL);
                                            cbf_free((void **)vindex, NULL);})
                            
                        }
                        if (state[depth-1]==2) {
                            
                            /* if (!(length==3 && line[1]=='\\' && line[2]=='\n')) {
                             
                             cbf_onerrornez (cbf_save_character_trim (file, ' '), val, 
                             { cbf_free((void **)vtokentype, NULL);
                             cbf_free((void **)vstate, NULL);
                             cbf_free((void **)vindex, NULL);})
                             
                             }
                             
                             */
                            
                            state[depth-1]=0;
                            
                        }
                        
                        state[depth-1]++;
                        
                        savechar = 0;
                        
                        depth++;
                        
                        
                        if (depth > tokentype_size) {
                            
                            cbf_onerrornez(cbf_realloc((void **)vtokentype, NULL, sizeof(int),tokentype_size*2),
                                           val,{cbf_free((void **)vtokentype, NULL);
                                           cbf_free((void **)vstate, NULL);
                                           cbf_free((void **)vindex, NULL);})
                            
                            tokentype_size *= 2;
                            
                        }
                        
                        if (depth > state_size) {
                            
                            cbf_onerrornez(cbf_realloc((void **)vstate, NULL, sizeof(int),state_size*2),
                                           val,{cbf_free((void **)vtokentype, NULL);
                                           cbf_free((void **)vstate, NULL);
                                           cbf_free((void **)vindex, NULL);})
                            
                            state_size *= 2;
                            
                        }
                        
                        
                        if (depth > index_size) {
                            
                            cbf_onerrornez(cbf_realloc((void **)vindex, NULL, sizeof(int),index_size*2),
                                           val,{cbf_free((void **)vtokentype, NULL);
                                           cbf_free((void **)vstate, NULL);
                                           cbf_free((void **)vindex, NULL);})
                            
                            index_size *= 2;
                            
                        }
                        
                        index[depth-1] = state[depth-1] = 0;
                        
                        switch(cqueue[0]) {
                                
                            case ('\'') : tokentype[depth-1]=CBF_TOKEN_SQSTRING; state[depth-1] = 1; break;
                            case ('"')  : tokentype[depth-1]=CBF_TOKEN_DQSTRING; state[depth-1] = 1; break;
                            case ('[')  : tokentype[depth-1]=CBF_TOKEN_BKTSTRING; break;
                            case ('{')  : tokentype[depth-1]=CBF_TOKEN_BRCSTRING; break;
                            case ('(')  : tokentype[depth-1]=CBF_TOKEN_PRNSTRING; break;
                            case (';')  : 
                                if (cqueue[1]=='\n') {
                                    tokentype[depth-1]=CBF_TOKEN_SCSTRING; state[depth-1] = 1; 
                                    cbf_onerrornez (cbf_save_character_trim (file, '\n'), val,
                                                    {cbf_free((void **)vtokentype, NULL);
                                                    cbf_free((void **)vstate, NULL);
                                                    cbf_free((void **)vindex, NULL);})
                                    break;
                                }
                            default:  tokentype[depth-1]= CBF_TOKEN_WORD; state[depth-1] = 1; break;
                                
                        }
                        cbf_onerrornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val,
                                        {cbf_free((void **)vtokentype, NULL);
                                        cbf_free((void **)vstate, NULL);
                                        cbf_free((void **)vindex, NULL);})
                        
                        breakout = 0;
                        break;
                        
                    }
                    
                    
                    savechar = 1;
                    breakout = 0;
                    break;
                    
            }

            if (savechar) {
            
              cbf_onerrornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val,
                {cbf_free((void **)vtokentype, NULL);
                cbf_free((void **)vstate, NULL);
                cbf_free((void **)vindex, NULL);})
                
                if (cqueue[0]=='\n' && line[1]=='\\' && file->buffer_used > 3 && line[2]=='\n' && file->buffer[file->buffer_used-2]=='\\') {
                    
                    file->buffer_used -=2;
                    
                    cqueue[0] = file->buffer[file->buffer_used-1];
                    
                    file->buffer[file->buffer_used] = '\0';
                    
                }
            	
            }
            
            if (breakout) break;
            
          }
  
      } while (cqueue[0] != EOF);
    	
    } else  {
    
      string = 0;
    	
    }

       /* COMMENT ([#][^\n]*) */

      if (comment) {
          
          if (length == 0) {
              
              comment = cqueue[0] == '#';
              
          } else  {
              
              comment = (cqueue[0] != '\n' && cqueue[0]!= EOF);
              
              if ((! comment) && !(file->read_headers & CBF_PARSE_WS)) {
                  
                  return cbf_return_text (COMMENT, val, &line [1], 0);
              }
          }
          
          if (!comment && length != 0) {
              
              cbf_errornez (cbf_get_buffer (file, &line, &length), val)
              
              for (ii = 0; ii < length; ii++) {
                  
                  cbf_errornez (cbf_save_character_trim (handle->commentfile, line[ii]), val)
                  
              }
              
              cbf_errornez (cbf_save_character_trim (handle->commentfile, '\n'), val)
              
              cbf_errornez (cbf_reset_buffer (file), val)
              
              cbf_errornez (cbf_get_buffer (file, &line, &length), val)
              
              cqueue[4] = cqueue[3] = cqueue[2] = cqueue[1] = ' ';
              
              column = reprocess = 0;
              
              data = save = loop = item = string = comment = 1;
              
              continue;
              
          }
      }

       /* CBFWORD ([^[:space:]]+) */

    if (!data && !loop && !item && !comment && !string && !column) {
          
      if (length && (file->read_headers & CBF_PARSE_CIF2_DELIMS) 
          && (cqueue[0] == '{' || cqueue[0] == '}' || cqueue[0] == '\'' || cqueue[0] == '"' || cqueue[0] == ',' || cqueue[0] == ':')) {
          
          cbf_log(handle,"invalid separator ",CBF_LOGWARNING|CBF_LOGCURRENTLOC);
          
          if (cqueue[0] != ',' && cqueue[0] != ':' ) {
            	
            	  cbf_errornez(cbf_lex_unget(file,val,cqueue), val)
            	  
            	}
          
          cqueue[0] = ' ';
      }
              

      if (length && (isspace (cqueue[0]) || cqueue[0] == EOF)) {

          /* Missing value? */

        if (length == 1 && (line [0] == '?' || line [0] == '.'))

          return cbf_return_text (CBFWORD, val, &line [0], CBF_TOKEN_NULL);

        else

          return cbf_return_text (CBFWORD, val, &line [0], CBF_TOKEN_WORD);

      }

    }


      /* semicolon-delimited STRING (^;[^\n]*[\n])([^;][^\n]*[\n])*(;) */

    if (length == 0 && cqueue[0] == ';')
    {
      cbf_errornez (cbf_get_filecoordinates (file, NULL, &file_column), val)

      if (file_column == 1)
      {
          /* Save the position */

        cbf_errornez (cbf_get_fileposition (file, &position), val)

        mime = 0;

        do
        {
            /* Save the character */

          cbf_errornez (cbf_save_character_trim (file, (cqueue[0]&0xFF)), val)


            /* Check for a Mime boundary */

          if (cqueue[0] == '-')
          {
            cbf_errornez (cbf_get_buffer (file, &line, &length), val)

            cbf_nblen (line, &length);

            if (length > 29)

              mime = cbf_cistrcmp (&line [length - 30],
                                   "\n--CIF-BINARY-FORMAT-SECTION--")
                                    == 0;
          }


            /* Read the next character */
            
          cqueue[4] = cqueue[3];

          cqueue[3] = cqueue[2];
        
          cqueue[2] = cqueue[1];
            
          cqueue[1] = cqueue[0];

          cqueue[0] = cbf_read_character (file);
            
          if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;

          ascii = isgraph (cqueue[0]) || isspace (cqueue[0]);
          
          if (!ascii && (unsigned char)cqueue[0]!=12 && (unsigned char)cqueue[0]!=26 && (unsigned char)cqueue[0]!=4 && cqueue[0] != EOF) 
          {
          	cbf_log(handle,"invalid character in text field", CBF_LOGWARNING|CBF_LOGCURRENTLOC);
          	
          	ascii = 1;
          }
          
          if (ascii) {

            if (file->column == file->columnlimit+1) {
      
            cbf_log(handle, "over line size limit", CBF_LOGWARNING|CBF_LOGCURRENTLOC);


            }
          	
          }

        }
        while ((cqueue[2] != '\n' 
               || cqueue[1] != ';'
               || file->buffer_used < 3 
               || !(isspace(cqueue[0]) || cqueue[0]==EOF ||(file->read_headers & CBF_PARSE_CIF2_DELIMS))) 
             && !mime && ascii && cqueue[0] != EOF);

        if ( cqueue[0] == EOF && (cqueue[1] != ';' || cqueue[2] != '\n')) {
        
          cbf_log(handle, "text field terminated by EOF", CBF_LOGERROR|CBF_LOGCURRENTLOC);
        	
        }
          /* Plain ASCII string or terminated by EOF */

        if ((!mime && ascii) || cqueue[0]==EOF)
        {
          cbf_errornez (cbf_get_buffer (file, &line, &length), val)

          ((char *) line) [(length>2)?(length - 2):1] = '\0';

          return cbf_return_text (STRING, val, &line [1],
                                                  CBF_TOKEN_SCSTRING);
        }

        encoding = ENC_NONE;

        bits = 0;

        sign = -1;

        real = -1;

        checked_digest = 0;


          /* Mime header */

        if (mime)
        {
            /* Position */

          cbf_errornez (cbf_get_fileposition (file, &position), val)


            /* Read the header */
            
          dimover=dimfast=dimmid=dimslow=padding = 0;
          
          byteorder="little_endian";

          cbf_errornez (cbf_parse_mimeheader (file, &encoding,
                                                    &size,
                                                    &id,
                                                    digest,
                                                    &compression,
                                                    &bits,
                                                    &sign,
                                                    &real,
                                                    &byteorder,
                                                    &dimover,
                                                    &dimfast, &dimmid, &dimslow,
                                                    &padding), val);

           /* Attempt recovery from missing size */

           if (size == 0) {
	
 	     cbf_log(handle,
		      "binary size missing, attempting recovery", 
		         CBF_LOGWARNING|CBF_LOGCURRENTLOC);

             size = (dimover*bits+7)/8;

             switch (compression) {

			   case CBF_CANONICAL:

               case CBF_PACKED:

               case CBF_PACKED_V2:
				 size /= 4;
				 break;

		         case CBF_BYTE_OFFSET:
				 if (bits < 32) size /= 2;
				 else size /=4;
				 break;

		     }

          }

            /* Check the digest? */

          if ((file->read_headers & (MSG_DIGESTNOW|MSG_DIGESTWARN) ) &&
                                    cbf_is_base64digest (digest))
          {
              /* Recalculate the digest (note that this will decode the
                 binary section but not save the result so this section
                 is not very efficient) */

            code_size = 0;

            switch (encoding)
        {
              case ENC_QP:

                cbf_errornez (cbf_fromqp (file, NULL, size, &code_size,
                                                         new_digest), val)

                break;

              case ENC_BASE64:

                cbf_errornez (cbf_frombase64 (file, NULL, size, &code_size,
                                                         new_digest), val)

                break;

              case ENC_BASE32K:

		        cbf_errornez (cbf_frombase32k (file, NULL, size, &code_size, new_digest), val)
		
                break;


              case ENC_BASE8:
              case ENC_BASE10:
              case ENC_BASE16:

                cbf_errornez (cbf_frombasex (file, NULL, size, &code_size,
                                                         new_digest),val)

                break;

          case ENC_NONE:

                cbf_errornez (cbf_parse_binaryheader (file, NULL, \
                                                            NULL, \
                                                            NULL, \
                                                            mime), val)

                code_size = size;

                cbf_errornez (cbf_get_fileposition (file, &position), val)

                cbf_errornez (cbf_md5digest (file, code_size, new_digest),
                                                              val)

                break;

             default:

               cbf_errornez (CBF_FORMAT, val)
            }


              /* Check the number of characters read */

            if ((size && (size != code_size)) || code_size == 0) {

               cbf_log(handle, 
	         "size required to process digest", CBF_LOGERROR|CBF_LOGCURRENTLOC);

              cbf_errornez (CBF_FORMAT, val)

            }

              /* Compare the old digest to the new one */

            if (strcmp (digest, new_digest) != 0)  {
            
              if((file->read_headers & MSG_DIGESTWARN) ) {
              
                char buffer[80];
                
                sprintf(buffer, "digest mismatch file %s data %s", digest, new_digest );
                
                cbf_warning(buffer);
              	
              } else {
              	
                cbf_errornez (CBF_FORMAT | 2, val)

              }

            	
            }

            checked_digest = 1;
          }
          else
          {

              /* Calculate the minimum number of characters in the data */

            if (encoding == ENC_NONE)
            {
              cbf_errornez (cbf_parse_binaryheader (file, NULL, NULL, NULL, \
                                                                  mime), val)

              cbf_errornez (cbf_get_fileposition (file, &position), val)

              code_size = size;
            }
            else

              if (encoding == ENC_QP)

                code_size = size;

              else

                if (encoding == ENC_BASE64)

                  code_size = size * 8 / 6;
                  
                else

                  if (encoding == ENC_BASE32K)


		            code_size = size * 16 / 15;

                  else

                    code_size = size / 4;



              /* Skip to the end of the data */

             cbf_errornez (cbf_set_fileposition (file, code_size, SEEK_CUR), val)

          }

        }
        else
        {
            /* Simple binary */

          cbf_errornez (cbf_parse_binaryheader (file, &size, \
                                                      &id,   \
                                                      &compression, mime), val)

          cbf_errornez (cbf_get_fileposition (file, &position), val)

          code_size = size;


            /* Skip to the end of the data */

          cbf_errornez (cbf_set_fileposition (file, code_size, SEEK_CUR), val)
        }


          /* Find the terminating semi-colon */

        cqueue[3] = cqueue[2] = cqueue[1] = cqueue[0] = 0;

        if (mime) {
            
            do {
                if (cqueue[0]==EOF) break;
                
                cqueue[4] = cqueue[3];
                
                cqueue[3] = cqueue[2];
                
                cqueue[2] = cqueue[1];
                
                cqueue[1] = cqueue[0];
                
                cqueue[0] = cbf_read_character (file);
                
                if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;
                
                if (cqueue[0] == EOF && (cqueue[2] != '\n' ||  cqueue[1] != ';')) {
                    
                    cbf_log(handle, "text field terminated by EOF", CBF_LOGERROR|CBF_LOGCURRENTLOC);
                    
                    cbf_errornez (CBF_FILEREAD, val)
                }
            } while ( !(cqueue[3] == '-' && cqueue[2] == '-' && cqueue[1] =='-' && cqueue[0]=='-'));
        }
          
        do {

          if (cqueue[0]==EOF) break;
            
          cqueue[4] = cqueue[3];
          
          cqueue[3] = cqueue[2];
  
          cqueue[2] = cqueue[1];
  
          cqueue[1] = cqueue[0];

          cqueue[0] = cbf_read_character (file);
            
          if (cqueue[1] == '\\' && cqueue[2] == '\\') cqueue[1] += 0x100;

          if (cqueue[0] == EOF && (cqueue[2] != '\n' ||  cqueue[1] != ';')) {

            cbf_log(handle, "text field terminated by EOF", CBF_LOGERROR|CBF_LOGCURRENTLOC);

            cbf_errornez (CBF_FILEREAD, val)
          }
            
        } while ( !(cqueue[2] == '\n' && cqueue[1] ==';' && (isspace(cqueue[0]) || cqueue[0]==EOF || (file->read_headers & CBF_PARSE_CIF2_DELIMS))));


          /* Check the element size and sign */

        if (bits < 0 || bits > 64)

          cbf_errornez (CBF_FORMAT, val)

        if (bits == 0)

          bits = 32;

        if (sign == -1)

          sign = 1;


          /* Add a connection */

        cbf_errornez (cbf_add_fileconnection (&file, NULL), val)


          /* Code the id, file, position, size and digest */

        if (!cbf_is_base64digest (digest))

          strcpy (digest, "------------------------");

        sprintf (out_line, "%lx %p %lx %lx %d %s %x %d %d %s %ld %ld %ld %ld %ld %u",
                            id, (void *)file, position, (unsigned long) size, checked_digest,
                            digest, bits, sign, real<1?0:1, 
                            byteorder, (unsigned long)dimover, 
                            (unsigned long)dimfast, 
                            (unsigned long)dimmid, 
                            (unsigned long)dimslow, 
                            (unsigned long)padding,
                            compression);

        if (encoding == ENC_NONE)

          errorcode = cbf_return_text (BINARY, val, out_line,
                                                      CBF_TOKEN_BIN);

        else

          errorcode = cbf_return_text (BINARY, val, out_line,
                                                      CBF_TOKEN_MIME_BIN);

        if (errorcode == ERROR)

          val->errorcode |= cbf_delete_fileconnection (&file);

        return errorcode;
      }
    }


      /* Add the character to the text */

    errorcode = cbf_save_character_trim (file, (cqueue[0]&0xFF));

    cbf_errornez (errorcode, val);
  }
  while (cqueue[0] != EOF);

  return 0;
}


#ifdef __cplusplus

}

#endif
