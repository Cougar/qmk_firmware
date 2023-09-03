#pragma once

#include "version.h"

// https://docs.qmk.fm/#/feature_caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef PRODUCT
#undef PRODUCT
#endif
#define PRODUCT "DZ60_ISO_HolyPanda"

#ifdef MANUFACTURER
#undef MANUFACTURER
#endif
#define MANUFACTURER "Cougar(KBDFans+QMK)"
