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


#include "RMGCerenkov.hh"

G4ThreadLocal CLHEP::HepRandomEngine* RMGCerenkov::fAlternativeEngine = nullptr;

RMGCerenkov::RMGCerenkov(const G4String& name) : G4Cerenkov(name) {
  if (!fAlternativeEngine) { fAlternativeEngine = new CLHEP::RanecuEngine; }
}

G4VParticleChange* RMGCerenkov::PostStepDoIt(const G4Track& track, const G4Step& step) {
  CLHEP::HepRandomEngine* defaultEngine = G4Random::getTheEngine();

  G4Random::setTheEngine(fAlternativeEngine);

  // Call the original Cerenkov PostStepDoIt
  G4VParticleChange* particleChange = G4Cerenkov::PostStepDoIt(track, step);

  G4Random::setTheEngine(defaultEngine);

  return particleChange;
}

G4double RMGCerenkov::PostStepGetPhysicalInteractionLength(const G4Track& aTrack, G4double,
    G4ForceCondition* condition) {
  G4double StepLimit = DBL_MAX;
  *condition = StronglyForced;
  return StepLimit;
}
