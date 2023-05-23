#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _Traub_reg(void);
extern void _dCaAP_reg(void);
extern void _myAMPA_reg(void);
extern void _myGABA_reg(void);
extern void _myNMDA_reg(void);
extern void _mySyn_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"GidonEtAl/_mod/Traub.mod\"");
    fprintf(stderr, " \"GidonEtAl/_mod/dCaAP.mod\"");
    fprintf(stderr, " \"GidonEtAl/_mod/myAMPA.mod\"");
    fprintf(stderr, " \"GidonEtAl/_mod/myGABA.mod\"");
    fprintf(stderr, " \"GidonEtAl/_mod/myNMDA.mod\"");
    fprintf(stderr, " \"GidonEtAl/_mod/mySyn.mod\"");
    fprintf(stderr, "\n");
  }
  _Traub_reg();
  _dCaAP_reg();
  _myAMPA_reg();
  _myGABA_reg();
  _myNMDA_reg();
  _mySyn_reg();
}

#if defined(__cplusplus)
}
#endif
