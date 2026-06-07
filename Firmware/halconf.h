#pragma once
#include_next "halconf.h"

// Required for ps2_interrupt driver (palEnableLineEvent / palSetLineCallback)
#undef PAL_USE_CALLBACKS
#define PAL_USE_CALLBACKS TRUE
