#include "PMPhysicsList.hh"

PMPhysicsList::PMPhysicsList()
{
    // EM standard physics
    RegisterPhysics(new G4EmStandardPhysics());
}

PMPhysicsList::~PMPhysicsList()
{
}