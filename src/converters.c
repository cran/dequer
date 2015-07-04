/*  Copyright (c) 2015, Schmidt
    All rights reserved.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    
    1. Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "deque.h"


static void append_item_to_Rlist(SEXP Rlist, int i, SEXP data)
{
  SEXP cpdata = duplicate(data);
/*  R_PreserveObject(cpdata);*/
  SET_VECTOR_ELT(Rlist, i, cpdata);
}

SEXP R_deque_to_Rlist(SEXP deque_ptr)
{
  deque_t *dl = (deque_t *) getRptr(deque_ptr);
  const int len = dl->len;
  
  list_t *l = dl->start;
  
  SEXP Rlist;
  PROTECT(Rlist = allocVector(VECSXP, len));
  
  for (int i=0; i<len; i++)
  {
    append_item_to_Rlist(Rlist, i, l->data);
    l = l->next;
  }
  
  UNPROTECT(1);
  return Rlist;
}



#if 0
SEXP R_deque_to_subRlist(SEXP deque_ptr, SEXP indices)
{
  deque_t *dl = (deque_t *) getRptr(deque_ptr);
  const int len = dl->len;
  const int indlen = LENGTH(indices);
  
  list_t *l = dl->start;
  
  SEXP Rlist;
  PROTECT(Rlist = allocVector(VECSXP, len));
  
  while (l)
  {
    
    append_item_to_Rlist(Rlist, i, l->data);
    
    l = l->next;
  }
  
  for (int i=0; i<len; i++)
  {
    append_item_to_Rlist(Rlist, i, l->data);
    l = l->next;
  }
  
  UNPROTECT(1);
  return Rlist;
}

#endif