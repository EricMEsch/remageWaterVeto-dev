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

#ifndef _RMG_PARTICLE_FILTER_OUTPUT_SCHEME_HH_
#define _RMG_PARTICLE_FILTER_OUTPUT_SCHEME_HH_

#include <optional>
#include <set>

#include "G4GenericMessenger.hh"

#include "RMGVOutputScheme.hh"

class RMGParticleFilterOutputScheme : public RMGVOutputScheme {

  public:

    RMGParticleFilterOutputScheme();

    std::optional<G4ClassificationOfNewTrack> StackingActionClassify(const G4Track*, int) override;

    inline void AddParticle(int pdg) { fParticles.insert(pdg); }
    void AddKeepVolume(std::string name);
    void AddKillVolume(std::string name);

  private:

    std::unique_ptr<G4GenericMessenger> fMessenger;
    void DefineCommands();

    std::set<int> fParticles;
    std::set<std::string> fKeepVolumes;
    std::set<std::string> fKillVolumes;
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab
