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


#ifndef _RMG_CERENKOV_HH_
#define _RMG_CERENKOV_HH_

#include "G4Cerenkov.hh"
#include "Randomize.hh"
#include "globals.hh"

class RMGCerenkov : public G4Cerenkov {
  public:

    static G4ThreadLocal CLHEP::HepRandomEngine* fAlternativeEngine;

    RMGCerenkov(const G4String& name = "RMGCerenkov");

    virtual G4VParticleChange* PostStepDoIt(const G4Track& track, const G4Step& step) override;

    G4double PostStepGetPhysicalInteractionLength(const G4Track& aTrack, G4double,
        G4ForceCondition* condition) override;
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
