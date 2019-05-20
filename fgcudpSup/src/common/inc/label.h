/*---------------------------------------------------------------------------------------------------------*\
  File:     label.h

  Purpose:  FGCD struct declaration userd for the labels generated by the parser

\*---------------------------------------------------------------------------------------------------------*/

#ifndef LABEL_H // header encapsulation
#define LABEL_H

#include <stdint.h>

struct sym_name
{
    uint32_t         type;               // Type index
    const char      *label;             // Pointer to label (string constant)
};

#endif  // LABEL_H end of header encapsulation
/*---------------------------------------------------------------------------------------------------------*\
  End of file: label.h
\*---------------------------------------------------------------------------------------------------------*/
