#ifndef _RMGUICMDSTEPLIMIT_HH
#define _RMGUICMDSTEPLIMIT_HH

#include "G4UIcommand.hh"

class RMGUIcmdStepLimit : public G4UIcommand {

  public:

    RMGUIcmdStepLimit(G4String command_path, G4UImessenger* messenger);
    G4double GetStepSize(G4String par_string);
    G4String GetParticleName(G4String par_string);
    G4String GetVolumeName(G4String par_string);
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab