#include "phaseplastApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
phaseplastApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_bahavior") = false;
  return params;
}

phaseplastApp::phaseplastApp(InputParameters parameters) : MooseApp(parameters)
{
  phaseplastApp::registerAll(_factory, _action_factory, _syntax);
}

phaseplastApp::~phaseplastApp() {}

void
phaseplastApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<phaseplastApp>(f, af, s);
  Registry::registerObjectsTo(f, {"phaseplastApp"});
  Registry::registerActionsTo(af, {"phaseplastApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
phaseplastApp::registerApps()
{
  registerApp(phaseplastApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
phaseplastApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  phaseplastApp::registerAll(f, af, s);
}
extern "C" void
phaseplastApp__registerApps()
{
  phaseplastApp::registerApps();
}
