//
//  kern_start.cpp
//  genericPatcher
//
//  Copyright © 2017 coderobe. All rights reserved.
//

#include <Headers/plugin_start.hpp>
#include <Headers/kern_api.hpp>

#include "kern_patchset.hpp"

static PatchSet patchset;

static const char *bootargOff[] {
	"-cdrpatchoff"
};

#ifdef DEVELOPER
static const char *bootargDebug[] {
	"-cdrpatchdbg"
};
#endif

static const char *bootargBeta[] {
	"-cdrpatchbeta"
};

PluginConfiguration ADDPR(config) {
    xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal,
    bootargOff,
    arrsize(bootargOff),
    bootargBeta,
    arrsize(bootargBeta),
    nullptr, 0,
    KernelVersion::HighSierra,
    KernelVersion::Catalina,
	[]() {
		patchset.init();
	}
};





