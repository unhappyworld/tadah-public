#include "stdafx.h"

#include "GameVerbs.h"

#include "Document.h"
#include "FunctionMarshaller.h"
#include "RenderSettingsItem.h"
#include "Resource.h"
#include "utility/FileSystem.h"
#include "utility/Http.h"
#include "utility/Statistics.h"
#include "v8datamodel/Game.h"
#include "v8datamodel/GameBasicSettings.h"
#include "View.h"
#include "Application.h"
#include "LogManager.h"

namespace RBX {

LeaveGameVerb::LeaveGameVerb(View& view, VerbContainer* container)
	: Verb(container, "Exit")
	, v(view)
{
}

void LeaveGameVerb::doIt(IDataState* dataState)
{
	MainLogManager::getMainLogManager()->setLeaveGame();
    v.CloseWindow();
}

ToggleFullscreenVerb::ToggleFullscreenVerb(View& view, VerbContainer* container) 
	: Verb(container, "ToggleFullScreen")
	, view(view)
{}

bool ToggleFullscreenVerb::isChecked() const 
{
	return view.IsFullscreen();
}

bool ToggleFullscreenVerb::isEnabled() const
{
	return true; 
}

void ToggleFullscreenVerb::doIt(RBX::IDataState* dataState)
{
	FASTLOG(FLog::Verbs, "Gui:ToggleFullscreen");

	view.SetFullscreen(!view.IsFullscreen());
}


}  // namespace RBX
