//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "phaseplastTestApp.h"
#include "phaseplastApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
phaseplastTestApp::validParams()
{
  InputParameters params = phaseplastApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

phaseplastTestApp::phaseplastTestApp(InputParameters parameters) : MooseApp(parameters)
{
  phaseplastTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

phaseplastTestApp::~phaseplastTestApp() {}

void
phaseplastTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  phaseplastApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"phaseplastTestApp"});
    Registry::registerActionsTo(af, {"phaseplastTestApp"});
  }
}

void
phaseplastTestApp::registerApps()
{
  registerApp(phaseplastApp);
  registerApp(phaseplastTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
phaseplastTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  phaseplastTestApp::registerAll(f, af, s);
}
extern "C" void
phaseplastTestApp__registerApps()
{
  phaseplastTestApp::registerApps();
}
