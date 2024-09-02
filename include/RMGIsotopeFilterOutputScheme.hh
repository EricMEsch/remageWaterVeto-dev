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

#ifndef _RMG_ISOTOPE_FILTER_OUTPUT_SCHEME_HH_
#define _RMG_ISOTOPE_FILTER_OUTPUT_SCHEME_HH_

#include <optional>
#include <set>

#include "G4AnalysisManager.hh"
#include "G4GenericMessenger.hh"
#include "G4VUserEventInformation.hh"

#include "RMGVOutputScheme.hh"

class RMGIsotopeFilterEventInformation : public G4VUserEventInformation {

  public:

    RMGIsotopeFilterEventInformation() = default;
    inline void Print() const override {}
};

class G4Event;
class RMGIsotopeFilterOutputScheme : public RMGVOutputScheme {

  public:

    RMGIsotopeFilterOutputScheme();

    bool ShouldDiscardEvent(const G4Event*) override;
    std::optional<bool> StackingActionNewStage(int) override;
    std::optional<G4ClassificationOfNewTrack> StackingActionClassify(const G4Track*, int) override;
    void TrackingActionPre(const G4Track* aTrack) override;

    inline void AddIsotope(int a, int z) { fIsotopes.insert({a, z}); }

  private:

    std::unique_ptr<G4GenericMessenger> fMessenger;
    void DefineCommands();

    std::set<std::pair<int, int>> fIsotopes;

    bool fDiscardPhotonsIfIsotopeNotProduced = false;
};

#endif

// vim: tabstop=2 shiftwidth=2 expandtab