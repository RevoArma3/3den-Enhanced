/*
  Author: R3vo

  Date: 2020-06-14

  Description:
  Used by the ENH_InventoryManager GUI. Creates a template.

  Parameter(s):
  0: CONTROL - Control Button

  Returns:
  -
*/

#include "\3denEnhanced\defineCommon.hpp"

disableSerialization;
params ["_ctrlButton"];
private _templates = profileNamespace getVariable ["ENH_IM_Templates", []];

//Return inventory data
private _value = [true] call ENH_fnc_IM_applyAttribute;

private _displayChild = ctrlParent _ctrlButton;
private _templateTitle = ctrlText (_displayChild displayCtrl IDC_IM_TEMPLATEDATA_TITLE);
private _templateDescription = ctrlText (_displayChild displayCtrl IDC_IM_TEMPLATEDATA_DESCRIPTION);

if !(_templateTitle isEqualTo "") then
{
  _templates pushBack [_templateTitle, _templateDescription, _value];
  profileNamespace setVariable ["ENH_IM_Templates", _templates];
  _displayChild closeDisplay 1;
  call ENH_fnc_IM_updateTemplateList;
};