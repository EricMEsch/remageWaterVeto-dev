// Copyright (C) 2022 Luigi Pertoldi <gipert@pm.me>
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.


#ifndef _RMG_SCINTILLATION_HH_
#define _RMG_SCINTILLATION_HH_

#include "G4Scintillation.hh"
#include "Randomize.hh"
#include "globals.hh"

class RMGScintillation : public G4Scintillation {
  public:

    RMGScintillation(const G4String& name = "Scintillation") : G4Scintillation(name) {}

    virtual G4VParticleChange* PostStepDoIt(const G4Track& track, const G4Step& step) override {
      CLHEP::HepRandomEngine* defaultEngine = G4Random::getTheEngine();

      CLHEP::HepRandomEngine* secondEngine = new CLHEP::RanecuEngine;

      G4Random::setTheEngine(secondEngine);

      // Call the original PostStepDoIt
      G4VParticleChange* particleChange = G4Scintillation::PostStepDoIt(track, step);

      G4Random::setTheEngine(defaultEngine);

      return particleChange;
    }
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
